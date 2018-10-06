/*
    This file is part of Konsole, a terminal emulator for KDE.

    Copyright 2018 by Mariusz Glebocki <mglb@arccos-1.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301  USA.
*/

//
// THIS IS A GENERATED FILE. DO NOT EDIT.
//
// CharacterWidth.cpp file is automatically generated - do not edit it.
// To change anything here, edit CharacterWidth.src.cpp and regenerate the file
// using following command:
//
// uni2characterwidth -U "https://unicode.org/Public/11.0.0/ucd/UnicodeData.txt" -A "https://unicode.org/Public/11.0.0/ucd/EastAsianWidth.txt" -E "https://unicode.org/Public/emoji/11.0/emoji-data.txt" -W "tools/uni2characterwidth/overrides.txt" --ambiguous-width=1 --emoji=presentation -g "code:src/CharacterWidth.src.cpp" "src/CharacterWidth.cpp"
//

#include "CharacterWidth.h"
#include "konsoledebug.h"
#include "konsoleprivate_export.h"


struct Range {
    uint first, last;
};

struct RangeLut {
    int8_t width;
    const Range * const lut;
    int size;
};

enum {
    InvalidWidth = INT8_MIN,
};


static constexpr const int8_t DIRECT_LUT[] = {
     0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};


static constexpr const Range LUT_NONPRINTABLE[] = {
    {0x00d800,0x00dfff},
};

static constexpr const Range LUT_2[] = {
    {0x001100,0x00115f},{0x00231a,0x00231b},{0x002329,0x00232a},{0x0023e9,0x0023ec},{0x0023f0,0x0023f0},{0x0023f3,0x0023f3},{0x0025fd,0x0025fe},{0x002614,0x002615},
    {0x002648,0x002653},{0x00267f,0x00267f},{0x002693,0x002693},{0x0026a1,0x0026a1},{0x0026aa,0x0026ab},{0x0026bd,0x0026be},{0x0026c4,0x0026c5},{0x0026ce,0x0026ce},
    {0x0026d4,0x0026d4},{0x0026ea,0x0026ea},{0x0026f2,0x0026f3},{0x0026f5,0x0026f5},{0x0026fa,0x0026fa},{0x0026fd,0x0026fd},{0x002705,0x002705},{0x00270a,0x00270b},
    {0x002728,0x002728},{0x00274c,0x00274c},{0x00274e,0x00274e},{0x002753,0x002755},{0x002757,0x002757},{0x002795,0x002797},{0x0027b0,0x0027b0},{0x0027bf,0x0027bf},
    {0x002b1b,0x002b1c},{0x002b50,0x002b50},{0x002b55,0x002b55},{0x002e80,0x002e99},{0x002e9b,0x002ef3},{0x002f00,0x002fd5},{0x002ff0,0x002ffb},{0x003000,0x003029},
    {0x00302e,0x00303e},{0x003041,0x003096},{0x00309b,0x0030ff},{0x003105,0x00312f},{0x003131,0x00318e},{0x003190,0x0031ba},{0x0031c0,0x0031e3},{0x0031f0,0x00321e},
    {0x003220,0x003247},{0x003250,0x0032fe},{0x003300,0x004dbf},{0x004e00,0x00a48c},{0x00a490,0x00a4c6},{0x00a960,0x00a97c},{0x00ac00,0x00d7a3},{0x00f900,0x00faff},
    {0x00fe10,0x00fe19},{0x00fe30,0x00fe52},{0x00fe54,0x00fe66},{0x00fe68,0x00fe6b},{0x00ff01,0x00ff60},{0x00ffe0,0x00ffe6},{0x016fe0,0x016fe1},{0x017000,0x0187f1},
    {0x018800,0x018af2},{0x01b000,0x01b11e},{0x01b170,0x01b2fb},{0x01f004,0x01f004},{0x01f0cf,0x01f0cf},{0x01f18e,0x01f18e},{0x01f191,0x01f19a},{0x01f1e6,0x01f202},
    {0x01f210,0x01f23b},{0x01f240,0x01f248},{0x01f250,0x01f251},{0x01f260,0x01f265},{0x01f300,0x01f320},{0x01f32d,0x01f335},{0x01f337,0x01f37c},{0x01f37e,0x01f393},
    {0x01f3a0,0x01f3ca},{0x01f3cf,0x01f3d3},{0x01f3e0,0x01f3f0},{0x01f3f4,0x01f3f4},{0x01f3f8,0x01f43e},{0x01f440,0x01f440},{0x01f442,0x01f4fc},{0x01f4ff,0x01f53d},
    {0x01f54b,0x01f54e},{0x01f550,0x01f567},{0x01f57a,0x01f57a},{0x01f595,0x01f596},{0x01f5a4,0x01f5a4},{0x01f5fb,0x01f64f},{0x01f680,0x01f6c5},{0x01f6cc,0x01f6cc},
    {0x01f6d0,0x01f6d2},{0x01f6eb,0x01f6ec},{0x01f6f4,0x01f6f9},{0x01f910,0x01f93e},{0x01f940,0x01f970},{0x01f973,0x01f976},{0x01f97a,0x01f97a},{0x01f97c,0x01f9a2},
    {0x01f9b0,0x01f9b9},{0x01f9c0,0x01f9c2},{0x01f9d0,0x01f9ff},{0x020000,0x02fffd},{0x030000,0x03fffd},
};

static constexpr const Range LUT_0[] = {
    {0x000300,0x00036f},{0x000483,0x000489},{0x000591,0x0005bd},{0x0005bf,0x0005bf},{0x0005c1,0x0005c2},{0x0005c4,0x0005c5},{0x0005c7,0x0005c7},{0x000600,0x000605},
    {0x000610,0x00061a},{0x00061c,0x00061c},{0x00064b,0x00065f},{0x000670,0x000670},{0x0006d6,0x0006dd},{0x0006df,0x0006e4},{0x0006e7,0x0006e8},{0x0006ea,0x0006ed},
    {0x00070f,0x00070f},{0x000711,0x000711},{0x000730,0x00074a},{0x0007a6,0x0007b0},{0x0007eb,0x0007f3},{0x0007fd,0x0007fd},{0x000816,0x000819},{0x00081b,0x000823},
    {0x000825,0x000827},{0x000829,0x00082d},{0x000859,0x00085b},{0x0008d3,0x000902},{0x00093a,0x00093a},{0x00093c,0x00093c},{0x000941,0x000948},{0x00094d,0x00094d},
    {0x000951,0x000957},{0x000962,0x000963},{0x000981,0x000981},{0x0009bc,0x0009bc},{0x0009c1,0x0009c4},{0x0009cd,0x0009cd},{0x0009e2,0x0009e3},{0x0009fe,0x0009fe},
    {0x000a01,0x000a02},{0x000a3c,0x000a3c},{0x000a41,0x000a42},{0x000a47,0x000a48},{0x000a4b,0x000a4d},{0x000a51,0x000a51},{0x000a70,0x000a71},{0x000a75,0x000a75},
    {0x000a81,0x000a82},{0x000abc,0x000abc},{0x000ac1,0x000ac5},{0x000ac7,0x000ac8},{0x000acd,0x000acd},{0x000ae2,0x000ae3},{0x000afa,0x000aff},{0x000b01,0x000b01},
    {0x000b3c,0x000b3c},{0x000b3f,0x000b3f},{0x000b41,0x000b44},{0x000b4d,0x000b4d},{0x000b56,0x000b56},{0x000b62,0x000b63},{0x000b82,0x000b82},{0x000bc0,0x000bc0},
    {0x000bcd,0x000bcd},{0x000c00,0x000c00},{0x000c04,0x000c04},{0x000c3e,0x000c40},{0x000c46,0x000c48},{0x000c4a,0x000c4d},{0x000c55,0x000c56},{0x000c62,0x000c63},
    {0x000c81,0x000c81},{0x000cbc,0x000cbc},{0x000cbf,0x000cbf},{0x000cc6,0x000cc6},{0x000ccc,0x000ccd},{0x000ce2,0x000ce3},{0x000d00,0x000d01},{0x000d3b,0x000d3c},
    {0x000d41,0x000d44},{0x000d4d,0x000d4d},{0x000d62,0x000d63},{0x000dca,0x000dca},{0x000dd2,0x000dd4},{0x000dd6,0x000dd6},{0x000e31,0x000e31},{0x000e34,0x000e3a},
    {0x000e47,0x000e4e},{0x000eb1,0x000eb1},{0x000eb4,0x000eb9},{0x000ebb,0x000ebc},{0x000ec8,0x000ecd},{0x000f18,0x000f19},{0x000f35,0x000f35},{0x000f37,0x000f37},
    {0x000f39,0x000f39},{0x000f71,0x000f7e},{0x000f80,0x000f84},{0x000f86,0x000f87},{0x000f8d,0x000f97},{0x000f99,0x000fbc},{0x000fc6,0x000fc6},{0x00102d,0x001030},
    {0x001032,0x001037},{0x001039,0x00103a},{0x00103d,0x00103e},{0x001058,0x001059},{0x00105e,0x001060},{0x001071,0x001074},{0x001082,0x001082},{0x001085,0x001086},
    {0x00108d,0x00108d},{0x00109d,0x00109d},{0x001160,0x001160},{0x00135d,0x00135f},{0x001712,0x001714},{0x001732,0x001734},{0x001752,0x001753},{0x001772,0x001773},
    {0x0017b4,0x0017b5},{0x0017b7,0x0017bd},{0x0017c6,0x0017c6},{0x0017c9,0x0017d3},{0x0017dd,0x0017dd},{0x00180b,0x00180e},{0x001885,0x001886},{0x0018a9,0x0018a9},
    {0x001920,0x001922},{0x001927,0x001928},{0x001932,0x001932},{0x001939,0x00193b},{0x001a17,0x001a18},{0x001a1b,0x001a1b},{0x001a56,0x001a56},{0x001a58,0x001a5e},
    {0x001a60,0x001a60},{0x001a62,0x001a62},{0x001a65,0x001a6c},{0x001a73,0x001a7c},{0x001a7f,0x001a7f},{0x001ab0,0x001abe},{0x001b00,0x001b03},{0x001b34,0x001b34},
    {0x001b36,0x001b3a},{0x001b3c,0x001b3c},{0x001b42,0x001b42},{0x001b6b,0x001b73},{0x001b80,0x001b81},{0x001ba2,0x001ba5},{0x001ba8,0x001ba9},{0x001bab,0x001bad},
    {0x001be6,0x001be6},{0x001be8,0x001be9},{0x001bed,0x001bed},{0x001bef,0x001bf1},{0x001c2c,0x001c33},{0x001c36,0x001c37},{0x001cd0,0x001cd2},{0x001cd4,0x001ce0},
    {0x001ce2,0x001ce8},{0x001ced,0x001ced},{0x001cf4,0x001cf4},{0x001cf8,0x001cf9},{0x001dc0,0x001df9},{0x001dfb,0x001dff},{0x00200b,0x00200f},{0x00202a,0x00202e},
    {0x002060,0x002064},{0x002066,0x00206f},{0x0020d0,0x0020f0},{0x002cef,0x002cf1},{0x002d7f,0x002d7f},{0x002de0,0x002dff},{0x00302a,0x00302d},{0x003099,0x00309a},
    {0x00a66f,0x00a672},{0x00a674,0x00a67d},{0x00a69e,0x00a69f},{0x00a6f0,0x00a6f1},{0x00a802,0x00a802},{0x00a806,0x00a806},{0x00a80b,0x00a80b},{0x00a825,0x00a826},
    {0x00a8c4,0x00a8c5},{0x00a8e0,0x00a8f1},{0x00a8ff,0x00a8ff},{0x00a926,0x00a92d},{0x00a947,0x00a951},{0x00a980,0x00a982},{0x00a9b3,0x00a9b3},{0x00a9b6,0x00a9b9},
    {0x00a9bc,0x00a9bc},{0x00a9e5,0x00a9e5},{0x00aa29,0x00aa2e},{0x00aa31,0x00aa32},{0x00aa35,0x00aa36},{0x00aa43,0x00aa43},{0x00aa4c,0x00aa4c},{0x00aa7c,0x00aa7c},
    {0x00aab0,0x00aab0},{0x00aab2,0x00aab4},{0x00aab7,0x00aab8},{0x00aabe,0x00aabf},{0x00aac1,0x00aac1},{0x00aaec,0x00aaed},{0x00aaf6,0x00aaf6},{0x00abe5,0x00abe5},
    {0x00abe8,0x00abe8},{0x00abed,0x00abed},{0x00fb1e,0x00fb1e},{0x00fe00,0x00fe0f},{0x00fe20,0x00fe2f},{0x00feff,0x00feff},{0x00fff9,0x00fffb},{0x0101fd,0x0101fd},
    {0x0102e0,0x0102e0},{0x010376,0x01037a},{0x010a01,0x010a03},{0x010a05,0x010a06},{0x010a0c,0x010a0f},{0x010a38,0x010a3a},{0x010a3f,0x010a3f},{0x010ae5,0x010ae6},
    {0x010d24,0x010d27},{0x010f46,0x010f50},{0x011001,0x011001},{0x011038,0x011046},{0x01107f,0x011081},{0x0110b3,0x0110b6},{0x0110b9,0x0110ba},{0x0110bd,0x0110bd},
    {0x0110cd,0x0110cd},{0x011100,0x011102},{0x011127,0x01112b},{0x01112d,0x011134},{0x011173,0x011173},{0x011180,0x011181},{0x0111b6,0x0111be},{0x0111c9,0x0111cc},
    {0x01122f,0x011231},{0x011234,0x011234},{0x011236,0x011237},{0x01123e,0x01123e},{0x0112df,0x0112df},{0x0112e3,0x0112ea},{0x011300,0x011301},{0x01133b,0x01133c},
    {0x011340,0x011340},{0x011366,0x01136c},{0x011370,0x011374},{0x011438,0x01143f},{0x011442,0x011444},{0x011446,0x011446},{0x01145e,0x01145e},{0x0114b3,0x0114b8},
    {0x0114ba,0x0114ba},{0x0114bf,0x0114c0},{0x0114c2,0x0114c3},{0x0115b2,0x0115b5},{0x0115bc,0x0115bd},{0x0115bf,0x0115c0},{0x0115dc,0x0115dd},{0x011633,0x01163a},
    {0x01163d,0x01163d},{0x01163f,0x011640},{0x0116ab,0x0116ab},{0x0116ad,0x0116ad},{0x0116b0,0x0116b5},{0x0116b7,0x0116b7},{0x01171d,0x01171f},{0x011722,0x011725},
    {0x011727,0x01172b},{0x01182f,0x011837},{0x011839,0x01183a},{0x011a01,0x011a0a},{0x011a33,0x011a38},{0x011a3b,0x011a3e},{0x011a47,0x011a47},{0x011a51,0x011a56},
    {0x011a59,0x011a5b},{0x011a8a,0x011a96},{0x011a98,0x011a99},{0x011c30,0x011c36},{0x011c38,0x011c3d},{0x011c3f,0x011c3f},{0x011c92,0x011ca7},{0x011caa,0x011cb0},
    {0x011cb2,0x011cb3},{0x011cb5,0x011cb6},{0x011d31,0x011d36},{0x011d3a,0x011d3a},{0x011d3c,0x011d3d},{0x011d3f,0x011d45},{0x011d47,0x011d47},{0x011d90,0x011d91},
    {0x011d95,0x011d95},{0x011d97,0x011d97},{0x011ef3,0x011ef4},{0x016af0,0x016af4},{0x016b30,0x016b36},{0x016f8f,0x016f92},{0x01bc9d,0x01bc9e},{0x01bca0,0x01bca3},
    {0x01d167,0x01d169},{0x01d173,0x01d182},{0x01d185,0x01d18b},{0x01d1aa,0x01d1ad},{0x01d242,0x01d244},{0x01da00,0x01da36},{0x01da3b,0x01da6c},{0x01da75,0x01da75},
    {0x01da84,0x01da84},{0x01da9b,0x01da9f},{0x01daa1,0x01daaf},{0x01e000,0x01e006},{0x01e008,0x01e018},{0x01e01b,0x01e021},{0x01e023,0x01e024},{0x01e026,0x01e02a},
    {0x01e8d0,0x01e8d6},{0x01e944,0x01e94a},{0x0e0001,0x0e0001},{0x0e0020,0x0e007f},{0x0e0100,0x0e01ef},
};


static constexpr const RangeLut RANGE_LUT_LIST[] = {
    {-1, LUT_NONPRINTABLE, 1},
    { 2, LUT_2           , 109},
    { 0, LUT_0           , 325},
    { 1, nullptr         , 1},
};
static constexpr const int RANGE_LUT_LIST_SIZE = 4;


int KONSOLEPRIVATE_EXPORT characterWidth(uint ucs4) {
    if(Q_LIKELY(ucs4 < sizeof(DIRECT_LUT))) {
        return DIRECT_LUT[ucs4];
    }

    for(auto rl = RANGE_LUT_LIST; rl->lut != nullptr; ++rl) {
        int l = 0;
        int r = rl->size - 1;
        while(l <= r) {
            const int m = (l + r) / 2;
            if(rl->lut[m].last < ucs4) {
                l = m + 1;
            } else if(rl->lut[m].first > ucs4) {
                r = m - 1;
            } else {
                return rl->width;
            }
        }
    }

    return RANGE_LUT_LIST[RANGE_LUT_LIST_SIZE - 1].width;
}

