//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyzeDirectory(const char *dirPath);
long getDirectorySize(const char *dirPath);
void printFileDetails(const char *filePath, long *totalSize);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path1> <directory_path2> ... <directory_pathN>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printf("\nAnalyzing directory: %s\n", argv[i]);
        analyzeDirectory(argv[i]);
    }

    return 0;
}

void analyzeDirectory(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    long totalSize = 0;

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[1024];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            printFileDetails(fullPath, &totalSize);
        }
    }

    closedir(dir);
    printf("Total size of directory '%s': %ld bytes\n", dirPath, totalSize);
}

void printFileDetails(const char *filePath, long *totalSize) {
    struct stat fileStat;
    if (stat(filePath, &fileStat) < 0) {
        perror("Could not get file status");
        return;
    }

    if (S_ISREG(fileStat.st_mode)) {
        printf("File: %s, Size: %ld bytes\n", filePath, fileStat.st_size);
        *totalSize += fileStat.st_size;
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Directory: %s\n", filePath);
        analyzeDirectory(filePath);  // Recursively analyze subdirectories
    } else {
        printf("Other type: %s\n", filePath);
    }
}