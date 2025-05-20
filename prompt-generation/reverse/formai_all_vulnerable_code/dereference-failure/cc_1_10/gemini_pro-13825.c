//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char *name;
    char *value;
} metadata_entry_t;

typedef struct {
    int num_entries;
    metadata_entry_t *entries;
} metadata_t;

metadata_t *metadata_new() {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    if (metadata == NULL) {
        return NULL;
    }
    metadata->num_entries = 0;
    metadata->entries = NULL;
    return metadata;
}

void metadata_free(metadata_t *metadata) {
    if (metadata == NULL) {
        return;
    }
    for (int i = 0; i < metadata->num_entries; i++) {
        free(metadata->entries[i].name);
        free(metadata->entries[i].value);
    }
    free(metadata->entries);
    free(metadata);
}

int metadata_add_entry(metadata_t *metadata, char *name, char *value) {
    if (metadata == NULL || name == NULL || value == NULL) {
        return -1;
    }
    metadata->entries = realloc(metadata->entries, (metadata->num_entries + 1) * sizeof(metadata_entry_t));
    if (metadata->entries == NULL) {
        return -1;
    }
    metadata->entries[metadata->num_entries].name = strdup(name);
    if (metadata->entries[metadata->num_entries].name == NULL) {
        return -1;
    }
    metadata->entries[metadata->num_entries].value = strdup(value);
    if (metadata->entries[metadata->num_entries].value == NULL) {
        free(metadata->entries[metadata->num_entries].name);
        return -1;
    }
    metadata->num_entries++;
    return 0;
}

int metadata_get_entry(metadata_t *metadata, char *name, char **value) {
    if (metadata == NULL || name == NULL || value == NULL) {
        return -1;
    }
    for (int i = 0; i < metadata->num_entries; i++) {
        if (strcmp(metadata->entries[i].name, name) == 0) {
            *value = metadata->entries[i].value;
            return 0;
        }
    }
    return -1;
}

int metadata_extract_from_file(metadata_t *metadata, char *filename) {
    if (metadata == NULL || filename == NULL) {
        return -1;
    }
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    struct stat st;
    if (fstat(fd, &st) == -1) {
        close(fd);
        return -1;
    }
    char *buffer = malloc(st.st_size);
    if (buffer == NULL) {
        close(fd);
        return -1;
    }
    if (read(fd, buffer, st.st_size) != st.st_size) {
        free(buffer);
        close(fd);
        return -1;
    }
    close(fd);
    // Parse the metadata from the buffer.
    char *line = buffer;
    while (*line != '\0') {
        char *name = line;
        while (*line != ':' && *line != '\n' && *line != '\0') {
            line++;
        }
        if (*line == '\n' || *line == '\0') {
            break;
        }
        *line = '\0';
        line++;
        char *value = line;
        while (*line != '\n' && *line != '\0') {
            line++;
        }
        *line = '\0';
        metadata_add_entry(metadata, name, value);
        line++;
    }
    free(buffer);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    metadata_t *metadata = metadata_new();
    if (metadata == NULL) {
        fprintf(stderr, "Error: Could not create metadata object.\n");
        return 1;
    }
    if (metadata_extract_from_file(metadata, argv[1]) == -1) {
        fprintf(stderr, "Error: Could not extract metadata from file.\n");
        metadata_free(metadata);
        return 1;
    }
    for (int i = 0; i < metadata->num_entries; i++) {
        printf("%s: %s\n", metadata->entries[i].name, metadata->entries[i].value);
    }
    metadata_free(metadata);
    return 0;
}