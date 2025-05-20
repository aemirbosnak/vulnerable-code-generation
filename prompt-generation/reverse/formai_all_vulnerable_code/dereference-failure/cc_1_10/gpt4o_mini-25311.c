//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

// Helper function to check if a file exists
int file_exists(const char *file_path) {
    struct stat buffer;   
    return (stat(file_path, &buffer) == 0);
}

// Helper function to copy a file from source to destination
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

// Synchronize the files from the source directory to the destination directory
void sync_directories(const char *source, const char *destination) {
    DIR *dir = opendir(source);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    char source_path[BUFFER_SIZE];
    char dest_path[BUFFER_SIZE];

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        // Check if it is a directory
        struct stat statbuf;
        if (stat(source_path, &statbuf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Create the destination directory if it doesn't exist
            mkdir(dest_path, 0755);
            sync_directories(source_path, dest_path);
        } else {
            // Copy the file if it doesn't exist in destination
            if (!file_exists(dest_path)) {
                printf("Copying file: %s to %s\n", source_path, dest_path);
                copy_file(source_path, dest_path);
            }
            // Add logic to update existing files if they differ (using mtime)
            else if (stat(source_path, &statbuf) == 0) {
                struct stat dest_stat;
                if (stat(dest_path, &dest_stat) == 0) {
                    // Compare modification times
                    if (difftime(statbuf.st_mtime, dest_stat.st_mtime) > 0) {
                        printf("Updating file: %s to %s\n", source_path, dest_path);
                        copy_file(source_path, dest_path);
                    }
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Create the destination directory if it does not exist
    if (!file_exists(destination_directory)) {
        mkdir(destination_directory, 0755);
    }

    sync_directories(source_directory, destination_directory);
    printf("File synchronization complete between '%s' and '%s'.\n", source_directory, destination_directory);
    return EXIT_SUCCESS;
}