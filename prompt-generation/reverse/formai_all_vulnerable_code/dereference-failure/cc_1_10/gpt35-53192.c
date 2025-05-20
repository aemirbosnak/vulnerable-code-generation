//FormAI DATASET v1.0 Category: File Synchronizer ; Style: lively
/*
 * C File Synchronizer
 * 
 * This program synchronizes two directories by copying missing files or those that are not up-to-date, from one directory to the other.
 * The program takes two arguments as input: the source and destination directories.
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Synchronize directory structure recursively
void sync_directory(char *src_dir, char *dst_dir){
    struct dirent *dir_entry;
    DIR *dir = opendir(src_dir);

    if (dir != NULL) {
        // Traverse all the files and sub-directories in the source directory
        while ((dir_entry = readdir(dir)) != NULL) {
            char src_path[PATH_MAX], dst_path[PATH_MAX];
            struct stat st;

            // Ignore parent and current directory entries
            if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
                continue;

            sprintf(src_path, "%s/%s", src_dir, dir_entry->d_name);
            sprintf(dst_path, "%s/%s", dst_dir, dir_entry->d_name);

            // Get file status
            if (lstat(src_path, &st) < 0)
                continue;

            // Create the destination directory if it does not exist
            if (S_ISDIR(st.st_mode)) {
                if (access(dst_path, F_OK) < 0) {
                    mkdir(dst_path, st.st_mode);
                    printf("Created directory %s\n", dst_path);
                }
                sync_directory(src_path, dst_path);
            }
            // Copy the file if it is not up-to-date or does not exist in the destination directory
            else {
                struct stat st_dst;
                if (access(dst_path, F_OK) < 0 || (lstat(dst_path, &st_dst) == 0 && st.st_mtime > st_dst.st_mtime)) {
                    FILE *src_file = fopen(src_path, "rb");
                    FILE *dst_file = fopen(dst_path, "wb");
                    char buf[4096];
                    size_t n;

                    printf("Copying %s to %s\n", src_path, dst_path);

                    while ((n = fread(buf, 1, sizeof(buf), src_file)) > 0) {
                        if (fwrite(buf, 1, n, dst_file) != n) {
                            printf("Error writing to file %s\n", dst_path);
                            break;
                        }
                    }
                    fclose(src_file);
                    fclose(dst_file);
                }
            }
        }
        closedir(dir);
    }
}

// Main function
int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: %s [Source Dir] [Destination Dir]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_directory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}