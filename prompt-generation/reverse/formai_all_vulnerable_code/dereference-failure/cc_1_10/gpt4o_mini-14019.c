//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path, long *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    char path[MAX_PATH];

    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (stat(path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // Recursively analyze subdirectories
            analyze_directory(path, total_size);
        } else if (S_ISREG(file_stat.st_mode)) {
            // Only consider regular files
            *total_size += file_stat.st_size;
            printf("File: %s, Size: %ld bytes\n", path, file_stat.st_size);
        }
    }

    closedir(dir);
}

void display_usage(long total_size) {
    printf("\nTotal Disk Usage: %ld bytes\n", total_size);
    printf("Total Disk Usage: %.2f MB\n", total_size / (1024.0 * 1024.0));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long total_size = 0;
    const char *directory_path = argv[1];

    printf("Analyzing directory: %s\n", directory_path);
    analyze_directory(directory_path, &total_size);

    display_usage(total_size);
    return EXIT_SUCCESS;
}