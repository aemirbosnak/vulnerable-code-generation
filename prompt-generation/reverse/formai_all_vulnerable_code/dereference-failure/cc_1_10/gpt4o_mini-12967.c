//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path, long long *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the . and .. entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            perror("Error getting file stats");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            long long subdir_size = 0;
            analyze_directory(full_path, &subdir_size);
            printf("Directory: %s, Size: %lld bytes\n", full_path, subdir_size);
            *total_size += subdir_size;
        } else if (S_ISREG(file_stat.st_mode)) {
            printf("File: %s, Size: %lld bytes\n", full_path, file_stat.st_size);
            *total_size += file_stat.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *dir_path = argv[1];
    long long total_size = 0;

    analyze_directory(dir_path, &total_size);
    printf("Total size of directory '%s': %lld bytes\n", dir_path, total_size);

    return EXIT_SUCCESS;
}