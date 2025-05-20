//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

// Function to check if the file needs to be copied
int should_copy(const char *src_path, const char *dst_path) {
    struct stat src_stat, dst_stat;

    if (stat(src_path, &src_stat) == -1) {
        perror("Failed to get source file status");
        return 0;
    }
    if (stat(dst_path, &dst_stat) == -1) {
        // If destination file doesn't exist, we should copy
        return 1;
    }

    // Compare modification times
    return src_stat.st_mtime > dst_stat.st_mtime;
}

// Function to copy file from src to dst
void copy_file(const char *src_path, const char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dst_file = fopen(dst_path, "wb");
    if (!dst_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
    printf("Copied: %s to %s\n", src_path, dst_path);
}

// Function to synchronize files from src_dir to dst_dir
void sync_directories(const char *src_dir, const char *dst_dir) {
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build full paths for source and destination
        char src_path[MAX_PATH];
        char dst_path[MAX_PATH];
        snprintf(src_path, MAX_PATH, "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, MAX_PATH, "%s/%s", dst_dir, entry->d_name);

        struct stat entry_stat;
        if (stat(src_path, &entry_stat) == -1) {
            perror("Failed to get entry status");
            continue;
        }

        if (S_ISDIR(entry_stat.st_mode)) {
            // Create directory in destination if it doesn't exist
            mkdir(dst_path, 0755);
            // Recursively sync sub-directory
            sync_directories(src_path, dst_path);
        } else {
            // Check if we need to copy the file
            if (should_copy(src_path, dst_path)) {
                copy_file(src_path, dst_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    struct stat dst_stat;
    if (stat(dst_dir, &dst_stat) == -1) {
        // If destination directory doesn't exist, create it
        if (mkdir(dst_dir, 0755) == -1) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
    } else if (!S_ISDIR(dst_stat.st_mode)) {
        fprintf(stderr, "Destination path is not a directory.\n");
        return EXIT_FAILURE;
    }

    sync_directories(src_dir, dst_dir);
    printf("Synchronization complete.\n");
    return EXIT_SUCCESS;
}