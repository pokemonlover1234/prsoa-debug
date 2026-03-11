#ifndef HEADERS_TYPES_COMMON_RANGER_DATA_H_
#define HEADERS_TYPES_COMMON_RANGER_DATA_H_

#include "enums.h"

struct ranger_data {
    struct ranger_core_data core_data;
    // This seems to update the as maps are entered... enteries 0-441 correspond to room_ids 0x0
    // thru 0x1b8.
    undefined4 room_nibble_field_0[441][6]; // This is really 441 sets of 48 nibbles!
    undefined4 room_nibble_field_1[441][4]; // This is really 441 sets of 32 nibbles!
    undefined4 room_nibble_field_2[441][4]; // This is really 441 sets of 32 nibbles!
    undefined4 room_nibble_field_3[441][4]; // This is really 441 sets of 32 nibbles!
    undefined4 field4_0x7c38;               // Related to battle result somehow...
    struct ranger_pokedex pokedex;
    struct ranger_glossary glossary;
    undefined4 field5_0x7f60;
    undefined4 field6_0x7f64;
    undefined4 field7_0x7f68;
    undefined2 field8_0x7f6c;
    undefined2 field9_0x7f6e[63];
    undefined2 field10_0x7fec[10];
    undefined4 field11_0x8000[27];
    undefined2 field12_0x806c[64];
    undefined2 field13_0x80ec[32];
    undefined2 field14_0x812c[32];
    undefined2 field15_0x816c[32];
    undefined4 field16_0x81ac;
    undefined4 field17_0x81b0;
    undefined4 field18_0x81b4;
    undefined4 field19_0x81b8[31];
    undefined4 field20_0x8234[48];
    undefined2 field21_0x82f4[160];
    undefined2 field22_0x8434;
    undefined2 field23_0x8436[32];
    undefined2 field24_0x8476[48];
    undefined2 field25_0x84d6[32];
    undefined2 field26_0x8516[48];
    undefined2 field27_0x8576[32];
    undefined2 field28_0x85b6[48];
    undefined2 field29_0x8616[32];
    undefined2 field30_0x8656[48];
    undefined2 field31_0x86b6[32];
    undefined2 field32_0x86f6[48];
    undefined1 field33_0x8756;
    undefined1 field34_0x8757;
    struct ranger_records records;
    undefined1 field36_0x87dc[7];
    char player_name[7];
    undefined1 field38_0x87ea[22];
    // This is likely the beginning of a sub-struct!
    undefined1 field33832_0x8800[2];
    undefined field33834_0x8802;
    undefined field33835_0x8803;
    struct pokemon_data recruited_pokemon_table[30];
    undefined4 field4_0x2d4[14];
    undefined4 field5_0x30c[14];
    char string_buffer[32];
    struct battle_result_8 battle_result;
    undefined field34361_0x8b65;
    undefined field34362_0x8b66;
    undefined field34363_0x8b67;
    // This is MUCH longer, but I do not know how long yet!
};
ASSERT_SIZE(struct ranger_data, 35688);

#endif
