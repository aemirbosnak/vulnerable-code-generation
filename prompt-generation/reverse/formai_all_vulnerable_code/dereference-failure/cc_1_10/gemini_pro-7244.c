//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define METADATA_SIZE 1024

typedef struct {
    uint32_t size;
    char *data;
} metadata_t;

// Reads the metadata from the given file.
metadata_t *read_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    // Read the size of the metadata.
    uint32_t size;
    if (fread(&size, sizeof(size), 1, file) != 1) {
        fclose(file);
        return NULL;
    }

    // Allocate memory for the metadata.
    metadata_t *metadata = malloc(sizeof(metadata_t));
    if (!metadata) {
        fclose(file);
        return NULL;
    }

    // Read the metadata.
    metadata->size = size;
    metadata->data = malloc(size);
    if (!metadata->data) {
        fclose(file);
        free(metadata);
        return NULL;
    }

    if (fread(metadata->data, size, 1, file) != 1) {
        fclose(file);
        free(metadata->data);
        free(metadata);
        return NULL;
    }

    fclose(file);
    return metadata;
}

// Writes the metadata to the given file.
int write_metadata(const char *filename, const metadata_t *metadata) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1;
    }

    // Write the size of the metadata.
    if (fwrite(&metadata->size, sizeof(metadata->size), 1, file) != 1) {
        fclose(file);
        return -1;
    }

    // Write the metadata.
    if (fwrite(metadata->data, metadata->size, 1, file) != 1) {
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

// Prints the metadata.
void print_metadata(const metadata_t *metadata) {
    printf("Size: %u\n", metadata->size);
    printf("Data: %s\n", metadata->data);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the metadata from the file.
    metadata_t *metadata = read_metadata(argv[1]);
    if (!metadata) {
        printf("Error reading metadata from file.\n");
        return 1;
    }

    // Print the metadata.
    print_metadata(metadata);

    // Write the metadata to a new file.
    char new_filename[METADATA_SIZE];
    sprintf(new_filename, "%s.new", argv[1]);
    if (write_metadata(new_filename, metadata) != 0) {
        printf("Error writing metadata to file.\n");
        return 1;
    }

    // Free the metadata.
    free(metadata->data);
    free(metadata);

    return 0;
}