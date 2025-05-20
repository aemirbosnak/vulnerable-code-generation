//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", program_name);
}

void sync_files(const char *src_dir, const char *dst_dir) {
    struct stat src_stat, dst_stat;
    char src_path[MAX_PATH], dst_path[MAX_PATH];
    DIR *src, *dst;
    struct dirent *entry;

    if (!(src = opendir(src_dir))) {
        perror("Source directory opening failed");
        exit(EXIT_FAILURE);
    }

    // Create destination directory if it doesn't exist
    if (stat(dst_dir, &dst_stat) != 0) {
        if (mkdir(dst_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            closedir(src);
            exit(EXIT_FAILURE);
        }
    }

    while ((entry = readdir(src)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        if (stat(src_path, &src_stat) == 0) { 
            // Check if the entry is a file or directory
            if (S_ISDIR(src_stat.st_mode)) {
                // Recursive call for directories
                sync_files(src_path, dst_path);
            } else {
                // File synchronization logic
                if (stat(dst_path, &dst_stat) != 0 || 
                    src_stat.st_mtime > dst_stat.st_mtime || 
                    src_stat.st_size != dst_stat.st_size) {
                    // Copy file if it doesn't exist or is outdated
                    FILE *src_file = fopen(src_path, "rb");
                    if (src_file) {
                        FILE *dst_file = fopen(dst_path, "wb");
                        if (dst_file) {
                            char buffer[BUFFER_SIZE];
                            size_t bytes;
                            while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src_file)) > 0) {
                                fwrite(buffer, sizeof(char), bytes, dst_file);
                            }
                            fclose(dst_file);
                        } else {
                            perror("Failed to open destination file");
                        }
                        fclose(src_file);
                        printf("Copied: %s -> %s\n", src_path, dst_path);
                    } else {
                        perror("Failed to open source file");
                    }
                } else {
                    printf("No changes: %s -> %s\n", src_path, dst_path);
                }
            }
        } else {
            perror("Stat error for source file");
        }
    }

    closedir(src);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);
    printf("Synchronization completed.\n");

    return EXIT_SUCCESS;
}