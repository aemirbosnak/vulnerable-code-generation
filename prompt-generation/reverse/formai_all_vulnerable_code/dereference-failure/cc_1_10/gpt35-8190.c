//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MB_FACTOR 1048576 // 1 MB = 1024*1024 bytes

struct DiskEntry {
    char path[MAX_PATH];
    long size;
};

struct DiskEntry diskEntries[MAX_PATH];
int totalEntries = 0;

int isDir(char *path) {
    struct stat stats;
    stat(path, &stats);

    if (S_ISDIR(stats.st_mode)) {
        return 1;
    } else {
        return 0;
    }
}

long getDirSize(char *path) {
    long size = 0;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        char filePath[MAX_PATH];
        struct stat stats;

        sprintf(filePath, "%s/%s", path, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (isDir(filePath)) {
            size += getDirSize(filePath);
        } else {
            stat(filePath, &stats);
            size += stats.st_size;
        }
    }
    closedir(dir);

    return size;
}

void addDiskEntry(char *path, long size) {
    strcpy(diskEntries[totalEntries].path, path);
    diskEntries[totalEntries].size = size;
    totalEntries++;
}

void analyzeDiskSpace(char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        char filePath[MAX_PATH];
        long size = 0;

        sprintf(filePath, "%s/%s", path, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (isDir(filePath)) {
            size = getDirSize(filePath);
        } else {
            struct stat stats;
            stat(filePath, &stats);
            size = stats.st_size;
        }
        addDiskEntry(filePath, size);
    }
    closedir(dir);
}

void printDiskAnalysis() {
    int i;
    long totalSize = 0;

    printf("%-50s  %10s\n", "File/Directory", "Size (MB)");
    for (i = 0; i < totalEntries; i++) {
        long sizeInMB = diskEntries[i].size / MB_FACTOR;
        printf("%-50s  %10ld\n", diskEntries[i].path, sizeInMB);
        totalSize += diskEntries[i].size;
    }

    printf("\nTotal disk size: %.2f GB\n", (float) totalSize / (1024*1024*1024));
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide the directory path as argument\n");
        return 1;
    }

    analyzeDiskSpace(argv[1]);
    printDiskAnalysis();

    return 0;
}