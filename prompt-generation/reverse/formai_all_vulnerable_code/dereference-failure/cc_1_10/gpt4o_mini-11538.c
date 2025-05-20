//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_directory(const char *dir_path, long *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *directory = opendir(dir_path);

    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    // It's a directory, recurse into it
                    long subdir_size = 0;
                    analyze_directory(full_path, &subdir_size);
                    printf("Directory: %s, Size: %ld bytes\n", full_path, subdir_size);
                    *total_size += subdir_size;
                } else {
                    // It's a file, add its size to the total
                    printf("File: %s, Size: %ld bytes\n", full_path, file_stat.st_size);
                    *total_size += file_stat.st_size;
                }
            } else {
                perror("Unable to get file stats");
            }
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long total_size = 0;
    analyze_directory(argv[1], &total_size);
    printf("\nTotal size of directory '%s': %ld bytes\n", argv[1], total_size);

    return EXIT_SUCCESS;
}