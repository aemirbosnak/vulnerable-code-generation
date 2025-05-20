//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define MAX_FILE_SIZE 1024*1024*1024

uint8_t *file_buffer;
size_t file_size;

void print_elf_header(Elf64_Ehdr *ehdr) {
    printf("ELF header:\n");
    printf("  Magic: 0x%02X 0x%02X 0x%02X 0x%02X\n", ehdr->e_ident[0], ehdr->e_ident[1], ehdr->e_ident[2], ehdr->e_ident[3]);
    printf("  Class: 0x%02X\n", ehdr->e_ident[4]);
    printf("  Data: 0x%02X\n", ehdr->e_ident[5]);
    printf("  Version: 0x%02X\n", ehdr->e_ident[6]);
    printf("  ABI: 0x%02X\n", ehdr->e_ident[7]);
    printf("  ABI version: 0x%02X\n", ehdr->e_ident[8]);
    printf("  Type: 0x%04X\n", ehdr->e_type);
    printf("  Machine: 0x%04X\n", ehdr->e_machine);
    printf("  Version: 0x%08X\n", ehdr->e_version);
    printf("  Entry point: 0x%016lX\n", (unsigned long)ehdr->e_entry);
    printf("  Program header offset: 0x%06lX\n", (unsigned long)ehdr->e_phoff);
    printf("  Section header offset: 0x%06lX\n", (unsigned long)ehdr->e_shoff);
    printf("  Flags: 0x%08X\n", ehdr->e_flags);
    printf("  Header size: 0x%04X\n", ehdr->e_ehsize);
    printf("  Program header size: 0x%04X\n", ehdr->e_phentsize);
    printf("  Program header count: %d\n", ehdr->e_phnum);
    printf("  Section header size: 0x%04X\n", ehdr->e_shentsize);
    printf("  Section header count: %d\n", ehdr->e_shnum);
    printf("  Section header string table index: %d\n", ehdr->e_shstrndx);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("Error: file size too large\n");
        return 1;
    }

    file_buffer = (uint8_t *)malloc(st.st_size);
    if (file_buffer == NULL) {
        perror("malloc");
        return 1;
    }

    if (read(fd, file_buffer, st.st_size) != st.st_size) {
        perror("read");
        return 1;
    }

    file_size = st.st_size;

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)file_buffer;

    print_elf_header(ehdr);

    return 0;
}