//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

typedef struct {
    char name[MAX_PATH];
    long totalSize;
    int fileCount;
} DirectoryInfo;

void analyzeDirectory(const char *path, DirectoryInfo *dirInfo) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Cannot open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(fullPath, &fileStat) == 0) {
                if (S_ISREG(fileStat.st_mode)) {
                    dirInfo->totalSize += fileStat.st_size;
                    dirInfo->fileCount += 1;
                } else if (S_ISDIR(fileStat.st_mode)) {
                    DirectoryInfo subDirInfo = {0};
                    strncpy(subDirInfo.name, fullPath, MAX_PATH);
                    analyzeDirectory(fullPath, &subDirInfo);
                    dirInfo->totalSize += subDirInfo.totalSize;
                    dirInfo->fileCount += subDirInfo.fileCount;
                }
            }
        }
    }
    closedir(dir);
}

void printDirectoryInfo(DirectoryInfo *dirInfo) {
    printf("Directory: %s\n", dirInfo->name);
    printf("Total Size: %ld bytes\n", dirInfo->totalSize);
    printf("Total Files: %d\n", dirInfo->fileCount);
    printf("================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DirectoryInfo rootDirInfo = {0};
    strncpy(rootDirInfo.name, argv[1], MAX_PATH);
    analyzeDirectory(argv[1], &rootDirInfo);
    
    printDirectoryInfo(&rootDirInfo);
    
    return EXIT_SUCCESS;
}