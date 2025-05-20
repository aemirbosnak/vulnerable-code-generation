//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFSIZE 4096

// Recursively copy a directory from 'src' to 'dst'
void copy_dir(const char *src, const char *dst) {
    // Create destination directory if it doesn't exist
    struct stat st;
    if (stat(dst, &st) == -1) {
        mkdir(dst, 0755);
    }

    // Open source directory
    DIR *src_dir = opendir(src);
    if (src_dir == NULL) {
        perror("opendir");
        return;
    }

    // Loop through source directory entries
    struct dirent *dirent;
    while ((dirent = readdir(src_dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        // Get file paths
        char src_path[PATH_MAX];
        char dst_path[PATH_MAX];
        snprintf(src_path, sizeof(src_path), "%s/%s", src, dirent->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, dirent->d_name);

        // Get file stats
        struct stat src_stat;
        if (lstat(src_path, &src_stat) == -1) {
            perror("lstat");
            continue;
        }

        // If it's a directory, recursively copy it
        if (S_ISDIR(src_stat.st_mode)) {
            copy_dir(src_path, dst_path);
        }
        // If it's a regular file, copy it
        else if (S_ISREG(src_stat.st_mode)) {
            FILE *src_file = fopen(src_path, "rb");
            if (src_file == NULL) {
                perror("fopen");
                continue;
            }
            FILE *dst_file = fopen(dst_path, "wb");
            if (dst_file == NULL) {
                perror("fopen");
                fclose(src_file);
                continue;
            }
            size_t bytes_read;
            char buffer[BUFFSIZE];
            while ((bytes_read = fread(buffer, 1, BUFFSIZE, src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dst_file);
            }
            fclose(src_file);
            fclose(dst_file);
        }
        // Otherwise, skip it
        else {
            continue;
        }
    }

    closedir(src_dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    copy_dir(argv[1], argv[2]);

    return 0;
}