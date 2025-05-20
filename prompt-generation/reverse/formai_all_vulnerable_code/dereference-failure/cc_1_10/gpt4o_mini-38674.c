//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function prototype
void analyzeDirectory(const char *dirPath, size_t *totalSize);
void printSize(size_t size);
void humanReadableSize(size_t size, char *buffer);

int main(int argc, char *argv[]) {
    char dirPath[MAX_PATH];
    size_t totalSize = 0;

    // Check for the correct number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Set the directory path from the command-line arguments
    snprintf(dirPath, sizeof(dirPath), "%s", argv[1]);

    // Analyze the given directory
    analyzeDirectory(dirPath, &totalSize);

    // Print the total size of files found
    printf("\nTotal size of files in '%s' directory: ", dirPath);
    printSize(totalSize);

    return EXIT_SUCCESS;
}

// Function to analyze the directory and calculate sizes
void analyzeDirectory(const char *dirPath, size_t *totalSize) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    struct stat fileStat;
    char fullPath[MAX_PATH];

    if (dir == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", dirPath);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        if (stat(fullPath, &fileStat) == -1) {
            fprintf(stderr, "Could not get the file statistics for: %s\n", fullPath);
            continue;
        }

        // If it's a directory, recursively analyze it
        if (S_ISDIR(fileStat.st_mode)) {
            printf("Entering directory: %s\n", fullPath);
            analyzeDirectory(fullPath, totalSize);
        } else {
            // It's a file, add its size to the total
            printf("Found file: %s (Size: ", fullPath);
            printSize(fileStat.st_size);
            *totalSize += fileStat.st_size;
        }
    }

    closedir(dir);
}

// Function to print the size in human-readable format
void printSize(size_t size) {
    char buffer[20];
    humanReadableSize(size, buffer);
    printf("%s\n", buffer);
}

// Function to convert size to human-readable format
void humanReadableSize(size_t size, char *buffer) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    
    double sizeInUnit = (double)size;
    while (sizeInUnit >= 1024 && unitIndex < 4) {
        sizeInUnit /= 1024;
        unitIndex++;
    }
    
    snprintf(buffer, 20, "%.2f %s", sizeInUnit, units[unitIndex]);
}