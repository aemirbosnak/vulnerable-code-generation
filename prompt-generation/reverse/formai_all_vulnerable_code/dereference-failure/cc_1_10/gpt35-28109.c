//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void analyzeDiskSpace(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStats;
    long long totalSize = 0;

    // Open the directory
    dir = opendir(path);

    // If the directory cannot be opened, exit the program
    if(!dir) {
        printf("Error: Unable to open directory\n");
        exit(1);
    }

    // Loop through all files in directory
    while((entry = readdir(dir)) != NULL) {
        char filePath[1024];
        sprintf(filePath, "%s/%s", path, entry->d_name);

        // Get the stat info for the file
        if(stat(filePath, &fileStats) == -1) {
            printf("Error: Unable to get file stats for %s. Skipping file.\n", filePath);
            continue;
        }

        // If the file is a directory, recursively call analyzeDiskSpace on the directory
        if(S_ISDIR(fileStats.st_mode)) {
            if(strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) {
                analyzeDiskSpace(filePath);
            }
        }
        else {
            // If the file is not a directory, add its size to the total size
            totalSize += fileStats.st_size;
        }
    }

    // Close the directory
    closedir(dir);

    // Print the file path and total size of the directory
    printf("%s: %lld bytes\n", path, totalSize);
}

// Main function, takes a directory path as argument
int main(int argc, char *argv[]) {
    // Check that exactly one argument was passed
    if(argc != 2) {
        printf("Error: Invalid number of arguments\n");
        printf("Usage: %s <directory path>\n", argv[0]);
        return 1;
    }

    // Get the path from the argument
    char *path = argv[1];

    // Analyze the disk space of the directory
    analyzeDiskSpace(path);

    return 0;
}