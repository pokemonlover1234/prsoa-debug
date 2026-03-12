# Other Resources
Reverse engineering _Shadows of Almia_ requires multiple skills in varying degrees. If you're a complete beginner and just want a single resource to start with, I recommend working through AnonymousRandomPerson's [_Reverse Engineering a DS Game_](https://www.starcubelabs.com/reverse-engineering-ds/), which walks through the basics of reverse engineering using _Explorers of Sky_ as an example.

If you're looking for more granular resources on specific topics, here's a breakdown of some of the individual skills involved in reverse engineering, with relevant links:
- How to read assembly, and enough low-level knowledge of computers to understand that assembly.
    - For SoA, there are technically _two_ forms of assembly you need to know, ARM and THUMB, although they're extremely similar, and for the most part you only need to know ARM. If you're just getting started, [this guide](https://forums.therockmanexezone.com/intro-to-asm-modding-hooking-t5374.html) is a great introduction to the concepts needed to read assembly, and [this guide](https://www.coranac.com/tonc/text/asm.htm) is a fantastic reference and introduction to the finer details of ARM assembly.
- Other systems-level knowledge of the Nintendo DS.
    - Working with the SoA binaries requires you to have some specialized knowledge (but it depends on what you're doing). One of the biggest things to know about is probably the [overlay system](overlays.md). If you're working with anything graphical, there are additional concepts you'll need to know, such as the OAM ([this series of posts](https://macabeus.medium.com/reverse-engineering-a-gameboy-advance-game-introduction-ec185bd8e02) is a great introduction to these concepts for the Game Boy Advance, most of which are also relevant to the NDS).
- What reverse engineering tools are available, and how to use them properly.
    - See [General reverse engineering](#general-reverse-engineering) for some suggestions.
    - With SoA, one of the biggest obstacles when starting out is figuring out how to even [set up a project properly](ghidra-setup.md), because it's unfortunately not as simple as importing the whole ROM with one button.

## General reverse engineering
If you want to learn about general reverse engineering, you can Google around for various resources. If you want some concrete links, check out [wtsxDev/reverse-engineering](https://github.com/wtsxDev/reverse-engineering) and [r/ReverseEngineering](https://www.reddit.com/r/ReverseEngineering/).

Project Pokémon has a [list of reverse engineering tools](https://projectpokemon.org/home/forums/topic/39011-rom-hacking-tool-and-resource-collection/?tab=comments#comment-204182) specifically geared towards NDS ROM hacking. GBATEK also has a [full technical reference dump](https://problemkaputt.de/gbatek.htm#ndsreference), which can be useful in very specific circumstances.

## A personal list of research tools
This is a list of tools that UsernameFodder has suggested for NDS research that might prove helpful to some people. Keep in mind that this list won't be suited for all use cases.

- [Ghidra](https://ghidra-sre.org/) (cross-platform) for the majority of asm research, since it's free and has one of the best decompilers out there. It has [built-in tutorials](https://github.com/NationalSecurityAgency/ghidra/tree/master/GhidraDocs/GhidraClass) ([HTML preview of the beginner class](https://htmlpreview.github.io/?https://github.com/NationalSecurityAgency/ghidra/blob/stable/GhidraDocs/GhidraClass/Beginner/Introduction_to_Ghidra_Student_Guide.html)). The other well known binary analysis tool is IDA, which you need to pay for (for ARM binaries). If you're a licensed IDA user, you probably don't need to be reading these docs anyway.
- [DeSmuME](https://desmume.org/) on Windows for watching memory at runtime (unfortunately only the Windows version has these tools at the time of writing). I find its memory viewer/editor (Tools > View Memory) and RAM Search (Tools > RAM Search...) tools particularly useful.
- [No$GBA](https://www.nogba.com/) (Windows only) for interactive debugging. However, I've found this emulator to be relatively unstable, and I try to avoid using it unless there's no other option.
- [DSLazy](https://projectpokemon.org/home/files/file/2118-dslazy/) (Windows only) for unpacking NDS ROMs, since it's the simplest thing with a GUI that works. It's a wrapper around [`ndstool`](https://github.com/devkitPro/ndstool), which is cross-platform. See the [Ghidra setup doc](ghidra-setup.md#unpack-the-rom) for detailed instructions.
- [SkyTemple](https://skytemple.org/) (cross-platform), primarily for getting up to speed on things the community has already figured out.
- [Hex Fiend](https://hexfiend.com/) (macOS only) and [HxD](https://mh-nexus.de/en/hxd/) (Windows only) on the rare occasion I need to do raw hex editing, but honestly any hex editor works.

## Tools created for SoA
This is a list of tools or projects created for Soa. It aims to give a comprehensive index of what is available on the internet specifically created for use with the game. Some document varying features of the game and/or overlap with documentation provided by other tools. They are listed in no particular order.
- [AlmiaE](https://github.com/SunakazeKun/AlmiaE) a complete editing suite for map data and Pokémon data written in Java. Documents a large basis for the structure map data takes.
- [almia-randomizer](https://github.com/ronitsinha/almia-randomizer) a Pokémon randomizer for SoA written in C. At the time it is not playable from a new save.
- [almiascript](https://gitlab.com/Fexean/almiascript) a tool for disassembling and compiling .fsb script files found in SoA written in C. Documents the structure of .fsb scripts and lists and documents opcodes and syscalls.
- [Almiamap](https://gitlab.com/Fexean/almiamap) a WIP level editor. Documents the structure map data takes. Expands on research by AlmiaE
- [ra23mes](https://github.com/SombrAbsol/ra23mes) MES text file converters for Pokémon Ranger: Shadows of Almia and Pokémon Ranger: Guardian Signs. Documents the MES format and lists control characters
- [PRSA---Rom-Manager-](https://github.com/etienerodri/PRSA---Rom-Manager-) a ROM manager tool with graphical interface. Documents map data
- [PRSA-Pokemon-Palette-Editor-
](https://github.com/etienerodri/PRSA-Pokemon-Palette-Editor) a palette editor for the Pokémon found in SoA with graphical interface.
- [ArchipelagoAlmia](https://github.com/WCutePy/ArchipelagoAlmia) an archipelago implementation for SoA.
  
## I don't know any of this and I'm feeling overwhelmed!
There's a lot to learn if you're just starting out, especially if you don't already have a background in computer science. If you want just _one_ thing to sink your teeth into initially, I recommend AnonymousRandomPerson's [_Reverse Engineering a DS Game_](https://www.starcubelabs.com/reverse-engineering-ds/). It'll teach you how to read assembly, guide you through setting up and using reverse engineering tools like [Ghidra](https://ghidra-sre.org/), and share basic reverse engineering strategies through practical examples.

After that, I recommend going through the [Ghidra setup tutorial](ghidra-setup.md) (the above article covers some of it, but stops short of actually importing debug info). By this point, you'll be well equipped to start exploring the SoA code on your own.
