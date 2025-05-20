//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Linus Torvalds style:
#define DUMP(fmt, ...) fprintf(stderr, "DISK SPACE ANALYZER: " fmt "\n", ##__VA_ARGS__)

// Global variables:
long long total_size;
long long dir_count;
long long file_count;

// Recursive function to analyze directory:
void analyze_dir(const char *dir) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char path[256];

    dp = opendir(dir);
    if (!dp) {
        DUMP("Error opening directory: %s", dir);
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
        if (lstat(path, &statbuf) != 0) {
            DUMP("Error getting file status: %s", path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_dir(path);
        } else if (S_ISREG(statbuf.st_mode)) {
            total_size += statbuf.st_size;
            file_count++;
        }
    }

    closedir(dp);
}

// Main function:
int main(int argc, char *argv[]) {
    if (argc != 2) {
        DUMP("Usage: %s <directory>", argv[0]);
        return 1;
    }

    analyze_dir(argv[1]);

    // Print the results:
    DUMP("Total size: %lld bytes", total_size);
    DUMP("Directories: %lld", dir_count);
    DUMP("Files: %lld", file_count);

    return 0;
}