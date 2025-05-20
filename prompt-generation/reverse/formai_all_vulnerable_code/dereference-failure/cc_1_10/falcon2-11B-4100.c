//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int size;
    char* content;
} Metadata;

Metadata extractMetadata(FILE* file) {
    Metadata metadata;

    // Extract file name
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    metadata.name = (char*) malloc(filesize + 1);
    fread(metadata.name, filesize, 1, file);
    metadata.name[filesize] = '\0';

    // Extract file size
    metadata.size = filesize;

    // Extract file content
    metadata.content = (char*) malloc(filesize + 1);
    fread(metadata.content, filesize, 1, file);
    metadata.content[filesize] = '\0';

    return metadata;
}

void printMetadata(Metadata metadata) {
    printf("Name: %s\n", metadata.name);
    printf("Size: %d\n", metadata.size);
    printf("Content:\n");
    printf("%s", metadata.content);
}

int main() {
    FILE* file = fopen("test.txt", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Metadata metadata = extractMetadata(file);
    printMetadata(metadata);

    fclose(file);

    return 0;
}