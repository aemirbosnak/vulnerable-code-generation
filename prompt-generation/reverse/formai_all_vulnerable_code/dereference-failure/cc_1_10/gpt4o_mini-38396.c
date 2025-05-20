//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void printSize(long long size) {
    const char *units[] = { "B", "KB", "MB", "GB", "TB" };
    int unitIndex = 0;

    while (size >= 1024 && unitIndex < 4) {
        size /= 1024;
        unitIndex++;
    }

    printf("%lld %s\n", size, units[unitIndex]);
}

long long calculateDirectorySize(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    long long totalSize = 0;

    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Unable to open directory");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current directory (.) and parent directory (..)
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
        if (stat(filePath, &statbuf) == -1) {
            perror("stat error");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursive call for directories
            totalSize += calculateDirectorySize(filePath);
        } else {
            // Accumulate file size
            totalSize += statbuf.st_size;
        }
    }

    closedir(dir);
    return totalSize;
}

void analyzeDiskSpace(const char *startDir) {
    printf("Analyzing disk space for directory: %s\n", startDir);
    long long totalSize = calculateDirectorySize(startDir);
    printf("Total size of directory %s is: ", startDir);
    printSize(totalSize);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyzeDiskSpace(argv[1]);
    return EXIT_SUCCESS;
}