//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define constants and global variables
const char *baseDir = "/";  // Base directory to search for files
const int MAX_PATH_LEN = 1024;  // Maximum length of file path
unsigned long long totalSize = 0;  // Total size of files in bytes

// Function to recursively calculate size of a directory
void calculateDirSize(char *path) {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        printf("Unable to open directory %s.\n", path);
        return;
    }

    struct dirent *entry;
    struct stat st;
    char filepath[MAX_PATH_LEN];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        if (lstat(filepath, &st) == -1) {
            printf("Error getting information for file %s.\n", filepath);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            calculateDirSize(filepath);  // Recursive call for subdirectories
        } else {
            totalSize += st.st_size;  // Add to total size for non-directories
        }
    }

    closedir(dir);
}

int main() {
    printf("Starting disk space analyzer...\n");

    // Calculate size of base directory
    calculateDirSize(baseDir);
    printf("Total size of files in %s: %llu bytes.\n", baseDir, totalSize);

    return 0;
}