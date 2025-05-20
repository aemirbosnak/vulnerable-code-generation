//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void sync_files(const char *src, const char *dst);
void create_dir_if_not_exists(const char *path);
int is_file_updated(const char *src_file, const char *dst_file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    sync_files(src_dir, dst_dir);
    printf("Synchronization completed from %s to %s\n", src_dir, dst_dir);
    return EXIT_SUCCESS;
}

void sync_files(const char *src, const char *dst) {
    DIR *dir = opendir(src);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[1024];
        char dst_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, entry->d_name);

        struct stat stat_buf;
        if (stat(src_path, &stat_buf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(stat_buf.st_mode)) {
            // Create the destination directory
            create_dir_if_not_exists(dst_path);
            // Recur into the directory
            sync_files(src_path, dst_path);
        } else if (S_ISREG(stat_buf.st_mode)) {
            // Sync the file if it doesn't exist or is updated
            if (!is_file_updated(src_path, dst_path)) {
                FILE *src_file = fopen(src_path, "rb");
                FILE *dst_file = fopen(dst_path, "wb");
                if (src_file && dst_file) {
                    char buffer[1024];
                    size_t bytes;
                    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, bytes, dst_file);
                    }
                    fclose(src_file);
                    fclose(dst_file);
                    printf("Copied: %s -> %s\n", src_path, dst_path);
                } else {
                    perror("Failed to open files for copying");
                    if (src_file) fclose(src_file);
                    if (dst_file) fclose(dst_file);
                }
            }
        }
    }
    closedir(dir);
}

void create_dir_if_not_exists(const char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        if (mkdir(path, 0755) != 0) {
            perror("Failed to create destination directory");
        }
    }
}

int is_file_updated(const char *src_file, const char *dst_file) {
    struct stat src_stat, dst_stat;
    if (stat(src_file, &src_stat) == -1) {
        perror("Failed to get source file status");
        return 1; // Consider it updated if any error occurs
    }

    if (stat(dst_file, &dst_stat) == -1) {
        return 1; // Destination file doesn't exist, so source is updated
    }

    // Compare modification times
    return src_stat.st_mtime > dst_stat.st_mtime;
}