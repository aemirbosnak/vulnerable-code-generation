//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to convert bytes to a human-readable format
void formatSize(unsigned long long size, char *buf) {
    const char *sizeStr[] = {"B", "KB", "MB", "GB", "TB"};
    int i;
    double s = size;
    for (i = 0; i < 5 && s > 1024; i++, s /= 1024) {
    }
    sprintf(buf, "%.2f %s", s, sizeStr[i]);
}

// Function to recursively traverse a directory and calculate its size
void analyzeDir(char *dirPath, unsigned long long *size) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char filePath[PATH_MAX];
    dir = opendir(dirPath);
    if (!dir) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(filePath, PATH_MAX, "%s/%s", dirPath, entry->d_name);
        if (lstat(filePath, &st) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }
        if (S_ISDIR(st.st_mode)) {
            analyzeDir(filePath, size);
        } else {
            *size += st.st_size;
        }
    }
    closedir(dir);
}

int main() {
    unsigned long long totalSize = 0;
    char totalSizeStr[32], filePath[PATH_MAX];
    analyzeDir(".", &totalSize);
    formatSize(totalSize, totalSizeStr);
    printf("Total disk space used: %s\n", totalSizeStr);
    return 0;
}