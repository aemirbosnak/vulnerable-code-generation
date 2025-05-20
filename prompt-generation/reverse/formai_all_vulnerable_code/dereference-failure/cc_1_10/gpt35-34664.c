//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

/*
 * This program scans the C disk and provides various information about the files
 * including its size, the number of files and directories, etc.
 */

// Declaration of global variables and helper function
int num_files = 0, num_dirs = 0;
long long total_size = 0;

void analyze_directory(const char *path);

int main(int argc, char *argv[]) {
    const char *path = argc > 1 ? argv[1] : "/";
    analyze_directory(path);

    printf("Number of files: %d\n", num_files);
    printf("Number of directories: %d\n", num_dirs - 1); // Subtract root directory
    printf("Total size: %lld bytes\n", total_size);

    return 0;
}

// Recursively analyze files and directories in a given path
void analyze_directory(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat file_stat;

    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char entry_path[1024];
        sprintf(entry_path, "%s/%s", path, entry->d_name);

        // Skip over "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        stat(entry_path, &file_stat);
        if (S_ISDIR(file_stat.st_mode)) {
            num_dirs++;
            analyze_directory(entry_path);
        } else {
            num_files++;
            total_size += file_stat.st_size;
        }
    }

    closedir(dir);
}