//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

void analyzeDirectory(char* path, long *size);

int main(int argc, char** argv) {

    // Check if argument is present
    if(argc < 2) {
        printf("Please specify a path to analyze.\n");
        exit(1);
    }

    char* path = argv[1];
    long size = 0;

    analyzeDirectory(path, &size);

    if(size >= GB) {
        printf("Total size: %0.2f GB\n", (float)size/(float)GB);
    } else if(size >= MB) {
        printf("Total size: %0.2f MB\n", (float)size/(float)MB);
    } else if(size >= KB) {
        printf("Total size: %0.2f KB\n", (float)size/(float)KB);
    } else {
        printf("Total size: %ld bytes\n", size);
    }

    return 0;
}

void analyzeDirectory(char* path, long *size) {

    DIR* directory = opendir(path);

    struct dirent* entry;

    while((entry = readdir(directory)) != NULL) {

        if(entry->d_type == DT_DIR) {

            // Ignore "." and ".." directories
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char* newPath = calloc(strlen(path) + strlen(entry->d_name) + 2, sizeof(char));
            sprintf(newPath, "%s\\%s", path, entry->d_name);

            // Analyze subdirectory recursively
            analyzeDirectory(newPath, size);

            free(newPath);

        } else if (entry->d_type == DT_REG) {
            char* filePath = calloc(strlen(path) + strlen(entry->d_name) + 2, sizeof(char));
            sprintf(filePath, "%s\\%s", path, entry->d_name);

            struct stat st;
            stat(filePath, &st);

            *size += st.st_size;

            free(filePath);
        }

    }

    closedir(directory);
}