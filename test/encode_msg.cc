// Copyright (c) 2015, Robert Escriva
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of this project nor the names of its contributors may
//       be used to endorse or promote products derived from this software
//       without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Generated test vectors against the demo Python implementation provided here:
// https://en.wikiversity.org/wiki/Reed%E2%80%93Solomon_codes_for_coders
// Demo implementation and accompanying text licenced under Creative Commons
// Attribution-ShareAlike License.

// redupe
#include "redupe.h"
#include "redupe-internal.h"

// testing
#include "th.h"

TEST(RsEncodeMsg, Test0)
{
    unsigned char msg_in[] = {204, 102, 215, 14, 174, 208, 193, 254, 246, 243, 13, 246, 212, 239, 126, 181, 113, 43, 169, 129, 69, 200, 210, 116, 25, 58, 157, 178, 76, 72, 226, 128, 46, 90, 13, 185, 190, 165, 59, 116, 38};
    const unsigned msg_in_sz = 41;
    unsigned char r[] = {204, 102, 215, 14, 174, 208, 193, 254, 246, 243, 13, 246, 212, 239, 126, 181, 113, 43, 169, 129, 69, 200, 210, 116, 25, 58, 157, 178, 76, 72, 226, 128, 46, 90, 13, 185, 190, 165, 59, 116, 38, 84, 41, 88, 152};
    const unsigned r_sz = 45;
    unsigned char buf[300];
    const unsigned nsym = 4;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test1)
{
    unsigned char msg_in[] = {214, 128, 99, 46, 194, 199, 253, 213, 235, 116, 127, 78, 15, 60, 108, 28, 68, 175, 92, 150, 193, 141, 10, 55, 216, 199, 33, 94, 109, 77, 140, 1, 166, 228, 57, 28, 53, 207, 214, 234, 163, 74, 20, 232, 244, 144, 159, 210, 5, 15, 161, 59, 136, 81, 186, 172, 11, 203, 9, 26, 240, 160, 123, 81};
    const unsigned msg_in_sz = 64;
    unsigned char r[] = {214, 128, 99, 46, 194, 199, 253, 213, 235, 116, 127, 78, 15, 60, 108, 28, 68, 175, 92, 150, 193, 141, 10, 55, 216, 199, 33, 94, 109, 77, 140, 1, 166, 228, 57, 28, 53, 207, 214, 234, 163, 74, 20, 232, 244, 144, 159, 210, 5, 15, 161, 59, 136, 81, 186, 172, 11, 203, 9, 26, 240, 160, 123, 81, 98, 177, 143, 113};
    const unsigned r_sz = 68;
    unsigned char buf[300];
    const unsigned nsym = 4;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test2)
{
    unsigned char msg_in[] = {102, 202, 185, 183, 187, 77, 196, 201, 122, 46, 176, 187, 215, 30, 78, 218, 95, 69, 140, 48, 74, 187, 41, 112, 183, 121, 4, 14, 211, 204, 124, 246, 122, 143, 163, 115, 89, 238, 19, 236, 49, 196, 130, 151, 254, 120, 103, 131, 186, 13, 61, 186, 189, 102, 94, 187, 103, 23, 181, 239, 132, 95, 177, 50, 97, 127, 180, 31, 174, 251, 15, 208, 6, 197, 199, 251, 10, 220, 220, 90, 51, 142, 149, 165, 208, 209, 204, 111, 167, 95, 225, 54, 10, 206, 193, 129, 195, 45, 223, 253, 140, 23, 12, 81, 124, 245, 29, 2, 106, 92, 185, 95, 208, 149, 93, 227, 42, 94, 77, 188, 57, 130, 222, 70, 80, 214, 138, 108, 52, 164, 28, 191, 32, 81, 232, 200, 195, 236, 147, 52, 5, 166, 38, 226, 163, 110, 17, 36, 46, 25, 193, 29, 50, 158, 86, 52, 236, 64, 200, 155, 248, 125, 182, 16, 252, 22, 84, 60, 25, 224, 63, 10, 79, 68, 10, 110, 88, 91, 39, 57, 73, 191, 179, 11, 157, 249, 227, 55, 196, 196, 167, 37, 43, 79, 178, 43, 65, 82, 218, 65, 240, 96, 206, 238, 65, 248, 76, 92, 93, 235, 213, 75};
    const unsigned msg_in_sz = 212;
    unsigned char r[] = {102, 202, 185, 183, 187, 77, 196, 201, 122, 46, 176, 187, 215, 30, 78, 218, 95, 69, 140, 48, 74, 187, 41, 112, 183, 121, 4, 14, 211, 204, 124, 246, 122, 143, 163, 115, 89, 238, 19, 236, 49, 196, 130, 151, 254, 120, 103, 131, 186, 13, 61, 186, 189, 102, 94, 187, 103, 23, 181, 239, 132, 95, 177, 50, 97, 127, 180, 31, 174, 251, 15, 208, 6, 197, 199, 251, 10, 220, 220, 90, 51, 142, 149, 165, 208, 209, 204, 111, 167, 95, 225, 54, 10, 206, 193, 129, 195, 45, 223, 253, 140, 23, 12, 81, 124, 245, 29, 2, 106, 92, 185, 95, 208, 149, 93, 227, 42, 94, 77, 188, 57, 130, 222, 70, 80, 214, 138, 108, 52, 164, 28, 191, 32, 81, 232, 200, 195, 236, 147, 52, 5, 166, 38, 226, 163, 110, 17, 36, 46, 25, 193, 29, 50, 158, 86, 52, 236, 64, 200, 155, 248, 125, 182, 16, 252, 22, 84, 60, 25, 224, 63, 10, 79, 68, 10, 110, 88, 91, 39, 57, 73, 191, 179, 11, 157, 249, 227, 55, 196, 196, 167, 37, 43, 79, 178, 43, 65, 82, 218, 65, 240, 96, 206, 238, 65, 248, 76, 92, 93, 235, 213, 75, 235, 29, 26, 106, 37, 163, 136, 242};
    const unsigned r_sz = 220;
    unsigned char buf[300];
    const unsigned nsym = 8;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test3)
{
    unsigned char msg_in[] = {245, 48, 202, 252, 83, 6, 145, 154, 216, 246, 67, 49, 94, 30, 214, 178, 45, 65, 107, 160, 105, 62, 75, 11, 8, 204, 151, 172, 182, 35, 135, 39, 201, 152, 175, 112, 21, 114, 220, 173, 45, 229, 52, 7, 78, 75, 104, 136, 104, 115, 26, 25, 169, 200, 13, 158, 157, 70, 192, 98, 10, 229, 73, 106, 152, 40, 18, 20, 193, 88, 100, 242, 118, 146, 240, 99, 107, 39, 167, 21, 240, 132, 113, 14, 92, 92, 230, 91, 170, 74, 28, 197, 101, 43, 180, 199, 105, 137, 134, 250, 222, 212, 196, 202, 49, 52, 193, 178, 150, 41, 62, 236, 185, 141, 14, 130, 153, 147, 64, 7, 35, 190, 144, 27, 249, 149, 97, 219, 218, 52, 52, 30, 140, 221, 68, 228, 182, 203, 254, 213, 35, 222, 206, 184, 6, 139, 198, 53, 116, 114, 19, 155, 166, 182, 24, 196, 34, 28, 79, 90, 96, 71, 199, 132, 228, 86, 113, 245, 181, 47};
    const unsigned msg_in_sz = 170;
    unsigned char r[] = {245, 48, 202, 252, 83, 6, 145, 154, 216, 246, 67, 49, 94, 30, 214, 178, 45, 65, 107, 160, 105, 62, 75, 11, 8, 204, 151, 172, 182, 35, 135, 39, 201, 152, 175, 112, 21, 114, 220, 173, 45, 229, 52, 7, 78, 75, 104, 136, 104, 115, 26, 25, 169, 200, 13, 158, 157, 70, 192, 98, 10, 229, 73, 106, 152, 40, 18, 20, 193, 88, 100, 242, 118, 146, 240, 99, 107, 39, 167, 21, 240, 132, 113, 14, 92, 92, 230, 91, 170, 74, 28, 197, 101, 43, 180, 199, 105, 137, 134, 250, 222, 212, 196, 202, 49, 52, 193, 178, 150, 41, 62, 236, 185, 141, 14, 130, 153, 147, 64, 7, 35, 190, 144, 27, 249, 149, 97, 219, 218, 52, 52, 30, 140, 221, 68, 228, 182, 203, 254, 213, 35, 222, 206, 184, 6, 139, 198, 53, 116, 114, 19, 155, 166, 182, 24, 196, 34, 28, 79, 90, 96, 71, 199, 132, 228, 86, 113, 245, 181, 47, 63, 15, 253, 79, 90, 207, 250, 152};
    const unsigned r_sz = 178;
    unsigned char buf[300];
    const unsigned nsym = 8;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test4)
{
    unsigned char msg_in[] = {51, 157, 106, 198, 80, 69, 121, 38, 235, 103, 162, 227, 60, 42, 31, 95, 169, 22, 155, 41, 216, 234, 153, 255, 70, 39, 126, 32, 122, 233, 194, 251};
    const unsigned msg_in_sz = 32;
    unsigned char r[] = {51, 157, 106, 198, 80, 69, 121, 38, 235, 103, 162, 227, 60, 42, 31, 95, 169, 22, 155, 41, 216, 234, 153, 255, 70, 39, 126, 32, 122, 233, 194, 251, 223, 10, 212, 165, 46, 107, 130, 82, 117, 89, 149, 90, 224, 165, 106, 226};
    const unsigned r_sz = 48;
    unsigned char buf[300];
    const unsigned nsym = 16;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test5)
{
    unsigned char msg_in[] = {218, 56, 193, 136, 169, 254, 253, 33, 249, 247, 227, 104, 47, 197, 195, 232, 89, 103, 230, 37, 87, 177, 159, 132, 80, 16, 41, 243, 1, 180, 134, 55, 96, 237, 168, 237, 156, 187, 199, 114, 140, 68, 96, 129, 172, 224, 207, 203, 186, 242, 156, 21, 59, 197, 79, 221, 44, 36, 111, 223, 95, 69, 127, 19, 171, 223, 72, 132, 26, 23, 201, 105, 103, 150, 182, 147, 107, 160, 50, 155, 98, 42, 143, 242, 57};
    const unsigned msg_in_sz = 85;
    unsigned char r[] = {218, 56, 193, 136, 169, 254, 253, 33, 249, 247, 227, 104, 47, 197, 195, 232, 89, 103, 230, 37, 87, 177, 159, 132, 80, 16, 41, 243, 1, 180, 134, 55, 96, 237, 168, 237, 156, 187, 199, 114, 140, 68, 96, 129, 172, 224, 207, 203, 186, 242, 156, 21, 59, 197, 79, 221, 44, 36, 111, 223, 95, 69, 127, 19, 171, 223, 72, 132, 26, 23, 201, 105, 103, 150, 182, 147, 107, 160, 50, 155, 98, 42, 143, 242, 57, 213, 144, 90, 92, 27, 84, 53, 184, 129, 135, 177, 244, 58, 196, 158, 175};
    const unsigned r_sz = 101;
    unsigned char buf[300];
    const unsigned nsym = 16;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test6)
{
    unsigned char msg_in[] = {241, 102, 33, 187, 100, 148, 209, 217, 117, 227, 220, 234, 164, 14, 27, 38, 84, 196, 90, 250, 217, 76, 163, 56, 104, 70, 198, 59, 201, 147, 186, 42, 6, 125, 245, 139, 121, 143, 94, 43, 19, 150, 157, 62, 131, 180, 128, 177, 54, 2, 3, 167, 109, 33, 105, 180, 159, 16, 134, 26, 152, 126, 244, 54, 183, 143, 102, 30, 233, 229, 140, 53, 88, 131, 204, 244, 104, 154, 22, 90, 253, 40, 186, 97, 92, 156, 169, 188, 52, 168, 127, 247, 23, 169, 190, 165, 205, 30, 106, 175, 150, 150, 175, 67, 205, 14, 188, 122, 239, 109, 20, 106, 62, 151, 196, 196, 194, 79, 74, 160, 49, 163, 21, 85, 197, 207, 85, 112, 153, 46, 14, 219, 21, 130, 193, 226, 45, 62, 3, 2, 86, 229, 207, 78, 179, 249, 121, 126, 124, 115, 77, 210, 146, 222, 233, 220};
    const unsigned msg_in_sz = 156;
    unsigned char r[] = {241, 102, 33, 187, 100, 148, 209, 217, 117, 227, 220, 234, 164, 14, 27, 38, 84, 196, 90, 250, 217, 76, 163, 56, 104, 70, 198, 59, 201, 147, 186, 42, 6, 125, 245, 139, 121, 143, 94, 43, 19, 150, 157, 62, 131, 180, 128, 177, 54, 2, 3, 167, 109, 33, 105, 180, 159, 16, 134, 26, 152, 126, 244, 54, 183, 143, 102, 30, 233, 229, 140, 53, 88, 131, 204, 244, 104, 154, 22, 90, 253, 40, 186, 97, 92, 156, 169, 188, 52, 168, 127, 247, 23, 169, 190, 165, 205, 30, 106, 175, 150, 150, 175, 67, 205, 14, 188, 122, 239, 109, 20, 106, 62, 151, 196, 196, 194, 79, 74, 160, 49, 163, 21, 85, 197, 207, 85, 112, 153, 46, 14, 219, 21, 130, 193, 226, 45, 62, 3, 2, 86, 229, 207, 78, 179, 249, 121, 126, 124, 115, 77, 210, 146, 222, 233, 220, 136, 25, 223, 42, 71, 62, 12, 169, 254, 27, 62, 26, 117, 251, 84, 76, 238, 40, 43, 238, 40, 47, 72, 203, 246, 21, 16, 10, 215, 112, 54, 213};
    const unsigned r_sz = 188;
    unsigned char buf[300];
    const unsigned nsym = 32;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test7)
{
    unsigned char msg_in[] = {110, 163, 11, 121, 86, 117, 208, 206, 141, 194, 156, 200, 163, 84, 204, 114, 135, 113, 79, 63, 156, 140, 168, 218, 132, 223, 207, 42, 8, 29, 17, 215, 71, 211, 157, 112, 2, 243, 210, 117, 97, 246, 66, 194, 118, 109, 80, 231, 213, 106, 104, 240, 183, 165, 212, 1, 131, 209, 88, 101, 37, 59, 107, 158, 105, 27, 1, 27, 144, 163, 173, 129, 29, 158, 244, 133, 84, 8, 51};
    const unsigned msg_in_sz = 79;
    unsigned char r[] = {110, 163, 11, 121, 86, 117, 208, 206, 141, 194, 156, 200, 163, 84, 204, 114, 135, 113, 79, 63, 156, 140, 168, 218, 132, 223, 207, 42, 8, 29, 17, 215, 71, 211, 157, 112, 2, 243, 210, 117, 97, 246, 66, 194, 118, 109, 80, 231, 213, 106, 104, 240, 183, 165, 212, 1, 131, 209, 88, 101, 37, 59, 107, 158, 105, 27, 1, 27, 144, 163, 173, 129, 29, 158, 244, 133, 84, 8, 51, 112, 92, 211, 120, 70, 145, 170, 134, 135, 183, 229, 195, 35, 121, 113, 106, 174, 85, 129, 127, 114, 165, 125, 227, 192, 171, 203, 212, 104, 144, 7, 175};
    const unsigned r_sz = 111;
    unsigned char buf[300];
    const unsigned nsym = 32;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test8)
{
    unsigned char msg_in[] = {156, 26, 19, 164, 238, 34, 159, 154, 139, 67, 175, 37, 193, 69, 31, 103, 171, 87, 89, 80, 213, 111, 219, 2, 41, 149, 233, 152, 101, 44, 32, 116, 35, 105, 7, 105, 93, 245, 126, 127, 190, 102, 168, 36, 53, 224, 252, 16, 44, 67, 96, 249, 223, 95, 47, 173, 250, 69, 163, 113, 30, 4, 86, 147, 142, 196, 111, 136, 1, 114, 8, 106, 94, 87, 27, 44, 140, 53, 212, 94, 151, 50, 69, 49, 73, 21, 27, 116, 228, 94, 71, 163, 21, 121, 213, 179, 210, 94, 156, 207, 77, 246, 117, 199, 120, 97, 134, 61, 248, 60, 210, 77, 232, 200, 83, 207, 173, 76, 156, 14, 236, 241, 119, 42, 32, 234, 226, 236, 115, 240, 113, 89, 176, 53, 209, 252, 130, 25, 84};
    const unsigned msg_in_sz = 139;
    unsigned char r[] = {156, 26, 19, 164, 238, 34, 159, 154, 139, 67, 175, 37, 193, 69, 31, 103, 171, 87, 89, 80, 213, 111, 219, 2, 41, 149, 233, 152, 101, 44, 32, 116, 35, 105, 7, 105, 93, 245, 126, 127, 190, 102, 168, 36, 53, 224, 252, 16, 44, 67, 96, 249, 223, 95, 47, 173, 250, 69, 163, 113, 30, 4, 86, 147, 142, 196, 111, 136, 1, 114, 8, 106, 94, 87, 27, 44, 140, 53, 212, 94, 151, 50, 69, 49, 73, 21, 27, 116, 228, 94, 71, 163, 21, 121, 213, 179, 210, 94, 156, 207, 77, 246, 117, 199, 120, 97, 134, 61, 248, 60, 210, 77, 232, 200, 83, 207, 173, 76, 156, 14, 236, 241, 119, 42, 32, 234, 226, 236, 115, 240, 113, 89, 176, 53, 209, 252, 130, 25, 84, 9};
    const unsigned r_sz = 140;
    unsigned char buf[300];
    const unsigned nsym = 1;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test9)
{
    unsigned char msg_in[] = {31, 111, 74, 91, 215, 87, 133, 213, 150, 5, 217, 85, 77, 178, 95, 16, 219, 182, 173, 183, 62, 218, 96, 164, 245, 163, 81, 171, 28, 163, 1, 239, 97, 228, 6, 70, 19, 213, 59, 151, 136, 36, 44, 104, 203, 214, 48, 144, 239, 127, 58, 96, 241, 150, 99, 100, 163, 109, 90, 80, 195, 61, 131, 186, 102, 205, 76, 29, 184, 42, 185, 108, 253, 196, 128};
    const unsigned msg_in_sz = 75;
    unsigned char r[] = {31, 111, 74, 91, 215, 87, 133, 213, 150, 5, 217, 85, 77, 178, 95, 16, 219, 182, 173, 183, 62, 218, 96, 164, 245, 163, 81, 171, 28, 163, 1, 239, 97, 228, 6, 70, 19, 213, 59, 151, 136, 36, 44, 104, 203, 214, 48, 144, 239, 127, 58, 96, 241, 150, 99, 100, 163, 109, 90, 80, 195, 61, 131, 186, 102, 205, 76, 29, 184, 42, 185, 108, 253, 196, 128, 227};
    const unsigned r_sz = 76;
    unsigned char buf[300];
    const unsigned nsym = 1;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test10)
{
    unsigned char msg_in[] = {139, 113, 250, 98, 70, 197, 234, 3, 69, 214, 134, 5, 102, 202, 134, 46, 143, 153, 206, 67, 93, 65, 225, 114, 199, 132, 37, 188, 29, 246, 89, 164, 139, 245, 144, 186, 119, 199, 135, 189, 200, 22, 195, 59, 66, 152, 124, 173, 88, 202, 127, 172, 146, 16, 62, 84, 175, 248, 232, 235, 14, 201, 64, 153, 33, 204, 73, 174, 217, 235, 23, 45, 198, 228, 54, 234, 110, 101, 132, 52, 217, 167, 61, 6, 143, 67, 101, 190, 226, 185, 55, 51, 136, 70, 231, 140, 179, 213, 26, 254, 23, 0, 244, 174, 22, 249, 63, 216, 124, 79, 166, 142, 178, 184, 96, 141, 122, 227, 58, 84, 23, 188, 135, 28, 73, 52, 90, 8, 84, 38, 200, 169, 209, 47, 35, 225, 151, 227, 21, 41, 196, 214, 152, 71, 126, 101, 143, 45, 39, 98, 140, 95, 216, 85, 158, 117, 208, 29, 186, 171, 69, 156, 133, 207, 131, 30};
    const unsigned msg_in_sz = 166;
    unsigned char r[] = {139, 113, 250, 98, 70, 197, 234, 3, 69, 214, 134, 5, 102, 202, 134, 46, 143, 153, 206, 67, 93, 65, 225, 114, 199, 132, 37, 188, 29, 246, 89, 164, 139, 245, 144, 186, 119, 199, 135, 189, 200, 22, 195, 59, 66, 152, 124, 173, 88, 202, 127, 172, 146, 16, 62, 84, 175, 248, 232, 235, 14, 201, 64, 153, 33, 204, 73, 174, 217, 235, 23, 45, 198, 228, 54, 234, 110, 101, 132, 52, 217, 167, 61, 6, 143, 67, 101, 190, 226, 185, 55, 51, 136, 70, 231, 140, 179, 213, 26, 254, 23, 0, 244, 174, 22, 249, 63, 216, 124, 79, 166, 142, 178, 184, 96, 141, 122, 227, 58, 84, 23, 188, 135, 28, 73, 52, 90, 8, 84, 38, 200, 169, 209, 47, 35, 225, 151, 227, 21, 41, 196, 214, 152, 71, 126, 101, 143, 45, 39, 98, 140, 95, 216, 85, 158, 117, 208, 29, 186, 171, 69, 156, 133, 207, 131, 30, 62, 40, 207};
    const unsigned r_sz = 169;
    unsigned char buf[300];
    const unsigned nsym = 3;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test11)
{
    unsigned char msg_in[] = {158, 81, 163, 82, 101, 224, 50, 245, 200, 2, 88, 4, 203, 114, 182, 104, 17, 240, 159, 251, 79, 25, 31, 98, 254, 94, 128, 231, 239, 57, 34, 108, 206, 212, 148, 8, 17, 19, 217, 86, 216, 53, 243, 183, 152, 125, 53, 126, 244, 140, 123, 224, 18, 208, 178, 244, 43, 131, 246, 82, 35, 79, 112, 171, 155, 59, 235, 160, 97, 103, 165};
    const unsigned msg_in_sz = 71;
    unsigned char r[] = {158, 81, 163, 82, 101, 224, 50, 245, 200, 2, 88, 4, 203, 114, 182, 104, 17, 240, 159, 251, 79, 25, 31, 98, 254, 94, 128, 231, 239, 57, 34, 108, 206, 212, 148, 8, 17, 19, 217, 86, 216, 53, 243, 183, 152, 125, 53, 126, 244, 140, 123, 224, 18, 208, 178, 244, 43, 131, 246, 82, 35, 79, 112, 171, 155, 59, 235, 160, 97, 103, 165, 208, 117, 65};
    const unsigned r_sz = 74;
    unsigned char buf[300];
    const unsigned nsym = 3;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test12)
{
    unsigned char msg_in[] = {164, 14, 32, 119, 243, 183, 210, 199, 189, 155, 129, 38, 53, 41, 137, 174, 20, 177, 193, 189, 87, 76, 187, 18, 237, 15, 193, 51, 110, 33, 3, 41, 15, 245, 166, 1, 207, 213, 20, 61, 148, 16, 126, 72, 121, 153, 123, 171, 6, 11, 201, 179, 203, 201, 33, 214, 55, 116, 11, 174, 19, 158, 76, 145, 236, 15, 170, 169, 217, 189, 37, 43};
    const unsigned msg_in_sz = 72;
    unsigned char r[] = {164, 14, 32, 119, 243, 183, 210, 199, 189, 155, 129, 38, 53, 41, 137, 174, 20, 177, 193, 189, 87, 76, 187, 18, 237, 15, 193, 51, 110, 33, 3, 41, 15, 245, 166, 1, 207, 213, 20, 61, 148, 16, 126, 72, 121, 153, 123, 171, 6, 11, 201, 179, 203, 201, 33, 214, 55, 116, 11, 174, 19, 158, 76, 145, 236, 15, 170, 169, 217, 189, 37, 43, 225, 133, 247, 88, 145};
    const unsigned r_sz = 77;
    unsigned char buf[300];
    const unsigned nsym = 5;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test13)
{
    unsigned char msg_in[] = {221, 130, 64, 189, 111, 95, 159, 34, 171, 232, 253, 153, 152, 2, 85, 46, 164, 109, 84, 48, 135, 234, 172, 89, 225, 196, 232, 167, 4, 197, 126, 154, 148, 245, 208, 151, 82, 216, 198, 235, 222, 64, 235, 172, 212, 152, 116, 57, 250, 152, 142, 42, 87, 3, 140, 15, 85, 70, 50, 14, 233};
    const unsigned msg_in_sz = 61;
    unsigned char r[] = {221, 130, 64, 189, 111, 95, 159, 34, 171, 232, 253, 153, 152, 2, 85, 46, 164, 109, 84, 48, 135, 234, 172, 89, 225, 196, 232, 167, 4, 197, 126, 154, 148, 245, 208, 151, 82, 216, 198, 235, 222, 64, 235, 172, 212, 152, 116, 57, 250, 152, 142, 42, 87, 3, 140, 15, 85, 70, 50, 14, 233, 60, 203, 136, 128, 226};
    const unsigned r_sz = 66;
    unsigned char buf[300];
    const unsigned nsym = 5;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test14)
{
    unsigned char msg_in[] = {118, 64, 171, 44, 111, 185, 63, 48, 227, 204, 223, 38, 20, 60, 37, 137, 51, 243};
    const unsigned msg_in_sz = 18;
    unsigned char r[] = {118, 64, 171, 44, 111, 185, 63, 48, 227, 204, 223, 38, 20, 60, 37, 137, 51, 243, 119, 227, 205, 63, 224, 141, 241};
    const unsigned r_sz = 25;
    unsigned char buf[300];
    const unsigned nsym = 7;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test15)
{
    unsigned char msg_in[] = {58, 160, 78, 82, 158, 117, 143, 129, 161, 147, 50, 86, 115, 119, 55, 104, 153, 32, 44, 169, 89, 163, 247, 80, 171, 69, 125, 146, 65, 208, 0, 202, 136, 154, 65, 33, 87, 77, 204, 155, 110};
    const unsigned msg_in_sz = 41;
    unsigned char r[] = {58, 160, 78, 82, 158, 117, 143, 129, 161, 147, 50, 86, 115, 119, 55, 104, 153, 32, 44, 169, 89, 163, 247, 80, 171, 69, 125, 146, 65, 208, 0, 202, 136, 154, 65, 33, 87, 77, 204, 155, 110, 198, 177, 48, 167, 10, 119, 153};
    const unsigned r_sz = 48;
    unsigned char buf[300];
    const unsigned nsym = 7;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test16)
{
    unsigned char msg_in[] = {64, 179, 16, 111, 104, 252, 80, 33, 212, 167, 103, 101, 129, 107, 223, 137, 30, 32, 20, 245, 184, 35, 235, 184, 130, 97, 30, 4, 41, 54, 150, 160, 100, 18, 72, 77, 1, 101, 29, 103, 68, 212, 98, 253, 245, 240};
    const unsigned msg_in_sz = 46;
    unsigned char r[] = {64, 179, 16, 111, 104, 252, 80, 33, 212, 167, 103, 101, 129, 107, 223, 137, 30, 32, 20, 245, 184, 35, 235, 184, 130, 97, 30, 4, 41, 54, 150, 160, 100, 18, 72, 77, 1, 101, 29, 103, 68, 212, 98, 253, 245, 240, 111, 229, 134, 211, 159, 86, 99, 48, 195, 102, 228};
    const unsigned r_sz = 57;
    unsigned char buf[300];
    const unsigned nsym = 11;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test17)
{
    unsigned char msg_in[] = {68, 138, 146, 211, 175, 33, 1, 134, 98, 22, 93, 138, 61, 25, 159, 183, 181, 92, 165, 139, 128, 125, 143, 184, 240, 135, 36, 136, 111, 210, 65, 7, 238, 38, 29, 107, 178, 95, 112, 154, 144, 37, 211, 185, 65, 84, 21, 47, 141, 59, 68, 251, 160, 224, 207, 78, 158, 117, 37, 156, 234, 178, 62, 175, 161, 107, 176, 97, 214, 227, 49, 227, 77, 180, 25, 103, 176, 58, 249, 75, 104, 161, 141, 252, 151, 43, 2, 66, 65, 29, 127, 64, 195, 131, 88, 100, 82, 48, 185, 63, 126, 80, 183, 125, 141, 56, 140, 88, 12, 112, 127, 157, 69, 100, 9, 92, 29, 131, 235, 92, 232, 164, 154, 122, 209, 91, 126, 188, 72, 93, 227, 128, 14, 65, 8, 188, 173, 196, 183, 255, 170, 135, 254, 6, 192, 134, 57, 196, 170, 140, 107, 43, 46, 106, 123, 244, 168, 50, 166, 157, 228, 105, 81, 208, 214, 186, 168, 86, 237, 238, 139, 208, 121, 173, 172, 127, 85, 185, 42, 87, 133, 58, 107, 104, 150, 207, 132, 15, 102, 26, 85, 53, 146, 241, 247, 173, 66, 182, 144, 144, 192, 89, 220};
    const unsigned msg_in_sz = 203;
    unsigned char r[] = {68, 138, 146, 211, 175, 33, 1, 134, 98, 22, 93, 138, 61, 25, 159, 183, 181, 92, 165, 139, 128, 125, 143, 184, 240, 135, 36, 136, 111, 210, 65, 7, 238, 38, 29, 107, 178, 95, 112, 154, 144, 37, 211, 185, 65, 84, 21, 47, 141, 59, 68, 251, 160, 224, 207, 78, 158, 117, 37, 156, 234, 178, 62, 175, 161, 107, 176, 97, 214, 227, 49, 227, 77, 180, 25, 103, 176, 58, 249, 75, 104, 161, 141, 252, 151, 43, 2, 66, 65, 29, 127, 64, 195, 131, 88, 100, 82, 48, 185, 63, 126, 80, 183, 125, 141, 56, 140, 88, 12, 112, 127, 157, 69, 100, 9, 92, 29, 131, 235, 92, 232, 164, 154, 122, 209, 91, 126, 188, 72, 93, 227, 128, 14, 65, 8, 188, 173, 196, 183, 255, 170, 135, 254, 6, 192, 134, 57, 196, 170, 140, 107, 43, 46, 106, 123, 244, 168, 50, 166, 157, 228, 105, 81, 208, 214, 186, 168, 86, 237, 238, 139, 208, 121, 173, 172, 127, 85, 185, 42, 87, 133, 58, 107, 104, 150, 207, 132, 15, 102, 26, 85, 53, 146, 241, 247, 173, 66, 182, 144, 144, 192, 89, 220, 125, 155, 98, 88, 97, 13, 64, 64, 56, 102, 202};
    const unsigned r_sz = 214;
    unsigned char buf[300];
    const unsigned nsym = 11;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test18)
{
    unsigned char msg_in[] = {201, 175, 161, 204, 175, 2, 155, 219, 90, 236, 29, 58, 196, 199, 198, 126, 193, 15, 225, 201, 132, 236, 41, 138, 14, 97, 84, 221, 115, 44, 24, 214, 213, 191, 164, 66, 165, 170, 254, 54, 244, 22, 220, 47, 38, 95, 220, 144, 94, 168, 105, 202, 90, 246, 62, 33, 26, 12, 144, 65, 252, 28, 211};
    const unsigned msg_in_sz = 63;
    unsigned char r[] = {201, 175, 161, 204, 175, 2, 155, 219, 90, 236, 29, 58, 196, 199, 198, 126, 193, 15, 225, 201, 132, 236, 41, 138, 14, 97, 84, 221, 115, 44, 24, 214, 213, 191, 164, 66, 165, 170, 254, 54, 244, 22, 220, 47, 38, 95, 220, 144, 94, 168, 105, 202, 90, 246, 62, 33, 26, 12, 144, 65, 252, 28, 211, 117, 100, 234, 21, 75, 73, 50, 16, 222, 207, 253, 54, 255};
    const unsigned r_sz = 76;
    unsigned char buf[300];
    const unsigned nsym = 13;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}

TEST(RsEncodeMsg, Test19)
{
    unsigned char msg_in[] = {107, 249, 170, 123, 6, 153, 36, 92, 125, 63, 38, 60, 107, 130, 85, 64, 181, 211, 35, 129, 43, 4, 14, 84, 89, 10, 202, 245, 218, 242, 31, 124, 200, 24, 90, 250, 99, 203, 74, 48, 159, 168, 0, 255, 131, 171, 91, 90, 68, 19, 125, 83, 164, 31, 241, 232, 17, 170, 45, 104, 231, 124, 78, 129, 197, 90, 108, 234, 126, 35, 37, 244, 206, 90, 237, 78, 210, 181, 70, 118, 176, 140, 204, 27, 237, 234, 3, 243, 181, 57, 190, 182, 172, 39, 198, 138, 246, 161, 105, 105, 100, 199, 253, 129, 50, 58, 185, 101, 9, 23, 254, 50, 104, 240, 95, 185, 242, 211, 53, 16, 5, 82, 15, 128, 174, 93, 85, 164, 108, 4, 64, 214, 79, 238, 82, 182, 214, 240, 141, 255, 116, 17, 176, 238, 43, 252, 62, 24, 237, 161, 201, 2, 70, 74, 194, 26, 141, 76, 47, 85, 80, 167, 30, 82, 213, 39, 156, 247, 218, 55, 156, 42, 246, 200, 189, 119, 198, 67, 142, 223, 53, 156, 157, 223, 200, 192, 216, 94, 254, 140, 9, 71, 112, 29, 220, 236, 84, 101, 230, 156, 23};
    const unsigned msg_in_sz = 201;
    unsigned char r[] = {107, 249, 170, 123, 6, 153, 36, 92, 125, 63, 38, 60, 107, 130, 85, 64, 181, 211, 35, 129, 43, 4, 14, 84, 89, 10, 202, 245, 218, 242, 31, 124, 200, 24, 90, 250, 99, 203, 74, 48, 159, 168, 0, 255, 131, 171, 91, 90, 68, 19, 125, 83, 164, 31, 241, 232, 17, 170, 45, 104, 231, 124, 78, 129, 197, 90, 108, 234, 126, 35, 37, 244, 206, 90, 237, 78, 210, 181, 70, 118, 176, 140, 204, 27, 237, 234, 3, 243, 181, 57, 190, 182, 172, 39, 198, 138, 246, 161, 105, 105, 100, 199, 253, 129, 50, 58, 185, 101, 9, 23, 254, 50, 104, 240, 95, 185, 242, 211, 53, 16, 5, 82, 15, 128, 174, 93, 85, 164, 108, 4, 64, 214, 79, 238, 82, 182, 214, 240, 141, 255, 116, 17, 176, 238, 43, 252, 62, 24, 237, 161, 201, 2, 70, 74, 194, 26, 141, 76, 47, 85, 80, 167, 30, 82, 213, 39, 156, 247, 218, 55, 156, 42, 246, 200, 189, 119, 198, 67, 142, 223, 53, 156, 157, 223, 200, 192, 216, 94, 254, 140, 9, 71, 112, 29, 220, 236, 84, 101, 230, 156, 23, 48, 51, 213, 25, 221, 112, 168, 235, 11, 201, 192, 12, 195};
    const unsigned r_sz = 214;
    unsigned char buf[300];
    const unsigned nsym = 13;
    redupe_encode_msg(msg_in, msg_in_sz, nsym, buf);
    ASSERT_EQ(msg_in_sz + nsym, r_sz);
    for (unsigned i = 0; i < nsym; ++i)
    {
        ASSERT_EQ(buf[i], r[msg_in_sz + i]);
    }
}
