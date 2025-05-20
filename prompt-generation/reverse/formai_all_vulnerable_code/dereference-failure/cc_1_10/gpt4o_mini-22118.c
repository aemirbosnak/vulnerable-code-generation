//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_MAX 4096

void copy_file(const char *src_path, const char *dst_path) {
    FILE *src = fopen(src_path, "rb");
    FILE *dst = fopen(dst_path, "wb");

    if (src == NULL || dst == NULL) {
        perror("File open error");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
}

int copy_newer_files(const char *src_dir, const char *dst_dir) {
    DIR *src = opendir(src_dir);
    if (src == NULL) {
        perror("Unable to open source directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(src)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files and '.' entries

        char src_path[PATH_MAX];
        char dst_path[PATH_MAX];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        struct stat src_stat, dst_stat;
        if (stat(src_path, &src_stat) == -1) {
            perror("Source stat error");
            continue;
        }

        if (stat(dst_path, &dst_stat) == -1) {
            // Destination file doesn't exist, copy the file
            printf("Copying (not found in dst): %s -> %s\n", src_path, dst_path);
            copy_file(src_path, dst_path);
        } else {
            // Check if the source file is newer
            if (difftime(src_stat.st_mtime, dst_stat.st_mtime) > 0) {
                printf("Copying (newer): %s -> %s\n", src_path, dst_path);
                copy_file(src_path, dst_path);
            }
        }
    }

    closedir(src);
    return 0;
}

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    if (copy_newer_files(src_dir, dst_dir) == -1) {
        return EXIT_FAILURE;
    }

    printf("Synchronization complete from %s to %s.\n", src_dir, dst_dir);
    return EXIT_SUCCESS;
}