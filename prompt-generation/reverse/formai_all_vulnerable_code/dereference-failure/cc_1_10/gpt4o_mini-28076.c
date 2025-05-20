//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void analyze_directory(const char *dir_path, long long *total_size) {
    DIR *directory;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];

    directory = opendir(dir_path);
    if (directory == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            fprintf(stderr, "Error retrieving info for: %s\n", full_path);
            continue;
        }

        // If it is a directory, recursively analyze it
        if (S_ISDIR(file_stat.st_mode)) {
            analyze_directory(full_path, total_size);
        } else {
            // If it is a file, accumulate its size
            *total_size += file_stat.st_size;
        }
    }

    closedir(directory);
}

void display_size(long long total_size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    while (total_size >= 1024 && unit_index < 4) {
        total_size /= 1024;
        unit_index++;
    }

    printf("Total Disk Space Used: %.2f %s\n", (double)total_size, units[unit_index]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    long long total_size = 0;
    const char *dir_path = argv[1];

    printf("Analyzing the peaceful realm of disk space...\n");
    printf("Directory: %s\n\n", dir_path);

    analyze_directory(dir_path, &total_size);
    display_size(total_size);

    printf("\nThe analysis journey is complete. May your disk spaces remain serene.\n");

    return 0;
}