//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

long long countDirSize(char *path, int *fileCount, int *dirCount) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat statbuf;
    long long size = 0;
    
    if (!dir) {
        printf("Failed to open directory %s\n", path);
        return 0;
    }

    while ((entry = readdir(dir))) {
        char newPath[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(newPath, "%s/%s", path, entry->d_name);

        if (stat(newPath, &statbuf) == -1) {
            printf("Failed to get stats for file %s\n", newPath);
            continue;
        }

        if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) {
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            *dirCount += 1;
            size += countDirSize(newPath, fileCount, dirCount);
        } else {
            *fileCount += 1;
            size += statbuf.st_size;
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    int fileCount = 0;
    int dirCount = 0;

    long long dirSize = countDirSize(path, &fileCount, &dirCount);
    printf("Directory size: %lld bytes\n", dirSize);
    printf("Number of files: %d\n", fileCount);
    printf("Number of directories: %d\n", dirCount);

    return 0;
}