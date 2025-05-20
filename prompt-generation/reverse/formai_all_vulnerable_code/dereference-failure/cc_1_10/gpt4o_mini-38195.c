//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store metadata of files
typedef struct {
    char *filename;
    long filesize;
    char *filetype;
    char *creationDate;
} FileMetadata;

// Function prototypes
void printMetadata(FileMetadata *metadata);
void freeMetadata(FileMetadata *metadata);
FileMetadata* extractMetadata(const char *filename);
void displayMenu();
void handleOption(int option);

// Main function
int main() {
    int option = 0;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        handleOption(option);
    }

    return 0;
}

// Function to create and extract metadata from a file
FileMetadata* extractMetadata(const char *filename) {
    FileMetadata *metadata = (FileMetadata *)malloc(sizeof(FileMetadata));
    if (metadata == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Assigning values to metadata
    metadata->filename = strdup(filename);
    FILE *file = fopen(filename, "rb");
    
    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        freeMetadata(metadata);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    metadata->filesize = ftell(file);
    rewind(file);
    
    // Simplistic way to get file type (just extension based)
    const char *dot = strrchr(filename, '.');
    if (dot) {
        metadata->filetype = strdup(dot + 1);
    } else {
        metadata->filetype = strdup("unknown");
    }
    
    // As a placeholder, we are using a static date (should ideally fetch file's actual creation date)
    metadata->creationDate = strdup("2023-01-01");

    fclose(file);
    return metadata;
}

// Function to free allocated memory for metadata
void freeMetadata(FileMetadata *metadata) {
    if (metadata != NULL) {
        free(metadata->filename);
        free(metadata->filetype);
        free(metadata->creationDate);
        free(metadata);
    }
}

// Function to print metadata information
void printMetadata(FileMetadata *metadata) {
    if (metadata) {
        printf("File: %s\n", metadata->filename);
        printf("Size: %ld bytes\n", metadata->filesize);
        printf("Type: %s\n", metadata->filetype);
        printf("Creation Date: %s\n", metadata->creationDate);
    }
}

// Function to display menu options
void displayMenu() {
    printf("\n==== Metadata Extractor ====\n");
    printf("1. Extract Metadata from File\n");
    printf("2. Exit\n");
}

// Function to handle user menu options
void handleOption(int option) {
    switch (option) {
        case 1: {
            char filename[256];
            printf("Enter filename: ");
            scanf("%s", filename);
            FileMetadata *metadata = extractMetadata(filename);
            printMetadata(metadata);
            freeMetadata(metadata);
            break;
        }
        case 2:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}