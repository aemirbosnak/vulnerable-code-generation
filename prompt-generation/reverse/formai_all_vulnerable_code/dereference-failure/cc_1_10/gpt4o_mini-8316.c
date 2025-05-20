//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define FILE_TYPE_DIR 1
#define FILE_TYPE_FILE 2

typedef struct {
    char path[MAX_PATH];
    long size;
    int type;
} FileInfo;

void analyzeDirectory(const char* dirPath, long* totalSize, int* fileCount, int indentLevel) {
    struct dirent *entry;
    struct stat fileStat;
    char currentPath[MAX_PATH];
    DIR *directory = opendir(dirPath);

    if (directory == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(currentPath, sizeof(currentPath), "%s/%s", dirPath, entry->d_name);
        if (stat(currentPath, &fileStat) == -1) {
            perror("Stat error");
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            printf("%*s[DIR] %s\n", indentLevel * 4, "", entry->d_name);
            analyzeDirectory(currentPath, totalSize, fileCount, indentLevel + 1);
        } else {
            printf("%*s[FILE] %s (%ld bytes)\n", indentLevel * 4, "", entry->d_name, fileStat.st_size);
            *totalSize += fileStat.st_size;
            (*fileCount)++;
        }
    }

    closedir(directory);
}

void displaySummary(long totalSize, int fileCount) {
    printf("\n*** Disk Space Summary ***\n");
    printf("Total Files: %d\n", fileCount);
    printf("Total Directory Size: %ld bytes\n", totalSize);
    printf("Total Directory Size: %.2f MB\n", totalSize / (1024.0 * 1024.0));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long totalSize = 0;
    int fileCount = 0;
    char* basePath = argv[1];

    printf("Analyzing Directory: %s\n", basePath);
    analyzeDirectory(basePath, &totalSize, &fileCount, 0);
    displaySummary(totalSize, fileCount);

    return EXIT_SUCCESS;
}