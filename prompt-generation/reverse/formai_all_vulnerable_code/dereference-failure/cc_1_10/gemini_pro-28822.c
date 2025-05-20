//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <elf-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the ELF file for reading.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read the ELF header.
    Elf64_Ehdr header;
    if (fread(&header, sizeof(header), 1, file) != 1) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    // Check if the ELF file is valid.
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s is not a valid ELF file.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Print the ELF header information.
    printf("ELF header:\n");
    printf("  Magic: %02x %02x %02x %02x\n",
        header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
        header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
    printf("  Class: %d\n", header.e_ident[EI_CLASS]);
    printf("  Data: %d\n", header.e_ident[EI_DATA]);
    printf("  Version: %d\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI: %d\n", header.e_ident[EI_OSABI]);
    printf("  ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type: %d\n", header.e_type);
    printf("  Machine: %d\n", header.e_machine);
    printf("  Version: %d\n", header.e_version);
    printf("  Entry point: %016lx\n", header.e_entry);
    printf("  Program header offset: %016lx\n", header.e_phoff);
    printf("  Section header offset: %016lx\n", header.e_shoff);
    printf("  Flags: %016lx\n", header.e_flags);
    printf("  Size of this header: %d\n", header.e_ehsize);
    printf("  Size of program headers: %d\n", header.e_phentsize);
    printf("  Number of program headers: %d\n", header.e_phnum);
    printf("  Size of section headers: %d\n", header.e_shentsize);
    printf("  Number of section headers: %d\n", header.e_shnum);
    printf("  Section header string table index: %d\n", header.e_shstrndx);

    // Close the ELF file.
    fclose(file);

    return EXIT_SUCCESS;
}