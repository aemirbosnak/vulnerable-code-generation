//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void print_usage() {
    printf("Usage: file_sync <source_file> <destination_file>\n");
    printf("Synchronizes the contents of source_file into destination_file.\n");
}

FILE* open_file(const char* filename, const char* mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

void sync_files(const char* source_file, const char* destination_file) {
    FILE *source = open_file(source_file, "r");
    FILE *destination = open_file(destination_file, "w");

    char source_line[MAX_LINE_LENGTH];
    char destination_line[MAX_LINE_LENGTH];

    // Flag to track whether to overwrite destination
    int should_sync = 0;

    while (fgets(source_line, sizeof(source_line), source) != NULL) {
        if (fgets(destination_line, sizeof(destination_line), destination) == NULL) {
            // If destination file ends but source file still has lines
            should_sync = 1;
            break;
        }
        // Check if lines are different
        if (strcmp(source_line, destination_line) != 0) {
            should_sync = 1;
            break;
        }
    }
  
    // If destination has leftover lines, we don't sync the whole file if they differ
    if (!should_sync) {
        while (fgets(destination_line, sizeof(destination_line), destination) != NULL) {
            should_sync = 1;  // The lengths differ, begin syncing
            break;
        }
    }
  
    rewind(source); // Reset source pointer for reading

    if (should_sync) {
        // Write the updated lines from source into destination
        printf("Synchronizing files...\n");
        while (fgets(source_line, sizeof(source_line), source) != NULL) {
            fputs(source_line, destination);
        }
    } else {
        printf("No changes detected. No synchronization needed.\n");
    }

    fclose(source);
    fclose(destination);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    sync_files(source_file, destination_file);
    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}