//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

// Function prototypes
void sync_directories(const char *source, const char *destination);
int copy_file(const char *source_file, const char *dest_file);
void ensure_directory_exists(const char *path);
void recursive_sync(const char *source, const char *destination);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    sync_directories(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

// Function to synchronize two directories
void sync_directories(const char *source, const char *destination) {
    ensure_directory_exists(destination);
    recursive_sync(source, destination);
}

// Function to ensure that a directory exists, creating it if it does not
void ensure_directory_exists(const char *path) {
    struct stat st = {0};
    if (stat(path, &st) == -1) {
        mkdir(path, 0700);
    }
}

// Function to perform recursive synchronization
void recursive_sync(const char *source, const char *destination) {
    struct dirent *entry;
    DIR *dp = opendir(source);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        // Ignore the special directories "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];
        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively sync subdirectories
            ensure_directory_exists(dest_path);
            recursive_sync(source_path, dest_path);
        } else if (entry->d_type == DT_REG) {
            // Copy regular files
            if (copy_file(source_path, dest_path) == -1) {
                fprintf(stderr, "Failed to copy %s to %s\n", source_path, dest_path);
            }
        }
    }
    closedir(dp);
}

// Function to copy a file from source to destination
int copy_file(const char *source_file, const char *dest_file) {
    FILE *src_fp = fopen(source_file, "rb");
    if (src_fp == NULL) {
        perror("fopen source");
        return -1;
    }

    FILE *dest_fp = fopen(dest_file, "wb");
    if (dest_fp == NULL) {
        perror("fopen destination");
        fclose(src_fp);
        return -1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytes, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);
    
    return 0;
}