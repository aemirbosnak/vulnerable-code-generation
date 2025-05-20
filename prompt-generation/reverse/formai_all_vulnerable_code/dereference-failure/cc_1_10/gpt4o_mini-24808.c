//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define BLOCK_SIZE 4096  // Size of a single block in bytes
#define FILE_TYPE_BUFFER 50

typedef struct {
    char fileType[FILE_TYPE_BUFFER];
    long long size;
} FileInfo;

void getFileInfo(const char *path, FileInfo *info);
void analyzeDirectory(const char *path, long long *totalSize, int level);
void printBarChart(long long totalSize, long long usedSize);
void printFileInfo(const char *path, FileInfo *info);
const char* getFileType(const char *path);
void printAnalysis(const char *path, long long totalSize, long long usedSize);

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LENGTH] = ".";  // Default to current directory
    if (argc > 1) {
        strncpy(path, argv[1], MAX_PATH_LENGTH - 1);
        path[MAX_PATH_LENGTH - 1] = '\0'; // Ensure null termination
    }

    long long totalSize = 0;
    long long usedSize = 0;

    analyzeDirectory(path, &usedSize, 0);
    totalSize = usedSize + (10 * BLOCK_SIZE); // Simulate total size for demonstration

    printAnalysis(path, totalSize, usedSize);
    
    return 0;
}

void analyzeDirectory(const char *path, long long *usedSize, int level) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    char fullPath[MAX_PATH_LENGTH];
    struct stat fileStat;

    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

            if (stat(fullPath, &fileStat) == -1) {
                continue; // Error handling for stat
            }

            if (S_ISDIR(fileStat.st_mode)) {
                analyzeDirectory(fullPath, usedSize, level + 1);
            } else {
                FileInfo info;
                getFileInfo(fullPath, &info);
                *usedSize += info.size;
                printFileInfo(fullPath, &info);
            }
        }
    }

    closedir(dir);
}

void getFileInfo(const char *path, FileInfo *info) {
    struct stat fileStat;

    if (stat(path, &fileStat) == 0) {
        info->size = fileStat.st_size;
        strncpy(info->fileType, getFileType(path), FILE_TYPE_BUFFER - 1);
        info->fileType[FILE_TYPE_BUFFER - 1] = '\0'; // Ensure null termination
    } else {
        info->size = 0;
        strcpy(info->fileType, "Unknown");
    }
}

const char* getFileType(const char *path) {
    const char *dot = strrchr(path, '.');
    if(!dot || dot == path) return "File";

    if (strcmp(dot, ".txt") == 0) return "Text File";
    if (strcmp(dot, ".c") == 0) return "C Source File";
    if (strcmp(dot, ".jpg") == 0) return "JPEG Image";
    if (strcmp(dot, ".png") == 0) return "PNG Image";
    if (strcmp(dot, ".sh") == 0) return "Shell Script";
    
    return "File";
}

void printFileInfo(const char *path, FileInfo *info) {
    printf("File: %s, Type: %s, Size: %lld bytes\n", path, info->fileType, info->size);
}

void printAnalysis(const char *path, long long totalSize, long long usedSize) {
    printf("\nDisk Space Analysis for: %s\n", path);
    printf("Total Disk Space: %lld bytes\n", totalSize);
    printf("Used Disk Space: %lld bytes\n", usedSize);
    printf("Free Disk Space: %lld bytes\n", totalSize - usedSize);
    printBarChart(totalSize, usedSize);
}

void printBarChart(long long totalSize, long long usedSize) {
    printf("\nDisk Usage Chart:\n");
    int totalBlocks = totalSize / BLOCK_SIZE;
    int usedBlocks = usedSize / BLOCK_SIZE;

    for(int i = 0; i < usedBlocks; i++) {
        printf("█");
    }
    for(int i = 0; i < totalBlocks - usedBlocks; i++) {
        printf("░");
    }
    printf(" (%lld%% used)\n", (usedBlocks * 100) / totalBlocks);
}