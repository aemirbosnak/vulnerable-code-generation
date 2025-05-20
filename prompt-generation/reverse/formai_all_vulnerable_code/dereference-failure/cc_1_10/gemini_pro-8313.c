//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef WIN32
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#define MAX_FILE_SIZE (1024 * 1024 * 10)

typedef struct {
    char *name;
    char *value;
} metadata_entry;

typedef struct {
    char *filename;
    metadata_entry *entries;
    size_t num_entries;
} metadata_file;

static int read_file(const char *filename, char **buffer, size_t *size)
{
    FILE *fp;
    struct stat st;

    if (stat(filename, &st) < 0) {
        perror("stat");
        return -1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File is too large: %s\n", filename);
        return -1;
    }

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    *buffer = malloc(st.st_size);
    if (*buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return -1;
    }

    *size = fread(*buffer, 1, st.st_size, fp);
    if (*size != st.st_size) {
        perror("fread");
        free(*buffer);
        fclose(fp);
        return -1;
    }

    fclose(fp);

    return 0;
}

static int parse_metadata(char *buffer, size_t size, metadata_file *metadata)
{
    char *line, *key, *value;

    line = buffer;
    while (line < buffer + size) {
        key = line;
        while (*line != ':' && *line != '\n' && *line != '\0') {
            line++;
        }
        if (*line == '\n' || *line == '\0') {
            break;
        }
        *line++ = '\0';

        value = line;
        while (*line != '\n' && *line != '\0') {
            line++;
        }
        *line++ = '\0';

        metadata->entries = realloc(metadata->entries, (metadata->num_entries + 1) * sizeof(metadata_entry));
        if (metadata->entries == NULL) {
            perror("realloc");
            return -1;
        }

        metadata->entries[metadata->num_entries].name = strdup(key);
        if (metadata->entries[metadata->num_entries].name == NULL) {
            perror("strdup");
            return -1;
        }

        metadata->entries[metadata->num_entries].value = strdup(value);
        if (metadata->entries[metadata->num_entries].value == NULL) {
            perror("strdup");
            return -1;
        }

        metadata->num_entries++;
    }

    return 0;
}

static void print_metadata(metadata_file *metadata)
{
    size_t i;

    printf("Filename: %s\n", metadata->filename);
    printf("Metadata:\n");
    for (i = 0; i < metadata->num_entries; i++) {
        printf("  %s: %s\n", metadata->entries[i].name, metadata->entries[i].value);
    }
}

int main(int argc, char **argv)
{
    char *buffer;
    size_t size;
    metadata_file metadata;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    metadata.filename = argv[1];
    metadata.entries = NULL;
    metadata.num_entries = 0;

    if (read_file(argv[1], &buffer, &size) < 0) {
        return 1;
    }

    if (parse_metadata(buffer, size, &metadata) < 0) {
        free(buffer);
        return 1;
    }

    free(buffer);

    print_metadata(&metadata);

    for (size_t i = 0; i < metadata.num_entries; i++) {
        free(metadata.entries[i].name);
        free(metadata.entries[i].value);
    }
    free(metadata.entries);

    return 0;
}