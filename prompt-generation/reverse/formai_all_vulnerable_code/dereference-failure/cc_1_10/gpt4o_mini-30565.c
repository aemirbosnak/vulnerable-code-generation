//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 4096
#define MAX_DIRS 1024

typedef struct {
    char name[MAX_PATH];
    long size;
} FileInfo;

typedef struct {
    char name[MAX_PATH];
    long totalSize;
    long fileCount;
    FileInfo files[MAX_DIRS];
} DirectoryInfo;

void calculateDirectorySize(const char *path, DirectoryInfo *dirInfo) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(path);
    
    if (!dir) {
        perror("opendir");
        return;
    }

    strncpy(dirInfo->name, path, MAX_PATH);
    dirInfo->totalSize = 0;
    dirInfo->fileCount = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Ignore hidden files and directories
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        
        if (stat(fullPath, &fileStat) == 0) {
            if (S_ISREG(fileStat.st_mode)) {
                dirInfo->files[dirInfo->fileCount].size = fileStat.st_size;
                strncpy(dirInfo->files[dirInfo->fileCount].name, entry->d_name, MAX_PATH);
                dirInfo->totalSize += fileStat.st_size;
                dirInfo->fileCount++;
            } else if (S_ISDIR(fileStat.st_mode)) {
                // For directories, we can call the function recursively
                DirectoryInfo subDirInfo;
                calculateDirectorySize(fullPath, &subDirInfo);
                printf("Directory: %s, Total Size: %ld bytes, Files: %ld\n", 
                       subDirInfo.name, subDirInfo.totalSize, subDirInfo.fileCount);
            }
        }
    }
    
    closedir(dir);
}

void printDirectoryInfo(DirectoryInfo *dirInfo) {
    printf("Directory: %s\n", dirInfo->name);
    printf("Total size: %ld bytes\n", dirInfo->totalSize);
    printf("Number of files: %ld\n", dirInfo->fileCount);
    printf("Files:\n");
    
    for (long i = 0; i < dirInfo->fileCount; i++) {
        printf("  %s (%ld bytes)\n", dirInfo->files[i].name, dirInfo->files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    DirectoryInfo dirInfo;
    calculateDirectorySize(argv[1], &dirInfo);
    printDirectoryInfo(&dirInfo);

    return EXIT_SUCCESS;
}