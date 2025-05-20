//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define PATH_SIZE 1024
#define OUTPUT_SIZE 2048

typedef struct {
    char name[PATH_SIZE];
    off_t size;
} FileInfo;

void analyze_directory(const char *path, off_t *total_size, int *file_count, int *dir_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[PATH_SIZE];

    if (!(dir = opendir(path))) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip "." and ".."
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            perror("Error getting file stats");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            (*dir_count)++;
            analyze_directory(full_path, total_size, file_count, dir_count); // Recur for subdirectories
        } else {
            (*file_count)++;
            *total_size += file_stat.st_size; // Add file size to total
        }
    }

    closedir(dir);
}

void print_disk_usage(const char *path) {
    off_t total_size = 0;
    int file_count = 0, dir_count = 0;

    analyze_directory(path, &total_size, &file_count, &dir_count);

    printf("Disk Usage Summary for '%s':\n", path);
    printf("Total files: %d\n", file_count);
    printf("Total directories: %d\n", dir_count);
    printf("Total size: %lld bytes\n", (long long)total_size);
    printf("Total size: %.2f MB\n", (double)total_size / (1024 * 1024));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_disk_usage(argv[1]);
    return EXIT_SUCCESS;
}