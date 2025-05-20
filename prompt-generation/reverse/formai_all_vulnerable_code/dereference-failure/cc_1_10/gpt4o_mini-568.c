//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_stats;
    DIR *directory = opendir(dir_path);
    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }

    long total_size = 0;
    printf("Listing files in directory: %s\n\n", dir_path);
    printf("%-40s %12s\n", "File Name", "Size (bytes)");
    printf("--------------------------------------------------\n");

    while ((entry = readdir(directory)) != NULL) {
        // Skip the current and parent directory entries.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &file_stats) == 0) {
            printf("%-40s %12ld\n", entry->d_name, file_stats.st_size);
            total_size += file_stats.st_size;
        } else {
            perror("stat");
        }
    }

    printf("--------------------------------------------------\n");
    printf("%-40s %12ld\n", "Total Size:", total_size);

    closedir(directory);
}

int main() {
    char dir_path[MAX_PATH];
    
    printf("Welcome to the Disk Space Analyzer!\n");
    printf("Please enter the directory path you would like to analyze: ");
    if (fgets(dir_path, sizeof(dir_path), stdin) != NULL) {
        // Remove the newline character from the end of the input
        dir_path[strcspn(dir_path, "\n")] = 0;

        analyze_directory(dir_path);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    printf("\nThank you for using the Disk Space Analyzer!\n");
    return EXIT_SUCCESS;
}