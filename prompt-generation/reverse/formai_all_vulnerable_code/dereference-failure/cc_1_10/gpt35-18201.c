//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BYTES 100000

int main(int argc, char *argv[]) {

    // Check if user has provided the filename
    if(argc != 2) {
        printf("Please provide the filename.\n");
        return 1;
    }

    // Open the file in read-only mode
    FILE *fp = fopen(argv[1], "r");

    // Check if the file exists
    if(fp == NULL) {
        printf("File does not exist.\n");
        return 1;
    }

    // Allocate memory for the file contents
    char *file_contents = (char *)malloc(MAX_BYTES * sizeof(char));

    // Read the file contents into memory
    int current_byte = fgetc(fp);
    int num_bytes = 0;

    while(current_byte != EOF && num_bytes < MAX_BYTES) {
        file_contents[num_bytes++] = (char)current_byte;
        current_byte = fgetc(fp);
    }

    // Close the file
    fclose(fp);

    // Extract the metadata
    char *metadata = NULL;

    // Look for the metadata tag at the beginning of the file
    if(strncmp(file_contents, "<metadata>", 10) == 0) {

        // Find the end of the metadata tag
        char *end_tag = strstr(file_contents, "</metadata>");
        if(end_tag == NULL) {
            printf("Invalid metadata tag.\n");
            return 1;
        }

        int metadata_size = end_tag - file_contents - 10;
        metadata = (char *)malloc((metadata_size + 1) * sizeof(char));

        // Copy the metadata into the buffer
        strncpy(metadata, file_contents + 10, metadata_size);
        metadata[metadata_size] = '\0';
    }

    // Print the metadata
    if(metadata != NULL) {
        printf("Metadata found: %s\n", metadata);
    } else {
        printf("No metadata found.\n");
    }

    // Free the memory
    free(file_contents);
    free(metadata);

    return 0;
}