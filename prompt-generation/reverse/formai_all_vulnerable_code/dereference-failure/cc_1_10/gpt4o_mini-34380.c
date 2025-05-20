//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PATH_LENGTH 512

// Structure to store information about a file.
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char type[16];
    long size;
} FileMetadata;

// Function to calculate the file type based on its extension.
void get_file_type(const char *filename, char *file_type) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) {
        strcpy(file_type, "unknown");
        return;
    }
    strcpy(file_type, dot + 1);
}

// Function to gather metadata of a single file.
void retrieve_metadata(const char *filepath, FileMetadata *metadata) {
    FILE *file = fopen(filepath, "rb");
    if (file) {
        strncpy(metadata->name, filepath, MAX_FILENAME_LENGTH);
        fseek(file, 0L, SEEK_END);
        metadata->size = ftell(file);
        fclose(file);
        get_file_type(filepath, metadata->type);
    } else {
        perror("File open error");
    }
}

// Function to recursively retrieve file metadata from a directory.
void explore_directory(const char *dir_name) {
    DIR *dir;
    struct dirent *entry;
    FileMetadata metadata;

    dir = opendir(dir_name);
    if (!dir) {
        perror("Directory open error");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[MAX_PATH_LENGTH];
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
            
            // Check if the entry is a directory or a file
            if (entry->d_type == DT_DIR) {
                explore_directory(path); // Recursive call for directories
            } else {
                retrieve_metadata(path, &metadata);
                printf("File: %s\nType: %s\nSize: %ld bytes\n\n", metadata.name, metadata.type, metadata.size);
            }
        }
    }

    closedir(dir);
}

// Main function to start the metadata extraction process.
int main(int argc, char *argv[]) {
    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    explore_directory(directory_path);

    return EXIT_SUCCESS;
}