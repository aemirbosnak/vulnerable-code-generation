//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void analyze_directory(const char *path, long long *total_size) {
    struct dirent *entry;
    struct stat file_info;
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

        char full_path[1024]; // Buffer to hold the full path
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_info) < 0) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_info.st_mode)) {
            // Recursively analyze the subdirectory
            analyze_directory(full_path, total_size);
        } else {
            // Accumulate file size
            *total_size += file_info.st_size;
            printf("File: %s Size: %lld bytes\n", full_path, (long long)file_info.st_size);
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    long long total_size = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];

    analyze_directory(directory_path, &total_size);
    printf("Total Size of files in '%s': %lld bytes\n", directory_path, total_size);

    return EXIT_SUCCESS;
}