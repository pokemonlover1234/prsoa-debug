// Shared types used throughout the game

#ifndef HEADERS_TYPES_COMMON_H_
#define HEADERS_TYPES_COMMON_H_

#include "util.h"
#include "enums.h"

// Parameters used by the NitroSDK to read the ROM.
struct start_module_params {
    void* autoload_list;
    void* autoload_list_end;
    void* autoload_start;
    void* static_bss_start;
    void* static_bss_end;
    uint32_t compressed_static_end;
    uint32_t version_id;
    uint32_t nitrocode_be;
    uint32_t nitrocode_le;
};

// Individual entry in the quest table
struct quest_table_entry {
    int8_t is_available : 1; // bit 0
    int8_t is_cleared : 1;   // bit 1
    int8_t unk_bit_2 : 1;
    int8_t unk_bit_3 : 1;
    int8_t name_visible : 1; // bit 4
    int8_t unk_bit_5 : 1;
    int8_t unk_bit_6 : 1;
    int8_t unk_bit_7 : 1;
};

ASSERT_SIZE(struct quest_table_entry, 1);

// Tracks relevant mission and quest data
struct quest_body {
    bool has_active_mission;
    bool has_active_quest;
    int8_t active_mission_id; // Eventually make this an enum
    int8_t active_quest_id;   // Eventually make this an enum
    int8_t num_missions_cleared;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    int chapter_num;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    undefined field13_0x10;
    undefined field14_0x11;
    undefined field15_0x12;
    undefined field16_0x13;
    struct quest_table_entry quest_table[62]; // bitfield by quest id
    undefined field_0x52;
    undefined field_0x53;
};
ASSERT_SIZE(struct quest_body, 84);

struct quest_footer {
    undefined* unk_pointer_1;
    undefined* unk_pointer_2;
};
ASSERT_SIZE(struct quest_footer, 8);

// Tracks relevant mission and quest data
struct quest {
    struct quest_body body;
    struct quest_footer footer;
};

ASSERT_SIZE(struct quest, 92);

// Contains critical player data, such as their gender, HP, position, and exp.
struct ranger_core_data {
    bool ranger_is_female;
    int8_t current_hp;
    int8_t max_hp;
    int8_t styler_rank : 4;
    enum styler_type styler_type : 4;
    int32_t partner_assist_gauge; // Maximum varies by partner.
    undefined field8_0x8;
    int8_t partner_pokemon_moods[17]; // 0x0 normal, 0x1 happy, 0x2 very happy?
    struct room_id_16 room;
    int16_t player_coordinates[2];
    undefined field28_0x20;
    undefined field29_0x21;
    undefined field30_0x22;
    undefined field31_0x23;
    int16_t player_face_direction;
    undefined field34_0x26; // Seems to mess with collision and following pokemon pathing when poked...
    undefined field35_0x27;
    int32_t current_styler_exp;
    int32_t current_player_exp;
};

ASSERT_SIZE(struct ranger_core_data, 48);

// Data type for befriended pokemon
struct pokemon_data {
    struct form_id_16 form;        // NOT natdex number!
    struct room_id_16 room_caught; // Used to determine if a pokemon was already caught here.
    int16_t room_caught_index;     // Index of this pokemon in room_caught's available pokemon.
    undefined field5_0x6; // Seems to be padding
    undefined field6_0x7;
    // Bitfield of data that affects whether the pokemon exists, can use poke-assists, can be released, etc.
    // Requires more research to fully understand... 
    undefined4 slot_status_fields;
    // These last 12 bytes change rapidly, and are likely related to pokemon motion.
    int x_coordinate;
    int y_coordinate;
    int16_t face_angle;
    undefined field21_0x16; // Not padding. When poked, these do strange things to the pokemon's pathing...
    undefined field22_0x17;
};

ASSERT_SIZE(struct pokemon_data, 24);

// Statistics on seend and befriended pokemon.
struct ranger_pokedex {
    enum species_status unk_0001_status : 2; // Bulbasaur
    enum species_status unk_0002_status : 2; // Ivysaur
    enum species_status unk_0003_status : 2; // Venusaur
    enum species_status charmander_status : 2;
    enum species_status charmeleon_status : 2;
    enum species_status charizard_status : 2;
    enum species_status squirtle_status : 2;
    enum species_status wartortle_status : 2;
    enum species_status blastoise_status : 2;
    enum species_status unk_0010_status : 2; // Caterpie
    enum species_status unk_0011_status : 2; // Metapod
    enum species_status unk_0012_status : 2; // Butterfree
    enum species_status weedle_status : 2;
    enum species_status unk_0014_status : 2; // Kakuna
    enum species_status beedrill_status : 2;
    enum species_status unk_0016_status : 2; // Pidgey
    enum species_status unk_0017_status : 2; // Pidgeotto
    enum species_status unk_0018_status : 2; // Pidgeot
    enum species_status rattata_status : 2;
    enum species_status raticate_status : 2;
    enum species_status spearow_status : 2;
    enum species_status fearow_status : 2;
    enum species_status unk_0023_status : 2; // Ekans
    enum species_status unk_0024_status : 2; // Arbok
    enum species_status pikachu_status : 2;
    enum species_status raichu_status : 2;
    enum species_status sandshrew_status : 2;
    enum species_status sandslash_status : 2;
    enum species_status unk_0029_status : 2; // Nidoran_f
    enum species_status unk_0030_status : 2; // Nidorina
    enum species_status unk_0031_status : 2; // Nidoqueen
    enum species_status unk_0032_status : 2; // Nidoran_m
    enum species_status unk_0033_status : 2; // Nidorino
    enum species_status unk_0034_status : 2; // Nidoking
    enum species_status unk_0035_status : 2; // Clefairy
    enum species_status unk_0036_status : 2; // Clefable
    enum species_status vulpix_status : 2;
    enum species_status ninetales_status : 2;
    enum species_status jigglypuff_status : 2;
    enum species_status wigglytuff_status : 2;
    enum species_status zubat_status : 2;
    enum species_status golbat_status : 2;
    enum species_status oddish_status : 2;
    enum species_status gloom_status : 2;
    enum species_status vileplume_status : 2;
    enum species_status unk_0046_status : 2; // Paras
    enum species_status unk_0047_status : 2; // Parasect
    enum species_status unk_0048_status : 2; // Venonat
    enum species_status unk_0049_status : 2; // Venomoth
    enum species_status unk_0050_status : 2; // Diglett
    enum species_status unk_0051_status : 2; // Dugtrio
    enum species_status unk_0052_status : 2; // Meowth
    enum species_status unk_0053_status : 2; // Persian
    enum species_status unk_0054_status : 2; // Psyduck
    enum species_status unk_0055_status : 2; // Golduck
    enum species_status mankey_status : 2;
    enum species_status primeape_status : 2;
    enum species_status growlithe_status : 2;
    enum species_status arcanine_status : 2;
    enum species_status unk_0060_status : 2; // Poliwag
    enum species_status unk_0061_status : 2; // Poliwhirl
    enum species_status unk_0062_status : 2; // Poliwrath
    enum species_status abra_status : 2;
    enum species_status unk_0064_status : 2; // Kadabra
    enum species_status alakazam_status : 2;
    enum species_status machop_status : 2;
    enum species_status machoke_status : 2;
    enum species_status machamp_status : 2;
    enum species_status unk_0069_status : 2; // Bellsprout
    enum species_status unk_0070_status : 2; // Weepinbell
    enum species_status victreebel_status : 2;
    enum species_status unk_0072_status : 2; // Tentacool
    enum species_status tentacruel_status : 2;
    enum species_status geodude_status : 2;
    enum species_status graveler_status : 2;
    enum species_status golem_status : 2;
    enum species_status ponyta_status : 2;
    enum species_status rapidash_status : 2;
    enum species_status unk_0079_status : 2; // Slowpoke
    enum species_status unk_0080_status : 2; // Slowbro
    enum species_status magnemite_status : 2;
    enum species_status magneton_status : 2;
    enum species_status unk_0083_status : 2; // Farfetchd
    enum species_status doduo_status : 2;
    enum species_status dodrio_status : 2;
    enum species_status unk_0086_status : 2; // Seel
    enum species_status unk_0087_status : 2; // Dewgong
    enum species_status unk_0088_status : 2; // Grimer
    enum species_status muk_status : 2;
    enum species_status unk_0090_status : 2; // Shellder
    enum species_status unk_0091_status : 2; // Cloyster
    enum species_status gastly_status : 2;
    enum species_status haunter_status : 2;
    enum species_status gengar_status : 2;
    enum species_status unk_0095_status : 2; // Onix
    enum species_status drowzee_status : 2;
    enum species_status hypno_status : 2;
    enum species_status unk_0098_status : 2; // Krabby
    enum species_status unk_0099_status : 2; // Kingler
    enum species_status voltorb_status : 2;
    enum species_status electrode_status : 2;
    enum species_status unk_0102_status : 2; // Exeggcute
    enum species_status unk_0103_status : 2; // Exeggutor
    enum species_status unk_0104_status : 2; // Cubone
    enum species_status unk_0105_status : 2; // Marowak
    enum species_status unk_0106_status : 2; // Hitmonlee
    enum species_status unk_0107_status : 2; // Hitmonchan
    enum species_status unk_0108_status : 2; // Lickitung
    enum species_status koffing_status : 2;
    enum species_status weezing_status : 2;
    enum species_status rhyhorn_status : 2;
    enum species_status rhydon_status : 2;
    enum species_status unk_0113_status : 2; // Chansey
    enum species_status unk_0114_status : 2; // Tangela
    enum species_status kangaskhan_status : 2;
    enum species_status horsea_status : 2;
    enum species_status seadra_status : 2;
    enum species_status unk_0118_status : 2; // Goldeen
    enum species_status unk_0119_status : 2; // Seaking
    enum species_status staryu_status : 2;
    enum species_status starmie_status : 2;
    enum species_status mr_mime_status : 2;
    enum species_status scyther_status : 2;
    enum species_status jynx_status : 2;
    enum species_status electabuzz_status : 2;
    enum species_status magmar_status : 2;
    enum species_status pinsir_status : 2;
    enum species_status tauros_status : 2;
    enum species_status unk_0129_status : 2; // Magikarp
    enum species_status unk_0130_status : 2; // Gyarados
    enum species_status unk_0131_status : 2; // Lapras
    enum species_status unk_0132_status : 2; // Ditto
    enum species_status eevee_status : 2;
    enum species_status vaporeon_status : 2;
    enum species_status jolteon_status : 2;
    enum species_status flareon_status : 2;
    enum species_status unk_0137_status : 2; // Porygon
    enum species_status omanyte_status : 2;
    enum species_status omastar_status : 2;
    enum species_status unk_0140_status : 2; // Kabuto
    enum species_status unk_0141_status : 2; // Kabutops
    enum species_status aerodactyl_status : 2;
    enum species_status unk_0143_status : 2; // Snorlax
    enum species_status unk_0144_status : 2; // Articuno
    enum species_status unk_0145_status : 2; // Zapdos
    enum species_status unk_0146_status : 2; // Moltres
    enum species_status dratini_status : 2;
    enum species_status dragonair_status : 2;
    enum species_status unk_0149_status : 2; // Dragonite
    enum species_status unk_0150_status : 2; // Mewtwo
    enum species_status unk_0151_status : 2; // Mew
    enum species_status unk_0152_status : 2; // Chikorita
    enum species_status unk_0153_status : 2; // Bayleef
    enum species_status unk_0154_status : 2; // Meganium
    enum species_status unk_0155_status : 2; // Cyndaquil
    enum species_status unk_0156_status : 2; // Quilava
    enum species_status unk_0157_status : 2; // Typhlosion
    enum species_status unk_0158_status : 2; // Totodile
    enum species_status unk_0159_status : 2; // Croconaw
    enum species_status unk_0160_status : 2; // Feraligatr
    enum species_status unk_0161_status : 2; // Sentret
    enum species_status unk_0162_status : 2; // Furret
    enum species_status unk_0163_status : 2; // Hoothoot
    enum species_status unk_0164_status : 2; // Noctowl
    enum species_status unk_0165_status : 2; // Ledyba
    enum species_status unk_0166_status : 2; // Ledian
    enum species_status spinarak_status : 2;
    enum species_status ariados_status : 2;
    enum species_status crobat_status : 2;
    enum species_status chinchou_status : 2;
    enum species_status lanturn_status : 2;
    enum species_status pichu_status : 2;
    enum species_status unk_0173_status : 2; // Cleffa
    enum species_status unk_0174_status : 2; // Igglybuff
    enum species_status unk_0175_status : 2; // Togepi
    enum species_status unk_0176_status : 2; // Togetic
    enum species_status unk_0177_status : 2; // Natu
    enum species_status unk_0178_status : 2; // Xatu
    enum species_status mareep_status : 2;
    enum species_status flaaffy_status : 2;
    enum species_status ampharos_status : 2;
    enum species_status bellossom_status : 2;
    enum species_status unk_0183_status : 2; // Marill
    enum species_status unk_0184_status : 2; // Azumarill
    enum species_status sudowoodo_status : 2;
    enum species_status unk_0186_status : 2; // Politoed
    enum species_status unk_0187_status : 2; // Hoppip
    enum species_status unk_0188_status : 2; // Skiploom
    enum species_status unk_0189_status : 2; // Jumpluff
    enum species_status aipom_status : 2;
    enum species_status unk_0191_status : 2; // Sunkern
    enum species_status unk_0192_status : 2; // Sunflora
    enum species_status yanma_status : 2;
    enum species_status unk_0194_status : 2; // Wooper
    enum species_status unk_0195_status : 2; // Quagsire
    enum species_status espeon_status : 2;
    enum species_status umbreon_status : 2;
    enum species_status murkrow_status : 2;
    enum species_status unk_0199_status : 2; // Slowking
    enum species_status misdreavus_status : 2;
    enum species_status unk_0201_status : 2; // Unown
    enum species_status unk_0202_status : 2; // Wobbuffet
    enum species_status girafarig_status : 2;
    enum species_status pineco_status : 2;
    enum species_status forretress_status : 2;
    enum species_status unk_0206_status : 2; // Dunsparce
    enum species_status gligar_status : 2;
    enum species_status unk_0208_status : 2; // Steelix
    enum species_status unk_0209_status : 2; // Snubbull
    enum species_status unk_0210_status : 2; // Granbull
    enum species_status qwilfish_status : 2;
    enum species_status scizor_status : 2;
    enum species_status unk_0213_status : 2; // Shuckle
    enum species_status unk_0214_status : 2; // Heracross
    enum species_status sneasel_status : 2;
    enum species_status unk_0216_status : 2; // Teddiursa
    enum species_status unk_0217_status : 2; // Ursaring
    enum species_status slugma_status : 2;
    enum species_status magcargo_status : 2;
    enum species_status swinub_status : 2;
    enum species_status piloswine_status : 2;
    enum species_status corsola_status : 2;
    enum species_status unk_0223_status : 2; // Remoraid
    enum species_status unk_0224_status : 2; // Octillery
    enum species_status delibird_status : 2;
    enum species_status mantine_status : 2;
    enum species_status skarmory_status : 2;
    enum species_status houndour_status : 2;
    enum species_status houndoom_status : 2;
    enum species_status kingdra_status : 2;
    enum species_status unk_0231_status : 2; // Phanpy
    enum species_status unk_0232_status : 2; // Donphan
    enum species_status unk_0233_status : 2; // Porygon2
    enum species_status unk_0234_status : 2; // Stantler
    enum species_status unk_0235_status : 2; // Smeargle
    enum species_status tyrogue_status : 2;
    enum species_status unk_0237_status : 2; // Hitmontop
    enum species_status unk_0238_status : 2; // Smoochum
    enum species_status elekid_status : 2;
    enum species_status magby_status : 2;
    enum species_status miltank_status : 2;
    enum species_status unk_0242_status : 2; // Blissey
    enum species_status unk_0243_status : 2; // Raikou
    enum species_status unk_0244_status : 2; // Entei
    enum species_status unk_0245_status : 2; // Suicune
    enum species_status larvitar_status : 2;
    enum species_status pupitar_status : 2;
    enum species_status tyranitar_status : 2;
    enum species_status unk_0249_status : 2; // Lugia
    enum species_status unk_0250_status : 2; // Ho-Oh
    enum species_status celebi_status : 2;
    enum species_status unk_0252_status : 2; // Treecko
    enum species_status unk_0253_status : 2; // Grovyle
    enum species_status sceptile_status : 2;
    enum species_status unk_0255_status : 2; // Torchic
    enum species_status unk_0256_status : 2; // Combusken
    enum species_status blaziken_status : 2;
    enum species_status unk_0258_status : 2; // Mudkip
    enum species_status unk_0259_status : 2; // Marshtomp
    enum species_status unk_0260_status : 2; // Swampert
    enum species_status unk_0261_status : 2; // Poochyena
    enum species_status unk_0262_status : 2; // Mightyena
    enum species_status unk_0263_status : 2; // Zigzagoon
    enum species_status unk_0264_status : 2; // Linoone
    enum species_status unk_0265_status : 2; // Wurmple
    enum species_status unk_0266_status : 2; // Silcoon
    enum species_status unk_0267_status : 2; // Beautifly
    enum species_status unk_0268_status : 2; // Cascoon
    enum species_status unk_0269_status : 2; // Dustox
    enum species_status unk_0270_status : 2; // Lotad
    enum species_status unk_0271_status : 2; // Lombre
    enum species_status unk_0272_status : 2; // Ludicolo
    enum species_status seedot_status : 2;
    enum species_status nuzleaf_status : 2;
    enum species_status shiftry_status : 2;
    enum species_status taillow_status : 2;
    enum species_status swellow_status : 2;
    enum species_status wingull_status : 2;
    enum species_status pelipper_status : 2;
    enum species_status ralts_status : 2;
    enum species_status kirlia_status : 2;
    enum species_status gardevoir_status : 2;
    enum species_status unk_0283_status : 2; // Surskit
    enum species_status unk_0284_status : 2; // Masquerain
    enum species_status unk_0285_status : 2; // Shroomish
    enum species_status unk_0286_status : 2; // Breloom
    enum species_status slakoth_status : 2;
    enum species_status unk_0288_status : 2; // Vigoroth
    enum species_status unk_0289_status : 2; // Slaking
    enum species_status unk_0290_status : 2; // Nincada
    enum species_status ninjask_status : 2;
    enum species_status unk_0292_status : 2; // Shedinja
    enum species_status unk_0293_status : 2; // Whismur
    enum species_status unk_0294_status : 2; // Loudred
    enum species_status unk_0295_status : 2; // Exploud
    enum species_status makuhita_status : 2;
    enum species_status hariyama_status : 2;
    enum species_status unk_0298_status : 2; // Azurill
    enum species_status nosepass_status : 2;
    enum species_status unk_0300_status : 2; // Skitty
    enum species_status unk_0301_status : 2; // Delcatty
    enum species_status sableye_status : 2;
    enum species_status mawile_status : 2;
    enum species_status aron_status : 2;
    enum species_status lairon_status : 2;
    enum species_status aggron_status : 2;
    enum species_status unk_0307_status : 2; // Meditite
    enum species_status unk_0308_status : 2; // Medicham
    enum species_status unk_0309_status : 2; // Electrike
    enum species_status unk_0310_status : 2; // Manectric
    enum species_status unk_0311_status : 2; // Plusle
    enum species_status unk_0312_status : 2; // Minun
    enum species_status unk_0313_status : 2; // Volbeat
    enum species_status unk_0314_status : 2; // Illumise
    enum species_status roselia_status : 2;
    enum species_status unk_0316_status : 2; // Gulpin
    enum species_status unk_0317_status : 2; // Swalot
    enum species_status unk_0318_status : 2; // Carvanha
    enum species_status sharpedo_status : 2;
    enum species_status wailmer_status : 2;
    enum species_status wailord_status : 2;
    enum species_status numel_status : 2;
    enum species_status camerupt_status : 2;
    enum species_status torkoal_status : 2;
    enum species_status unk_0325_status : 2; // Spoink
    enum species_status unk_0326_status : 2; // Grumpig
    enum species_status unk_0327_status : 2; // Spinda
    enum species_status unk_0328_status : 2; // Trapinch
    enum species_status unk_0329_status : 2; // Vibrava
    enum species_status flygon_status : 2;
    enum species_status cacnea_status : 2;
    enum species_status cacturne_status : 2;
    enum species_status unk_0333_status : 2; // Swablu
    enum species_status altaria_status : 2;
    enum species_status unk_0335_status : 2; // Zangoose
    enum species_status unk_0336_status : 2; // Seviper
    enum species_status unk_0337_status : 2; // Lunatone
    enum species_status unk_0338_status : 2; // Solrock
    enum species_status unk_0339_status : 2; // Barboach
    enum species_status unk_0340_status : 2; // Whiscash
    enum species_status unk_0341_status : 2; // Corphish
    enum species_status unk_0342_status : 2; // Crawdaunt
    enum species_status unk_0343_status : 2; // Baltoy
    enum species_status claydol_status : 2;
    enum species_status unk_0345_status : 2; // Lileep
    enum species_status unk_0346_status : 2; // Cradily
    enum species_status unk_0347_status : 2; // Anorith
    enum species_status unk_0348_status : 2; // Armaldo
    enum species_status unk_0349_status : 2; // Feebas
    enum species_status unk_0350_status : 2; // Milotic
    enum species_status unk_0351_status : 2; // Castform
    enum species_status unk_0352_status : 2; // Kecleon
    enum species_status shuppet_status : 2;
    enum species_status banette_status : 2;
    enum species_status duskull_status : 2;
    enum species_status dusclops_status : 2;
    enum species_status unk_0357_status : 2; // Tropius
    enum species_status unk_0358_status : 2; // Chimecho
    enum species_status absol_status : 2;
    enum species_status unk_0360_status : 2; // Wynaut
    enum species_status snorunt_status : 2;
    enum species_status glalie_status : 2;
    enum species_status spheal_status : 2;
    enum species_status sealeo_status : 2;
    enum species_status walrein_status : 2;
    enum species_status unk_0366_status : 2; // Clamperl
    enum species_status huntail_status : 2;
    enum species_status gorebyss_status : 2;
    enum species_status unk_0369_status : 2; // Relicanth
    enum species_status unk_0370_status : 2; // Luvdisc
    enum species_status bagon_status : 2;
    enum species_status shelgon_status : 2;
    enum species_status salamence_status : 2;
    enum species_status unk_0374_status : 2; // Beldum
    enum species_status unk_0375_status : 2; // Metang
    enum species_status unk_0376_status : 2; // Metagross
    enum species_status regirock_status : 2;
    enum species_status regice_status : 2;
    enum species_status registeel_status : 2;
    enum species_status unk_0380_status : 2; // Latias
    enum species_status unk_0381_status : 2; // Latios
    enum species_status unk_0382_status : 2; // Kyogre
    enum species_status unk_0383_status : 2; // Groudon
    enum species_status unk_0384_status : 2; // Rayquaza
    enum species_status unk_0385_status : 2; // Jirachi
    enum species_status unk_0386_status : 2; // Deoxys
    enum species_status turtwig_status : 2;
    enum species_status grotle_status : 2;
    enum species_status torterra_status : 2;
    enum species_status chimchar_status : 2;
    enum species_status monferno_status : 2;
    enum species_status infernape_status : 2;
    enum species_status piplup_status : 2;
    enum species_status prinplup_status : 2;
    enum species_status empoleon_status : 2;
    enum species_status starly_status : 2;
    enum species_status staravia_status : 2;
    enum species_status staraptor_status : 2;
    enum species_status bidoof_status : 2;
    enum species_status bibarel_status : 2;
    enum species_status kricketot_status : 2;
    enum species_status kricketune_status : 2;
    enum species_status shinx_status : 2;
    enum species_status luxio_status : 2;
    enum species_status luxray_status : 2;
    enum species_status budew_status : 2;
    enum species_status roserade_status : 2;
    enum species_status cranidos_status : 2;
    enum species_status rampardos_status : 2;
    enum species_status shieldon_status : 2;
    enum species_status bastiodon_status : 2;
    enum species_status unk_0412_status : 2; // Burmy
    enum species_status unk_0413_status : 2; // Wormadam
    enum species_status mothim_status : 2;
    enum species_status combee_status : 2;
    enum species_status vespiquen_status : 2;
    enum species_status pachirisu_status : 2;
    enum species_status buizel_status : 2;
    enum species_status floatzel_status : 2;
    enum species_status cherubi_status : 2;
    enum species_status cherrim_status : 2;
    enum species_status shellos_status : 2;
    enum species_status gastrodon_status : 2;
    enum species_status ambipom_status : 2;
    enum species_status drifloon_status : 2;
    enum species_status drifblim_status : 2;
    enum species_status buneary_status : 2;
    enum species_status lopunny_status : 2;
    enum species_status mismagius_status : 2;
    enum species_status honchkrow_status : 2;
    enum species_status glameow_status : 2;
    enum species_status purugly_status : 2;
    enum species_status chingling_status : 2;
    enum species_status stunky_status : 2;
    enum species_status skuntank_status : 2;
    enum species_status bronzor_status : 2;
    enum species_status bronzong_status : 2;
    enum species_status bonsly_status : 2;
    enum species_status mime_jr_status : 2;
    enum species_status happiny_status : 2;
    enum species_status chatot_status : 2;
    enum species_status spiritomb_status : 2;
    enum species_status gible_status : 2;
    enum species_status gabite_status : 2;
    enum species_status garchomp_status : 2;
    enum species_status munchlax_status : 2;
    enum species_status riolu_status : 2;
    enum species_status lucario_status : 2;
    enum species_status hippopotas_status : 2;
    enum species_status hippowdon_status : 2;
    enum species_status skorupi_status : 2;
    enum species_status drapion_status : 2;
    enum species_status croagunk_status : 2;
    enum species_status toxicroak_status : 2;
    enum species_status carnivine_status : 2;
    enum species_status finneon_status : 2;
    enum species_status lumineon_status : 2;
    enum species_status mantyke_status : 2;
    enum species_status snover_status : 2;
    enum species_status abomasnow_status : 2;
    enum species_status weavile_status : 2;
    enum species_status magnezone_status : 2;
    enum species_status lickilicky_status : 2;
    enum species_status rhyperior_status : 2;
    enum species_status tangrowth_status : 2;
    enum species_status electivire_status : 2;
    enum species_status magmortar_status : 2;
    enum species_status togekiss_status : 2;
    enum species_status yanmega_status : 2;
    enum species_status leafeon_status : 2;
    enum species_status glaceon_status : 2;
    enum species_status gliscor_status : 2;
    enum species_status mamoswine_status : 2;
    enum species_status porygon_z_status : 2;
    enum species_status gallade_status : 2;
    enum species_status probopass_status : 2;
    enum species_status dusknoir_status : 2;
    enum species_status froslass_status : 2;
    enum species_status unk_0479_status : 2; // Rotom
    enum species_status unk_0480_status : 2; // Uxie
    enum species_status unk_0481_status : 2; // Mesprit
    enum species_status unk_0482_status : 2; // Azelf
    enum species_status dialga_status : 2;
    enum species_status palkia_status : 2;
    enum species_status heatran_status : 2;
    enum species_status regigigas_status : 2;
    enum species_status unk_0487_status : 2; // Giratina
    enum species_status cresselia_status : 2;
    enum species_status unk_0489_status : 2; // Phione
    enum species_status unk_0490_status : 2; // Manaphy
    enum species_status darkrai_status : 2;
    enum species_status shaymin_status : 2;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    int8_t lifetime_caught_table[492]; // one byte per species
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    enum capture_rank unk_0001_rank : 2; // Bulbasaur
    enum capture_rank unk_0002_rank : 2; // Ivysaur
    enum capture_rank unk_0003_rank : 2; // Venusaur
    enum capture_rank charmander_rank : 2;
    enum capture_rank charmeleon_rank : 2;
    enum capture_rank charizard_rank : 2;
    enum capture_rank squirtle_rank : 2;
    enum capture_rank wartortle_rank : 2;
    enum capture_rank blastoise_rank : 2;
    enum capture_rank unk_0010_rank : 2; // Caterpie
    enum capture_rank unk_0011_rank : 2; // Metapod
    enum capture_rank unk_0012_rank : 2; // Butterfree
    enum capture_rank weedle_rank : 2;
    enum capture_rank unk_0014_rank : 2; // Kakuna
    enum capture_rank beedrill_rank : 2;
    enum capture_rank unk_0016_rank : 2; // Pidgey
    enum capture_rank unk_0017_rank : 2; // Pidgeotto
    enum capture_rank unk_0018_rank : 2; // Pidgeot
    enum capture_rank rattata_rank : 2;
    enum capture_rank raticate_rank : 2;
    enum capture_rank spearow_rank : 2;
    enum capture_rank fearow_rank : 2;
    enum capture_rank unk_0023_rank : 2; // Ekans
    enum capture_rank unk_0024_rank : 2; // Arbok
    enum capture_rank pikachu_rank : 2;
    enum capture_rank raichu_rank : 2;
    enum capture_rank sandshrew_rank : 2;
    enum capture_rank sandslash_rank : 2;
    enum capture_rank unk_0029_rank : 2; // Nidoran_f
    enum capture_rank unk_0030_rank : 2; // Nidorina
    enum capture_rank unk_0031_rank : 2; // Nidoqueen
    enum capture_rank unk_0032_rank : 2; // Nidoran_m
    enum capture_rank unk_0033_rank : 2; // Nidorino
    enum capture_rank unk_0034_rank : 2; // Nidoking
    enum capture_rank unk_0035_rank : 2; // Clefairy
    enum capture_rank unk_0036_rank : 2; // Clefable
    enum capture_rank vulpix_rank : 2;
    enum capture_rank ninetales_rank : 2;
    enum capture_rank jigglypuff_rank : 2;
    enum capture_rank wigglytuff_rank : 2;
    enum capture_rank zubat_rank : 2;
    enum capture_rank golbat_rank : 2;
    enum capture_rank oddish_rank : 2;
    enum capture_rank gloom_rank : 2;
    enum capture_rank vileplume_rank : 2;
    enum capture_rank unk_0046_rank : 2; // Paras
    enum capture_rank unk_0047_rank : 2; // Parasect
    enum capture_rank unk_0048_rank : 2; // Venonat
    enum capture_rank unk_0049_rank : 2; // Venomoth
    enum capture_rank unk_0050_rank : 2; // Diglett
    enum capture_rank unk_0051_rank : 2; // Dugtrio
    enum capture_rank unk_0052_rank : 2; // Meowth
    enum capture_rank unk_0053_rank : 2; // Persian
    enum capture_rank unk_0054_rank : 2; // Psyduck
    enum capture_rank unk_0055_rank : 2; // Golduck
    enum capture_rank mankey_rank : 2;
    enum capture_rank primeape_rank : 2;
    enum capture_rank growlithe_rank : 2;
    enum capture_rank arcanine_rank : 2;
    enum capture_rank unk_0060_rank : 2; // Poliwag
    enum capture_rank unk_0061_rank : 2; // Poliwhirl
    enum capture_rank unk_0062_rank : 2; // Poliwrath
    enum capture_rank abra_rank : 2;
    enum capture_rank unk_0064_rank : 2; // Kadabra
    enum capture_rank alakazam_rank : 2;
    enum capture_rank machop_rank : 2;
    enum capture_rank machoke_rank : 2;
    enum capture_rank machamp_rank : 2;
    enum capture_rank unk_0069_rank : 2; // Bellsprout
    enum capture_rank unk_0070_rank : 2; // Weepinbell
    enum capture_rank victreebel_rank : 2;
    enum capture_rank unk_0072_rank : 2; // Tentacool
    enum capture_rank tentacruel_rank : 2;
    enum capture_rank geodude_rank : 2;
    enum capture_rank graveler_rank : 2;
    enum capture_rank golem_rank : 2;
    enum capture_rank ponyta_rank : 2;
    enum capture_rank rapidash_rank : 2;
    enum capture_rank unk_0079_rank : 2; // Slowpoke
    enum capture_rank unk_0080_rank : 2; // Slowbro
    enum capture_rank magnemite_rank : 2;
    enum capture_rank magneton_rank : 2;
    enum capture_rank unk_0083_rank : 2; // Farfetchd
    enum capture_rank doduo_rank : 2;
    enum capture_rank dodrio_rank : 2;
    enum capture_rank unk_0086_rank : 2; // Seel
    enum capture_rank unk_0087_rank : 2; // Dewgong
    enum capture_rank unk_0088_rank : 2; // Grimer
    enum capture_rank muk_rank : 2;
    enum capture_rank unk_0090_rank : 2; // Shellder
    enum capture_rank unk_0091_rank : 2; // Cloyster
    enum capture_rank gastly_rank : 2;
    enum capture_rank haunter_rank : 2;
    enum capture_rank gengar_rank : 2;
    enum capture_rank unk_0095_rank : 2; // Onix
    enum capture_rank drowzee_rank : 2;
    enum capture_rank hypno_rank : 2;
    enum capture_rank unk_0098_rank : 2; // Krabby
    enum capture_rank unk_0099_rank : 2; // Kingler
    enum capture_rank voltorb_rank : 2;
    enum capture_rank electrode_rank : 2;
    enum capture_rank unk_0102_rank : 2; // Exeggcute
    enum capture_rank unk_0103_rank : 2; // Exeggutor
    enum capture_rank unk_0104_rank : 2; // Cubone
    enum capture_rank unk_0105_rank : 2; // Marowak
    enum capture_rank unk_0106_rank : 2; // Hitmonlee
    enum capture_rank unk_0107_rank : 2; // Hitmonchan
    enum capture_rank unk_0108_rank : 2; // Lickitung
    enum capture_rank koffing_rank : 2;
    enum capture_rank weezing_rank : 2;
    enum capture_rank rhyhorn_rank : 2;
    enum capture_rank rhydon_rank : 2;
    enum capture_rank unk_0113_rank : 2; // Chansey
    enum capture_rank unk_0114_rank : 2; // Tangela
    enum capture_rank kangaskhan_rank : 2;
    enum capture_rank horsea_rank : 2;
    enum capture_rank seadra_rank : 2;
    enum capture_rank unk_0118_rank : 2; // Goldeen
    enum capture_rank unk_0119_rank : 2; // Seaking
    enum capture_rank staryu_rank : 2;
    enum capture_rank starmie_rank : 2;
    enum capture_rank mr_mime_rank : 2;
    enum capture_rank scyther_rank : 2;
    enum capture_rank jynx_rank : 2;
    enum capture_rank electabuzz_rank : 2;
    enum capture_rank magmar_rank : 2;
    enum capture_rank pinsir_rank : 2;
    enum capture_rank tauros_rank : 2;
    enum capture_rank unk_0129_rank : 2; // Magikarp
    enum capture_rank unk_0130_rank : 2; // Gyarados
    enum capture_rank unk_0131_rank : 2; // Lapras
    enum capture_rank unk_0132_rank : 2; // Ditto
    enum capture_rank eevee_rank : 2;
    enum capture_rank vaporeon_rank : 2;
    enum capture_rank jolteon_rank : 2;
    enum capture_rank flareon_rank : 2;
    enum capture_rank unk_0137_rank : 2; // Porygon
    enum capture_rank omanyte_rank : 2;
    enum capture_rank omastar_rank : 2;
    enum capture_rank unk_0140_rank : 2; // Kabuto
    enum capture_rank unk_0141_rank : 2; // Kabutops
    enum capture_rank aerodactyl_rank : 2;
    enum capture_rank unk_0143_rank : 2; // Snorlax
    enum capture_rank unk_0144_rank : 2; // Articuno
    enum capture_rank unk_0145_rank : 2; // Zapdos
    enum capture_rank unk_0146_rank : 2; // Moltres
    enum capture_rank dratini_rank : 2;
    enum capture_rank dragonair_rank : 2;
    enum capture_rank unk_0149_rank : 2; // Dragonite
    enum capture_rank unk_0150_rank : 2; // Mewtwo
    enum capture_rank unk_0151_rank : 2; // Mew
    enum capture_rank unk_0152_rank : 2; // Chikorita
    enum capture_rank unk_0153_rank : 2; // Bayleef
    enum capture_rank unk_0154_rank : 2; // Meganium
    enum capture_rank unk_0155_rank : 2; // Cyndaquil
    enum capture_rank unk_0156_rank : 2; // Quilava
    enum capture_rank unk_0157_rank : 2; // Typhlosion
    enum capture_rank unk_0158_rank : 2; // Totodile
    enum capture_rank unk_0159_rank : 2; // Croconaw
    enum capture_rank unk_0160_rank : 2; // Feraligatr
    enum capture_rank unk_0161_rank : 2; // Sentret
    enum capture_rank unk_0162_rank : 2; // Furret
    enum capture_rank unk_0163_rank : 2; // Hoothoot
    enum capture_rank unk_0164_rank : 2; // Noctowl
    enum capture_rank unk_0165_rank : 2; // Ledyba
    enum capture_rank unk_0166_rank : 2; // Ledian
    enum capture_rank spinarak_rank : 2;
    enum capture_rank ariados_rank : 2;
    enum capture_rank crobat_rank : 2;
    enum capture_rank chinchou_rank : 2;
    enum capture_rank lanturn_rank : 2;
    enum capture_rank pichu_rank : 2;
    enum capture_rank unk_0173_rank : 2; // Cleffa
    enum capture_rank unk_0174_rank : 2; // Igglybuff
    enum capture_rank unk_0175_rank : 2; // Togepi
    enum capture_rank unk_0176_rank : 2; // Togetic
    enum capture_rank unk_0177_rank : 2; // Natu
    enum capture_rank unk_0178_rank : 2; // Xatu
    enum capture_rank mareep_rank : 2;
    enum capture_rank flaaffy_rank : 2;
    enum capture_rank ampharos_rank : 2;
    enum capture_rank bellossom_rank : 2;
    enum capture_rank unk_0183_rank : 2; // Marill
    enum capture_rank unk_0184_rank : 2; // Azumarill
    enum capture_rank sudowoodo_rank : 2;
    enum capture_rank unk_0186_rank : 2; // Politoed
    enum capture_rank unk_0187_rank : 2; // Hoppip
    enum capture_rank unk_0188_rank : 2; // Skiploom
    enum capture_rank unk_0189_rank : 2; // Jumpluff
    enum capture_rank aipom_rank : 2;
    enum capture_rank unk_0191_rank : 2; // Sunkern
    enum capture_rank unk_0192_rank : 2; // Sunflora
    enum capture_rank yanma_rank : 2;
    enum capture_rank unk_0194_rank : 2; // Wooper
    enum capture_rank unk_0195_rank : 2; // Quagsire
    enum capture_rank espeon_rank : 2;
    enum capture_rank umbreon_rank : 2;
    enum capture_rank murkrow_rank : 2;
    enum capture_rank unk_0199_rank : 2; // Slowking
    enum capture_rank misdreavus_rank : 2;
    enum capture_rank unk_0201_rank : 2; // Unown
    enum capture_rank unk_0202_rank : 2; // Wobbuffet
    enum capture_rank girafarig_rank : 2;
    enum capture_rank pineco_rank : 2;
    enum capture_rank forretress_rank : 2;
    enum capture_rank unk_0206_rank : 2; // Dunsparce
    enum capture_rank gligar_rank : 2;
    enum capture_rank unk_0208_rank : 2; // Steelix
    enum capture_rank unk_0209_rank : 2; // Snubbull
    enum capture_rank unk_0210_rank : 2; // Granbull
    enum capture_rank qwilfish_rank : 2;
    enum capture_rank scizor_rank : 2;
    enum capture_rank unk_0213_rank : 2; // Shuckle
    enum capture_rank unk_0214_rank : 2; // Heracross
    enum capture_rank sneasel_rank : 2;
    enum capture_rank unk_0216_rank : 2; // Teddiursa
    enum capture_rank unk_0217_rank : 2; // Ursaring
    enum capture_rank slugma_rank : 2;
    enum capture_rank magcargo_rank : 2;
    enum capture_rank swinub_rank : 2;
    enum capture_rank piloswine_rank : 2;
    enum capture_rank corsola_rank : 2;
    enum capture_rank unk_0223_rank : 2; // Remoraid
    enum capture_rank unk_0224_rank : 2; // Octillery
    enum capture_rank delibird_rank : 2;
    enum capture_rank mantine_rank : 2;
    enum capture_rank skarmory_rank : 2;
    enum capture_rank houndour_rank : 2;
    enum capture_rank houndoom_rank : 2;
    enum capture_rank kingdra_rank : 2;
    enum capture_rank unk_0231_rank : 2; // Phanpy
    enum capture_rank unk_0232_rank : 2; // Donphan
    enum capture_rank unk_0233_rank : 2; // Porygon2
    enum capture_rank unk_0234_rank : 2; // Stantler
    enum capture_rank unk_0235_rank : 2; // Smeargle
    enum capture_rank tyrogue_rank : 2;
    enum capture_rank unk_0237_rank : 2; // Hitmontop
    enum capture_rank unk_0238_rank : 2; // Smoochum
    enum capture_rank elekid_rank : 2;
    enum capture_rank magby_rank : 2;
    enum capture_rank miltank_rank : 2;
    enum capture_rank unk_0242_rank : 2; // Blissey
    enum capture_rank unk_0243_rank : 2; // Raikou
    enum capture_rank unk_0244_rank : 2; // Entei
    enum capture_rank unk_0245_rank : 2; // Suicune
    enum capture_rank larvitar_rank : 2;
    enum capture_rank pupitar_rank : 2;
    enum capture_rank tyranitar_rank : 2;
    enum capture_rank unk_0249_rank : 2; // Lugia
    enum capture_rank unk_0250_rank : 2; // Ho-Oh
    enum capture_rank celebi_rank : 2;
    enum capture_rank unk_0252_rank : 2; // Treecko
    enum capture_rank unk_0253_rank : 2; // Grovyle
    enum capture_rank sceptile_rank : 2;
    enum capture_rank unk_0255_rank : 2; // Torchic
    enum capture_rank unk_0256_rank : 2; // Combusken
    enum capture_rank blaziken_rank : 2;
    enum capture_rank unk_0258_rank : 2; // Mudkip
    enum capture_rank unk_0259_rank : 2; // Marshtomp
    enum capture_rank unk_0260_rank : 2; // Swampert
    enum capture_rank unk_0261_rank : 2; // Poochyena
    enum capture_rank unk_0262_rank : 2; // Mightyena
    enum capture_rank unk_0263_rank : 2; // Zigzagoon
    enum capture_rank unk_0264_rank : 2; // Linoone
    enum capture_rank unk_0265_rank : 2; // Wurmple
    enum capture_rank unk_0266_rank : 2; // Silcoon
    enum capture_rank unk_0267_rank : 2; // Beautifly
    enum capture_rank unk_0268_rank : 2; // Cascoon
    enum capture_rank unk_0269_rank : 2; // Dustox
    enum capture_rank unk_0270_rank : 2; // Lotad
    enum capture_rank unk_0271_rank : 2; // Lombre
    enum capture_rank unk_0272_rank : 2; // Ludicolo
    enum capture_rank seedot_rank : 2;
    enum capture_rank nuzleaf_rank : 2;
    enum capture_rank shiftry_rank : 2;
    enum capture_rank taillow_rank : 2;
    enum capture_rank swellow_rank : 2;
    enum capture_rank wingull_rank : 2;
    enum capture_rank pelipper_rank : 2;
    enum capture_rank ralts_rank : 2;
    enum capture_rank kirlia_rank : 2;
    enum capture_rank gardevoir_rank : 2;
    enum capture_rank unk_0283_rank : 2; // Surskit
    enum capture_rank unk_0284_rank : 2; // Masquerain
    enum capture_rank unk_0285_rank : 2; // Shroomish
    enum capture_rank unk_0286_rank : 2; // Breloom
    enum capture_rank slakoth_rank : 2;
    enum capture_rank unk_0288_rank : 2; // Vigoroth
    enum capture_rank unk_0289_rank : 2; // Slaking
    enum capture_rank unk_0290_rank : 2; // Nincada
    enum capture_rank ninjask_rank : 2;
    enum capture_rank unk_0292_rank : 2; // Shedinja
    enum capture_rank unk_0293_rank : 2; // Whismur
    enum capture_rank unk_0294_rank : 2; // Loudred
    enum capture_rank unk_0295_rank : 2; // Exploud
    enum capture_rank makuhita_rank : 2;
    enum capture_rank hariyama_rank : 2;
    enum capture_rank unk_0298_rank : 2; // Azurill
    enum capture_rank nosepass_rank : 2;
    enum capture_rank unk_0300_rank : 2; // Skitty
    enum capture_rank unk_0301_rank : 2; // Delcatty
    enum capture_rank sableye_rank : 2;
    enum capture_rank mawile_rank : 2;
    enum capture_rank aron_rank : 2;
    enum capture_rank lairon_rank : 2;
    enum capture_rank aggron_rank : 2;
    enum capture_rank unk_0307_rank : 2; // Meditite
    enum capture_rank unk_0308_rank : 2; // Medicham
    enum capture_rank unk_0309_rank : 2; // Electrike
    enum capture_rank unk_0310_rank : 2; // Manectric
    enum capture_rank unk_0311_rank : 2; // Plusle
    enum capture_rank unk_0312_rank : 2; // Minun
    enum capture_rank unk_0313_rank : 2; // Volbeat
    enum capture_rank unk_0314_rank : 2; // Illumise
    enum capture_rank roselia_rank : 2;
    enum capture_rank unk_0316_rank : 2; // Gulpin
    enum capture_rank unk_0317_rank : 2; // Swalot
    enum capture_rank unk_0318_rank : 2; // Carvanha
    enum capture_rank sharpedo_rank : 2;
    enum capture_rank wailmer_rank : 2;
    enum capture_rank wailord_rank : 2;
    enum capture_rank numel_rank : 2;
    enum capture_rank camerupt_rank : 2;
    enum capture_rank torkoal_rank : 2;
    enum capture_rank unk_0325_rank : 2; // Spoink
    enum capture_rank unk_0326_rank : 2; // Grumpig
    enum capture_rank unk_0327_rank : 2; // Spinda
    enum capture_rank unk_0328_rank : 2; // Trapinch
    enum capture_rank unk_0329_rank : 2; // Vibrava
    enum capture_rank flygon_rank : 2;
    enum capture_rank cacnea_rank : 2;
    enum capture_rank cacturne_rank : 2;
    enum capture_rank unk_0333_rank : 2; // Swablu
    enum capture_rank altaria_rank : 2;
    enum capture_rank unk_0335_rank : 2; // Zangoose
    enum capture_rank unk_0336_rank : 2; // Seviper
    enum capture_rank unk_0337_rank : 2; // Lunatone
    enum capture_rank unk_0338_rank : 2; // Solrock
    enum capture_rank unk_0339_rank : 2; // Barboach
    enum capture_rank unk_0340_rank : 2; // Whiscash
    enum capture_rank unk_0341_rank : 2; // Corphish
    enum capture_rank unk_0342_rank : 2; // Crawdaunt
    enum capture_rank unk_0343_rank : 2; // Baltoy
    enum capture_rank claydol_rank : 2;
    enum capture_rank unk_0345_rank : 2; // Lileep
    enum capture_rank unk_0346_rank : 2; // Cradily
    enum capture_rank unk_0347_rank : 2; // Anorith
    enum capture_rank unk_0348_rank : 2; // Armaldo
    enum capture_rank unk_0349_rank : 2; // Feebas
    enum capture_rank unk_0350_rank : 2; // Milotic
    enum capture_rank unk_0351_rank : 2; // Castform
    enum capture_rank unk_0352_rank : 2; // Kecleon
    enum capture_rank shuppet_rank : 2;
    enum capture_rank banette_rank : 2;
    enum capture_rank duskull_rank : 2;
    enum capture_rank dusclops_rank : 2;
    enum capture_rank unk_0357_rank : 2; // Tropius
    enum capture_rank unk_0358_rank : 2; // Chimecho
    enum capture_rank absol_rank : 2;
    enum capture_rank unk_0360_rank : 2; // Wynaut
    enum capture_rank snorunt_rank : 2;
    enum capture_rank glalie_rank : 2;
    enum capture_rank spheal_rank : 2;
    enum capture_rank sealeo_rank : 2;
    enum capture_rank walrein_rank : 2;
    enum capture_rank unk_0366_rank : 2; // Clamperl
    enum capture_rank huntail_rank : 2;
    enum capture_rank gorebyss_rank : 2;
    enum capture_rank unk_0369_rank : 2; // Relicanth
    enum capture_rank unk_0370_rank : 2; // Luvdisc
    enum capture_rank bagon_rank : 2;
    enum capture_rank shelgon_rank : 2;
    enum capture_rank salamence_rank : 2;
    enum capture_rank unk_0374_rank : 2; // Beldum
    enum capture_rank unk_0375_rank : 2; // Metang
    enum capture_rank unk_0376_rank : 2; // Metagross
    enum capture_rank regirock_rank : 2;
    enum capture_rank regice_rank : 2;
    enum capture_rank registeel_rank : 2;
    enum capture_rank unk_0380_rank : 2; // Latias
    enum capture_rank unk_0381_rank : 2; // Latios
    enum capture_rank unk_0382_rank : 2; // Kyogre
    enum capture_rank unk_0383_rank : 2; // Groudon
    enum capture_rank unk_0384_rank : 2; // Rayquaza
    enum capture_rank unk_0385_rank : 2; // Jirachi
    enum capture_rank unk_0386_rank : 2; // Deoxys
    enum capture_rank turtwig_rank : 2;
    enum capture_rank grotle_rank : 2;
    enum capture_rank torterra_rank : 2;
    enum capture_rank chimchar_rank : 2;
    enum capture_rank monferno_rank : 2;
    enum capture_rank infernape_rank : 2;
    enum capture_rank piplup_rank : 2;
    enum capture_rank prinplup_rank : 2;
    enum capture_rank empoleon_rank : 2;
    enum capture_rank starly_rank : 2;
    enum capture_rank staravia_rank : 2;
    enum capture_rank staraptor_rank : 2;
    enum capture_rank bidoof_rank : 2;
    enum capture_rank bibarel_rank : 2;
    enum capture_rank kricketot_rank : 2;
    enum capture_rank kricketune_rank : 2;
    enum capture_rank shinx_rank : 2;
    enum capture_rank luxio_rank : 2;
    enum capture_rank luxray_rank : 2;
    enum capture_rank budew_rank : 2;
    enum capture_rank roserade_rank : 2;
    enum capture_rank cranidos_rank : 2;
    enum capture_rank rampardos_rank : 2;
    enum capture_rank shieldon_rank : 2;
    enum capture_rank bastiodon_rank : 2;
    enum capture_rank unk_0412_rank : 2; // Burmy
    enum capture_rank unk_0413_rank : 2; // Wormadam
    enum capture_rank mothim_rank : 2;
    enum capture_rank combee_rank : 2;
    enum capture_rank vespiquen_rank : 2;
    enum capture_rank pachirisu_rank : 2;
    enum capture_rank buizel_rank : 2;
    enum capture_rank floatzel_rank : 2;
    enum capture_rank cherubi_rank : 2;
    enum capture_rank cherrim_rank : 2;
    enum capture_rank shellos_rank : 2;
    enum capture_rank gastrodon_rank : 2;
    enum capture_rank ambipom_rank : 2;
    enum capture_rank drifloon_rank : 2;
    enum capture_rank drifblim_rank : 2;
    enum capture_rank buneary_rank : 2;
    enum capture_rank lopunny_rank : 2;
    enum capture_rank mismagius_rank : 2;
    enum capture_rank honchkrow_rank : 2;
    enum capture_rank glameow_rank : 2;
    enum capture_rank purugly_rank : 2;
    enum capture_rank chingling_rank : 2;
    enum capture_rank stunky_rank : 2;
    enum capture_rank skuntank_rank : 2;
    enum capture_rank bronzor_rank : 2;
    enum capture_rank bronzong_rank : 2;
    enum capture_rank bonsly_rank : 2;
    enum capture_rank mime_jr_rank : 2;
    enum capture_rank happiny_rank : 2;
    enum capture_rank chatot_rank : 2;
    enum capture_rank spiritomb_rank : 2;
    enum capture_rank gible_rank : 2;
    enum capture_rank gabite_rank : 2;
    enum capture_rank garchomp_rank : 2;
    enum capture_rank munchlax_rank : 2;
    enum capture_rank riolu_rank : 2;
    enum capture_rank lucario_rank : 2;
    enum capture_rank hippopotas_rank : 2;
    enum capture_rank hippowdon_rank : 2;
    enum capture_rank skorupi_rank : 2;
    enum capture_rank drapion_rank : 2;
    enum capture_rank croagunk_rank : 2;
    enum capture_rank toxicroak_rank : 2;
    enum capture_rank carnivine_rank : 2;
    enum capture_rank finneon_rank : 2;
    enum capture_rank lumineon_rank : 2;
    enum capture_rank mantyke_rank : 2;
    enum capture_rank snover_rank : 2;
    enum capture_rank abomasnow_rank : 2;
    enum capture_rank weavile_rank : 2;
    enum capture_rank magnezone_rank : 2;
    enum capture_rank lickilicky_rank : 2;
    enum capture_rank rhyperior_rank : 2;
    enum capture_rank tangrowth_rank : 2;
    enum capture_rank electivire_rank : 2;
    enum capture_rank magmortar_rank : 2;
    enum capture_rank togekiss_rank : 2;
    enum capture_rank yanmega_rank : 2;
    enum capture_rank leafeon_rank : 2;
    enum capture_rank glaceon_rank : 2;
    enum capture_rank gliscor_rank : 2;
    enum capture_rank mamoswine_rank : 2;
    enum capture_rank porygon_z_rank : 2;
    enum capture_rank gallade_rank : 2;
    enum capture_rank probopass_rank : 2;
    enum capture_rank dusknoir_rank : 2;
    enum capture_rank froslass_rank : 2;
    enum capture_rank unk_0479_rank : 2; // Rotom
    enum capture_rank unk_0480_rank : 2; // Uxie
    enum capture_rank unk_0481_rank : 2; // Mesprit
    enum capture_rank unk_0482_rank : 2; // Azelf
    enum capture_rank dialga_rank : 2;
    enum capture_rank palkia_rank : 2;
    enum capture_rank heatran_rank : 2;
    enum capture_rank regigigas_rank : 2;
    enum capture_rank unk_0487_rank : 2; // Giratina
    enum capture_rank cresselia_rank : 2;
    enum capture_rank unk_0489_rank : 2; // Phione
    enum capture_rank unk_0490_rank : 2; // Manaphy
    enum capture_rank darkrai_rank : 2;
    enum capture_rank shaymin_rank : 2;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
};
ASSERT_SIZE(struct ranger_pokedex, 756);

// Stored the time played in hours, minutes, and seconds.
struct play_time {
    int hours;
    int8_t minutes; // Created by retype action
    int8_t seconds;
    bool has_max_play_time;
    int8_t styler_level; // This is suspicious, but the alternative is that this struct is size 0x7.
};
ASSERT_SIZE(struct play_time, 8);

// Records for various things the player can do.
struct ranger_records {
    int32_t max_steps_record;
    int32_t conversations_record;
    int32_t targets_checked_record;
    int32_t game_saves_record;
    int32_t pokemon_rides_record;
    // This seems to determine the obscure "Best Partner" Ranger Record in-game. It increments by one
    // at the end of each battle where the partner used a poke-assist. Cannot exceed 9,999,999.
    int32_t best_partner_record_table[17];
    int32_t capture_line_len_record;
    int32_t num_loops_record;
    int16_t pokemon_captured_record;
    int16_t pokemon_fled_record;
    int16_t poke_assists_used_record;
    undefined field78_0x66;
    int8_t timer_type_active; // 0 = no timer, 1 = timer counting down, 2 = unknown
    int32_t timer_1_frames_left;
    int32_t timer_2_frames_left; // May count upwards. More clarification needed.
    // This seems to be the internal order used by the partners.
    enum partner_unlock_flag munchlax_met : 1;
    enum partner_unlock_flag chimchar_met : 1;
    enum partner_unlock_flag piplup_met : 1;
    enum partner_unlock_flag turtwig_met : 1;
    enum partner_unlock_flag pachirisu_met : 1;
    enum partner_unlock_flag snorunt_met : 1;
    enum partner_unlock_flag machop_met : 1;
    enum partner_unlock_flag croagunk_met : 1;
    enum partner_unlock_flag hippopotas_met : 1;
    enum partner_unlock_flag starly_met : 1;
    enum partner_unlock_flag mime_jr_met : 1;
    enum partner_unlock_flag kricketot_met : 1;
    enum partner_unlock_flag cranidos_met : 1;
    enum partner_unlock_flag misdreavus_met : 1;
    enum partner_unlock_flag gible_met : 1;
    enum partner_unlock_flag sneasel_met : 1;
    enum partner_unlock_flag shieldon_met : 1;
    enum partner_unlock_flag unused_flags : 15;
    struct play_time last_play_time;
    struct play_time current_play_time;
};
ASSERT_SIZE(struct ranger_records, 132);

struct ranger_glossary {
    // Start of the "Field" glossary bitfield
    enum glossary_table_entry friend_pokemon_entry : 2;
    enum glossary_table_entry partner_pokemon_entry : 2;
    enum glossary_table_entry partner_energy_entry : 2;
    enum glossary_table_entry happy_mood_entry : 2;
    enum glossary_table_entry release_entry : 2;
    enum glossary_table_entry partner_farm_entry : 2;
    enum glossary_table_entry field_moves_and_targets_entry : 2;
    enum glossary_table_entry target_clear_entry : 2;
    enum glossary_table_entry map_moves_entry : 2;
    enum glossary_table_entry recharge_entry : 2;
    enum glossary_table_entry agility_entry : 2;
    enum glossary_table_entry fly_entry : 2;
    enum glossary_table_entry teleport_entry : 2;
    enum glossary_table_entry area_moves_entry : 2;
    enum glossary_table_entry missions_entry : 2;
    enum glossary_table_entry quests_entry : 2;
    enum glossary_table_entry field_damage_entry : 2;
    enum glossary_table_entry change_screen_button_entry : 2;
    enum glossary_table_entry unk_entry_0 : 2;
    enum glossary_table_entry unk_entry_1 : 2;
    // Presumed to be padding.
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    // Start of the "Capture" glossary bitfield
    enum glossary_table_entry capture_disc_entry : 2;
    enum glossary_table_entry capture_line_entry : 2;
    enum glossary_table_entry capture_entry : 2;
    enum glossary_table_entry capture_results_entry : 2;
    enum glossary_table_entry styler_energy_entry : 2;
    enum glossary_table_entry styler_damage_entry : 2;
    enum glossary_table_entry styler_level_entry : 2;
    enum glossary_table_entry flee_entry : 2;
    enum glossary_table_entry power_charge_entry : 2;
    enum glossary_table_entry styler_status_entry : 2;
    enum glossary_table_entry power_up_data_entry : 2;
    enum glossary_table_entry poke_assists_entry : 2;
    enum glossary_table_entry poke_assist_matchups_entry : 2;
    enum glossary_table_entry poke_assist_grass_entry : 2;
    enum glossary_table_entry poke_assist_flying_entry : 2;
    enum glossary_table_entry poke_assist_normal_entry : 2;
    enum glossary_table_entry poke_assist_recharge_entry : 2;
    enum glossary_table_entry poke_assist_water_entry : 2;
    enum glossary_table_entry poke_assist_rock_entry : 2;
    enum glossary_table_entry poke_assist_electric_entry : 2;
    enum glossary_table_entry poke_assist_bug_entry : 2;
    enum glossary_table_entry poke_assist_fire_entry : 2;
    enum glossary_table_entry poke_assist_fighting_entry : 2;
    enum glossary_table_entry poke_assist_ground_entry : 2;
    enum glossary_table_entry poke_assist_steel_entry : 2;
    enum glossary_table_entry poke_assist_poison_entry : 2;
    enum glossary_table_entry poke_assist_ghost_entry : 2;
    enum glossary_table_entry poke_assist_psychic_entry : 2;
    enum glossary_table_entry poke_assist_dark_entry : 2;
    enum glossary_table_entry poke_assist_ice_entry : 2;
    enum glossary_table_entry poke_assist_dragon_entry : 2;
    enum glossary_table_entry poke_assist_special_effects_entry : 2;
    // Presumed to be padding.
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    // Start of the "Terms" header glossary bitfield
    enum glossary_table_entry pokemon_rangers_entry : 2;
    enum glossary_table_entry student_rangers_entry : 2;
    enum glossary_table_entry top_rangers_entry : 2;
    enum glossary_table_entry ranger_union_entry : 2;
    enum glossary_table_entry ranger_base_entry : 2;
    enum glossary_table_entry ranger_depot_entry : 2;
    enum glossary_table_entry ranger_rank_entry : 2;
    enum glossary_table_entry school_styler_entry : 2;
    enum glossary_table_entry capture_styler_entry : 2;
    enum glossary_table_entry fine_styler_entry : 2;
    enum glossary_table_entry vatonage_styler_entry : 2;
    enum glossary_table_entry ranger_record_entry : 2;
    enum glossary_table_entry capture_arena_entry : 2;
    enum glossary_table_entry ranger_school_entry : 2;
    enum glossary_table_entry chicole_village_entry : 2;
    enum glossary_table_entry vientown_entry : 2;
    enum glossary_table_entry vien_forest_entry : 2;
    enum glossary_table_entry pueltown_entry : 2;
    enum glossary_table_entry puel_sea_entry : 2;
    enum glossary_table_entry altru_park_entry : 2;
    enum glossary_table_entry altru_inc_entry : 2;
    enum glossary_table_entry peril_cliffs_entry : 2;
    enum glossary_table_entry boyleland_entry : 2;
    enum glossary_table_entry boyle_volcano_entry : 2;
    enum glossary_table_entry cargo_ship_entry : 2;
    enum glossary_table_entry chroma_highlands_entry : 2;
    enum glossary_table_entry chroma_ruins_entry : 2;
    enum glossary_table_entry altru_ruins_entry : 2;
    enum glossary_table_entry hia_valley_entry : 2;
    enum glossary_table_entry shiver_camp_entry : 2;
    enum glossary_table_entry ice_lake_entry : 2;
    enum glossary_table_entry almia_castle_entry : 2;
    enum glossary_table_entry sea_of_wailord_entry : 2;
    enum glossary_table_entry oil_field_hideout_entry : 2;
    enum glossary_table_entry haruba_village_entry : 2;
    enum glossary_table_entry hippowdon_temple_entry : 2;
    enum glossary_table_entry altru_tower_entry : 2;
    enum glossary_table_entry unk_entry_02 : 2;
    enum glossary_table_entry unk_entry_03 : 2;
    enum glossary_table_entry unk_entry_04 : 2;
    // Presumed to be padding.
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

ASSERT_SIZE(struct ranger_glossary, 48);

struct following_npc {
    int is_valid; // 0x0: If true, an NPC is following the player.
    undefined4 unk_field0_0x4;
    int16_t sprite_id; // 0x8: Determines which sprite the following NPC will have.
    int16_t
        face_angle;   // 0xA: Continuous, Right = 0x0000, Down = 0x4000, Left = 0x8000, Up = 0xC000.
    int x_coordinate; // 0xC
    int y_coordinate; // 0x10
    char talk_script_func_name[32]; // 0x14: Unknown how long this actually is. Name of the script
                                    // function called when NPC is tapped.
    int16_t unk_field1_0x34;        // 0x34
    undefined unk_field1_0x36;      // 0x36
    undefined unk_field1_0x37;      // 0x37
};

ASSERT_SIZE(struct following_npc, 56);
/*
struct styler_upgrades {
    enum styler_upgrade_level grass_defense : 2;
    enum styler_upgrade_level water_defense : 2;
    enum styler_upgrade_level electric_defense : 2;
    enum styler_upgrade_level fire_defense : 2;

    enum styler_upgrade_level fighting_defense : 2;
    enum styler_upgrade_level poison_defense : 2;
    enum styler_upgrade_level psychic_defense : 2;
    enum styler_upgrade_level bug_defense : 2;

    enum styler_upgrade_level ground_defense : 2;
    enum styler_upgrade_level flying_defense : 2;
    enum styler_upgrade_level dark_defense : 2;
    enum styler_upgrade_level rock_defense : 2;

    enum styler_upgrade_level ghost_defense : 2;
    enum styler_upgrade_level ice_defense : 2;
    enum styler_upgrade_level normal_defense : 2;
    enum styler_upgrade_level steel_defense : 2;

    enum styler_upgrade_level dragon_defense : 2;
    enum styler_upgrade_level time_assist : 2;
    enum styler_upgrade_level latent_power : 2;
    enum styler_upgrade_level combo_bonus : 2;

    enum styler_upgrade_level recovery : 2;
    enum styler_upgrade_level energy_plus : 2;
    enum styler_upgrade_level power_plus : 2;
    enum styler_upgrade_level long_line : 2;
};

ASSERT_SIZE(struct styler_upgrades, 6);
*/

// Most interactions with these values seem to treat them as tables of ints, rather than individual
// fields. For ghidra analysis in the short term, this struct will be a simple table for now, even
// though we know what some of these values mean.
struct settings_and_variables {
    // Generally, the event_variable_table can be thought of as chapter-specific scratch paper.
    int32_t event_variable_table[21];
    // Used to track in-game settings, and has a byte to play the unlock cutscene for a styler
    // upgrade.
    int32_t settings_variable_table[31];
    // Unknown, but debug prints seem to suggest these relate to quests. Or something else that
    // begins with q...
    int32_t quest_variable_table[11];
};

ASSERT_SIZE(struct settings_and_variables, 252);

// This struct is equivalent the the above event_variable_table, but with definitions instead of
// being an arbitrary table of ints.
struct event_variables {
    int32_t subchapter_progression; // 0x00: Seems to increase linearly, or to the nearest multiple
                                    // of 10. Sub-sub-chapters perhaps?
    int32_t scrach_paper[20];       // 0x04: Varies wildly by subchapter.
};

ASSERT_SIZE(struct event_variables, 84);

// This struct is equivalent the the above settings_variable_table, but with definitions instead of
// being an arbitrary table of ints.
struct settings_variables {
    int32_t unk_setting_0x0;
    int32_t window_border; // 0x4: Determines what color the textbox border will be.
    int32_t text_speed; // 0x8: 0x03 for slow, 0x02 for medium, 0x01 for fast. No other values seem
                        // to have an impact. :(
    // If non-zero, opening the styler upgrade menu will unlock a new styler upgrade.
    enum styler_unlock_upgrade_type styler_upgrade_interrupt; // 0xC
    // Incremented by the cutscene produced by the above field!
    int32_t num_styler_upgrades; // 0x10
    int32_t unk_settings[26];    // 0x14
};

ASSERT_SIZE(struct settings_variables, 124);

// This struct is equivalent the the above quest_variable_table, but with definitions instead of
// being an arbitrary table of ints.
struct quest_variables {
    // 0x0: Enabled when the Breeze Hill sign is repaired, disabled when starting a quest?
    // Either this is a bitflag of some kind, or it's actually used as a subquest progression
    // marker, and only starting a quest resets it?
    int32_t maybe_quest_progression;
    int32_t unk_quest_vars[10]; // 0x4: So far no use observed, but likely scratch paper to be used
                                // individually by quest.
};

ASSERT_SIZE(struct quest_variables, 44);

// This is populated in an unknown way upon starting any battle.
struct battle_init {
    undefined unk_fields[2048];
};

ASSERT_SIZE(struct battle_init, 2048);

struct battle_combatants {
    int *unk_struct_ptr_0x0;
    int8_t current_hp;
    int8_t styler_level;
    bool partner_assist_unlocked;
    undefined field4_0x7;
    int partner_gauge_current;
    int partner_gauge_max;
    int partner_gauge_fill_rate?;
    int8_t num_party_pokemon;
    undefined field9_0x15;
    int16_t party_form_ids[8];
    int8_t party_slot_statuses_table[8];
    int8_t num_enemy_forms;
    undefined field13_0x2f;
    int16_t enemy_form_ids[4];
    int8_t unk_enemy_data_0x38[4];
    int8_t unk_enemy_data_0x3C[4];
    int8_t num_enemy_pokemon; // Created by Rename Structure Field action
    int8_t unk_enemy_data_0x41[8]; // Might be related to enemy catch status?
    int8_t arena_graphic_id;
    int8_t weather_graphic_id;
    int8_t sequence_script_id; // runs "data/script/battle/sequence/s%03d.fsb" with this id.
    int8_t tutorial_script_id; // runs "data/script/battle/tutorial/s%03d.fsb" with this id.
    int8_t start_script_id; // runs "data/script/battle/start/s%03d.fsb" with this id.
    int8_t bgm_id;
    bool can_view_party;
    bool can_flee;
    bool show_boss_health_bar;
    int8_t field28_0x52;
    undefined field29_0x53;
    int8_t field30_0x54;
    undefined field31_0x55;
    int16_t gender_and_uniform; // bit 0: ranger_gender. bit 1+ styler_type, aka uniform
    int8_t field_alloc_bits; // bit 0: , bit 1: , bit 2: field_0x56.
    undefined field34_0x59;
    undefined field35_0x5a;
    undefined field36_0x5b;
    // May be larger than this!
};

ASSERT_SIZE(struct battle_combatants, 92);


struct battle_struct {
    undefined4 *function_ptr_0x0;
    undefined4 *unk_pointer_0x4;
    int16_t field2_0x8;
    int16_t field3_0xa;
    uint capture_rank_bit_field;
    int *field5_0x10;
    undefined field6_0x14;
    undefined field7_0x15;
    undefined field8_0x16;
    undefined field9_0x17;
    int field10_0x18;
    struct battle_combatants *battle_combatants_ptr;
    int current_battle_state;
    int previous_battle_state;
    int time_in_battle_frames;
    int16_t field15_0x2c;
    int16_t field16_0x2e;
    int16_t maybe_styler_power; // This quantity is boosted by styler upgrade 0x16.
    undefined field18_0x32;
    undefined field19_0x33;
    int num_new_lines_drawn;
    int num_times_taken_damage;
    int consecutive_loops_made;
    int field23_0x40;
    int8_t num_caught_pokemon;
    undefined field25_0x45;
    int16_t caught_form_ids[8];
    ushort field27_0x56;
    int total_loops_made;
    undefined field29_0x5c;
    int8_t unk_table_0x5e_index;
    int16_t unk_table_0x5e[4];
    undefined field32_0x66;
    undefined field33_0x67;
    int field34_0x68;
    int16_t fight_end_animation_timer;
    undefined field36_0x6e;
    undefined field37_0x6f;
    int field38_0x70;
    int partner_assist_gauge_current;
    int partner_assist_gauge_max;
    int maybe_partner_assist_gauge_increment;
    int8_t partner_something_1;
    int8_t styler_charge_amount;
    int16_t party_form_ids[8];
    bool poke_assists_available[8];
    bool poke_assists_used[8];
    undefined field47_0xa2;
    undefined field48_0xa3;
    int8_t *poke_assists_used_ptrs[8];
    int *unk_struct_size_0x3C_ptrs[3]; // May live at +0x2468 from the start of this struct!
    int8_t *field51_0xd0;
    int field52_0xd4;
    int *field53_0xd8;
    undefined4 *mystery_struct_ptrs[8];
    int field55_0xfc[4];
    int field56_0x10c[8];
    int *field57_0x12c;
    int *field58_0x130[96]; // Mostly size 0x7DC, but the first few aren't...
    int *field59_0x2b0[18];
    int *field60_0x2f8[32]; // Mostly size 0x7DC, but the first few aren't...
    int field61_0x378[3];
    int *partner_something_ptr;
    int *recruit_something_ptrs[8];
    int *unk_struct_size_0xC4_ptrs[512]; // May live at +0x4B6C from the start of this struct!
    int field65_0xba8;
    undefined4 field66_0xbac;
    int *field67_0xbb0;
    int *field68_0xbb4;
    int field69_0xbb8;
    int *field70_0xbbc;
    int field71_0xbc0;
    int *unk_struct_size_0x24_ptrs[8];
    undefined field73_0xbe4;
    undefined field74_0xbe5;
    undefined field75_0xbe6;
    undefined field76_0xbe7;
    int field77_0xbe8;
    int field78_0xbec;
    int field79_0xbf0;
    int field80_0xbf4;
    int field81_0xbf8;
    int field82_0xbfc;
    int field83_0xc00;
    int field84_0xc04;
    int field85_0xc08;
    int field86_0xc0c;
    undefined4* battle_graphic_struct_ptr;
    int field88_0xc14;
    int *unk_struct_size_0x18_ptrs[3];
    int field90_0xc24;
    int field91_0xc28;
    int *field92_0xc2c;
    int field93_0xc30;
    int field94_0xc34;
    int field95_0xc38;
    undefined field96_0xc3c;
    undefined field97_0xc3d;
    undefined field98_0xc3e;
    undefined field99_0xc3f;
    int field100_0xc40;
    int *field101_0xc44;
    int *field102_0xc48;
    undefined field103_0xc4c;
    undefined field104_0xc4d;
    undefined field105_0xc4e;
    undefined field106_0xc4f;
    undefined field107_0xc50;
    undefined field108_0xc51;
    undefined field109_0xc52;
    undefined field110_0xc53;
    undefined field111_0xc54;
    undefined field112_0xc55;
    undefined field113_0xc56;
    undefined field114_0xc57;
    undefined field115_0xc58;
    undefined field116_0xc59;
    undefined field117_0xc5a;
    undefined field118_0xc5b;
    undefined field119_0xc5c;
    undefined field120_0xc5d;
    undefined field121_0xc5e;
    undefined field122_0xc5f;
    undefined field123_0xc60;
    undefined field124_0xc61;
    undefined field125_0xc62;
    undefined field126_0xc63;
    undefined field127_0xc64;
    undefined field128_0xc65;
    undefined field129_0xc66;
    undefined field130_0xc67;
    undefined field131_0xc68;
    undefined field132_0xc69;
    undefined field133_0xc6a;
    undefined field134_0xc6b;
    undefined field135_0xc6c;
    undefined field136_0xc6d;
    undefined field137_0xc6e;
    undefined field138_0xc6f;
    undefined field139_0xc70;
    undefined field140_0xc71;
    undefined field141_0xc72;
    undefined field142_0xc73;
    undefined field143_0xc74;
    undefined field144_0xc75;
    undefined field145_0xc76;
    undefined field146_0xc77;
    undefined field147_0xc78;
    undefined field148_0xc79;
    undefined field149_0xc7a;
    undefined field150_0xc7b;
    undefined field151_0xc7c;
    undefined field152_0xc7d;
    undefined field153_0xc7e;
    undefined field154_0xc7f;
    undefined field155_0xc80;
    undefined field156_0xc81;
    undefined field157_0xc82;
    undefined field158_0xc83;
    undefined field159_0xc84;
    undefined field160_0xc85;
    undefined field161_0xc86;
    undefined field162_0xc87;
    undefined field163_0xc88;
    undefined field164_0xc89;
    undefined field165_0xc8a;
    undefined field166_0xc8b;
    undefined field167_0xc8c;
    undefined field168_0xc8d;
    undefined field169_0xc8e;
    undefined field170_0xc8f;
    undefined field171_0xc90;
    undefined field172_0xc91;
    undefined field173_0xc92;
    undefined field174_0xc93;
    undefined field175_0xc94;
    undefined field176_0xc95;
    undefined field177_0xc96;
    undefined field178_0xc97;
    undefined field179_0xc98;
    undefined field180_0xc99;
    undefined field181_0xc9a;
    undefined field182_0xc9b;
    undefined field183_0xc9c;
    undefined field184_0xc9d;
    undefined field185_0xc9e;
    undefined field186_0xc9f;
    undefined field187_0xca0;
    undefined field188_0xca1;
    undefined field189_0xca2;
    undefined field190_0xca3;
    undefined field191_0xca4;
    undefined field192_0xca5;
    undefined field193_0xca6;
    undefined field194_0xca7;
    undefined field195_0xca8;
    undefined field196_0xca9;
    undefined field197_0xcaa;
    undefined field198_0xcab;
    undefined field199_0xcac;
    undefined field200_0xcad;
    undefined field201_0xcae;
    undefined field202_0xcaf;
    undefined field203_0xcb0;
    undefined field204_0xcb1;
    undefined field205_0xcb2;
    undefined field206_0xcb3;
    undefined field207_0xcb4;
    undefined field208_0xcb5;
    undefined field209_0xcb6;
    undefined field210_0xcb7;
    undefined field211_0xcb8;
    undefined field212_0xcb9;
    undefined field213_0xcba;
    undefined field214_0xcbb;
    undefined field215_0xcbc;
    undefined field216_0xcbd;
    undefined field217_0xcbe;
    undefined field218_0xcbf;
    undefined field219_0xcc0;
    undefined field220_0xcc1;
    undefined field221_0xcc2;
    undefined field222_0xcc3;
    undefined field223_0xcc4;
    undefined field224_0xcc5;
    undefined field225_0xcc6;
    undefined field226_0xcc7;
    undefined field227_0xcc8;
    undefined field228_0xcc9;
    undefined field229_0xcca;
    undefined field230_0xccb;
    undefined field231_0xccc;
    undefined field232_0xccd;
    undefined field233_0xcce;
    undefined field234_0xccf;
    undefined field235_0xcd0;
    undefined field236_0xcd1;
    undefined field237_0xcd2;
    undefined field238_0xcd3;
    undefined field239_0xcd4;
    undefined field240_0xcd5;
    undefined field241_0xcd6;
    undefined field242_0xcd7;
    undefined field243_0xcd8;
    undefined field244_0xcd9;
    undefined field245_0xcda;
    undefined field246_0xcdb;
    undefined field247_0xcdc;
    undefined field248_0xcdd;
    undefined field249_0xcde;
    undefined field250_0xcdf;
    undefined field251_0xce0;
    undefined field252_0xce1;
    undefined field253_0xce2;
    undefined field254_0xce3;
    undefined field255_0xce4;
    undefined field256_0xce5;
    undefined field257_0xce6;
    undefined field258_0xce7;
    undefined field259_0xce8;
    undefined field260_0xce9;
    undefined field261_0xcea;
    undefined field262_0xceb;
    undefined field263_0xcec;
    undefined field264_0xced;
    undefined field265_0xcee;
    undefined field266_0xcef;
    undefined field267_0xcf0;
    undefined field268_0xcf1;
    undefined field269_0xcf2;
    undefined field270_0xcf3;
    undefined field271_0xcf4;
    undefined field272_0xcf5;
    undefined field273_0xcf6;
    undefined field274_0xcf7;
    undefined field275_0xcf8;
    undefined field276_0xcf9;
    undefined field277_0xcfa;
    undefined field278_0xcfb;
    undefined field279_0xcfc;
    undefined field280_0xcfd;
    undefined field281_0xcfe;
    undefined field282_0xcff;
    undefined field283_0xd00;
    undefined field284_0xd01;
    undefined field285_0xd02;
    undefined field286_0xd03;
    undefined field287_0xd04;
    undefined field288_0xd05;
    undefined field289_0xd06;
    undefined field290_0xd07;
    undefined field291_0xd08;
    undefined field292_0xd09;
    undefined field293_0xd0a;
    undefined field294_0xd0b;
    undefined field295_0xd0c;
    undefined field296_0xd0d;
    undefined field297_0xd0e;
    undefined field298_0xd0f;
    undefined field299_0xd10;
    undefined field300_0xd11;
    undefined field301_0xd12;
    undefined field302_0xd13;
    undefined field303_0xd14;
    undefined field304_0xd15;
    undefined field305_0xd16;
    undefined field306_0xd17;
    undefined field307_0xd18;
    undefined field308_0xd19;
    undefined field309_0xd1a;
    undefined field310_0xd1b;
    undefined field311_0xd1c;
    undefined field312_0xd1d;
    undefined field313_0xd1e;
    undefined field314_0xd1f;
    undefined field315_0xd20;
    undefined field316_0xd21;
    undefined field317_0xd22;
    undefined field318_0xd23;
    undefined field319_0xd24;
    undefined field320_0xd25;
    undefined field321_0xd26;
    undefined field322_0xd27;
    undefined field323_0xd28;
    undefined field324_0xd29;
    undefined field325_0xd2a;
    undefined field326_0xd2b;
    undefined field327_0xd2c;
    undefined field328_0xd2d;
    undefined field329_0xd2e;
    undefined field330_0xd2f;
    undefined field331_0xd30;
    undefined field332_0xd31;
    undefined field333_0xd32;
    undefined field334_0xd33;
    undefined field335_0xd34;
    undefined field336_0xd35;
    undefined field337_0xd36;
    undefined field338_0xd37;
    undefined field339_0xd38;
    undefined field340_0xd39;
    undefined field341_0xd3a;
    undefined field342_0xd3b;
    undefined field343_0xd3c;
    undefined field344_0xd3d;
    undefined field345_0xd3e;
    undefined field346_0xd3f;
    undefined field347_0xd40;
    undefined field348_0xd41;
    undefined field349_0xd42;
    undefined field350_0xd43;
    undefined field351_0xd44;
    undefined field352_0xd45;
    undefined field353_0xd46;
    undefined field354_0xd47;
    undefined field355_0xd48;
    undefined field356_0xd49;
    undefined field357_0xd4a;
    undefined field358_0xd4b;
    undefined field359_0xd4c;
    undefined field360_0xd4d;
    undefined field361_0xd4e;
    undefined field362_0xd4f;
    undefined field363_0xd50;
    undefined field364_0xd51;
    undefined field365_0xd52;
    undefined field366_0xd53;
    undefined field367_0xd54;
    undefined field368_0xd55;
    undefined field369_0xd56;
    undefined field370_0xd57;
    undefined field371_0xd58;
    undefined field372_0xd59;
    undefined field373_0xd5a;
    undefined field374_0xd5b;
    undefined field375_0xd5c;
    undefined field376_0xd5d;
    undefined field377_0xd5e;
    undefined field378_0xd5f;
    undefined field379_0xd60;
    undefined field380_0xd61;
    undefined field381_0xd62;
    undefined field382_0xd63;
    undefined field383_0xd64;
    undefined field384_0xd65;
    undefined field385_0xd66;
    undefined field386_0xd67;
    undefined field387_0xd68;
    undefined field388_0xd69;
    undefined field389_0xd6a;
    undefined field390_0xd6b;
    undefined field391_0xd6c;
    undefined field392_0xd6d;
    undefined field393_0xd6e;
    undefined field394_0xd6f;
    undefined field395_0xd70;
    undefined field396_0xd71;
    undefined field397_0xd72;
    undefined field398_0xd73;
    undefined field399_0xd74;
    undefined field400_0xd75;
    undefined field401_0xd76;
    undefined field402_0xd77;
    undefined field403_0xd78;
    undefined field404_0xd79;
    undefined field405_0xd7a;
    undefined field406_0xd7b;
    undefined field407_0xd7c;
    undefined field408_0xd7d;
    undefined field409_0xd7e;
    undefined field410_0xd7f;
    undefined field411_0xd80;
    undefined field412_0xd81;
    undefined field413_0xd82;
    undefined field414_0xd83;
    undefined field415_0xd84;
    undefined field416_0xd85;
    undefined field417_0xd86;
    undefined field418_0xd87;
    undefined field419_0xd88;
    undefined field420_0xd89;
    undefined field421_0xd8a;
    undefined field422_0xd8b;
    undefined field423_0xd8c;
    undefined field424_0xd8d;
    undefined field425_0xd8e;
    undefined field426_0xd8f;
    undefined field427_0xd90;
    undefined field428_0xd91;
    undefined field429_0xd92;
    undefined field430_0xd93;
    undefined field431_0xd94;
    undefined field432_0xd95;
    undefined field433_0xd96;
    undefined field434_0xd97;
    undefined field435_0xd98;
    undefined field436_0xd99;
    undefined field437_0xd9a;
    undefined field438_0xd9b;
    undefined field439_0xd9c;
    undefined field440_0xd9d;
    undefined field441_0xd9e;
    undefined field442_0xd9f;
    undefined field443_0xda0;
    undefined field444_0xda1;
    undefined field445_0xda2;
    undefined field446_0xda3;
    undefined field447_0xda4;
    undefined field448_0xda5;
    undefined field449_0xda6;
    undefined field450_0xda7;
    undefined field451_0xda8;
    undefined field452_0xda9;
    undefined field453_0xdaa;
    undefined field454_0xdab;
    undefined field455_0xdac;
    undefined field456_0xdad;
    undefined field457_0xdae;
    undefined field458_0xdaf;
    undefined field459_0xdb0;
    undefined field460_0xdb1;
    undefined field461_0xdb2;
    undefined field462_0xdb3;
    undefined field463_0xdb4;
    undefined field464_0xdb5;
    undefined field465_0xdb6;
    undefined field466_0xdb7;
    undefined field467_0xdb8;
    undefined field468_0xdb9;
    undefined field469_0xdba;
    undefined field470_0xdbb;
    undefined field471_0xdbc;
    undefined field472_0xdbd;
    undefined field473_0xdbe;
    undefined field474_0xdbf;
    undefined field475_0xdc0;
    undefined field476_0xdc1;
    undefined field477_0xdc2;
    undefined field478_0xdc3;
    undefined field479_0xdc4;
    undefined field480_0xdc5;
    undefined field481_0xdc6;
    undefined field482_0xdc7;
    undefined field483_0xdc8;
    undefined field484_0xdc9;
    undefined field485_0xdca;
    undefined field486_0xdcb;
    undefined field487_0xdcc;
    undefined field488_0xdcd;
    undefined field489_0xdce;
    undefined field490_0xdcf;
    undefined field491_0xdd0;
    undefined field492_0xdd1;
    undefined field493_0xdd2;
    undefined field494_0xdd3;
    undefined field495_0xdd4;
    undefined field496_0xdd5;
    undefined field497_0xdd6;
    undefined field498_0xdd7;
    undefined field499_0xdd8;
    undefined field500_0xdd9;
    undefined field501_0xdda;
    undefined field502_0xddb;
    undefined field503_0xddc;
    undefined field504_0xddd;
    undefined field505_0xdde;
    undefined field506_0xddf;
    undefined field507_0xde0;
    undefined field508_0xde1;
    undefined field509_0xde2;
    undefined field510_0xde3;
    undefined field511_0xde4;
    undefined field512_0xde5;
    undefined field513_0xde6;
    undefined field514_0xde7;
    undefined field515_0xde8;
    undefined field516_0xde9;
    undefined field517_0xdea;
    undefined field518_0xdeb;
    undefined field519_0xdec;
    undefined field520_0xded;
    undefined field521_0xdee;
    undefined field522_0xdef;
    undefined field523_0xdf0;
    undefined field524_0xdf1;
    undefined field525_0xdf2;
    undefined field526_0xdf3;
    undefined field527_0xdf4;
    undefined field528_0xdf5;
    undefined field529_0xdf6;
    undefined field530_0xdf7;
    undefined field531_0xdf8;
    undefined field532_0xdf9;
    undefined field533_0xdfa;
    undefined field534_0xdfb;
    undefined field535_0xdfc;
    undefined field536_0xdfd;
    undefined field537_0xdfe;
    undefined field538_0xdff;
    undefined field539_0xe00;
    undefined field540_0xe01;
    undefined field541_0xe02;
    undefined field542_0xe03;
    undefined field543_0xe04;
    undefined field544_0xe05;
    undefined field545_0xe06;
    undefined field546_0xe07;
    undefined field547_0xe08;
    undefined field548_0xe09;
    undefined field549_0xe0a;
    undefined field550_0xe0b;
    undefined field551_0xe0c;
    undefined field552_0xe0d;
    undefined field553_0xe0e;
    undefined field554_0xe0f;
    undefined field555_0xe10;
    undefined field556_0xe11;
    undefined field557_0xe12;
    undefined field558_0xe13;
    undefined field559_0xe14;
    undefined field560_0xe15;
    undefined field561_0xe16;
    undefined field562_0xe17;
    undefined field563_0xe18;
    undefined field564_0xe19;
    undefined field565_0xe1a;
    undefined field566_0xe1b;
    undefined field567_0xe1c;
    undefined field568_0xe1d;
    undefined field569_0xe1e;
    undefined field570_0xe1f;
    undefined field571_0xe20;
    undefined field572_0xe21;
    undefined field573_0xe22;
    undefined field574_0xe23;
    undefined field575_0xe24;
    undefined field576_0xe25;
    undefined field577_0xe26;
    undefined field578_0xe27;
    undefined field579_0xe28;
    undefined field580_0xe29;
    undefined field581_0xe2a;
    undefined field582_0xe2b;
    undefined field583_0xe2c;
    undefined field584_0xe2d;
    undefined field585_0xe2e;
    undefined field586_0xe2f;
    undefined field587_0xe30;
    undefined field588_0xe31;
    undefined field589_0xe32;
    undefined field590_0xe33;
    undefined field591_0xe34;
    undefined field592_0xe35;
    undefined field593_0xe36;
    undefined field594_0xe37;
    undefined field595_0xe38;
    undefined field596_0xe39;
    undefined field597_0xe3a;
    undefined field598_0xe3b;
    undefined field599_0xe3c;
    undefined field600_0xe3d;
    undefined field601_0xe3e;
    undefined field602_0xe3f;
    undefined field603_0xe40;
    undefined field604_0xe41;
    undefined field605_0xe42;
    undefined field606_0xe43;
    undefined field607_0xe44;
    undefined field608_0xe45;
    undefined field609_0xe46;
    undefined field610_0xe47;
    undefined field611_0xe48;
    undefined field612_0xe49;
    undefined field613_0xe4a;
    undefined field614_0xe4b;
    undefined field615_0xe4c;
    undefined field616_0xe4d;
    undefined field617_0xe4e;
    undefined field618_0xe4f;
    int field619_0xe50;
    undefined field620_0xe54;
    undefined field621_0xe55;
    undefined field622_0xe56;
    undefined field623_0xe57;
    undefined field624_0xe58;
    undefined field625_0xe59;
    undefined field626_0xe5a;
    undefined field627_0xe5b;
    undefined field628_0xe5c;
    undefined field629_0xe5d;
    undefined field630_0xe5e;
    undefined field631_0xe5f;
    undefined field632_0xe60;
    undefined field633_0xe61;
    undefined field634_0xe62;
    undefined field635_0xe63;
    undefined field636_0xe64;
    undefined field637_0xe65;
    undefined field638_0xe66;
    undefined field639_0xe67;
    undefined field640_0xe68;
    undefined field641_0xe69;
    undefined field642_0xe6a;
    undefined field643_0xe6b;
    undefined field644_0xe6c;
    undefined field645_0xe6d;
    undefined field646_0xe6e;
    undefined field647_0xe6f;
    int *field648_0xe70;
    int field649_0xe74;
    undefined field650_0xe78;
    undefined field651_0xe79;
    undefined field652_0xe7a;
    undefined field653_0xe7b;
    undefined field654_0xe7c;
    undefined field655_0xe7d;
    undefined field656_0xe7e;
    undefined field657_0xe7f;
    undefined field658_0xe80;
    undefined field659_0xe81;
    undefined field660_0xe82;
    undefined field661_0xe83;
    undefined field662_0xe84;
    undefined field663_0xe85;
    undefined field664_0xe86;
    undefined field665_0xe87;
    undefined field666_0xe88;
    undefined field667_0xe89;
    undefined field668_0xe8a;
    undefined field669_0xe8b;
    undefined field670_0xe8c;
    undefined field671_0xe8d;
    undefined field672_0xe8e;
    undefined field673_0xe8f;
    undefined field674_0xe90;
    undefined field675_0xe91;
    undefined field676_0xe92;
    undefined field677_0xe93;
    undefined field678_0xe94;
    undefined field679_0xe95;
    undefined field680_0xe96;
    undefined field681_0xe97;
    undefined field682_0xe98;
    undefined field683_0xe99;
    undefined field684_0xe9a;
    undefined field685_0xe9b;
    undefined field686_0xe9c;
    undefined field687_0xe9d;
    undefined field688_0xe9e;
    undefined field689_0xe9f;
    undefined field690_0xea0;
    undefined field691_0xea1;
    undefined field692_0xea2;
    undefined field693_0xea3;
    undefined field694_0xea4;
    undefined field695_0xea5;
    undefined field696_0xea6;
    undefined field697_0xea7;
    undefined field698_0xea8;
    undefined field699_0xea9;
    undefined field700_0xeaa;
    undefined field701_0xeab;
    undefined field702_0xeac;
    undefined field703_0xead;
    undefined field704_0xeae;
    undefined field705_0xeaf;
    undefined field706_0xeb0;
    undefined field707_0xeb1;
    undefined field708_0xeb2;
    undefined field709_0xeb3;
    undefined field710_0xeb4;
    undefined field711_0xeb5;
    undefined field712_0xeb6;
    undefined field713_0xeb7;
    undefined field714_0xeb8;
    undefined field715_0xeb9;
    undefined field716_0xeba;
    undefined field717_0xebb;
    undefined field718_0xebc;
    undefined field719_0xebd;
    undefined field720_0xebe;
    undefined field721_0xebf;
    undefined field722_0xec0;
    undefined field723_0xec1;
    undefined field724_0xec2;
    undefined field725_0xec3;
    undefined field726_0xec4;
    undefined field727_0xec5;
    undefined field728_0xec6;
    undefined field729_0xec7;
    undefined field730_0xec8;
    undefined field731_0xec9;
    undefined field732_0xeca;
    undefined field733_0xecb;
    undefined field734_0xecc;
    undefined field735_0xecd;
    undefined field736_0xece;
    undefined field737_0xecf;
    undefined field738_0xed0;
    undefined field739_0xed1;
    undefined field740_0xed2;
    undefined field741_0xed3;
    undefined field742_0xed4;
    undefined field743_0xed5;
    undefined field744_0xed6;
    undefined field745_0xed7;
    undefined field746_0xed8;
    undefined field747_0xed9;
    undefined field748_0xeda;
    undefined field749_0xedb;
    undefined field750_0xedc;
    undefined field751_0xedd;
    undefined field752_0xede;
    undefined field753_0xedf;
    undefined field754_0xee0;
    undefined field755_0xee1;
    undefined field756_0xee2;
    undefined field757_0xee3;
    undefined field758_0xee4;
    undefined field759_0xee5;
    undefined field760_0xee6;
    undefined field761_0xee7;
    undefined field762_0xee8;
    undefined field763_0xee9;
    undefined field764_0xeea;
    undefined field765_0xeeb;
    undefined field766_0xeec;
    undefined field767_0xeed;
    undefined field768_0xeee;
    undefined field769_0xeef;
    undefined field770_0xef0;
    undefined field771_0xef1;
    undefined field772_0xef2;
    undefined field773_0xef3;
    undefined field774_0xef4;
    undefined field775_0xef5;
    undefined field776_0xef6;
    undefined field777_0xef7;
    undefined field778_0xef8;
    undefined field779_0xef9;
    undefined field780_0xefa;
    undefined field781_0xefb;
    undefined field782_0xefc;
    undefined field783_0xefd;
    undefined field784_0xefe;
    undefined field785_0xeff;
    undefined field786_0xf00;
    undefined field787_0xf01;
    undefined field788_0xf02;
    undefined field789_0xf03;
    undefined field790_0xf04;
    undefined field791_0xf05;
    undefined field792_0xf06;
    undefined field793_0xf07;
    undefined field794_0xf08;
    undefined field795_0xf09;
    undefined field796_0xf0a;
    undefined field797_0xf0b;
    undefined field798_0xf0c;
    undefined field799_0xf0d;
    undefined field800_0xf0e;
    undefined field801_0xf0f;
    undefined field802_0xf10;
    undefined field803_0xf11;
    undefined field804_0xf12;
    undefined field805_0xf13;
    undefined field806_0xf14;
    undefined field807_0xf15;
    undefined field808_0xf16;
    undefined field809_0xf17;
    undefined field810_0xf18;
    undefined field811_0xf19;
    undefined field812_0xf1a;
    undefined field813_0xf1b;
    undefined field814_0xf1c;
    undefined field815_0xf1d;
    undefined field816_0xf1e;
    undefined field817_0xf1f;
    undefined field818_0xf20;
    undefined field819_0xf21;
    undefined field820_0xf22;
    undefined field821_0xf23;
    undefined field822_0xf24;
    undefined field823_0xf25;
    undefined field824_0xf26;
    undefined field825_0xf27;
    undefined field826_0xf28;
    undefined field827_0xf29;
    undefined field828_0xf2a;
    undefined field829_0xf2b;
    undefined field830_0xf2c;
    undefined field831_0xf2d;
    undefined field832_0xf2e;
    undefined field833_0xf2f;
    undefined field834_0xf30;
    undefined field835_0xf31;
    undefined field836_0xf32;
    undefined field837_0xf33;
    undefined field838_0xf34;
    undefined field839_0xf35;
    undefined field840_0xf36;
    undefined field841_0xf37;
    undefined field842_0xf38;
    undefined field843_0xf39;
    undefined field844_0xf3a;
    undefined field845_0xf3b;
    undefined field846_0xf3c;
    undefined field847_0xf3d;
    undefined field848_0xf3e;
    undefined field849_0xf3f;
    undefined field850_0xf40;
    undefined field851_0xf41;
    undefined field852_0xf42;
    undefined field853_0xf43;
    undefined field854_0xf44;
    undefined field855_0xf45;
    undefined field856_0xf46;
    undefined field857_0xf47;
    undefined field858_0xf48;
    undefined field859_0xf49;
    undefined field860_0xf4a;
    undefined field861_0xf4b;
    undefined field862_0xf4c;
    undefined field863_0xf4d;
    undefined field864_0xf4e;
    undefined field865_0xf4f;
    undefined field866_0xf50;
    undefined field867_0xf51;
    undefined field868_0xf52;
    undefined field869_0xf53;
    undefined field870_0xf54;
    undefined field871_0xf55;
    undefined field872_0xf56;
    undefined field873_0xf57;
    undefined field874_0xf58;
    undefined field875_0xf59;
    undefined field876_0xf5a;
    undefined field877_0xf5b;
    undefined field878_0xf5c;
    undefined field879_0xf5d;
    undefined field880_0xf5e;
    undefined field881_0xf5f;
    undefined field882_0xf60;
    undefined field883_0xf61;
    undefined field884_0xf62;
    undefined field885_0xf63;
    undefined field886_0xf64;
    undefined field887_0xf65;
    undefined field888_0xf66;
    undefined field889_0xf67;
    undefined field890_0xf68;
    undefined field891_0xf69;
    undefined field892_0xf6a;
    undefined field893_0xf6b;
    undefined field894_0xf6c;
    undefined field895_0xf6d;
    undefined field896_0xf6e;
    undefined field897_0xf6f;
    undefined field898_0xf70;
    undefined field899_0xf71;
    undefined field900_0xf72;
    undefined field901_0xf73;
    undefined field902_0xf74;
    undefined field903_0xf75;
    undefined field904_0xf76;
    undefined field905_0xf77;
    undefined field906_0xf78;
    undefined field907_0xf79;
    undefined field908_0xf7a;
    undefined field909_0xf7b;
    undefined field910_0xf7c;
    undefined field911_0xf7d;
    undefined field912_0xf7e;
    undefined field913_0xf7f;
    undefined field914_0xf80;
    undefined field915_0xf81;
    undefined field916_0xf82;
    undefined field917_0xf83;
    undefined field918_0xf84;
    undefined field919_0xf85;
    undefined field920_0xf86;
    undefined field921_0xf87;
    undefined field922_0xf88;
    undefined field923_0xf89;
    undefined field924_0xf8a;
    undefined field925_0xf8b;
    undefined field926_0xf8c;
    undefined field927_0xf8d;
    undefined field928_0xf8e;
    undefined field929_0xf8f;
    undefined field930_0xf90;
    undefined field931_0xf91;
    undefined field932_0xf92;
    undefined field933_0xf93;
    undefined field934_0xf94;
    undefined field935_0xf95;
    undefined field936_0xf96;
    undefined field937_0xf97;
    undefined field938_0xf98;
    undefined field939_0xf99;
    undefined field940_0xf9a;
    undefined field941_0xf9b;
    undefined field942_0xf9c;
    undefined field943_0xf9d;
    undefined field944_0xf9e;
    undefined field945_0xf9f;
    undefined field946_0xfa0;
    undefined field947_0xfa1;
    undefined field948_0xfa2;
    undefined field949_0xfa3;
    undefined field950_0xfa4;
    undefined field951_0xfa5;
    undefined field952_0xfa6;
    undefined field953_0xfa7;
    undefined field954_0xfa8;
    undefined field955_0xfa9;
    undefined field956_0xfaa;
    undefined field957_0xfab;
    undefined field958_0xfac;
    undefined field959_0xfad;
    undefined field960_0xfae;
    undefined field961_0xfaf;
    undefined field962_0xfb0;
    undefined field963_0xfb1;
    undefined field964_0xfb2;
    undefined field965_0xfb3;
    undefined field966_0xfb4;
    undefined field967_0xfb5;
    undefined field968_0xfb6;
    undefined field969_0xfb7;
    undefined field970_0xfb8;
    undefined field971_0xfb9;
    undefined field972_0xfba;
    undefined field973_0xfbb;
    undefined field974_0xfbc;
    undefined field975_0xfbd;
    undefined field976_0xfbe;
    undefined field977_0xfbf;
    undefined field978_0xfc0;
    undefined field979_0xfc1;
    undefined field980_0xfc2;
    undefined field981_0xfc3;
    undefined field982_0xfc4;
    undefined field983_0xfc5;
    undefined field984_0xfc6;
    undefined field985_0xfc7;
    undefined field986_0xfc8;
    undefined field987_0xfc9;
    undefined field988_0xfca;
    undefined field989_0xfcb;
    undefined field990_0xfcc;
    undefined field991_0xfcd;
    undefined field992_0xfce;
    undefined field993_0xfcf;
    undefined field994_0xfd0;
    undefined field995_0xfd1;
    undefined field996_0xfd2;
    undefined field997_0xfd3;
    undefined field998_0xfd4;
    undefined field999_0xfd5;
    undefined field1000_0xfd6;
    undefined field1001_0xfd7;
    undefined field1002_0xfd8;
    undefined field1003_0xfd9;
    undefined field1004_0xfda;
    undefined field1005_0xfdb;
    undefined field1006_0xfdc;
    undefined field1007_0xfdd;
    undefined field1008_0xfde;
    undefined field1009_0xfdf;
    undefined field1010_0xfe0;
    undefined field1011_0xfe1;
    undefined field1012_0xfe2;
    undefined field1013_0xfe3;
    undefined field1014_0xfe4;
    undefined field1015_0xfe5;
    undefined field1016_0xfe6;
    undefined field1017_0xfe7;
    undefined field1018_0xfe8;
    undefined field1019_0xfe9;
    undefined field1020_0xfea;
    undefined field1021_0xfeb;
    undefined field1022_0xfec;
    undefined field1023_0xfed;
    undefined field1024_0xfee;
    undefined field1025_0xfef;
    undefined field1026_0xff0;
    undefined field1027_0xff1;
    undefined field1028_0xff2;
    undefined field1029_0xff3;
    undefined field1030_0xff4;
    undefined field1031_0xff5;
    undefined field1032_0xff6;
    undefined field1033_0xff7;
    undefined field1034_0xff8;
    undefined field1035_0xff9;
    undefined field1036_0xffa;
    undefined field1037_0xffb;
    undefined field1038_0xffc;
    undefined field1039_0xffd;
    undefined field1040_0xffe;
    undefined field1041_0xfff;
    undefined field1042_0x1000;
    undefined field1043_0x1001;
    undefined field1044_0x1002;
    undefined field1045_0x1003;
    undefined field1046_0x1004;
    undefined field1047_0x1005;
    undefined field1048_0x1006;
    undefined field1049_0x1007;
    undefined field1050_0x1008;
    undefined field1051_0x1009;
    undefined field1052_0x100a;
    undefined field1053_0x100b;
    undefined field1054_0x100c;
    undefined field1055_0x100d;
    undefined field1056_0x100e;
    undefined field1057_0x100f;
    undefined field1058_0x1010;
    undefined field1059_0x1011;
    undefined field1060_0x1012;
    undefined field1061_0x1013;
    undefined field1062_0x1014;
    undefined field1063_0x1015;
    undefined field1064_0x1016;
    undefined field1065_0x1017;
    undefined field1066_0x1018;
    undefined field1067_0x1019;
    undefined field1068_0x101a;
    undefined field1069_0x101b;
    undefined field1070_0x101c;
    undefined field1071_0x101d;
    undefined field1072_0x101e;
    undefined field1073_0x101f;
    undefined field1074_0x1020;
    undefined field1075_0x1021;
    undefined field1076_0x1022;
    undefined field1077_0x1023;
    undefined field1078_0x1024;
    undefined field1079_0x1025;
    undefined field1080_0x1026;
    undefined field1081_0x1027;
    undefined field1082_0x1028;
    undefined field1083_0x1029;
    undefined field1084_0x102a;
    undefined field1085_0x102b;
    undefined field1086_0x102c;
    undefined field1087_0x102d;
    undefined field1088_0x102e;
    undefined field1089_0x102f;
    undefined field1090_0x1030;
    undefined field1091_0x1031;
    undefined field1092_0x1032;
    undefined field1093_0x1033;
    undefined field1094_0x1034;
    undefined field1095_0x1035;
    undefined field1096_0x1036;
    undefined field1097_0x1037;
    undefined field1098_0x1038;
    undefined field1099_0x1039;
    undefined field1100_0x103a;
    undefined field1101_0x103b;
    undefined field1102_0x103c;
    undefined field1103_0x103d;
    undefined field1104_0x103e;
    undefined field1105_0x103f;
    undefined field1106_0x1040;
    undefined field1107_0x1041;
    undefined field1108_0x1042;
    undefined field1109_0x1043;
    undefined field1110_0x1044;
    undefined field1111_0x1045;
    undefined field1112_0x1046;
    undefined field1113_0x1047;
    undefined field1114_0x1048;
    undefined field1115_0x1049;
    undefined field1116_0x104a;
    undefined field1117_0x104b;
    undefined field1118_0x104c;
    undefined field1119_0x104d;
    undefined field1120_0x104e;
    undefined field1121_0x104f;
    undefined field1122_0x1050;
    undefined field1123_0x1051;
    undefined field1124_0x1052;
    undefined field1125_0x1053;
    undefined field1126_0x1054;
    undefined field1127_0x1055;
    undefined field1128_0x1056;
    undefined field1129_0x1057;
    undefined field1130_0x1058;
    undefined field1131_0x1059;
    undefined field1132_0x105a;
    undefined field1133_0x105b;
    undefined field1134_0x105c;
    undefined field1135_0x105d;
    undefined field1136_0x105e;
    undefined field1137_0x105f;
    undefined field1138_0x1060;
    undefined field1139_0x1061;
    undefined field1140_0x1062;
    undefined field1141_0x1063;
    undefined field1142_0x1064;
    undefined field1143_0x1065;
    undefined field1144_0x1066;
    undefined field1145_0x1067;
    undefined field1146_0x1068;
    undefined field1147_0x1069;
    undefined field1148_0x106a;
    undefined field1149_0x106b;
    undefined field1150_0x106c;
    undefined field1151_0x106d;
    undefined field1152_0x106e;
    undefined field1153_0x106f;
    undefined field1154_0x1070;
    undefined field1155_0x1071;
    undefined field1156_0x1072;
    undefined field1157_0x1073;
    undefined field1158_0x1074;
    undefined field1159_0x1075;
    undefined field1160_0x1076;
    undefined field1161_0x1077;
    undefined field1162_0x1078;
    undefined field1163_0x1079;
    undefined field1164_0x107a;
    undefined field1165_0x107b;
    int field1166_0x107c;
    undefined field1167_0x1080;
    undefined field1168_0x1081;
    undefined field1169_0x1082;
    undefined field1170_0x1083;
    undefined field1171_0x1084;
    undefined field1172_0x1085;
    undefined field1173_0x1086;
    undefined field1174_0x1087;
    undefined field1175_0x1088;
    undefined field1176_0x1089;
    undefined field1177_0x108a;
    undefined field1178_0x108b;
    undefined field1179_0x108c;
    undefined field1180_0x108d;
    undefined field1181_0x108e;
    undefined field1182_0x108f;
    undefined field1183_0x1090;
    undefined field1184_0x1091;
    undefined field1185_0x1092;
    undefined field1186_0x1093;
    undefined field1187_0x1094;
    undefined field1188_0x1095;
    undefined field1189_0x1096;
    undefined field1190_0x1097;
    undefined field1191_0x1098;
    undefined field1192_0x1099;
    undefined field1193_0x109a;
    undefined field1194_0x109b;
    int *field1195_0x109c;
    int field1196_0x10a0;
    undefined field1197_0x10a4;
    undefined field1198_0x10a5;
    undefined field1199_0x10a6;
    undefined field1200_0x10a7;
    undefined field1201_0x10a8;
    undefined field1202_0x10a9;
    undefined field1203_0x10aa;
    undefined field1204_0x10ab;
    undefined field1205_0x10ac;
    undefined field1206_0x10ad;
    undefined field1207_0x10ae;
    undefined field1208_0x10af;
    undefined field1209_0x10b0;
    undefined field1210_0x10b1;
    undefined field1211_0x10b2;
    undefined field1212_0x10b3;
    undefined field1213_0x10b4;
    undefined field1214_0x10b5;
    undefined field1215_0x10b6;
    undefined field1216_0x10b7;
    undefined field1217_0x10b8;
    undefined field1218_0x10b9;
    undefined field1219_0x10ba;
    undefined field1220_0x10bb;
    undefined field1221_0x10bc;
    undefined field1222_0x10bd;
    undefined field1223_0x10be;
    undefined field1224_0x10bf;
    undefined field1225_0x10c0;
    undefined field1226_0x10c1;
    undefined field1227_0x10c2;
    undefined field1228_0x10c3;
    undefined field1229_0x10c4;
    undefined field1230_0x10c5;
    undefined field1231_0x10c6;
    undefined field1232_0x10c7;
    undefined field1233_0x10c8;
    undefined field1234_0x10c9;
    undefined field1235_0x10ca;
    undefined field1236_0x10cb;
    undefined field1237_0x10cc;
    undefined field1238_0x10cd;
    undefined field1239_0x10ce;
    undefined field1240_0x10cf;
    undefined field1241_0x10d0;
    undefined field1242_0x10d1;
    undefined field1243_0x10d2;
    undefined field1244_0x10d3;
    undefined field1245_0x10d4;
    undefined field1246_0x10d5;
    undefined field1247_0x10d6;
    undefined field1248_0x10d7;
    undefined field1249_0x10d8;
    undefined field1250_0x10d9;
    undefined field1251_0x10da;
    undefined field1252_0x10db;
    undefined field1253_0x10dc;
    undefined field1254_0x10dd;
    undefined field1255_0x10de;
    undefined field1256_0x10df;
    undefined field1257_0x10e0;
    undefined field1258_0x10e1;
    undefined field1259_0x10e2;
    undefined field1260_0x10e3;
    undefined field1261_0x10e4;
    undefined field1262_0x10e5;
    undefined field1263_0x10e6;
    undefined field1264_0x10e7;
    undefined field1265_0x10e8;
    undefined field1266_0x10e9;
    undefined field1267_0x10ea;
    undefined field1268_0x10eb;
    undefined field1269_0x10ec;
    undefined field1270_0x10ed;
    undefined field1271_0x10ee;
    undefined field1272_0x10ef;
    undefined field1273_0x10f0;
    undefined field1274_0x10f1;
    undefined field1275_0x10f2;
    undefined field1276_0x10f3;
    undefined field1277_0x10f4;
    undefined field1278_0x10f5;
    undefined field1279_0x10f6;
    undefined field1280_0x10f7;
    undefined field1281_0x10f8;
    undefined field1282_0x10f9;
    undefined field1283_0x10fa;
    undefined field1284_0x10fb;
    undefined field1285_0x10fc;
    undefined field1286_0x10fd;
    undefined field1287_0x10fe;
    undefined field1288_0x10ff;
    undefined field1289_0x1100;
    undefined field1290_0x1101;
    undefined field1291_0x1102;
    undefined field1292_0x1103;
    undefined field1293_0x1104;
    undefined field1294_0x1105;
    undefined field1295_0x1106;
    undefined field1296_0x1107;
    undefined field1297_0x1108;
    undefined field1298_0x1109;
    undefined field1299_0x110a;
    undefined field1300_0x110b;
    undefined field1301_0x110c;
    undefined field1302_0x110d;
    undefined field1303_0x110e;
    undefined field1304_0x110f;
    undefined field1305_0x1110;
    undefined field1306_0x1111;
    undefined field1307_0x1112;
    undefined field1308_0x1113;
    undefined field1309_0x1114;
    undefined field1310_0x1115;
    undefined field1311_0x1116;
    undefined field1312_0x1117;
    undefined field1313_0x1118;
    undefined field1314_0x1119;
    undefined field1315_0x111a;
    undefined field1316_0x111b;
    undefined field1317_0x111c;
    undefined field1318_0x111d;
    undefined field1319_0x111e;
    undefined field1320_0x111f;
    undefined field1321_0x1120;
    undefined field1322_0x1121;
    undefined field1323_0x1122;
    undefined field1324_0x1123;
    undefined field1325_0x1124;
    undefined field1326_0x1125;
    undefined field1327_0x1126;
    undefined field1328_0x1127;
    undefined field1329_0x1128;
    undefined field1330_0x1129;
    undefined field1331_0x112a;
    undefined field1332_0x112b;
    undefined field1333_0x112c;
    undefined field1334_0x112d;
    undefined field1335_0x112e;
    undefined field1336_0x112f;
    undefined field1337_0x1130;
    undefined field1338_0x1131;
    undefined field1339_0x1132;
    undefined field1340_0x1133;
    undefined field1341_0x1134;
    undefined field1342_0x1135;
    undefined field1343_0x1136;
    undefined field1344_0x1137;
    undefined field1345_0x1138;
    undefined field1346_0x1139;
    undefined field1347_0x113a;
    undefined field1348_0x113b;
    undefined field1349_0x113c;
    undefined field1350_0x113d;
    undefined field1351_0x113e;
    undefined field1352_0x113f;
    undefined field1353_0x1140;
    undefined field1354_0x1141;
    undefined field1355_0x1142;
    undefined field1356_0x1143;
    undefined field1357_0x1144;
    undefined field1358_0x1145;
    undefined field1359_0x1146;
    undefined field1360_0x1147;
    undefined field1361_0x1148;
    undefined field1362_0x1149;
    undefined field1363_0x114a;
    undefined field1364_0x114b;
    undefined field1365_0x114c;
    undefined field1366_0x114d;
    undefined field1367_0x114e;
    undefined field1368_0x114f;
    undefined field1369_0x1150;
    undefined field1370_0x1151;
    undefined field1371_0x1152;
    undefined field1372_0x1153;
    undefined field1373_0x1154;
    undefined field1374_0x1155;
    undefined field1375_0x1156;
    undefined field1376_0x1157;
    undefined field1377_0x1158;
    undefined field1378_0x1159;
    undefined field1379_0x115a;
    undefined field1380_0x115b;
    undefined field1381_0x115c;
    undefined field1382_0x115d;
    undefined field1383_0x115e;
    undefined field1384_0x115f;
    undefined field1385_0x1160;
    undefined field1386_0x1161;
    undefined field1387_0x1162;
    undefined field1388_0x1163;
    undefined field1389_0x1164;
    undefined field1390_0x1165;
    undefined field1391_0x1166;
    undefined field1392_0x1167;
    undefined field1393_0x1168;
    undefined field1394_0x1169;
    undefined field1395_0x116a;
    undefined field1396_0x116b;
    undefined field1397_0x116c;
    undefined field1398_0x116d;
    undefined field1399_0x116e;
    undefined field1400_0x116f;
    undefined field1401_0x1170;
    undefined field1402_0x1171;
    undefined field1403_0x1172;
    undefined field1404_0x1173;
    undefined field1405_0x1174;
    undefined field1406_0x1175;
    undefined field1407_0x1176;
    undefined field1408_0x1177;
    undefined field1409_0x1178;
    undefined field1410_0x1179;
    undefined field1411_0x117a;
    undefined field1412_0x117b;
    undefined field1413_0x117c;
    undefined field1414_0x117d;
    undefined field1415_0x117e;
    undefined field1416_0x117f;
    undefined field1417_0x1180;
    undefined field1418_0x1181;
    undefined field1419_0x1182;
    undefined field1420_0x1183;
    undefined field1421_0x1184;
    undefined field1422_0x1185;
    undefined field1423_0x1186;
    undefined field1424_0x1187;
    undefined field1425_0x1188;
    undefined field1426_0x1189;
    undefined field1427_0x118a;
    undefined field1428_0x118b;
    undefined field1429_0x118c;
    undefined field1430_0x118d;
    undefined field1431_0x118e;
    undefined field1432_0x118f;
    undefined field1433_0x1190;
    undefined field1434_0x1191;
    undefined field1435_0x1192;
    undefined field1436_0x1193;
    undefined field1437_0x1194;
    undefined field1438_0x1195;
    undefined field1439_0x1196;
    undefined field1440_0x1197;
    undefined field1441_0x1198;
    undefined field1442_0x1199;
    undefined field1443_0x119a;
    undefined field1444_0x119b;
    undefined field1445_0x119c;
    undefined field1446_0x119d;
    undefined field1447_0x119e;
    undefined field1448_0x119f;
    undefined field1449_0x11a0;
    undefined field1450_0x11a1;
    undefined field1451_0x11a2;
    undefined field1452_0x11a3;
    undefined field1453_0x11a4;
    undefined field1454_0x11a5;
    undefined field1455_0x11a6;
    undefined field1456_0x11a7;
    undefined field1457_0x11a8;
    undefined field1458_0x11a9;
    undefined field1459_0x11aa;
    undefined field1460_0x11ab;
    undefined field1461_0x11ac;
    undefined field1462_0x11ad;
    undefined field1463_0x11ae;
    undefined field1464_0x11af;
    undefined field1465_0x11b0;
    undefined field1466_0x11b1;
    undefined field1467_0x11b2;
    undefined field1468_0x11b3;
    undefined field1469_0x11b4;
    undefined field1470_0x11b5;
    undefined field1471_0x11b6;
    undefined field1472_0x11b7;
    undefined field1473_0x11b8;
    undefined field1474_0x11b9;
    undefined field1475_0x11ba;
    undefined field1476_0x11bb;
    undefined field1477_0x11bc;
    undefined field1478_0x11bd;
    undefined field1479_0x11be;
    undefined field1480_0x11bf;
    undefined field1481_0x11c0;
    undefined field1482_0x11c1;
    undefined field1483_0x11c2;
    undefined field1484_0x11c3;
    undefined field1485_0x11c4;
    undefined field1486_0x11c5;
    undefined field1487_0x11c6;
    undefined field1488_0x11c7;
    undefined field1489_0x11c8;
    undefined field1490_0x11c9;
    undefined field1491_0x11ca;
    undefined field1492_0x11cb;
    undefined field1493_0x11cc;
    undefined field1494_0x11cd;
    undefined field1495_0x11ce;
    undefined field1496_0x11cf;
    undefined field1497_0x11d0;
    undefined field1498_0x11d1;
    undefined field1499_0x11d2;
    undefined field1500_0x11d3;
    undefined field1501_0x11d4;
    undefined field1502_0x11d5;
    undefined field1503_0x11d6;
    undefined field1504_0x11d7;
    undefined field1505_0x11d8;
    undefined field1506_0x11d9;
    undefined field1507_0x11da;
    undefined field1508_0x11db;
    undefined field1509_0x11dc;
    undefined field1510_0x11dd;
    undefined field1511_0x11de;
    undefined field1512_0x11df;
    undefined field1513_0x11e0;
    undefined field1514_0x11e1;
    undefined field1515_0x11e2;
    undefined field1516_0x11e3;
    undefined field1517_0x11e4;
    undefined field1518_0x11e5;
    undefined field1519_0x11e6;
    undefined field1520_0x11e7;
    undefined field1521_0x11e8;
    undefined field1522_0x11e9;
    undefined field1523_0x11ea;
    undefined field1524_0x11eb;
    undefined field1525_0x11ec;
    undefined field1526_0x11ed;
    undefined field1527_0x11ee;
    undefined field1528_0x11ef;
    undefined field1529_0x11f0;
    undefined field1530_0x11f1;
    undefined field1531_0x11f2;
    undefined field1532_0x11f3;
    undefined field1533_0x11f4;
    undefined field1534_0x11f5;
    undefined field1535_0x11f6;
    undefined field1536_0x11f7;
    undefined field1537_0x11f8;
    undefined field1538_0x11f9;
    undefined field1539_0x11fa;
    undefined field1540_0x11fb;
    undefined field1541_0x11fc;
    undefined field1542_0x11fd;
    undefined field1543_0x11fe;
    undefined field1544_0x11ff;
    undefined field1545_0x1200;
    undefined field1546_0x1201;
    undefined field1547_0x1202;
    undefined field1548_0x1203;
    undefined field1549_0x1204;
    undefined field1550_0x1205;
    undefined field1551_0x1206;
    undefined field1552_0x1207;
    undefined field1553_0x1208;
    undefined field1554_0x1209;
    undefined field1555_0x120a;
    undefined field1556_0x120b;
    undefined field1557_0x120c;
    undefined field1558_0x120d;
    undefined field1559_0x120e;
    undefined field1560_0x120f;
    undefined field1561_0x1210;
    undefined field1562_0x1211;
    undefined field1563_0x1212;
    undefined field1564_0x1213;
    undefined field1565_0x1214;
    undefined field1566_0x1215;
    undefined field1567_0x1216;
    undefined field1568_0x1217;
    undefined field1569_0x1218;
    undefined field1570_0x1219;
    undefined field1571_0x121a;
    undefined field1572_0x121b;
    undefined field1573_0x121c;
    undefined field1574_0x121d;
    undefined field1575_0x121e;
    undefined field1576_0x121f;
    undefined field1577_0x1220;
    undefined field1578_0x1221;
    undefined field1579_0x1222;
    undefined field1580_0x1223;
    undefined field1581_0x1224;
    undefined field1582_0x1225;
    undefined field1583_0x1226;
    undefined field1584_0x1227;
    undefined field1585_0x1228;
    undefined field1586_0x1229;
    undefined field1587_0x122a;
    undefined field1588_0x122b;
    undefined field1589_0x122c;
    undefined field1590_0x122d;
    undefined field1591_0x122e;
    undefined field1592_0x122f;
    undefined field1593_0x1230;
    undefined field1594_0x1231;
    undefined field1595_0x1232;
    undefined field1596_0x1233;
    undefined field1597_0x1234;
    undefined field1598_0x1235;
    undefined field1599_0x1236;
    undefined field1600_0x1237;
    undefined field1601_0x1238;
    undefined field1602_0x1239;
    undefined field1603_0x123a;
    undefined field1604_0x123b;
    undefined field1605_0x123c;
    undefined field1606_0x123d;
    undefined field1607_0x123e;
    undefined field1608_0x123f;
    undefined field1609_0x1240;
    undefined field1610_0x1241;
    undefined field1611_0x1242;
    undefined field1612_0x1243;
    undefined field1613_0x1244;
    undefined field1614_0x1245;
    undefined field1615_0x1246;
    undefined field1616_0x1247;
    undefined field1617_0x1248;
    undefined field1618_0x1249;
    undefined field1619_0x124a;
    undefined field1620_0x124b;
    undefined field1621_0x124c;
    undefined field1622_0x124d;
    undefined field1623_0x124e;
    undefined field1624_0x124f;
    undefined field1625_0x1250;
    undefined field1626_0x1251;
    undefined field1627_0x1252;
    undefined field1628_0x1253;
    undefined field1629_0x1254;
    undefined field1630_0x1255;
    undefined field1631_0x1256;
    undefined field1632_0x1257;
    undefined field1633_0x1258;
    undefined field1634_0x1259;
    undefined field1635_0x125a;
    undefined field1636_0x125b;
    undefined field1637_0x125c;
    undefined field1638_0x125d;
    undefined field1639_0x125e;
    undefined field1640_0x125f;
    undefined field1641_0x1260;
    undefined field1642_0x1261;
    undefined field1643_0x1262;
    undefined field1644_0x1263;
    undefined field1645_0x1264;
    undefined field1646_0x1265;
    undefined field1647_0x1266;
    undefined field1648_0x1267;
    undefined field1649_0x1268;
    undefined field1650_0x1269;
    undefined field1651_0x126a;
    undefined field1652_0x126b;
    undefined field1653_0x126c;
    undefined field1654_0x126d;
    undefined field1655_0x126e;
    undefined field1656_0x126f;
    undefined field1657_0x1270;
    undefined field1658_0x1271;
    undefined field1659_0x1272;
    undefined field1660_0x1273;
    undefined field1661_0x1274;
    undefined field1662_0x1275;
    undefined field1663_0x1276;
    undefined field1664_0x1277;
    undefined field1665_0x1278;
    undefined field1666_0x1279;
    undefined field1667_0x127a;
    undefined field1668_0x127b;
    undefined field1669_0x127c;
    undefined field1670_0x127d;
    undefined field1671_0x127e;
    undefined field1672_0x127f;
    undefined field1673_0x1280;
    undefined field1674_0x1281;
    undefined field1675_0x1282;
    undefined field1676_0x1283;
    undefined field1677_0x1284;
    undefined field1678_0x1285;
    undefined field1679_0x1286;
    undefined field1680_0x1287;
    undefined field1681_0x1288;
    undefined field1682_0x1289;
    undefined field1683_0x128a;
    undefined field1684_0x128b;
    undefined field1685_0x128c;
    undefined field1686_0x128d;
    undefined field1687_0x128e;
    undefined field1688_0x128f;
    undefined field1689_0x1290;
    undefined field1690_0x1291;
    undefined field1691_0x1292;
    undefined field1692_0x1293;
    undefined field1693_0x1294;
    undefined field1694_0x1295;
    undefined field1695_0x1296;
    undefined field1696_0x1297;
    undefined field1697_0x1298;
    undefined field1698_0x1299;
    undefined field1699_0x129a;
    undefined field1700_0x129b;
    undefined field1701_0x129c;
    undefined field1702_0x129d;
    undefined field1703_0x129e;
    undefined field1704_0x129f;
    undefined field1705_0x12a0;
    undefined field1706_0x12a1;
    undefined field1707_0x12a2;
    undefined field1708_0x12a3;
    undefined field1709_0x12a4;
    undefined field1710_0x12a5;
    undefined field1711_0x12a6;
    undefined field1712_0x12a7;
    int field1713_0x12a8;
    undefined field1714_0x12ac;
    undefined field1715_0x12ad;
    undefined field1716_0x12ae;
    undefined field1717_0x12af;
    undefined field1718_0x12b0;
    undefined field1719_0x12b1;
    undefined field1720_0x12b2;
    undefined field1721_0x12b3;
    undefined field1722_0x12b4;
    undefined field1723_0x12b5;
    undefined field1724_0x12b6;
    undefined field1725_0x12b7;
    undefined field1726_0x12b8;
    undefined field1727_0x12b9;
    undefined field1728_0x12ba;
    undefined field1729_0x12bb;
    undefined field1730_0x12bc;
    undefined field1731_0x12bd;
    undefined field1732_0x12be;
    undefined field1733_0x12bf;
    undefined field1734_0x12c0;
    undefined field1735_0x12c1;
    undefined field1736_0x12c2;
    undefined field1737_0x12c3;
    undefined field1738_0x12c4;
    undefined field1739_0x12c5;
    undefined field1740_0x12c6;
    undefined field1741_0x12c7;
    int field1742_0x12c8;
    int field1743_0x12cc;
    int field1744_0x12d0;
    int field1745_0x12d4;
    int field1746_0x12d8;
    int field1747_0x12dc;
    int field1748_0x12e0;
    int field1749_0x12e4;
    // May be larger!
};

ASSERT_SIZE(struct battle_struct, 4840);


#include "ranger_data.h"

struct save_header {
    char game_mark[0x8];    // 0x0: For this game, is DSPRS
    int main_save_0_offset; // 0x8: Should be 0x1C
    int main_save_1_offset; // 0xC: Should be 0x949E
    int checksum;           // 0x10
    int newest_save_index;  // 0x14: 00 = main_save_0, 01 = main_save_1, 02+ unknown.
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
};

ASSERT_SIZE(struct save_header, 28);

struct save_data {
    struct ranger_data ranger_data_struct; // 0x0
    // Of the 30 pokemon slots, only the first 8 of each group are stored in the save file...
    struct pokemon_data party_group_0[8]; // 0x8804
    struct pokemon_data party_group_1[8]; // 0x88C4
    struct pokemon_data party_group_2[8]; // 0x8984
    struct following_npc follower_1;      // 0x8A44
    struct following_npc follower_2;      // 0x8A7C
    struct quest_body quest_body;         // 0x8AB4
    // Consists of event flags,
    struct settings_and_variables settings_and_variables; // 0x8B08
    undefined unk_field_0x8c04[96];                       // 0x8C04: Permanent home is 0x210C1C0
    struct battle_init battle_init;                       // 0x8C64: Permanent home is 0x210C228
    undefined unk_field_0x9464[4];                        // 0x9464: Permanent home is 0x208B5C0
    undefined unk_field_0x9468[8];                        // 0x9468: Permanent home is 0x20AF5E4
    undefined unk_field_0x9470[8];                        // 0x9470: Permanent home is 0x20AF5F8
    undefined unk_field_0x9478[8];                        // 0x9478: Permanent home is 0x20AF60C
    int16_t ranger_net_completion_bits;                   // 0x9480
    undefined unk_field_0x9482;
    undefined unk_field_0x9483;
};

ASSERT_SIZE(struct save_data, 38020);

struct save_file {
    struct save_header main_save_header;  // 0x0
    struct save_data main_save_0;         // 0x1C
    struct save_data main_save_1;         // 0x94A0
    struct save_header quick_save_header; // 0x12924: Should be zeroed if quicksave not active.
    struct save_data quick_save; // 0x12940: So far, no reason to believe different from main save.
    int8_t ranger_net_mission1[0x3020]; // 0x1BDC4
    int8_t ranger_net_mission2[0x3020]; // 0x1EDE4
    int8_t ranger_net_mission3[0x3020]; // 0x21E04
    int8_t ranger_net_mission4[0x3020]; // 0x24E24
    int8_t ranger_net_mission5[0x3020]; // 0x27E44
    int8_t ranger_net_mission6[0x3020]; // 0x2AE64
};
ASSERT_SIZE(struct save_file, 188036);

#endif
