//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <elf.h>

static void print_elf_header(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf("  Magic: %02x %02x %02x %02x\n", header->e_ident[EI_MAG0], header->e_ident[EI_MAG1], header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
    printf("  Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "Little-Endian" : "Big-Endian");
    printf("  Version: %d\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI: %s\n", header->e_ident[EI_OSABI] == ELFOSABI_NONE ? "None" : "Unknown");
    printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type: %s\n", header->e_type == ET_EXEC ? "Executable" : "Shared Object");
    printf("  Machine: %s\n", header->e_machine == EM_X86_64 ? "x86-64" : "Unknown");
    printf("  Entry Point: 0x%016lx\n", header->e_entry);
    printf("  Program Header Offset: 0x%016lx\n", header->e_phoff);
    printf("  Section Header Offset: 0x%016lx\n", header->e_shoff);
    printf("  Flags: 0x%016lx\n", header->e_flags);
    printf("  Header Size: %d\n", header->e_ehsize);
    printf("  Program Header Entry Size: %d\n", header->e_phentsize);
    printf("  Program Header Count: %d\n", header->e_phnum);
    printf("  Section Header Entry Size: %d\n", header->e_shentsize);
    printf("  Section Header Count: %d\n", header->e_shnum);
    printf("  Section Header String Table Index: %d\n", header->e_shstrndx);
}

static void print_elf_program_header(Elf64_Phdr *header)
{
    printf("Program Header:\n");
    printf("  Type: %s\n", header->p_type == PT_LOAD ? "Loadable" : "Unknown");
    printf("  Offset: 0x%016lx\n", header->p_offset);
    printf("  Virtual Address: 0x%016lx\n", header->p_vaddr);
    printf("  Physical Address: 0x%016lx\n", header->p_paddr);
    printf("  File Size: 0x%016lx\n", header->p_filesz);
    printf("  Memory Size: 0x%016lx\n", header->p_memsz);
    printf("  Flags: 0x%016lx\n", header->p_flags);
    printf("  Alignment: 0x%016lx\n", header->p_align);
}

static void print_elf_section_header(Elf64_Shdr *header)
{
    printf("Section Header:\n");
    printf("  Name: %s\n", header->sh_name);
    printf("  Type: %s\n", header->sh_type == SHT_PROGBITS ? "Program Data" : "Unknown");
    printf("  Flags: 0x%016lx\n", header->sh_flags);
    printf("  Address: 0x%016lx\n", header->sh_addr);
    printf("  Offset: 0x%016lx\n", header->sh_offset);
    printf("  Size: 0x%016lx\n", header->sh_size);
    printf("  Link: %d\n", header->sh_link);
    printf("  Info: %d\n", header->sh_info);
    printf("  Alignment: 0x%016lx\n", header->sh_addralign);
    printf("  Entry Size: 0x%016lx\n", header->sh_entsize);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    void *data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    Elf64_Ehdr *header = (Elf64_Ehdr *)data;

    if (header->e_ident[EI_MAG0] != 0x7f ||
        header->e_ident[EI_MAG1] != 'E' ||
        header->e_ident[EI_MAG2] != 'L' ||
        header->e_ident[EI_MAG3] != 'F') {
        printf("Not an ELF file\n");
        munmap(data, sb.st_size);
        close(fd);
        return 1;
    }

    print_elf_header(header);

    Elf64_Phdr *phdr = (Elf64_Phdr *)((uintptr_t)data + header->e_phoff);
    for (int i = 0; i < header->e_phnum; i++) {
        print_elf_program_header(phdr + i);
    }

    Elf64_Shdr *shdr = (Elf64_Shdr *)((uintptr_t)data + header->e_shoff);
    for (int i = 0; i < header->e_shnum; i++) {
        print_elf_section_header(shdr + i);
    }

    munmap(data, sb.st_size);
    close(fd);

    return 0;
}