//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BYTES_IN_GB 1073741824
#define BYTES_IN_MB 1048756

void analyze_dir(const char *dir_path, int depth);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }
    
    analyze_dir(argv[1], 0);

    return 0;
}

void analyze_dir(const char *dir_path, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char path_buffer[512];
    long long total_size = 0;

    // Check if directory can be accessed
    if ((dir = opendir(dir_path)) == NULL) {
        printf("Cannot open directory \"%s\"\n", dir_path);
        return;
    }

    // Print current directory and its depth
    printf("%*s Directory: %s\n", depth * 4, "", dir_path);

    // Traverse directory, calculating size and analyzing subdirectories recursively
    while ((entry = readdir(dir)) != NULL) {
        snprintf(path_buffer, sizeof(path_buffer), "%s/%s", dir_path, entry->d_name);
        if (stat(path_buffer, &file_stat) == 0) {
            // Check if directory entry is a directory
            if (S_ISDIR(file_stat.st_mode)) {
                // Skip '.' and '..'
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }

                // Analyze subdirectory recursively
                analyze_dir(path_buffer, depth + 1);
            }
            else {
                // Add file size to total size
                total_size += file_stat.st_size;
            }
        }
    }

    // Print the total size of the directory
    if (total_size >= BYTES_IN_GB) {
        printf("%*s Size: %.2f GB\n", depth * 4, "", (double) total_size / BYTES_IN_GB);
    }
    else if (total_size >= BYTES_IN_MB) {
        printf("%*s Size: %.2f MB\n", depth * 4, "", (double) total_size / BYTES_IN_MB);
    }
    else {
        printf("%*s Size: %lld bytes\n", depth * 4, "", total_size);
    }

    closedir(dir);
}