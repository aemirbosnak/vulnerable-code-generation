//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <elf.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

// Define a structure to hold the metadata of a function.
typedef struct {
    char *name;
    uint64_t address;
    uint64_t size;
} FunctionMetadata;

// Define a function to extract the metadata of a function from an ELF file.
FunctionMetadata *extract_function_metadata(char *filename, char *function_name) {
    // Open the ELF file.
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    // Map the ELF file into memory.
    void *elf_map = mmap(NULL, sysconf(_SC_PAGE_SIZE), PROT_READ, MAP_PRIVATE, fd, 0);
    if (elf_map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;
    }

    // Get the ELF header.
    Elf64_Ehdr *elf_hdr = (Elf64_Ehdr *)elf_map;

    // Get the program headers.
    Elf64_Phdr *phdr = (Elf64_Phdr *)(elf_map + elf_hdr->e_phoff);

    // Find the program header for the .text section.
    Elf64_Phdr *text_phdr = NULL;
    for (int i = 0; i < elf_hdr->e_phnum; i++) {
        if (phdr[i].p_type == PT_LOAD && strcmp(phdr[i].p_filesz, ".text") == 0) {
            text_phdr = &phdr[i];
            break;
        }
    }

    // If the .text section was not found, return NULL.
    if (text_phdr == NULL) {
        munmap(elf_map, sysconf(_SC_PAGE_SIZE));
        close(fd);
        return NULL;
    }

    // Get the section headers.
    Elf64_Shdr *shdr = (Elf64_Shdr *)(elf_map + elf_hdr->e_shoff);

    // Find the section header for the .symtab section.
    Elf64_Shdr *symtab_shdr = NULL;
    for (int i = 0; i < elf_hdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB && strcmp(shdr[i].sh_name, ".symtab") == 0) {
            symtab_shdr = &shdr[i];
            break;
        }
    }

    // If the .symtab section was not found, return NULL.
    if (symtab_shdr == NULL) {
        munmap(elf_map, sysconf(_SC_PAGE_SIZE));
        close(fd);
        return NULL;
    }

    // Get the symbol table.
    Elf64_Sym *symtab = (Elf64_Sym *)(elf_map + symtab_shdr->sh_offset);

    // Find the symbol for the function.
    Elf64_Sym *func_sym = NULL;
    for (int i = 0; i < symtab_shdr->sh_size / sizeof(Elf64_Sym); i++) {
        if (strcmp(symtab[i].st_name, function_name) == 0) {
            func_sym = &symtab[i];
            break;
        }
    }

    // If the symbol for the function was not found, return NULL.
    if (func_sym == NULL) {
        munmap(elf_map, sysconf(_SC_PAGE_SIZE));
        close(fd);
        return NULL;
    }

    // Allocate memory for the function metadata.
    FunctionMetadata *metadata = malloc(sizeof(FunctionMetadata));
    if (metadata == NULL) {
        munmap(elf_map, sysconf(_SC_PAGE_SIZE));
        close(fd);
        return NULL;
    }

    // Copy the function metadata into the allocated memory.
    metadata->name = strdup(func_sym->st_name);
    metadata->address = func_sym->st_value;
    metadata->size = func_sym->st_size;

    // Unmap the ELF file from memory.
    munmap(elf_map, sysconf(_SC_PAGE_SIZE));

    // Close the ELF file.
    close(fd);

    // Return the function metadata.
    return metadata;
}

// Define a function to print the metadata of a function.
void print_function_metadata(FunctionMetadata *metadata) {
    printf("Function name: %s\n", metadata->name);
    printf("Function address: 0x%llx\n", metadata->address);
    printf("Function size: 0x%llx\n", metadata->size);
}

// Define a function to free the memory allocated for a function metadata.
void free_function_metadata(FunctionMetadata *metadata) {
    free(metadata->name);
    free(metadata);
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user provided an ELF file and a function name.
    if (argc < 3) {
        printf("Usage: %s <elf_file> <function_name>\n", argv[0]);
        return 1;
    }

    // Extract the metadata of the function.
    FunctionMetadata *metadata = extract_function_metadata(argv[1], argv[2]);
    if (metadata == NULL) {
        printf("Could not extract metadata for function %s in file %s.\n", argv[2], argv[1]);
        return 1;
    }

    // Print the metadata of the function.
    print_function_metadata(metadata);

    // Free the memory allocated for the function metadata.
    free_function_metadata(metadata);

    return 0;
}