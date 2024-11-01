/* Copyright (c) 2015, Robert Escriva
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of this project nor the names of its contributors may
 *       be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* C */
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <string.h>

/* POSIX */
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

/* popt */
#include <popt.h>

/* redupe */
#include <redupe.h>

#define BUF_SIZE 4096

static int
encode_stream(FILE* input, struct redupe_encode_file* output)
{
    unsigned char buf[BUF_SIZE];

    while (1)
    {
        size_t amt = fread(buf, 1, BUF_SIZE, input);

        if (ferror(input))
        {
            fprintf(stderr, "error reading input\n");
            return EXIT_FAILURE;
        }

        if (amt == 0)
        {
            break;
        }

        assert(amt > 0);
        ssize_t written = redupe_encode_write(output, buf, amt);

        if (written != (ssize_t)amt)
        {
            fprintf(stderr, "error writing output\n");
            return EXIT_FAILURE;
        }

        if (feof(input))
        {
            break;
        }
    }

    return EXIT_SUCCESS;
}

static int
correct_stream(struct redupe_correct_file* input, FILE* output)
{
    unsigned char buf[BUF_SIZE];

    while (1)
    {
        ssize_t amt = redupe_correct_read(input, buf, BUF_SIZE);

        if (amt < 0)
        {
            fprintf(stderr, "error reading input\n");
            return EXIT_FAILURE;
        }
        else if (amt == 0)
        {
            break;
        }

        size_t written = fwrite(buf, 1, amt, output);

        if (written != (size_t)amt)
        {
            fprintf(stderr, "error writing output\n");
            return EXIT_FAILURE;
        }
    }

    if (fflush(output) != 0)
    {
        fprintf(stderr, "error flushing output: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    fsync(fileno(output));
    return EXIT_SUCCESS;
}

int
main(int argc, const char* argv[])
{
    int rc;

    int encode = 0;
    int decode = 0;
    double overhead = 12.549;
    char* input_file = NULL;
    char* output_file = NULL;

    struct poptOption redupe_args[] = {
        POPT_AUTOHELP
        {"encode", 'e', POPT_ARG_NONE, &encode, 0, "Encode file or stream", ""},
        {"decode", 'd', POPT_ARG_NONE, &decode, 0, "Decode file or stream", ""},
        {"percent", 'p', POPT_ARG_DOUBLE, &overhead, 0, "overhead as a % (default 12.5%)", "0-100"},
        {"input", 'i', POPT_ARG_STRING, &input_file, 0, "Input filename, default stdin", ""},
        {"output", 'o', POPT_ARG_STRING, &output_file, 0, "Input filename, default stdout", ""},
        POPT_TABLEEND
    };

    poptContext ctx;
    ctx = poptGetContext(NULL, argc, argv, redupe_args,
                         POPT_CONTEXT_POSIXMEHARDER);

    while ((rc = poptGetNextOpt(ctx)) != -1)
    {
        if (rc <= 0)
        {
            switch (rc)
            {
                case POPT_ERROR_NOARG:
                case POPT_ERROR_BADOPT:
                case POPT_ERROR_BADNUMBER:
                case POPT_ERROR_OVERFLOW:
                    fprintf(stderr, "%s %s\n", poptStrerror(rc), poptBadOption(ctx, 0));
                    poptPrintUsage(ctx, stderr, 0);
                    return EXIT_FAILURE;
                case POPT_ERROR_OPTSTOODEEP:
                case POPT_ERROR_BADQUOTE:
                case POPT_ERROR_ERRNO:
                default:
                    fprintf(stderr, "logic error in argument parsing\n");
                    poptPrintUsage(ctx, stderr, 0);
                    return EXIT_FAILURE;
            }

            continue;
        }
    }

    if (!(encode || decode))
    {
        fprintf(stderr, "encode or decode operation must be specified\n");
        poptPrintUsage(ctx, stderr, 0);
        return EXIT_FAILURE;
    }
    if (encode && decode)
    {
        fprintf(stderr, "Only encode or decode operation must be specified, not both\n");
        poptPrintUsage(ctx, stderr, 0);
        return EXIT_FAILURE;
    }

    if (overhead < 1 || overhead >= 95)
    {
        fprintf(stderr, "overhead %% must be in the range [1, 95)\n");
        poptPrintUsage(ctx, stderr, 0);
        return EXIT_FAILURE;
    }

    unsigned code_sz = 32;
    unsigned msg_sz = 223;
    code_sz = ceil(2.55 * overhead);
    msg_sz = 255 - code_sz;
    assert(code_sz < 255);
    assert(code_sz > 0);
    assert(msg_sz <= 255);
    assert(msg_sz > 0);

    const char** args = poptGetArgs(ctx);
    int ret = EXIT_SUCCESS;

    FILE *input = stdin;
    if (input_file) {
        fprintf(stderr, "Using input %s\n", input_file);
        input = fopen(input_file, "r");
        if (input == NULL) {
            perror("open input");
            exit(1);
        }
    }

    FILE *output = stdout;
    if (output_file) {
        fprintf(stderr, "Using output %s\n", output_file);
        output = fopen(output_file, "w");
        if (output == NULL) {
            perror("open output");
            exit(1);
        }
    }


    if (!args || !*args)
    {
        if (decode)
        {
            struct redupe_correct_file* stream = redupe_correct_from_file(input);

            if (!stream)
            {
                fprintf(stderr, "error allocating memory\n");
                ret = EXIT_FAILURE;
            }
            else
            {
                ret = correct_stream(stream, output);

                if (redupe_correct_close(stream) < 0)
                {
                    fprintf(stderr, "error reading input\n");
                    ret = EXIT_FAILURE;
                }
            }
        }
        else
        {
            struct redupe_encode_file* stream = redupe_encode_from_file(output, code_sz);

            if (!stream)
            {
                fprintf(stderr, "error allocating memory\n");
                ret = EXIT_FAILURE;
            }
            else
            {
                ret = encode_stream(input, stream);

                if (redupe_encode_close(stream) < 0)
                {
                    fprintf(stderr, "error reading output\n");
                    ret = EXIT_FAILURE;
                }
            }
        }
    }
    else
    {
        poptPrintUsage(ctx, stderr, 0);
    }

    poptFreeContext(ctx);
    return ret;
}
