//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void traverse_directory(const char *dir_path, long long *total_size, int level);
void print_spaces(int level);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    traverse_directory(argv[1], &total_size, 0);

    printf("Total Disk Space Used: %lld bytes\n", total_size);

    return EXIT_SUCCESS;
}

void traverse_directory(const char *dir_path, long long *total_size, int level) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        fprintf(stderr, "Error: Unable to open directory %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (stat(path, &file_stat) == -1) {
            fprintf(stderr, "Error: Unable to stat %s\n", path);
            continue;
        }

        // If it's a directory, recursively traverse it
        if (S_ISDIR(file_stat.st_mode)) {
            print_spaces(level);
            printf("Directory: %s\n", path);
            traverse_directory(path, total_size, level + 1);
        } else {
            // It's a regular file, accumulate its size
            *total_size += file_stat.st_size;
            print_spaces(level);
            printf("File: %s (%lld bytes)\n", path, file_stat.st_size);
        }
    }

    closedir(dp);
}

void print_spaces(int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}