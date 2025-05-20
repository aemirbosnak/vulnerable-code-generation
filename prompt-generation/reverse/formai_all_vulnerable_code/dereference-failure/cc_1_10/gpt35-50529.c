//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to get the size of a file
long int getFileSize(char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

// Function to calculate the size of a directory
long int getDirSize(char* path) {
    long int totalSize = 0;
    DIR* dir;
    struct dirent* entry;
    char subPath[256];
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Cannot open directory '%s'\n", path);
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Build the subpath of the directory entry
        snprintf(subPath, sizeof(subPath), "%s/%s", path, entry->d_name);
        // If this is a directory, calculate its size recursively
        if (entry->d_type == DT_DIR) {
            long int subDirSize = getDirSize(subPath);
            if (subDirSize == -1) {
                continue;
            }
            totalSize += subDirSize;
        }
        // If this is a file, add its size to the total size
        else if (entry->d_type == DT_REG) {
            long int fileSize = getFileSize(subPath);
            if (fileSize == -1) {
                continue;
            }
            totalSize += fileSize;
        }
    }
    closedir(dir);
    return totalSize;
}

int main() {
    char path[256];
    printf("Enter the path to scan: ");
    fgets(path, sizeof(path), stdin);
    // Remove the newline character at the end of the input
    path[strcspn(path, "\n")] = 0;
    long int totalSize = getDirSize(path);
    if (totalSize == -1) {
        printf("Error: Cannot get the size of directory '%s'\n", path);
    }
    else {
        printf("Total size of directory '%s': %ld bytes\n", path, totalSize);
    }
    return 0;
}