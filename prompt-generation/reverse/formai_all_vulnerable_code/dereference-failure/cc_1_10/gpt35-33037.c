//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 4096

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    long file_size;
    char *file_buffer = NULL;
    char *file_name = argv[1];
    char *metadata = NULL;
    int metadata_length, i;

    if (argc != 2) {
        printf("Usage: %s file_path\n", argv[0]);
        return 1;
    }

    file = fopen(file_name, "rb");

    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    file_buffer = (char *) malloc(file_size + 1);

    if (!file_buffer) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fread(file_buffer, file_size, 1, file);
    fclose(file);

    metadata_length = strlen(file_buffer) - MAX_CHARS;

    if (metadata_length <= 0) {
        printf("Error: No metadata found in file.\n");
        free(file_buffer);
        return 1;
    }

    metadata = (char *) malloc(metadata_length + 1);

    if (!metadata) {
        printf("Error: Could not allocate memory for metadata.\n");
        free(file_buffer);
        return 1;
    }

    strncpy(metadata, file_buffer + MAX_CHARS, metadata_length);
    metadata[metadata_length] = '\0';

    printf("Metadata for %s:\n", file_name);

    for (i = 0; i < metadata_length; i++) {
        if (metadata[i] != '\n') {
            printf("%c", metadata[i]);
        } else {
            printf("\n");
        }
    }

    free(file_buffer);
    free(metadata);

    return 0;
}