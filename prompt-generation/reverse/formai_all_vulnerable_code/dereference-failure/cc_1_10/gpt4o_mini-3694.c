//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 4096
#define DEADLINE 100 // 100 MB threshold for warning
#define WARNING "WARNING: Insufficient disk space! We must scavenge!"

void analyzeDirectory(const char *path, long *totalSize, long *freeSpace) {
    struct dirent *entry;
    struct stat sb;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (stat(fullPath, &sb) == 0) {
            if (S_ISDIR(sb.st_mode)) {
                analyzeDirectory(fullPath, totalSize, freeSpace);
            } else {
                *totalSize += sb.st_size;
            }
        }
    }
    closedir(dir);
}

void checkDiskSpace(long totalSize) {
    if (totalSize > (DEADLINE * 1024 * 1024)) {
        printf("%s\n", WARNING);
    } else {
        printf("Safe Motherboard! Total used space: %ld MB\n", totalSize / (1024 * 1024));
    }
}

void displayHelp() {
    printf("Doom Disk Space Analyzer v1.0\n");
    printf("Usage: ./space_analyzer [directory]\n");
    printf("Default Path: Current directory\n");
}

int main(int argc, char *argv[]) {
    long totalSize = 0;
    char *path = "."; // Start from current directory

    if (argc > 1) {
        path = argv[1];
    } else {
        displayHelp();
    }

    printf("Scanning the wastelands of %s...\n", path);
    analyzeDirectory(path, &totalSize, NULL);
    checkDiskSpace(totalSize);
    printf("Total Size Analyzed: %ld bytes\n", totalSize);
    return 0;
}