//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

int analyzeDirectory(char *path);
int isDirectory(char *path);

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LENGTH];

    // If a path is passed, use it as starting point, otherwise use current dir
    if(argc > 1) {
        strncpy(path, argv[1], MAX_PATH_LENGTH);
    } else {
        if(getcwd(path, MAX_PATH_LENGTH) == NULL) {
            printf("Error: Unable to get current working directory\n");
            return -1;
        }
    }

    return analyzeDirectory(path);
}

// Analyze directory contents and prints out sizes of files and subdirectories
int analyzeDirectory(char *path) {
    DIR *directory = opendir(path);

    if(directory == NULL) {
        printf("Error: Unable to open directory \"%s\"\n", path);
        return -1;
    }

    struct dirent *entry;
    char subPath[MAX_PATH_LENGTH];
    int totalSize = 0;

    while((entry = readdir(directory)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            // Skip current and parent directories
            continue;
        }

        snprintf(subPath, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        if(isDirectory(subPath)) {
            // A subdirectory, so recursively analyze it
            int size = analyzeDirectory(subPath);
            printf("%d\t%s\n", size, subPath);

            totalSize += size;
        } else {
            // A file, just get the size
            struct stat fileStats;

            if(stat(subPath, &fileStats) < 0) {
                printf("Error: Unable to get size of file \"%s\"\n", subPath);
            } else {
                int size = fileStats.st_size;
                printf("%d\t%s\n", size, subPath);
                
                totalSize += size;
            }
        }
    }

    closedir(directory);

    printf("Total size of \"%s\": %d bytes\n", path, totalSize);

    return totalSize;
}

// Check if a path is a directory
int isDirectory(char *path) {
    struct stat fileStats;

    if(stat(path, &fileStats) < 0) {
        printf("Error: Unable to get file \"%s\"\n", path);
        return -1;
    }

    return S_ISDIR(fileStats.st_mode);
}