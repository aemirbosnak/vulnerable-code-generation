//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(const char *dir_path, long long *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char path[1024];

        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        // Get file statistics
        if (stat(path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        // If it's a directory, call the function recursively
        if (S_ISDIR(file_stat.st_mode)) {
            printf("Directory: %s\n", path);
            analyze_directory(path, total_size);
        } else {
            // It's a file; print the size and add to total
            printf("File: %s, Size: %lld bytes\n", path, (long long)file_stat.st_size);
            *total_size += file_stat.st_size;
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

    // Start analyzing the directory
    analyze_directory(argv[1], &total_size);

    // Print the total size of all files
    printf("\nTotal size of files in '%s': %lld bytes\n", argv[1], total_size);

    return EXIT_SUCCESS;
}