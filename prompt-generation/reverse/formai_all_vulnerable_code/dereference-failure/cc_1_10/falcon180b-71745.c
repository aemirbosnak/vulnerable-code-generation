//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_SIZE];
    int line_number = 0;

    // Extract file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Extract file type
    char file_type[20];
    fgets(line, MAX_LINE_SIZE, file);
    sscanf(line, "%*s %19s", file_type);

    // Extract creation date and time
    char creation_date[20];
    fgets(line, MAX_LINE_SIZE, file);
    sscanf(line, "%*s %19s", creation_date);

    // Extract modification date and time
    char modification_date[20];
    fgets(line, MAX_LINE_SIZE, file);
    sscanf(line, "%*s %19s", modification_date);

    // Extract author name
    char author[50];
    fgets(line, MAX_LINE_SIZE, file);
    sscanf(line, "%*s %49s", author);

    // Extract number of lines
    int num_lines = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        num_lines++;
    }

    // Print metadata
    printf("Metadata for %s:\n", filename);
    printf("File size: %ld bytes\n", file_size);
    printf("File type: %s\n", file_type);
    printf("Creation date and time: %s\n", creation_date);
    printf("Modification date and time: %s\n", modification_date);
    printf("Author: %s\n", author);
    printf("Number of lines: %d\n", num_lines);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    // Extract metadata
    extract_metadata(file, filename);

    fclose(file);
    return 0;
}