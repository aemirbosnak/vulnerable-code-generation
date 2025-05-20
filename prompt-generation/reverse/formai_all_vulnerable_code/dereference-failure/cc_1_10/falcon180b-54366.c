//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for metadata information
typedef struct {
    char file_name[100];
    int file_size;
    char creation_date[20];
    char modification_date[20];
    char author_name[50];
} Metadata;

// Function to extract metadata from a file
void extract_metadata(char* file_path, Metadata* metadata) {
    FILE* file;
    char buffer[100];

    // Open the file for reading
    file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    // Read file name
    fseek(file, 0, SEEK_SET);
    fread(buffer, 1, 100, file);
    strcpy(metadata->file_name, buffer);

    // Read file size
    fseek(file, 0, SEEK_END);
    metadata->file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read creation and modification dates
    fread(buffer, 1, 20, file);
    strcpy(metadata->creation_date, buffer);
    fread(buffer, 1, 20, file);
    strcpy(metadata->modification_date, buffer);

    // Read author name
    fread(buffer, 1, 50, file);
    strcpy(metadata->author_name, buffer);

    fclose(file);
}

// Function to print metadata information
void print_metadata(Metadata* metadata) {
    printf("File name: %s\n", metadata->file_name);
    printf("File size: %d bytes\n", metadata->file_size);
    printf("Creation date: %s\n", metadata->creation_date);
    printf("Modification date: %s\n", metadata->modification_date);
    printf("Author name: %s\n", metadata->author_name);
}

// Main function
int main(int argc, char* argv[]) {
    Metadata metadata;

    if (argc!= 2) {
        printf("Usage:./program <file_path>\n");
        exit(1);
    }

    extract_metadata(argv[1], &metadata);
    print_metadata(&metadata);

    return 0;
}