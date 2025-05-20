//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

void calculate_directory_size(const char *path, long long *total_size, int *file_count);
void print_size_summary(const char *path, long long size, int files);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    int file_count = 0;

    const char *directory_path = argv[1];
    calculate_directory_size(directory_path, &total_size, &file_count);
    print_size_summary(directory_path, total_size, file_count);

    return EXIT_SUCCESS;
}

void calculate_directory_size(const char *path, long long *total_size, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            calculate_directory_size(full_path, total_size, file_count); // Recursive call for subdirectories
        } else if (S_ISREG(file_stat.st_mode)) {
            *total_size += file_stat.st_size;
            (*file_count)++;
        }
    }

    closedir(dp);
}

void print_size_summary(const char *path, long long size, int files) {
    printf("Directory: %s\n", path);
    printf("Total Size: %lld bytes\n", size);
    printf("Total Files: %d\n", files);
    printf("Average File Size: %f bytes\n", files > 0 ? (double)size / files : 0.0);
}