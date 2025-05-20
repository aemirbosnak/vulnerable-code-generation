//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int count = 0;
int totalSize = 0;

void analyzeFolder(char* path) {
    DIR* folder = opendir(path);
    struct dirent* dirEntry;

    if(folder == NULL) {
        printf("Unable to read directory %s\n", path);
        return;
    }

    while((dirEntry = readdir(folder)) != NULL) {
        if(strcmp(".", dirEntry->d_name) == 0 || strcmp("..", dirEntry->d_name) == 0) {
            continue;
        }

        char filePath[255];
        sprintf(filePath, "%s/%s", path, dirEntry->d_name);
        
        struct stat fileStat;
        if(stat(filePath, &fileStat) < 0) {
            printf("Unable to get stats for file %s\n", filePath);
            continue;
        }

        if(S_ISDIR(fileStat.st_mode)) {
            analyzeFolder(filePath);
        } else {
            count++;
            totalSize += fileStat.st_size;
        }
    }

    closedir(folder);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <folder_path>\n", argv[0]);
        return 0;
    }

    char* path = argv[1];
    analyzeFolder(path);

    printf("Number of files found: %d\n", count);
    printf("Total size of files: %d bytes\n", totalSize);

    return 0;
}