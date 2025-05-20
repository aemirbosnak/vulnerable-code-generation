//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

bool my_file_explorer(char *path) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        perror(path);
        return false;
    }
    struct dirent *entry;
    int num_files = 0;
    int num_subdirs = 0;
    double total_size = 0;
    while ((entry = readdir(directory)) != NULL) {
        struct stat file_info;
        char full_path[strlen(path) + strlen(entry->d_name) + 2]; // +2 for slash and null terminator
        sprintf(full_path, "%s/%s", path, entry->d_name);
        if (lstat(full_path, &file_info) == -1) {
            perror(full_path);
            closedir(directory);
            return false;
        }
        if (S_ISDIR(file_info.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                num_subdirs++;
                if (!my_file_explorer(full_path)) {
                    closedir(directory);
                    return false;
                }
            }
        } else {
            num_files++;
            total_size += file_info.st_size;
        }
    }
    closedir(directory);
    printf("%s: %d files, %d subdirectories, %.2f MB\n", path, num_files, num_subdirs, total_size / (1024.0 * 1024.0));
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (!my_file_explorer(argv[1])) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}