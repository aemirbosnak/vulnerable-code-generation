//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 4096
#define PAGE_ALIGN(addr) (((addr) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))

typedef struct {
    uint32_t page_count;
    uint32_t* pages;
} page_table_t;

typedef struct {
    uint32_t address;
    uint32_t length;
    uint8_t* data;
} section_t;

typedef struct {
    uint32_t section_count;
    section_t* sections;
} elf_header_t;

static void load_elf(const char* filename, elf_header_t* header)
{
    // Open the file.
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Read the file header.
    fread(&header->section_count, sizeof(header->section_count), 1, file);

    // Allocate memory for the sections.
    header->sections = malloc(sizeof(section_t) * header->section_count);

    // Read the sections.
    for (uint32_t i = 0; i < header->section_count; i++) {
        section_t* section = &header->sections[i];

        // Read the section header.
        fread(&section->address, sizeof(section->address), 1, file);
        fread(&section->length, sizeof(section->length), 1, file);

        // Allocate memory for the section data.
        section->data = malloc(section->length);

        // Read the section data.
        fread(section->data, 1, section->length, file);
    }

    // Close the file.
    fclose(file);

    // Sort the sections by address.
    qsort(header->sections, header->section_count, sizeof(section_t),
        (int (*)(const void*, const void*)) strcmp);
}

static void create_page_table(elf_header_t* header, page_table_t* page_table)
{
    // Allocate memory for the page table.
    page_table->page_count = (header->sections[header->section_count - 1].address + header->sections[header->section_count - 1].length + PAGE_SIZE - 1) / PAGE_SIZE;
    page_table->pages = malloc(sizeof(uint32_t) * page_table->page_count);

    // Clear the page table.
    memset(page_table->pages, 0, sizeof(uint32_t) * page_table->page_count);

    // Mark the pages for each section.
    for (uint32_t i = 0; i < header->section_count; i++) {
        section_t* section = &header->sections[i];
        uint32_t page_start = section->address / PAGE_SIZE;
        uint32_t page_end = (section->address + section->length - 1) / PAGE_SIZE;
        for (uint32_t page = page_start; page <= page_end; page++) {
            page_table->pages[page] = 1;
        }
    }
}

static void write_page_table(page_table_t* page_table, const char* filename)
{
    // Open the file.
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Write the page table.
    fwrite(page_table->pages, sizeof(uint32_t), page_table->page_count, file);

    // Close the file.
    fclose(file);
}

static void write_elf(elf_header_t* header, const char* filename)
{
    // Open the file.
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Write the file header.
    fwrite(&header->section_count, sizeof(header->section_count), 1, file);

    // Write the sections.
    for (uint32_t i = 0; i < header->section_count; i++) {
        section_t* section = &header->sections[i];

        // Write the section header.
        fwrite(&section->address, sizeof(section->address), 1, file);
        fwrite(&section->length, sizeof(section->length), 1, file);

        // Write the section data.
        fwrite(section->data, 1, section->length, file);
    }

    // Close the file.
    fclose(file);
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input ELF file> <output page table file>\n", argv[0]);
        exit(1);
    }

    // Load the ELF file.
    elf_header_t header;
    load_elf(argv[1], &header);

    // Create the page table.
    page_table_t page_table;
    create_page_table(&header, &page_table);

    // Write the page table.
    write_page_table(&page_table, argv[2]);

    // Write the optimized ELF file.
    write_elf(&header, "optimized.elf");

    return 0;
}