//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of metadata
typedef struct {
    char* name;
    int size;
    char* author;
    char* date;
} Metadata;

// Function to extract metadata from a file
Metadata* extractMetadata(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->name = strdup(filename);

    // Extract file size
    fseek(file, 0L, SEEK_END);
    metadata->size = ftell(file);
    rewind(file);

    // Extract author name
    char author[100];
    fscanf(file, "%s", author);
    metadata->author = strdup(author);

    // Extract date
    char date[100];
    fscanf(file, "%s", date);
    metadata->date = strdup(date);

    fclose(file);
    return metadata;
}

// Function to print metadata
void printMetadata(Metadata* metadata) {
    printf("File name: %s\n", metadata->name);
    printf("File size: %d bytes\n", metadata->size);
    printf("Author: %s\n", metadata->author);
    printf("Date: %s\n", metadata->date);
}

// Main function
int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    Metadata* metadata = extractMetadata(filename);
    printMetadata(metadata);

    free(metadata->name);
    free(metadata->author);
    free(metadata->date);
    free(metadata);

    return 0;
}