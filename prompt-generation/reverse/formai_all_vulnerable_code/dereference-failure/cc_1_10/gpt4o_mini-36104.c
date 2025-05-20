//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

// Function to calculate the size of a directory recursively
long long get_directory_size(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    long long total_size = 0;

    // Attempt to open the directory
    if ((dir = opendir(directory)) == NULL) {
        perror("Failed to open directory");
        return -1;
    }

    // Loop through entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..'
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            // Get stats of the entry
            if (stat(path, &statbuf) == 0) {
                // If it's a directory, make a recursive call
                if (S_ISDIR(statbuf.st_mode)) {
                    long long dir_size = get_directory_size(path);
                    if (dir_size != -1) {
                        total_size += dir_size;
                    }
                } else {
                    // It's a file, add its size
                    total_size += statbuf.st_size;
                }
            } else {
                perror("Failed to get stats");
            }
        }
    }

    // Close the directory
    closedir(dir);
    return total_size;
}

// Function to print human-readable sizes
void print_size(long long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    while (size >= 1024 && unit_index < sizeof(units)/sizeof(units[0]) - 1) {
        size /= 1024;
        unit_index++;
    }

    printf("%lld %s\n", size, units[unit_index]);
}

int main(int argc, char *argv[]) {
    // Welcome message
    printf("Welcome to the Energetic Disk Space Analyzer!\n");
    printf("Let's explore your filesystem and analyze some disk space!\n");

    // Check if the directory path is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    printf("Analyzing directory: %s...\n", directory);

    // Calculate the directory size
    long long total_size = get_directory_size(directory);
    
    // If size calculation was successful, print the results
    if (total_size != -1) {
        printf("Total size of directory '%s': ", directory);
        print_size(total_size);
    } else {
        fprintf(stderr, "Error analyzing directory '%s'\n", directory);
    }

    // Ending message
    printf("Thank you for using the Energetic Disk Space Analyzer!\n");
    printf("Keep your files organized and your disk clean!\n");
    
    return EXIT_SUCCESS;
}