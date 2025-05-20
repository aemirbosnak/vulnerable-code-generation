//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // the maximum file size we'll handle
#define MAX_METADATA_SIZE 100 // the maximum size of the metadata we'll extract
#define METADATA_MARKER "@metadata" // the marker we'll use to indicate the start of our metadata

// function that extracts metadata from a character buffer
char* extract_metadata(char* buffer) {
    char* metadata = (char*) malloc(MAX_METADATA_SIZE * sizeof(char)); // allocate space for our metadata
    memset(metadata, 0, MAX_METADATA_SIZE); // initialize to 0
    char* metadata_start = strstr(buffer, METADATA_MARKER); // find the start of our metadata
    if (metadata_start != NULL) { // if we found it
        metadata_start += strlen(METADATA_MARKER); // move past the marker
        char* metadata_end = strstr(metadata_start, "\n"); // find the end of the metadata
        if (metadata_end != NULL) { // if we found it
            strncpy(metadata, metadata_start, metadata_end - metadata_start); // copy the metadata to our buffer
        }
    }
    return metadata; // return our metadata (or null if we didn't find any)
}

// function that reads a file into a character buffer
char* read_file(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r"); // open the file in read mode
    if (fp == NULL) { // if we couldn't open the file
        printf("Error opening file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END); // move to the end of the file
    long file_size = ftell(fp); // get the size of the file
    fseek(fp, 0, SEEK_SET); // move back to the beginning of the file
    if (file_size > MAX_FILE_SIZE) { // if the file is too big
        printf("File is too big.\n");
        exit(1);
    }
    char* buffer = (char*) malloc(file_size * sizeof(char)); // allocate space for the file buffer
    fread(buffer, file_size, 1, fp); // read the file into the buffer
    fclose(fp); // close the file
    return buffer; // return the buffer
}

// main function
int main(int argc, char* argv[]) {
    if (argc < 2) { // if we didn't get a filename
        printf("Usage: metadata_extractor <filename>\n");
        return 1; // return an error code
    }
    char* buffer = read_file(argv[1]); // read the file into a buffer
    char* metadata = extract_metadata(buffer); // extract the metadata from the buffer
    if (metadata != NULL) { // if we found metadata
        printf("Metadata: %s\n", metadata);
    } else { // if we didn't find metadata
        printf("No metadata found.\n");
    }
    free(buffer); // free the buffer
    free(metadata); // free the metadata buffer
    return 0; // return success
}