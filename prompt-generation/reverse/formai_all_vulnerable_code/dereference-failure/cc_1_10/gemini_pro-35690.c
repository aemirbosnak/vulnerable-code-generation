//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct metadata {
    uint32_t magic;
    uint32_t version;
    uint32_t size;
    uint32_t num_entries;
    struct entry {
        uint32_t offset;
        uint32_t size;
        char name[32];
    } entries[];
};

int main() {
    FILE *f = fopen("metadata.bin", "rb");
    if (!f) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct metadata *md = malloc(sizeof(struct metadata));
    if (!md) {
        perror("malloc");
        fclose(f);
        return EXIT_FAILURE;
    }

    fread(md, sizeof(struct metadata), 1, f);

    if (md->magic != 0x4d444154) { // "MDAT"
        fprintf(stderr, "Invalid metadata file\n");
        fclose(f);
        free(md);
        return EXIT_FAILURE;
    }

    printf("Metadata version: %u\n", md->version);
    printf("Metadata size: %u\n", md->size);
    printf("Number of entries: %u\n", md->num_entries);

    for (uint32_t i = 0; i < md->num_entries; i++) {
        struct entry *e = &md->entries[i];
        printf("%d: offset=%u, size=%u, name=\"%s\"\n", i, e->offset, e->size, e->name);
    }

    fclose(f);
    free(md);

    return EXIT_SUCCESS;
}