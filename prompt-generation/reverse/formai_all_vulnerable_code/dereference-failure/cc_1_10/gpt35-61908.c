//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the size of a directory
long long calculateFolderSize(const char *folderPath) {
    struct dirent *directoryEntry;
    DIR *directoryPointer;
    long long folderSize = 0;

    directoryPointer = opendir(folderPath);

    while ((directoryEntry = readdir(directoryPointer)) != NULL) {
        char *filePath = malloc(strlen(folderPath) + strlen(directoryEntry->d_name) + 2);
        sprintf(filePath, "%s/%s", folderPath, directoryEntry->d_name);

        struct stat fileStat;
        // Make a stat() system call for the file
        if (stat(filePath, &fileStat) >= 0) {
            // if it is a directory, recursively call this function
            if (S_ISDIR(fileStat.st_mode)) {
                if (strcmp(directoryEntry->d_name, ".") != 0 && strcmp(directoryEntry->d_name, "..") != 0) {
                    folderSize += calculateFolderSize(filePath);
                }
            } else {
                // if it is a file, add the file size to folder size
                folderSize += fileStat.st_size;
            }
        }
        free(filePath);
    }
    closedir(directoryPointer);
    return folderSize;
}

int main() {
    char folderPath[100];
    printf("Enter the folder path: ");
    scanf("%s", folderPath);
    long long folderSize = 0;

    struct stat folderStat;
    int result = stat(folderPath, &folderStat);

    if (result < 0) {
        printf("Error: Unable to get statistics of the provided directory.\n");
    } else {
        if (S_ISDIR(folderStat.st_mode)) {
            folderSize = calculateFolderSize(folderPath);
            printf("The size of the provided directory %s is %lld bytes.\n", folderPath, folderSize);
        } else {
            printf("Error: The provided path is not a directory.\n");
        }
    }
    return 0;
}