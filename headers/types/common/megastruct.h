#include "enums.h"
#include "common.h"

struct megastruct {
    undefined4 field0_0x0;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    int field5_0x8;
    void* unk_struct_unsized_0xc; // Pointer to a struct of unknown size.
    int field7_0x10;
    void* unk_struct_size_0x2c_0; // May be a pair of struct pointers.
    void* unk_struct_size_0x2c_1;
    void* unk_struct_size_0x54;
    int field11_0x20;
    // Supposedly a cache of some kind. Unsure what type it uses, but it's 1024 bytes long.
    undefined1 unk_cache_0x400[1024];
    undefined4 field13_0x424[2]; // Likely bigger!
    undefined field14_0x42c[30];
    undefined2 field44_0x44a;
    undefined field45_0x44c[6];
    undefined2 field51_0x452;
    undefined field52_0x454[6];
    undefined2 field58_0x45a;
    undefined field59_0x45c[6];
    undefined2 field65_0x462;
    undefined field66_0x464[960];
    undefined2 unk_table_0[32][4];
    undefined field1027_0x924[768];
    void* unk_struct_size_0x4c;
    void* unk_struct_size_0x4c_1;
    void* unk_struct_size_0x80;
    void* unk_struct_size_0x80_1;
    undefined field1799_0xc34;
    undefined field1800_0xc35;
    undefined field1801_0xc36;
    undefined field1802_0xc37;
    void* unk_struct_unsized_0xc38; // Pointer to a struct of unknown size.
    undefined field1804_0xc3c[12];
    void* unk_struct_unsized_0xc48; // Pointer to a struct of unknown size.
    undefined field1817_0xc4c[12];
    void* unk_struct_unsized_0xc58; // Pointer to a struct of unknown size.
    undefined field1830_0xc5c[12];
    void* unk_struct_unsized_0xc68; // Pointer to a struct of unknown size.
    undefined field1843_0xc6c[12];
    void* unk_struct_unsized_0xc78; // Pointer to a struct of unknown size.
    undefined field1856_0xc7c[12];
    void* unk_struct_unsized_0xc88; // Pointer to a struct of unknown size.
    undefined field1869_0xc8c[1960];
    void* unk_struct_size_0x8;
    void* unk_struct_size_0x10;
    struct battle_combatants* battle_combatants_ptr;
    undefined4 field3832_0x1440;
    undefined4* unk_struct_size_0x84;
    int32_t unk_int_0x1234;
    undefined4 field3835_0x144c;
    undefined4 field3836_0x1450;
    undefined4 field3837_0x1454;
    undefined4 field3838_0x1458;
    undefined4 field3839_0x145c;
    undefined4 field3840_0x1460;
    undefined4 field3841_0x1464;
    undefined4 field3842_0x1468;
    undefined field3843_0x146c[32];
    void* unk_struct_size_0x1ac;
    void* unk_struct_size_0x158;
    void* unk_struct_size_0x44;
    void* unk_struct_size_0x40;
    void* unk_struct_size_0x1881C;
    struct mission_quest_data* mission_quest_data_ptr;
    struct ranger_data_old* ranger_data_ptr;
    undefined4 field3882_0x14a8;
    void* font_data_ptr_size_0x1c;
    void* unk_struct_size_0x14;
    struct settings_and_variables* settings_vars_ptr;
    void* unk_struct_size_0x28;
    void* unk_struct_size_0x1c;
    void* unk_struct_size_0x1c_1;
    int16_t* unk_struct_size_0xc7c;
    int16_t* unk_struct_size_0xc7c_1;
    struct field_data_bin* field_data_bin;
    void* field3892_0x14d0[32];
    undefined field3893_0x1550[128];
    undefined4 field4021_0x15d0;
    undefined4 field4022_0x15d4;
    void* unk_struct_size_0x58;
    undefined field4024_0x15dc;
    undefined field4025_0x15dd;
    undefined field4026_0x15de;
    undefined field4027_0x15df;
    undefined4 field4028_0x15e0;
};

ASSERT_SIZE(struct megastruct, 5604);