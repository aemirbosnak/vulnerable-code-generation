//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void traverseDirectory(char *dirPath, int depth);

int main(int argc, char *argv[]) {
    char *directoryPath;

    if (argc < 2) {
        directoryPath = ".";
    } else {
        directoryPath = argv[1];
    }

    printf("Analyzing directory: %s\n\n", directoryPath);
    traverseDirectory(directoryPath, 0);

    return 0;
}

void traverseDirectory(char *dirPath, int depth) {
    DIR *directory = opendir(dirPath);
    struct dirent *dirEntry;
    struct stat fileStat;
    int totalSize = 0;

    if (directory == NULL) {
        printf("Failed to open directory: %s\n", dirPath);
        return;
    }

    while ((dirEntry = readdir(directory)) != NULL) {
        char filePath[1024];

        if (strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) {
            continue;
        }

        sprintf(filePath, "%s/%s", dirPath, dirEntry->d_name);

        if (lstat(filePath, &fileStat) < 0) {
            printf("Failed to get file stats for: %s\n", filePath);
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            int pathLength = strlen(filePath);

            printf("%*sDirectory: %s\n", depth * 2, "", filePath);

            traverseDirectory(filePath, depth + 1);
        } else {
            int fileSize = fileStat.st_size;

            printf("%*sFile: %s (%d bytes)\n", depth * 2, "", filePath, fileSize);

            totalSize += fileSize;
        }
    }

    printf("%*sTotal size of directory %s: %d bytes\n", depth * 2, "", dirPath, totalSize);

    closedir(directory);
}