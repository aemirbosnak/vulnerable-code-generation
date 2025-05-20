//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    char *name;
    char *value;
} MetadataItem;

typedef struct {
    char *path;
    MetadataItem *items;
    int num_items;
} Metadata;

Metadata *metadata_new(const char *path) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->path = strdup(path);
    metadata->items = NULL;
    metadata->num_items = 0;
    return metadata;
}

void metadata_free(Metadata *metadata) {
    free(metadata->path);
    for (int i = 0; i < metadata->num_items; i++) {
        free(metadata->items[i].name);
        free(metadata->items[i].value);
    }
    free(metadata->items);
    free(metadata);
}

int metadata_load(Metadata *metadata) {
    int fd = open(metadata->path, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) < 0) {
        close(fd);
        return -1;
    }

    char *buffer = malloc(statbuf.st_size);
    if (buffer == NULL) {
        close(fd);
        return -1;
    }

    if (read(fd, buffer, statbuf.st_size) != statbuf.st_size) {
        free(buffer);
        close(fd);
        return -1;
    }

    close(fd);

    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        if (name != NULL && value != NULL) {
            MetadataItem item = { .name = strdup(name), .value = strdup(value) };
            metadata->items = realloc(metadata->items, (metadata->num_items + 1) * sizeof(MetadataItem));
            metadata->items[metadata->num_items++] = item;
        }
        line = strtok(NULL, "\n");
    }

    free(buffer);

    return 0;
}

void metadata_print(Metadata *metadata) {
    for (int i = 0; i < metadata->num_items; i++) {
        printf("%s: %s\n", metadata->items[i].name, metadata->items[i].value);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata *metadata = metadata_new(argv[1]);
    if (metadata_load(metadata) < 0) {
        fprintf(stderr, "Error loading metadata from file\n");
        metadata_free(metadata);
        return EXIT_FAILURE;
    }

    metadata_print(metadata);

    metadata_free(metadata);

    return EXIT_SUCCESS;
}