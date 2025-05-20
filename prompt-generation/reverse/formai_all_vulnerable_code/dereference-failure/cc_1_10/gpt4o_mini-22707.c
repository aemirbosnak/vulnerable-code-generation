//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Structure to hold metadata information of a file
typedef struct {
    char name[256];
    char path[512];
    size_t size;
    time_t last_modified;
} FileMetadata;

// Function to extract metadata of a file
void extract_metadata(const char *file_path, FileMetadata *metadata) {
    struct stat file_stat;

    // Get file status
    if (stat(file_path, &file_stat) == -1) {
        perror("stat error");
        return;
    }

    // Populate metadata struct
    strcpy(metadata->name, file_path);
    strcpy(metadata->path, file_path);
    metadata->size = file_stat.st_size;
    metadata->last_modified = file_stat.st_mtime;
}

// Function to print metadata information
void print_metadata(const FileMetadata *metadata) {
    struct tm *time_info;
    char buffer[80];

    // Convert timestamp to human-readable format
    time_info = localtime(&metadata->last_modified);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);

    printf("File Name: %s\n", metadata->name);
    printf("File Path: %s\n", metadata->path);
    printf("File Size: %lu bytes\n", (unsigned long)metadata->size);
    printf("Last Modified: %s\n", buffer);
}

// Function to traverse a directory and extract metadata from files
void traverse_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("opendir error");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Build the full path of the file
            char full_path[512];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

            // Check if it's a regular file
            struct stat file_stat;
            if (stat(full_path, &file_stat) == -1) {
                perror("stat error");
                continue;
            }

            // If it's a regular file, extract and print its metadata
            if (S_ISREG(file_stat.st_mode)) {
                FileMetadata metadata;
                extract_metadata(full_path, &metadata);
                print_metadata(&metadata);
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    // Check if the path argument is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Call the function to traverse the given directory
    traverse_directory(argv[1]);
    
    return 0;
}