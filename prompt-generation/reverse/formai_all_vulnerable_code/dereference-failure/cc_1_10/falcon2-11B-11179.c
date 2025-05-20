//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

// Function to get disk usage of a directory
ssize_t getDiskUsage(const char* path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("stat");
        return -1;
    }
    return st.st_size;
}

// Function to calculate total disk usage of a directory
ssize_t totalDiskUsage(const char* path) {
    DIR* dir;
    struct dirent* entry;
    ssize_t totalSize = 0;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir))!= NULL) {
        const char* filePath = entry->d_name;
        if (strcmp(filePath, ".")!= 0 && strcmp(filePath, "..")!= 0) {
            totalSize += getDiskUsage(filePath);
        }
    }

    closedir(dir);
    return totalSize;
}

// Function to print disk usage of a directory
void printDiskUsage(const char* path) {
    ssize_t diskUsage = totalDiskUsage(path);
    if (diskUsage == -1) {
        perror("totalDiskUsage");
        return;
    }
    printf("Disk usage: %ld bytes\n", diskUsage);
}

int main() {
    printDiskUsage("/path/to/directory");
    return 0;
}