//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILES 100
#define MAX_LINE_LENGTH 1024
#define METADATA_KEY "Metadata"

// Structure to hold extracted metadata
typedef struct {
    char filename[256];
    char metadata[MAX_LINE_LENGTH];
} Metadata;

// Function to extract metadata from a file
int extract_metadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int found_metadata = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, METADATA_KEY) != NULL) {
            strcpy(metadata->metadata, line);
            found_metadata = 1;
            break; // Exit once we find the metadata
        }
    }

    fclose(file);
    return found_metadata ? 0 : -1; // Return success if metadata found
}

// Function to list files in a directory
void list_files(const char *path, char files[][256], int *file_count) {
    FILE *fp;
    char command[256];

    // Create a command to list files
    snprintf(command, sizeof(command), "ls %s", path);
    fp = popen(command, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error listing files: %s\n", strerror(errno));
        return;
    }

    while (fgets(files[*file_count], sizeof(files[0]), fp) != NULL) {
        // Remove the newline character at the end
        size_t length = strlen(files[*file_count]);
        if (length > 0 && files[*file_count][length - 1] == '\n') {
            files[*file_count][length - 1] = '\0';
        }
        (*file_count)++;
    }

    pclose(fp);
}

// Function to display extracted metadata
void display_metadata(Metadata *metadata, int count) {
    printf("Extracted Metadata:\n");
    for (int i = 0; i < count; i++) {
        printf("Filename: %s\n", metadata[i].filename);
        printf("Metadata: %s\n", metadata[i].metadata);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char files[MAX_FILES][256];
    int file_count = 0;

    list_files(argv[1], files, &file_count);

    Metadata metadata[MAX_FILES];
    int metadata_count = 0;

    // Iterate over the files and extract metadata
    for (int i = 0; i < file_count; i++) {
        strncpy(metadata[metadata_count].filename, files[i], sizeof(metadata[metadata_count].filename));
        if (extract_metadata(files[i], &metadata[metadata_count]) == 0) {
            metadata_count++;
        }
    }

    display_metadata(metadata, metadata_count);

    return EXIT_SUCCESS;
}