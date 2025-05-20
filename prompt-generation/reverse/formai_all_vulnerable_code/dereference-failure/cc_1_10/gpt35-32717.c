//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

long long int totalSize = 0; // For storing the total size of the directory

// This function recursively traverses the directory and calculates the total disk space used.
void calculateDiskSpace(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    
    dir = opendir(path);

    if (dir == NULL)
        return;

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[256];

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        stat(fullPath, &fileStat);

        if (S_ISDIR(fileStat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            calculateDiskSpace(fullPath); // Recursively traverse directories
        } else {
            totalSize += fileStat.st_size; // Add the size of the current file to the total
        }
    }

    closedir(dir);
}

int main() {
    char path[256];

    printf("Enter the directory path to analyze: ");
    fgets(path, sizeof(path), stdin);

    // Remove the newline character from path
    path[strcspn(path, "\n")] = 0;

    calculateDiskSpace(path);

    // Print the total disk space used in kilobytes, megabytes and gigabytes
    printf("Total disk space used: %lli bytes\n", totalSize);
    printf("Total disk space used: %.2f KB\n", (float)totalSize / 1024);
    printf("Total disk space used: %.2f MB\n", (float)totalSize / 1024 / 1024);
    printf("Total disk space used: %.2f GB\n", (float)totalSize / 1024 / 1024 / 1024);

    return 0;
}