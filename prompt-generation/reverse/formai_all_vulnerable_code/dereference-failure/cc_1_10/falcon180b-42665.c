//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum length of metadata field
#define MAX_METADATA_LEN 512

// Function to extract metadata from a file
void extract_metadata(FILE *fp, char *filename, char *metadata) {
    // Set metadata to empty string
    strcpy(metadata, "");

    // Read first 512 bytes of file
    char buffer[MAX_METADATA_LEN];
    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, MAX_METADATA_LEN, fp);
    fclose(fp);

    // Search for metadata fields
    char *title = strstr(buffer, "title=");
    char *author = strstr(buffer, "author=");
    char *date = strstr(buffer, "date=");

    // Extract metadata fields
    if (title) {
        char *end = strchr(title, '>');
        if (end) {
            strncat(metadata, title + 7, end - title - 7);
        }
    }
    if (author) {
        char *end = strchr(author, '>');
        if (end) {
            strncat(metadata, author + 8, end - author - 8);
        }
    }
    if (date) {
        char *end = strchr(date, '>');
        if (end) {
            strncat(metadata, date + 6, end - date - 6);
        }
    }
}

// Function to print metadata
void print_metadata(char *filename, char *metadata) {
    printf("Metadata for %s:\n", filename);
    if (metadata[0]!= '\0') {
        printf("  Title: %s\n", metadata);
    }
    if (strstr(metadata, "author=")) {
        printf("  Author: %s\n", metadata);
    }
    if (strstr(metadata, "date=")) {
        printf("  Date: %s\n", metadata);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <output_metadata_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Allocate memory for metadata
    char metadata[MAX_METADATA_LEN];

    // Extract metadata
    extract_metadata(fp, argv[1], metadata);

    // Close input file
    fclose(fp);

    // Open output file
    FILE *output_fp = fopen(argv[2], "w");
    if (!output_fp) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Print metadata to output file
    print_metadata(argv[1], metadata);

    // Close output file
    fclose(output_fp);

    return 0;
}