//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_METADATA_SIZE 1024
#define MAX_FILE_SIZE 1024 * 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *metadata;
int metadata_size;

void read_metadata(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *key, *value;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (read == 0) {
            continue;
        }

        // Parse the line into key and value
        key = strtok(line, ":");
        value = strtok(NULL, "\n");

        // Add the metadata to the array
        metadata = realloc(metadata, (metadata_size + 1) * sizeof(Metadata));
        metadata[metadata_size].name = strdup(key);
        metadata[metadata_size].value = strdup(value);
        metadata_size++;
    }

    fclose(fp);
}

void print_metadata() {
    int i;

    for (i = 0; i < metadata_size; i++) {
        printf("%s = %s\n", metadata[i].name, metadata[i].value);
    }
}

void free_metadata() {
    int i;

    for (i = 0; i < metadata_size; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }

    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_metadata(argv[1]);
    print_metadata();
    free_metadata();

    return EXIT_SUCCESS;
}