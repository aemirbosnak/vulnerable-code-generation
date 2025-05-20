//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function to get the size of a file
long getFileSize(const char *filePath) {
    struct stat fileStat;
    if (stat(filePath, &fileStat) == 0) {
        return fileStat.st_size;
    }
    return -1; // Error in getting file size
}

// Function to analyze the space in a directory
void analyzeDirectory(const char *directoryPath) {
    DIR *dir;
    struct dirent *entry;
    long totalSize = 0; 
    long dirSize = 0;
    char fullPath[MAX_PATH];

    if ((dir = opendir(directoryPath)) == NULL) {
        perror("opendir");
        return;
    }

    printf("Analyzing directory: %s\n", directoryPath);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the special entries
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);
        if (entry->d_type == DT_DIR) {
            // Recursive call for subdirectory
            analyzeDirectory(fullPath);
        } else if (entry->d_type == DT_REG) {
            // Regular file
            long fileSize = getFileSize(fullPath);
            if (fileSize != -1) {
                printf("File: %-40s Size: %ld bytes\n", fullPath, fileSize);
                totalSize += fileSize;
            } else {
                printf("Could not get size for file: %s\n", fullPath);
            }
        }
    }

    closedir(dir);
    printf("Total size of files in directory %s: %ld bytes\n", directoryPath, totalSize);
    printf("-----------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Start analyzing the provided directory
    analyzeDirectory(argv[1]);

    return 0;
}