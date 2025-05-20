//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// function to convert bytes to human readable format
char *humanReadableFormat(double size) {
    static char buf[10];
    const char *units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    int i;
    for (i = 0; i < sizeof(units)/sizeof(units[0])-1 && size >= 1024; i++) {
        size /= 1024;
    }
    sprintf(buf, "%.2f %s", size, units[i]);
    return buf;
}

// function to recursively traverse directories and print file sizes
long long traverseDir(char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat statBuf;
    long long totalSize = 0;
    if (dir == NULL) {
        printf("Unable to open directory %s\n", path);
        return 0;
    }
    while ((entry = readdir(dir)) != NULL) {
        char filePath[512];
        sprintf(filePath, "%s/%s", path, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (stat(filePath, &statBuf) == -1) {
            printf("Unable to get file info for %s\n", filePath);
            continue;
        }
        if (S_ISDIR(statBuf.st_mode)) {
            long long dirSize = traverseDir(filePath);
            totalSize += dirSize;
            printf("%s\t%s\n", humanReadableFormat(dirSize), filePath);
        } else {
            totalSize += statBuf.st_size;
            printf("%s\t%s/%s\n", humanReadableFormat(statBuf.st_size), path, entry->d_name);
        }
    }
    closedir(dir);
    return totalSize;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 0;
    }
    char *path = argv[1];
    long long totalSize = traverseDir(path);
    printf("Total size: %s\n", humanReadableFormat(totalSize));
    return 0;
}