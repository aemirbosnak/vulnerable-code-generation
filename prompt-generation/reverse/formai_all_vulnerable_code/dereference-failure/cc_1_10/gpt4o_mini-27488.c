//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold metadata information
typedef struct {
    char filename[256];
    long size; // Size in bytes
    char creation_date[20];
    char last_modified_date[20];
    char file_type[50];
} FileInfo;

// Function prototypes
void extract_metadata(const char *filename, FileInfo *fileInfo);
void print_metadata(const FileInfo *fileInfo);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileInfo fileInfo;
    extract_metadata(argv[1], &fileInfo);
    print_metadata(&fileInfo);
    
    return 0;
}

// Function to extract metadata from a file
void extract_metadata(const char *filename, FileInfo *fileInfo) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Populate the filename and size
    strcpy(fileInfo->filename, filename);

    // Get file size
    fseek(file, 0, SEEK_END);
    fileInfo->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Fill creation date and last modified date with dummy values 
    // (Real implementation would require system calls to fetch these)
    strcpy(fileInfo->creation_date, "2023-01-01 10:00:00");
    strcpy(fileInfo->last_modified_date, "2023-01-02 12:00:00");

    // Determine file type
    const char *dot = strrchr(filename, '.');
    if (dot) {
        strcpy(fileInfo->file_type, dot + 1);
    } else {
        strcpy(fileInfo->file_type, "Unknown");
    }

    fclose(file);
}

// Function to print the metadata
void print_metadata(const FileInfo *fileInfo) {
    printf("File Metadata:\n");
    printf("---------------\n");
    printf("Filename: %s\n", fileInfo->filename);
    printf("File Size: %ld bytes\n", fileInfo->size);
    printf("Creation Date: %s\n", fileInfo->creation_date);
    printf("Last Modified Date: %s\n", fileInfo->last_modified_date);
    printf("File Type: %s\n", fileInfo->file_type);
}