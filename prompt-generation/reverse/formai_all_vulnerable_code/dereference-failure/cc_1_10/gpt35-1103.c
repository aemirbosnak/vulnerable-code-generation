//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Function to calculate the size of a directory or file
long long calculateSize(char *path);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        exit(1);
    }

    struct stat s;
    if (lstat(argv[1], &s) != 0) {
        printf("Error getting stats for %s\n", argv[1]);
        exit(1);
    }

    long long size = 0;

    if (S_ISDIR(s.st_mode)) {
        // Calculate size of a directory
        size = calculateSize(argv[1]);
    } else if (S_ISREG(s.st_mode)) {
        // Calculate size of a file
        size = s.st_size;
    }

    // Output the size of the directory or file
    if (size < 1024) {
        printf("%lld bytes\n", size);
    } else if (size >= 1024 && size < 1024 * 1024) {
        printf("%lld KB\n", size / 1024);
    } else if (size >= 1024 * 1024 && size < 1024 * 1024 * 1024) {
        printf("%lld MB\n", size / (1024 * 1024));
    } else {
        printf("%lld GB\n", size / (1024 * 1024 * 1024));
    }

    return 0;
}

long long calculateSize(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat s;
    long long size = 0;

    if (!(dir = opendir(path))) {
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Ignore "." and ".." directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Calculate size of subdirectory
            char subdir[1024];
            snprintf(subdir, sizeof(subdir), "%s/%s", path, entry->d_name);
            size += calculateSize(subdir);
        } else if (entry->d_type == DT_REG) {
            // Calculate size of file
            char file_path[1024];
            snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
            if (lstat(file_path, &s) == 0) {
                size += s.st_size;
            }
        }
    }

    closedir(dir);

    return size;
}