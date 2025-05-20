//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

void printAnswer(char dir[], int depth, long unsigned int size){
    printf("%*sTotal Size: %lu bytes\n", depth, "", size);
    printf("%*sDirectory: %s\n", depth, "", dir);
}

void analyzeDirectory(char directory[], int depth, bool isLast) {

    DIR *directoryPointer;
    struct dirent *directoryContent;
    struct stat statInfo;
    long unsigned int totalSize = 0;
    char subdirName[1024];

    if (!(directoryPointer = opendir(directory))) {
        printf("Error opening directory %s", directory);
        return;
    }

    while ((directoryContent = readdir(directoryPointer)) != NULL) {
        if (strcmp(directoryContent->d_name, ".") == 0 || strcmp(directoryContent->d_name, "..") == 0) {
            continue;
        }
        sprintf(subdirName, "%s/%s", directory, directoryContent->d_name);
        if (lstat(subdirName, &statInfo) == -1) {
            printf("Error getting statistics for %s", subdirName);
            continue;
        }
        totalSize += statInfo.st_size;

        if (S_ISDIR(statInfo.st_mode)) {
            printf("%*s[%s]\n", depth * 2, "", directoryContent->d_name);
            analyzeDirectory(subdirName, depth + 1, false);
        } else {
            printf("%*s%s\n", depth * 2, "", directoryContent->d_name);
        }

        isLast = false;
    }

    closedir(directoryPointer);

    if (isLast) {
        printAnswer(directory, depth, totalSize);
    } else {
        printf("%*sTotal Size: %lu bytes\n", depth, "", totalSize);
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Disk Space Analyzer. Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyzeDirectory(argv[1], 0, true);

    return 0;
}