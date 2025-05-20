//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Define the maximum length of a file path
#define MAX_PATH_LENGTH 1024

// Structure to store the size and path of a file
typedef struct {
    long long size;
    char path[MAX_PATH_LENGTH];
} FileInfo;

// Function to compare two FileInfo structures by size
int compareFileInfo(const void *a, const void *b) {
    const FileInfo *fileInfoA = (const FileInfo *)a;
    const FileInfo *fileInfoB = (const FileInfo *)b;

    return fileInfoA->size - fileInfoB->size;
}

// Function to recursively analyze the disk space usage of a directory
long long analyzeDiskSpace(const char *path) {
    // Initialize the total size to 0
    long long totalSize = 0;

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }

    // Read the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the file or directory
        char fullPath[MAX_PATH_LENGTH];
        snprintf(fullPath, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        // Get the file or directory information
        struct stat statbuf;
        if (stat(fullPath, &statbuf) != 0) {
            perror("Error getting file information");
            continue;
        }

        // If the file or directory is a regular file, add its size to the total
        if (S_ISREG(statbuf.st_mode)) {
            totalSize += statbuf.st_size;
        }
        // If the file or directory is a directory, recursively analyze its disk space usage
        else if (S_ISDIR(statbuf.st_mode)) {
            totalSize += analyzeDiskSpace(fullPath);
        }
    }

    // Close the directory
    closedir(dir);

    // Return the total size
    return totalSize;
}

// Function to print the disk space usage of the top 10 largest files in a directory
void printTop10LargestFiles(const char *path) {
    // Initialize an array of FileInfo structures to store the top 10 largest files
    FileInfo largestFiles[10];

    // Recursively analyze the disk space usage of the directory
    long long totalSize = analyzeDiskSpace(path);

    // Get the list of all files in the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    // Read the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the file
        char fullPath[MAX_PATH_LENGTH];
        snprintf(fullPath, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        // Get the file information
        struct stat statbuf;
        if (stat(fullPath, &statbuf) != 0) {
            perror("Error getting file information");
            continue;
        }

        // If the file is a regular file, add it to the array of largest files
        if (S_ISREG(statbuf.st_mode)) {
            FileInfo fileInfo = {statbuf.st_size, fullPath};

            // Find the index of the smallest file in the array
            int smallestIndex = 0;
            for (int i = 1; i < 10; i++) {
                if (largestFiles[i].size < largestFiles[smallestIndex].size) {
                    smallestIndex = i;
                }
            }

            // If the file is larger than the smallest file in the array, replace the smallest file with the new file
            if (fileInfo.size > largestFiles[smallestIndex].size) {
                largestFiles[smallestIndex] = fileInfo;
            }
        }
    }

    // Close the directory
    closedir(dir);

    // Sort the array of largest files by size
    qsort(largestFiles, 10, sizeof(FileInfo), compareFileInfo);

    // Print the top 10 largest files
    printf("Top 10 Largest Files in %s:\n", path);
    for (int i = 0; i < 10; i++) {
        printf("%d. %s (%lld bytes)\n", i + 1, largestFiles[i].path, largestFiles[i].size);
    }

    printf("Total size: %lld bytes\n", totalSize);
}

int main() {
    // Get the path of the directory to analyze
    char path[MAX_PATH_LENGTH];
    printf("Enter the path of the directory to analyze: ");
    scanf("%s", path);

    // Print the disk space usage of the top 10 largest files in the directory
    printTop10LargestFiles(path);

    return 0;
}