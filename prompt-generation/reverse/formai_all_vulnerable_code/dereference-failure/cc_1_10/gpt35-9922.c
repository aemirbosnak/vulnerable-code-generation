//FormAI DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/*
 * This program synchronizes the content of two directories by comparing 
 * the files in both directories and updating the files in the destination 
 * directory if necessary.
 */

void sync_dir(const char *src_dir, const char *dst_dir);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    sync_dir(argv[1], argv[2]);

    printf("Synchronization complete!\n");

    return 0;
}

void sync_dir(const char *src_dir, const char *dst_dir) {
    struct dirent *entry_src, *entry_dst;
    DIR *dir_src, *dir_dst;

    dir_src = opendir(src_dir);
    if (dir_src == NULL) {
        perror("Error opening source directory");
        exit(1);
    }

    dir_dst = opendir(dst_dir);
    if (dir_dst == NULL) {
        perror("Error opening destination directory");
        exit(1);
    }

    // Walk through the source directory
    while ((entry_src = readdir(dir_src)) != NULL) {
        char *filename_src = entry_src->d_name;
        if (strcmp(filename_src, ".") == 0 || strcmp(filename_src, "..") == 0) {
            continue;
        }

        // Look for the corresponding file in the destination directory
        rewinddir(dir_dst);
        int found = 0;
        while ((entry_dst = readdir(dir_dst)) != NULL) {
            char *filename_dst = entry_dst->d_name;
            if (strcmp(filename_dst, ".") == 0 || strcmp(filename_dst, "..") == 0) {
                continue;
            }

            if (strcmp(filename_src, filename_dst) == 0) {
                found = 1;
                break;
            }
        }

        // If the file exists in both directories, compare their modification time
        // and update the destination file if necessary
        if (found) {
            struct stat stat_src, stat_dst;
            char path_src[1024], path_dst[1024];
            snprintf(path_src, sizeof(path_src), "%s/%s", src_dir, filename_src);
            snprintf(path_dst, sizeof(path_dst), "%s/%s", dst_dir, filename_src);
            stat(path_src, &stat_src);
            stat(path_dst, &stat_dst);
            if (difftime(stat_src.st_mtime, stat_dst.st_mtime) > 0) {
                // Source file is newer, update the destination file
                printf("Updating file %s\n", path_dst);
                FILE *src_file = fopen(path_src, "rb");
                if (src_file == NULL) {
                    perror("Error opening source file");
                    exit(1);
                }
                FILE *dst_file = fopen(path_dst, "wb");
                if (dst_file == NULL) {
                    perror("Error opening destination file");
                    exit(1);
                }
                char buffer[1024];
                size_t nread;
                while ((nread = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, nread, dst_file);
                }
                fclose(src_file);
                fclose(dst_file);
            }
        } else {
            // File only exists in source directory, copy to destination directory
            printf("Copying file %s\n", filename_src);
            char path_src[1024], path_dst[1024];
            snprintf(path_src, sizeof(path_src), "%s/%s", src_dir, filename_src);
            snprintf(path_dst, sizeof(path_dst), "%s/%s", dst_dir, filename_src);
            FILE *src_file = fopen(path_src, "rb");
            if (src_file == NULL) {
                perror("Error opening source file");
                exit(1);
            }
            FILE *dst_file = fopen(path_dst, "wb");
            if (dst_file == NULL) {
                perror("Error opening destination file");
                exit(1);
            }
            char buffer[1024];
            size_t nread;
            while ((nread = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, nread, dst_file);
            }
            fclose(src_file);
            fclose(dst_file);
        }
    }

    closedir(dir_src);
    closedir(dir_dst);
}