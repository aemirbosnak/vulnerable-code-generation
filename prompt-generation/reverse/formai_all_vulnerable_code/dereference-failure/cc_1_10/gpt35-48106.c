//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program is a C Metadata Extractor
// It takes in a file as input and outputs any useful metadata

// Define useful metadata information
#define AUTHOR_TAG "Author: "
#define DATE_TAG "Date: "
#define DESCRIPTION_TAG "Description: "

// Define structure to hold metadata information
typedef struct {
    char* author;
    char* date;
    char* description;
} Metadata;

// Prototypes
int get_file_length(FILE* file);
Metadata* extract_metadata(FILE* file);
char* extract_metadata_line(FILE* file, char* tag);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please specify a file to extract metadata from.\n");
        return 1;
    }

    // Open file
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Extract metadata
    Metadata* metadata = extract_metadata(file);

    // Output metadata
    if (metadata->author) 
        printf("%s%s\n", AUTHOR_TAG, metadata->author);
    if (metadata->date) 
        printf("%s%s\n", DATE_TAG, metadata->date);
    if (metadata->description) 
        printf("%s%s\n", DESCRIPTION_TAG, metadata->description);

    // Close file and free memory
    fclose(file);
    free(metadata->author);
    free(metadata->date);
    free(metadata->description);
    free(metadata);

    return 0;
}

// Get length of file by seeking to end and then returning position
int get_file_length(FILE* file) {
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    rewind(file);
    return length;
}

// Extract metadata from file and return as Metadata structure
Metadata* extract_metadata(FILE* file) {
    Metadata* metadata = (Metadata*)malloc(sizeof(Metadata));

    // Initialize metadata
    metadata->author = NULL;
    metadata->date = NULL;
    metadata->description = NULL;

    int file_length = get_file_length(file);

    // Read through file until end or metadata section is complete
    while (ftell(file) < file_length) {
        char* line = extract_metadata_line(file, AUTHOR_TAG);
        if (line != NULL) {
            metadata->author = line;
            continue;
        }

        line = extract_metadata_line(file, DATE_TAG);
        if (line != NULL) {
            metadata->date = line;
            continue;
        }

        line = extract_metadata_line(file, DESCRIPTION_TAG);
        if (line != NULL) {
            metadata->description = line;
            continue;
        }

        // Stop reading file if metadata section is complete
        break;
    }

    return metadata;
}

// Extract line of metadata starting with given tag
char* extract_metadata_line(FILE* file, char* tag) {
    int tag_length = strlen(tag);
    char* line = (char*)malloc(1024 * sizeof(char));

    // Read in line and check if it starts with tag
    if (fgets(line, 1024, file) != NULL) {
        if (strncmp(line, tag, tag_length) == 0) {
            int line_length = strlen(line);
            line[line_length - 1] = '\0'; // Remove newline character

            // Move pointer back to the start of tag
            fseek(file, -1 * (tag_length - 1), SEEK_CUR);

            // Return line minus tag
            return line + (tag_length * sizeof(char));
        }
    }

    // Free memory if line was not metadata
    free(line);

    return NULL;
}