//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void listDirectory(const char *path, int *totalSize) {
    DIR *directory;
    struct dirent *entry;
    struct stat fileStat;

    directory = opendir(path);
    if (!directory) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        
        if (stat(fullPath, &fileStat) == -1) {
            perror("Error obtaining file status");
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            printf("Directory: %s\n", fullPath);
            // Recursively list subdirectories
            listDirectory(fullPath, totalSize);
        } else if (S_ISREG(fileStat.st_mode)) {
            printf("File: %s (Size: %ld bytes)\n", fullPath, fileStat.st_size);
            *totalSize += fileStat.st_size;
        }
    }

    closedir(directory);
}

int main() {
    char dirPath[1024];
    int totalSize = 0;

    printf("Enter the directory path to analyze: ");
    if (fgets(dirPath, sizeof(dirPath), stdin) != NULL) {
        dirPath[strcspn(dirPath, "\n")] = 0; // Remove the newline character
    } else {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    printf("Analyzing disk space for directory: %s\n\n", dirPath);
    listDirectory(dirPath, &totalSize);

    printf("\nTotal size of files in directory: %d bytes\n", totalSize);
    return EXIT_SUCCESS;
}