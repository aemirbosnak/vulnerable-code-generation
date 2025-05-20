//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 4096

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

void sync_file(const char *src, const char *dst) {
    FILE *source_file = fopen(src, "rb");
    FILE *dest_file = fopen(dst, "wb");

    if (source_file == NULL || dest_file == NULL) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

void sync_directory(const char *src_dir, const char *dst_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);

    if (dp == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char src_path[MAX_PATH_LENGTH];
            char dst_path[MAX_PATH_LENGTH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

            if (entry->d_type == DT_REG) { // If it's a regular file
                if (!file_exists(dst_path)) {
                    printf("Copying new file: %s -> %s\n", src_path, dst_path);
                    sync_file(src_path, dst_path);
                } else {
                    printf("File exists, skipping: %s\n", dst_path);
                }
            } else if (entry->d_type == DT_DIR) { // If it's a directory
                if (!file_exists(dst_path)) {
                    mkdir(dst_path, 0755);
                }
                sync_directory(src_path, dst_path); // Recur into the directory
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    // Check if source directory exists
    if (!file_exists(src_dir)) {
        fprintf(stderr, "Source directory does not exist: %s\n", src_dir);
        exit(EXIT_FAILURE);
    }

    // Create destination directory if it doesn't exist
    if (!file_exists(dst_dir)) {
        if (mkdir(dst_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            exit(EXIT_FAILURE);
        }
    }

    sync_directory(src_dir, dst_dir);

    printf("Synchronization complete!\n");
    return 0;
}