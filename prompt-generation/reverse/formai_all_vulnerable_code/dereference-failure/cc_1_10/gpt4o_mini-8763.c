//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(const char *src_path, const char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dst_file = fopen(dst_path, "wb");
    if (!src_file || !dst_file) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
    printf("Copied: %s to %s\n", src_path, dst_path);
}

void synchronize_directories(const char *src_dir, const char *dst_dir) {
    struct dirent *entry;
    DIR *src = opendir(src_dir);
    if (src == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(src)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_path[256], dst_path[256];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        struct stat src_stat, dst_stat;

        // Check if source file exists
        if (stat(src_path, &src_stat) == -1) {
            perror("Stat error on source");
            continue;
        }

        // If destination file exists, check modification time
        if (stat(dst_path, &dst_stat) == -1) {
            // Destination file doesn't exist, copy source to destination
            copy_file(src_path, dst_path);
        } else {
            // Compare modification times
            if (src_stat.st_mtime > dst_stat.st_mtime) {
                // Source is newer, copy to destination
                copy_file(src_path, dst_path);
            } else {
                printf("Skipping (not newer): %s\n", src_path);
            }
        }
    }
    closedir(src);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    synchronize_directories(src_dir, dst_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}