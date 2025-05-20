//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long long *total_size, int *file_count, int *dir_count) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &statbuf) == -1) {
            perror("Error getting file stats");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            (*dir_count)++;
            analyze_directory(full_path, total_size, file_count, dir_count);
        } else {
            (*file_count)++;
            *total_size += statbuf.st_size;
        }
    }
    closedir(dir);
}

void display_results(const char *path, long long total_size, int file_count, int dir_count) {
    printf("Wow! You've hit the jackpot!\n");
    printf("Directory analyzed: %s\n", path);
    printf("Total files: %d\n", file_count);
    printf("Total directories: %d\n", dir_count);
    printf("Total size: %lld bytes\n", total_size);
    printf("Impressive, isn't it?\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *start_path = argv[1];
    long long total_size = 0;
    int file_count = 0;
    int dir_count = 0;

    printf("Hold on tight! Analyzing the wondrous realm of: %s\n", start_path);
    analyze_directory(start_path, &total_size, &file_count, &dir_count);
    display_results(start_path, total_size, file_count, dir_count);

    return EXIT_SUCCESS;
}