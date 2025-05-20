//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

void analyze_directory(const char *dir_path, long long *total_size, int *small_count, int *medium_count, int *large_count) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH_LENGTH];
    
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            perror("Unable to get file status");
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(file_stat.st_mode)) {
            analyze_directory(full_path, total_size, small_count, medium_count, large_count);  // Recursive call
        } else {
            (*total_size) += file_stat.st_size;
            if (file_stat.st_size < 1024) {
                (*small_count)++;
            } else if (file_stat.st_size < 1048576) {
                (*medium_count)++;
            } else {
                (*large_count)++;
            }
        }
    }
    closedir(dp);
}

void print_summary(long long total_size, int small_count, int medium_count, int large_count) {
    printf("Disk Space Analyzer Summary:\n");
    printf("----------------------------\n");
    printf("Total Size of Files: %lld bytes\n", total_size);
    printf("Small files (< 1 KB): %d\n", small_count);
    printf("Medium files (1 KB - 1 MB): %d\n", medium_count);
    printf("Large files (> 1 MB): %d\n", large_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    int small_count = 0, medium_count = 0, large_count = 0;

    analyze_directory(argv[1], &total_size, &small_count, &medium_count, &large_count);
    
    print_summary(total_size, small_count, medium_count, large_count);

    return EXIT_SUCCESS;
}