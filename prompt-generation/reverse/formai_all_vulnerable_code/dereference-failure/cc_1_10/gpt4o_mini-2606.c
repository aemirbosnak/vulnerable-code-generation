//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

void analyze_directory(const char *directory, long long *total_size, int *file_count, int *dir_count) {
    struct dirent *entry;
    struct stat entry_stat;
    DIR *dp = opendir(directory);

    if (!dp) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory links
        }

        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

        if (stat(full_path, &entry_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(entry_stat.st_mode)) {
            // It's a directory
            (*dir_count)++;
            analyze_directory(full_path, total_size, file_count, dir_count);
        } else if (S_ISREG(entry_stat.st_mode)) {
            // It's a regular file
            (*file_count)++;
            (*total_size) += entry_stat.st_size;
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    int file_count = 0, dir_count = 0;

    analyze_directory(argv[1], &total_size, &file_count, &dir_count);

    printf("Directory: %s\n", argv[1]);
    printf("Total files: %d\n", file_count);
    printf("Total directories: %d\n", dir_count);
    printf("Total size: %lld bytes\n", total_size);
    
    return EXIT_SUCCESS;
}