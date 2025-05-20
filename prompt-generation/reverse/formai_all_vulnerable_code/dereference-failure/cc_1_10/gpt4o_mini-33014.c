//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

void analyze_directory(const char *path, long long *total_size) {
    struct dirent *entry;
    struct stat file_info;
    char full_path[MAX_PATH_LENGTH];
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Construct the full path of the entry
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_info) == -1) {
            perror("Failed to stat");
            continue;
        }
        
        // If it's a directory, recurse into it
        if (S_ISDIR(file_info.st_mode)) {
            long long subdir_size = 0;
            analyze_directory(full_path, &subdir_size);
            printf("Directory: %s - Size: %lld bytes\n", full_path, subdir_size);
            *total_size += subdir_size;
        } else {
            // Otherwise, it is a file, accumulate the file size
            printf("File: %s - Size: %lld bytes\n", full_path, file_info.st_size);
            *total_size += file_info.st_size;
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *start_path = argv[1];
    long long total_size = 0;

    printf("Analyzing the directory: %s\n", start_path);
    
    // Start analyzing the specified directory
    analyze_directory(start_path, &total_size);
    
    printf("Total size of directory '%s' : %lld bytes\n", start_path, total_size);

    return 0;
}