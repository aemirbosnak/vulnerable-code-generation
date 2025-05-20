//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long long *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) == 0) {
            // Check if it is a directory
            if (S_ISDIR(file_stat.st_mode)) {
                printf("Directory: %s, Size: %lld bytes\n", full_path, file_stat.st_size);
                analyze_directory(full_path, total_size); // Recur for subdirectory
            } else {
                printf("File: %s, Size: %lld bytes\n", full_path, file_stat.st_size);
            }

            // Accumulate the total size
            *total_size += file_stat.st_size;
        } else {
            perror("stat");
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    long long total_size = 0;
    const char *path;

    // Default path is current directory if no argument provided
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

    printf("Analyzing directory: %s\n", path);
    analyze_directory(path, &total_size);
    
    printf("Total size of all files and directories: %lld bytes\n", total_size);
    return 0;
}