//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH 1024

void copy_file(const char *src, const char *dest) {
    int src_fd, dest_fd;
    char buffer[1024];
    ssize_t bytes;

    // Open source file
    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Failed to open source file");
        return;
    }

    // Create destination file
    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Failed to create destination file");
        close(src_fd);
        return;
    }

    // Copy content from source to destination
    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes);
    }

    close(src_fd);
    close(dest_fd);
}

int file_modified(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;

    // Get the status of source and destination files
    if (stat(src, &src_stat) < 0 || stat(dest, &dest_stat) < 0) {
        return 1; // If destination doesn't exist, consider it modified
    }

    // Compare modification times
    return difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0;
}

void synchronize_directory(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];

    // Open source directory
    dir = opendir(src_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    // Iterate through the source directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create full paths for source and destination
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // Check if it is a file (not a directory)
        if (entry->d_type == DT_REG) {
            // If file does not exist in destination or is modified
            if (access(dest_path, F_OK) == -1 || file_modified(src_path, dest_path)) {
                printf("Copying file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        } else if (entry->d_type == DT_DIR) {
            // Handle subdirectory (recursive)
            mkdir(dest_path, 0755); // Create subdirectory
            synchronize_directory(src_path, dest_path); // Recursive call
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
    const char *dest_dir = argv[2];

    // Create destination directory if it doesn't exist
    mkdir(dest_dir, 0755);

    // Start synchronization
    synchronize_directory(src_dir, dest_dir);

    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}