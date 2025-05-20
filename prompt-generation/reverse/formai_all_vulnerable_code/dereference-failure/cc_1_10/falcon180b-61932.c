//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char filename[100];
    int filesize;
    char date_created[20];
    char author[50];
} Metadata;

// Function to extract metadata from a file
void extract_metadata(FILE *file, Metadata *metadata) {
    // Read in the filename
    fseek(file, 0, SEEK_SET);
    fread(metadata->filename, 1, 100, file);
    metadata->filename[strcspn(metadata->filename, "\0")] = '\0';

    // Read in the filesize
    fseek(file, 0, SEEK_END);
    metadata->filesize = ftell(file);
    rewind(file);

    // Read in the date created
    char buffer[20];
    fseek(file, 0, SEEK_SET);
    fread(buffer, 1, 20, file);
    metadata->date_created[strcspn(buffer, "\0")] = '\0';

    // Read in the author
    fseek(file, 0, SEEK_SET);
    fread(metadata->author, 1, 50, file);
    metadata->author[strcspn(metadata->author, "\0")] = '\0';
}

// Function to print metadata
void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Filesize: %d bytes\n", metadata->filesize);
    printf("Date created: %s\n", metadata->date_created);
    printf("Author: %s\n", metadata->author);
}

int main() {
    // Initialize metadata structure
    Metadata metadata;

    // Open file for reading
    FILE *file = fopen("example.txt", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Extract metadata from file
    extract_metadata(file, &metadata);

    // Print metadata
    printf("Metadata:\n");
    print_metadata(&metadata);

    // Close file
    fclose(file);
    return 0;
}