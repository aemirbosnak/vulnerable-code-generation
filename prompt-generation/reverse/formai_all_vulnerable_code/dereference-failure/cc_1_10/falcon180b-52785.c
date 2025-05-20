//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata information
typedef struct {
    char *filename;
    int filesize;
    char *mimetype;
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(char *filename) {
    FILE *fp;
    Metadata meta;
    char buffer[1024];

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    meta.filesize = ftell(fp);
    rewind(fp);
    meta.filename = strdup(filename);

    fread(buffer, 1, 1024, fp);
    buffer[1023] = '\0';
    meta.mimetype = strdup(buffer);

    // Close the file
    fclose(fp);

    return meta;
}

// Function to print metadata information
void print_metadata(Metadata meta) {
    printf("Filename: %s\n", meta.filename);
    printf("File Size: %d bytes\n", meta.filesize);
    printf("MIME Type: %s\n", meta.mimetype);
}

// Main function to run the program
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Metadata meta = extract_metadata(argv[1]);
    print_metadata(meta);

    free(meta.filename);
    free(meta.mimetype);

    return 0;
}