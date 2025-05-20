//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure for metadata
typedef struct {
    char *filename;
    int filesize;
    char *creationdate;
    char *modificationdate;
    char *author;
} Metadata;

// Function to extract metadata from a file
Metadata* extractMetadata(char *filename) {
    FILE *file = fopen(filename, "rb");
    Metadata *metadata = (Metadata*)malloc(sizeof(Metadata));

    if (file == NULL) {
        metadata->filename = NULL;
        metadata->filesize = 0;
        metadata->creationdate = NULL;
        metadata->modificationdate = NULL;
        metadata->author = NULL;
        return metadata;
    }

    fseek(file, 0, SEEK_END);
    metadata->filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        if (strstr(buffer, "creationDate")!= NULL) {
            char *date = strstr(buffer, ":") + 1;
            metadata->creationdate = strdup(date);
        } else if (strstr(buffer, "modificationDate")!= NULL) {
            char *date = strstr(buffer, ":") + 1;
            metadata->modificationdate = strdup(date);
        } else if (strstr(buffer, "author")!= NULL) {
            char *author = strstr(buffer, ":") + 1;
            metadata->author = strdup(author);
        }
    }

    metadata->filename = strdup(filename);
    fclose(file);

    return metadata;
}

// Function to print metadata
void printMetadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("Creation date: %s\n", metadata->creationdate);
    printf("Modification date: %s\n", metadata->modificationdate);
    printf("Author: %s\n", metadata->author);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Metadata *metadata = extractMetadata(argv[1]);
    printMetadata(metadata);

    free(metadata->filename);
    free(metadata->creationdate);
    free(metadata->modificationdate);
    free(metadata->author);
    free(metadata);

    return 0;
}