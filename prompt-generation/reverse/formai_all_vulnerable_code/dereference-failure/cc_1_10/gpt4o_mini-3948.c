//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyzeDiskSpace(const char* path, long long *totalSize, long long *fileCount, long long *dirCount) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        fprintf(stderr, "Error: Unable to open directory %s\n", path);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
            
            if (stat(fullPath, &statbuf) == -1) {
                perror("stat");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                (*dirCount)++;
                analyzeDiskSpace(fullPath, totalSize, fileCount, dirCount);
            } else if (S_ISREG(statbuf.st_mode)) {
                (*fileCount)++;
                *totalSize += statbuf.st_size;
            }
        }
    }

    closedir(dp);
}

void printDiskUsage(const char* path) {
    long long totalSize = 0;
    long long fileCount = 0;
    long long dirCount = 0;

    analyzeDiskSpace(path, &totalSize, &fileCount, &dirCount);

    printf("Disk usage for directory: %s\n", path);
    printf("Total files: %lld\n", fileCount);
    printf("Total directories: %lld\n", dirCount);
    printf("Total size: %lld bytes\n", totalSize);
    printf("Total size: %.2f MB\n", totalSize / (1024.0 * 1024.0));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Analyzing disk space...\n");
    printDiskUsage(argv[1]);
    
    return EXIT_SUCCESS;
}