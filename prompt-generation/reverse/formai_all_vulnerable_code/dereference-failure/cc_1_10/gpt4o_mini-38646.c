//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to analyze space and accumulate total size
void analyze_directory(const char *path, long long *total_size) {
    struct dirent *entry;
    struct stat file_stats;

    // Open the directory
    DIR *dp = opendir(path);
    if (dp == NULL) {
        printf("Whoa! Can't open directory: %s\n", path);
        return;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        // Ignore the . and .. directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        // Get the file stats
        if (stat(full_path, &file_stats) == -1) {
            printf("Surprise! Can't get stats for: %s\n", full_path);
            continue;
        }

        // Check if it's a directory or a file
        if (S_ISDIR(file_stats.st_mode)) {
            printf("Exploring the mysterious directory: %s...\n", full_path);
            analyze_directory(full_path, total_size); // Recurse into directory
        } else {
            printf("Found a treasure file: %s (Size: %lld bytes)\n", full_path, file_stats.st_size);
            *total_size += file_stats.st_size; // Accumulate size
        }
    }

    // Close the directory
    closedir(dp);
}

// The main function - the starting point of the surprise!
int main(int argc, char *argv[]) {
    long long total_size = 0;

    // Check if directory is passed as argument
    if (argc < 2) {
        printf("Oh no! You forgot to provide a directory path. Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    printf("Let the disk space analysis begin in directory: %s\n", argv[1]);
    
    // Start the analysis
    analyze_directory(argv[1], &total_size);
    
    // Output the total size found
    printf("Wow! The total size of files in %s is: %lld bytes\n", argv[1], total_size);
    return 0;
}