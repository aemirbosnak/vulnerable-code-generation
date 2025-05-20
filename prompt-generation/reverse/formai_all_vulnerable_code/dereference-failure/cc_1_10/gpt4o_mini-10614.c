//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(const char *path);
void display_space(unsigned long total_size, unsigned long file_count);
void get_full_path(char *destination, const char *path, const char *file_name);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Welcome to the Peaceful Disk Space Analyzer!\n");
        printf("Usage: %s <directory_path>\n", argv[0]);
        printf("Please, enter a directory path to analyze peacefully.\n");
        return EXIT_FAILURE;
    }

    printf("Starting the analysis of the directory: %s...\n", argv[1]);
    analyze_directory(argv[1]);
    printf("Thank you for using the Peaceful Disk Space Analyzer!\n");
    return EXIT_SUCCESS;
}

void analyze_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    unsigned long total_size = 0;
    unsigned long file_count = 0;

    dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path for file
        char full_path[1024];
        get_full_path(full_path, path, entry->d_name);

        // Get the file statistics
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) { // Regular file
                total_size += file_stat.st_size;
                file_count++;
            }
        }
    }

    closedir(dir);
    display_space(total_size, file_count);
}

void get_full_path(char *destination, const char *path, const char *file_name) {
    snprintf(destination, 1024, "%s/%s", path, file_name);
}

void display_space(unsigned long total_size, unsigned long file_count) {
    printf("\n--- Disk Space Analysis Results ---\n");
    printf("Total number of files: %lu\n", file_count);
    printf("Total size of files: %lu bytes\n", total_size);
    
    // Display in a more readable format
    if (total_size > 1024 * 1024) {
        printf("Total size: %.2f MB\n", total_size / (1024.0 * 1024.0));
    } else if (total_size > 1024) {
        printf("Total size: %.2f KB\n", total_size / 1024.0);
    } else {
        printf("Total size: %lu bytes\n", total_size);
    }

    printf("-----------------------------------\n");
    printf("May your disk be always organized and peaceful.\n");
}