//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the size of a directory recursively
long long calculateSize(char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileInfo;
    long long size = 0;

    dir = opendir(dirPath);
    if (dir == NULL) {
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];
        sprintf(fullPath, "%s/%s", dirPath, entry->d_name);
        if (stat(fullPath, &fileInfo) == -1) {
            continue;
        }

        if (S_ISDIR(fileInfo.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            size += calculateSize(fullPath);
        } else {
            size += fileInfo.st_size;
        }
    }

    closedir(dir);
    return size;
}

// Function to display the disk space usage report
void printReport(char *dirPath, long long totalSize) {
    printf("\nDisk space usage report for directory '%s':\n", dirPath);
    printf("-------------------------------------------------------\n");
    printf("Total size: %lld bytes\n", totalSize);
    printf("Size per file:\n");

    DIR *dir;
    struct dirent *entry;
    struct stat fileInfo;

    dir = opendir(dirPath);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];
        sprintf(fullPath, "%s/%s", dirPath, entry->d_name);
        if (stat(fullPath, &fileInfo) == -1) {
            continue;
        }

        if (S_ISREG(fileInfo.st_mode)) {
            printf("\t%s: %lld bytes\n", entry->d_name, fileInfo.st_size);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dirPath = argv[1];
    long long totalSize = calculateSize(dirPath);
    if (totalSize == -1) {
        printf("Error: could not open directory '%s'\n", dirPath);
        exit(EXIT_FAILURE);
    }

    printReport(dirPath, totalSize);

    return 0;
}