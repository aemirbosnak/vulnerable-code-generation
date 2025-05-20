//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Find the file size
    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the entire file contents
    char *file_contents = (char *) malloc(file_size);
    if (file_contents == NULL) {
        fprintf(stderr, "Failed to allocate memory for file contents\n");
        exit(EXIT_FAILURE);
    }

    // Read the entire file into memory
    size_t bytes_read = fread(file_contents, sizeof(char), file_size, file);
    if (bytes_read != file_size) {
        fprintf(stderr, "Failed to read file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Extract the metadata
    char *metadata_start = strstr(file_contents, "<metadata>");
    if (metadata_start == NULL) {
        fprintf(stderr, "Failed to find <metadata> tag in file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char *metadata_end = strstr(metadata_start, "</metadata>");
    if (metadata_end == NULL) {
        fprintf(stderr, "Failed to find </metadata> tag in file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    size_t metadata_size = metadata_end - metadata_start + strlen("</metadata>");
    char *metadata = (char *) malloc(metadata_size);
    if (metadata == NULL) {
        fprintf(stderr, "Failed to allocate memory for metadata\n");
        exit(EXIT_FAILURE);
    }

    strncpy(metadata, metadata_start, metadata_size - strlen("</metadata>"));
    printf("Metadata for file '%s':\n%s\n", filename, metadata);

    fclose(file);
    free(file_contents);
    free(metadata);
    exit(EXIT_SUCCESS);
}