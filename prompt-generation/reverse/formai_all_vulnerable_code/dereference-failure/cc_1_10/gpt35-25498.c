//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_METADATA_LEN 1024

/**
 * Extracts metadata from a file given a filename and stores it in a string.
 *
 * Arguments:
 *     filename: char array containing the filename
 *     metadata: char array to store the extracted metadata
 *
 * Returns:
 *     0 if successful, -1 if there was an error
 */
int extract_metadata(char *filename, char *metadata) {
    FILE *fp;
    char buffer[MAX_METADATA_LEN];
    char *result;
    int i = 0;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Read the file line by line until the metadata is found
    while ((result = fgets(buffer, MAX_METADATA_LEN, fp)) != NULL) {
        if (strncmp(buffer, "METADATA:", 9) == 0) {
            strcpy(metadata, buffer + 9);
            break;
        }
        i++;
    }

    // Close the file
    fclose(fp);

    if (result == NULL) {
        printf("Error finding metadata in file.\n");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LEN];
    char metadata[MAX_METADATA_LEN] = "";
    int ret;

    // Check if a filename was supplied
    if (argc < 2) {
        printf("Usage: metadata_extractor <filename>\n");
        return 0;
    }

    // Extract metadata from the file
    strcpy(filename, argv[1]);
    ret = extract_metadata(filename, metadata);
    if (ret != 0) {
        return 0;
    }

    // Print the extracted metadata
    printf("METADATA: %s", metadata);

    return 0;
}