//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char name[64];
    int value;
} Metadata;

Metadata extract_metadata(char *buffer, size_t size);
void print_metadata(Metadata metadata);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    Metadata metadata = extract_metadata(buffer, file_size);
    print_metadata(metadata);

    free(buffer);
    fclose(file);

    return 0;
}

Metadata extract_metadata(char *buffer, size_t size) {
    Metadata metadata = {0};
    size_t i = 0;

    while (i < size && strncmp((char *)buffer + i, "METADATA", 7) != 0) {
        i++;
    }

    if (i + 8 > size) {
        return metadata;
    }

    memcpy(metadata.name, (char *)buffer + i + 7, 60);
    metadata.name[60] = '\0';

    memcpy(&metadata.value, (char *)buffer + i + 77, sizeof(int));

    return metadata;
}

void print_metadata(Metadata metadata) {
    printf("Name: %s\n", metadata.name);
    printf("Value: %d\n", metadata.value);
}