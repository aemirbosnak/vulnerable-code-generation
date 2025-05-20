//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function to get the full path of a file
void get_full_path(const char *dir, const char *file, char *full_path) {
    snprintf(full_path, MAX_PATH, "%s/%s", dir, file);
}

// Function to check if a file exists
int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Function to get the modification time of a file
time_t get_modification_time(const char *path) {
    struct stat buffer;
    if (stat(path, &buffer) != 0) {
        return -1; // Error occurred
    }
    return buffer.st_mtime;
}

// Function to copy a file from source to destination
void copy_file(const char *src, const char *dest) {
    FILE *source_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");

    if (!source_file || !dest_file) {
        perror("File error");
        return;
    }

    char buffer[1024];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, n, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    printf("Copied: %s to %s\n", src, dest);
}

// Function to synchronize two directories
void synchronize_directories(const char *source, const char *destination) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(source))) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];

        get_full_path(source, entry->d_name, src_path);
        get_full_path(destination, entry->d_name, dest_path);

        if (file_exists(src_path)) {
            if (!file_exists(dest_path) || get_modification_time(src_path) > get_modification_time(dest_path)) {
                copy_file(src_path, dest_path);
            }
        } else {
            fprintf(stderr, "Missing file in source: %s\n", src_path);
        }
    }

    closedir(dir);
}

// Main function that receives input from the user and initiates synchronization
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    synchronize_directories(source_directory, destination_directory);

    printf("Synchronization completed from %s to %s\n", source_directory, destination_directory);
    
    return EXIT_SUCCESS;
}