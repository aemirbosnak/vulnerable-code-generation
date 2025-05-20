//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(const char *path, long *total_size, int *file_count, int *dir_count);

void analyze_directory(const char *path, long *total_size, int *file_count, int *dir_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];

    // Open the directory
    if ((dir = opendir(path)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get file stats
        if (stat(full_path, &file_stat) == -1) {
            perror("Unable to retrieve file stats");
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) { // If it's a regular file
            *total_size += file_stat.st_size; // Add to total size
            (*file_count)++; // Increment file count
        } else if (S_ISDIR(file_stat.st_mode)) { // If it's a directory
            (*dir_count)++; // Increment directory count
            analyze_directory(full_path, total_size, file_count, dir_count); // Analyze subdirectory
        }
    }

    closedir(dir); // Close the directory
}

int main(int argc, char *argv[]) {
    long total_size = 0;
    int file_count = 0;
    int dir_count = 0;

    // Check if the user provided a directory
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze the specified directory
    analyze_directory(argv[1], &total_size, &file_count, &dir_count);

    // Print the summary
    printf("Directory: %s\n", argv[1]);
    printf("Total Size: %ld bytes\n", total_size);
    printf("Total Files: %d\n", file_count);
    printf("Total Directories: %d\n", dir_count);

    return EXIT_SUCCESS;
}