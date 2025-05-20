//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_METADATA_SIZE 512

void extract_metadata(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char* metadata = (char*) malloc(MAX_METADATA_SIZE);
    if (metadata == NULL) {
        fprintf(stderr, "Failed to allocate memory for metadata\n");
        exit(EXIT_FAILURE);
    }
    size_t metadata_size = 0;
    char buffer[BUFFER_SIZE];
    while (!feof(file)) {
        size_t read_size = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        for (size_t i = 0; i < read_size; i++) {
            if (buffer[i] == '<') {
                size_t metadata_start = i + 1;
                size_t metadata_end = metadata_start;
                while (metadata_end < read_size && buffer[metadata_end] != '>') {
                    metadata_end++;
                }
                if (metadata_end >= read_size) {
                    while (!feof(file)) {
                        read_size = fread(buffer, sizeof(char), BUFFER_SIZE, file);
                        metadata_end = 0;
                        while (metadata_end < read_size && buffer[metadata_end] != '>') {
                            metadata[metadata_size++] = buffer[metadata_end++];
                            if (metadata_size >= MAX_METADATA_SIZE) {
                                fprintf(stderr, "Metadata size exceeds maximum size limit\n");
                                exit(EXIT_FAILURE);
                            }
                        }
                        if (metadata_end < read_size) {
                            break;
                        }
                    }
                }
                else {
                    size_t metadata_length = metadata_end - metadata_start + 1;
                    if (metadata_size + metadata_length >= MAX_METADATA_SIZE) {
                        fprintf(stderr, "Metadata size exceeds maximum size limit\n");
                        exit(EXIT_FAILURE);
                    }
                    memcpy(metadata + metadata_size, buffer + metadata_start, metadata_length);
                    metadata_size += metadata_length;
                    metadata[metadata_size] = '\0';
                    printf("%s\n", metadata);
                }
            }
        }
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: metadata_extractor filename\n");
        return 0;
    }
    extract_metadata(argv[1]);
    return 0;
}