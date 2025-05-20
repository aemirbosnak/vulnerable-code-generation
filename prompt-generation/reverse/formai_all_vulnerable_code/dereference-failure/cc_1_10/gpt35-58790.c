//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define KiB 1024
#define MiB 1048576
#define GiB 1073741824

void analyzeDirectory(char *path, int *totalSize);

void analyzeFile(char *filePath, int *totalSize);

void printSize(int size);

int main(int argc, char **argv) {
    int totalSize = 0;
    DIR *dir = opendir(".");
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            analyzeDirectory(entry->d_name, &totalSize);
        } else if (entry->d_type == DT_REG) {
            analyzeFile(entry->d_name, &totalSize);
        }
    }
    closedir(dir);

    printf("Total size of all files and directories in current directory: ");
    printSize(totalSize);
    printf("\n");

    return 0;
}

void analyzeDirectory(char *path, int *totalSize) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char nextPath[1024];
            sprintf(nextPath, "%s/%s", path, entry->d_name);
            analyzeDirectory(nextPath, totalSize);
        } else if (entry->d_type == DT_REG) {
            char filePath[1024];
            sprintf(filePath, "%s/%s", path, entry->d_name);
            analyzeFile(filePath, totalSize);
        }
    }
    closedir(dir);
}

void analyzeFile(char *filePath, int *totalSize) {
    struct stat fileInfo;
    if (stat(filePath, &fileInfo) == 0) {
        *totalSize += fileInfo.st_size;
    }
}

void printSize(int size) {
    if (size >= GiB) {
        printf("%.2f GiB", (float)size / GiB);
    } else if (size >= MiB) {
        printf("%.2f MiB", (float)size / MiB);
    } else if (size >= KiB) {
        printf("%.2f KiB", (float)size / KiB);
    } else {
        printf("%d bytes", size);
    }
}