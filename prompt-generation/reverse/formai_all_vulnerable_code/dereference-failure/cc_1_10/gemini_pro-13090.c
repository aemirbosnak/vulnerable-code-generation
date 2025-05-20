//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZEOF_HEADER 1024
#define SIZEOF_SECTION 1024
#define SIZEOF_SIGNATURE 4

typedef struct {
    char *magic;
    uint32_t num_sections;
    uint32_t size_of_header;
    uint32_t size_of_section;
} header_t;

typedef struct {
    char *name;
    uint32_t offset;
    uint32_t size;
    uint32_t signature;
} section_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    if (size < SIZEOF_HEADER) {
        fprintf(stderr, "File too small\n");
        return 1;
    }

    header_t header;
    fread(&header, sizeof(header), 1, fp);

    if (strcmp(header.magic, "AV") != 0) {
        fprintf(stderr, "Invalid file format\n");
        return 1;
    }

    section_t *sections = malloc(sizeof(section_t) * header.num_sections);
    for (uint32_t i = 0; i < header.num_sections; i++) {
        fread(&sections[i], sizeof(section_t), 1, fp);
    }

    for (uint32_t i = 0; i < header.num_sections; i++) {
        fseek(fp, sections[i].offset, SEEK_SET);
        char *buf = malloc(sections[i].size);
        fread(buf, sections[i].size, 1, fp);

        if (sections[i].signature == 0xDEADBEEF) {
            // Found a virus!
            printf("Found virus in section %s\n", sections[i].name);
            free(buf);
            free(sections);
            fclose(fp);
            return 1;
        }

        free(buf);
    }

    printf("No viruses found\n");
    free(sections);
    fclose(fp);
    return 0;
}