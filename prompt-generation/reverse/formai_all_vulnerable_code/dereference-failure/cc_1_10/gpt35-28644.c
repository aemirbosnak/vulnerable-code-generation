//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate size of directories
long calculate_directory_size(char* path) {
    DIR* dirp = opendir(path);
    struct dirent *dp;
    struct stat stats;
    long total_size = 0;

    // Return if directory is not accessible
    if (dirp == NULL) {
        printf("Error: Could not open directory.\n");
        return -1;
    }

    while ((dp = readdir(dirp)) != NULL) {
        // Check if entry is a directory or a file
        if (dp->d_type == DT_DIR) {
            char pathName[256];
            sprintf(pathName, "%s/%s", path, dp->d_name);

            // Skip parent and current directories to avoid infinite recursion
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
                total_size += calculate_directory_size(pathName);
            }
        } else if (dp->d_type == DT_REG) {
            char fileName[256];
            sprintf(fileName, "%s/%s", path, dp->d_name);

            // Get file stats and add size to total
            if (stat(fileName, &stats) == 0) {
                total_size += stats.st_size;
            }
        }
    }

    closedir(dirp);

    return total_size;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: Please specify a directory path.\n");
        return -1;
    }

    char* path = argv[1];
    long total_size = calculate_directory_size(path);

    if (total_size < 0) {
        return -1;
    }

    printf("Total Size of %s: %ld Bytes\n", path, total_size);

    return 0;
}