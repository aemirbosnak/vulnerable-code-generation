//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct metadata_entry {
    char *name;
    uint32_t offset;
    uint32_t size;
};

struct metadata_table {
    struct metadata_entry *entries;
    uint32_t num_entries;
};

struct metadata_extractor {
    int fd;
    struct metadata_table table;
};

int metadata_extractor_init(struct metadata_extractor *extractor, const char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    extractor->fd = fd;
    extractor->table.num_entries = 0;
    extractor->table.entries = NULL;

    return 0;
}

void metadata_extractor_destroy(struct metadata_extractor *extractor)
{
    close(extractor->fd);
    free(extractor->table.entries);
}

int metadata_extractor_add_entry(struct metadata_extractor *extractor, const char *name, uint32_t offset, uint32_t size)
{
    struct metadata_entry *entry;

    entry = realloc(extractor->table.entries, (extractor->table.num_entries + 1) * sizeof(*entry));
    if (entry == NULL) {
        return -1;
    }

    extractor->table.entries = entry;
    extractor->table.entries[extractor->table.num_entries].name = strdup(name);
    extractor->table.entries[extractor->table.num_entries].offset = offset;
    extractor->table.entries[extractor->table.num_entries].size = size;
    extractor->table.num_entries++;

    return 0;
}

int metadata_extractor_extract(struct metadata_extractor *extractor, const char *name, void *buffer, size_t size)
{
    int i;

    for (i = 0; i < extractor->table.num_entries; i++) {
        if (strcmp(extractor->table.entries[i].name, name) == 0) {
            break;
        }
    }

    if (i == extractor->table.num_entries) {
        return -1;
    }

    if (lseek(extractor->fd, extractor->table.entries[i].offset, SEEK_SET) == -1) {
        return -1;
    }

    if (read(extractor->fd, buffer, extractor->table.entries[i].size) != extractor->table.entries[i].size) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    struct metadata_extractor extractor;
    char buffer[1024];
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (metadata_extractor_init(&extractor, argv[1]) != 0) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    metadata_extractor_add_entry(&extractor, "name", 0, 10);
    metadata_extractor_add_entry(&extractor, "age", 10, 4);
    metadata_extractor_add_entry(&extractor, "gender", 14, 1);

    if (metadata_extractor_extract(&extractor, "name", buffer, sizeof(buffer)) != 0) {
        fprintf(stderr, "Failed to extract name\n");
        return EXIT_FAILURE;
    }

    printf("Name: %s\n", buffer);

    if (metadata_extractor_extract(&extractor, "age", buffer, sizeof(buffer)) != 0) {
        fprintf(stderr, "Failed to extract age\n");
        return EXIT_FAILURE;
    }

    printf("Age: %d\n", *buffer);

    if (metadata_extractor_extract(&extractor, "gender", buffer, sizeof(buffer)) != 0) {
        fprintf(stderr, "Failed to extract gender\n");
        return EXIT_FAILURE;
    }

    printf("Gender: %s\n", buffer);

    metadata_extractor_destroy(&extractor);

    return EXIT_SUCCESS;
}