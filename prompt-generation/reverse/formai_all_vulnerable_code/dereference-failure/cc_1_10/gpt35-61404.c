//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* Function declarations */
void analyzeDiskSpace(const char *folderPath);
unsigned long long getTotalSize(const char *folderPath);

int main() {
    /* Folder path to analyze */
    char folderPath[100];

    printf("Enter the folder path to analyze: ");
    fgets(folderPath, sizeof(folderPath), stdin);

    /* Remove newline character from input */
    folderPath[strcspn(folderPath, "\n")] = 0;

    /* Call function to analyze disk space */
    analyzeDiskSpace(folderPath);

    return 0;
}

/* Function to analyze disk space */
void analyzeDiskSpace(const char *folderPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    unsigned long long totalSize = 0;

    /* Open directory */
    dir = opendir(folderPath);

    /* If directory exists */
    if (dir) {
        /* Loop through all files/folders in directory */
        while ((entry = readdir(dir)) != NULL) {
            /* Ignore current and parent directory entries */
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;

            /* Construct file/folder path */
            char path[100];
            sprintf(path, "%s/%s", folderPath, entry->d_name);

            /* Get file/folder information */
            if (stat(path, &fileStat) == -1) {
                printf("Unable to get file/folder information for %s\n", path);
                continue;
            }

            /* If it is a directory, recursively analyze it */
            if (S_ISDIR(fileStat.st_mode)) {
                analyzeDiskSpace(path);
            }

            /* Update total size */
            totalSize += fileStat.st_size;
        }

        /* Close directory */
        closedir(dir);
    } 
    /* If directory doesn't exist */
    else {
        printf("Unable to open directory %s\n", folderPath);
    }

    /* Print total size */
    printf("Total size of %s: %llu bytes\n", folderPath, totalSize);
}

/* Function to get total size of folder */
unsigned long long getTotalSize(const char *folderPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    unsigned long long totalSize = 0;

    /* Open directory */
    dir = opendir(folderPath);

    /* If directory exists */
    if (dir) {
        /* Loop through all files/folders in directory */
        while ((entry = readdir(dir)) != NULL) {
            /* Ignore current and parent directory entries */
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;

            /* Construct file/folder path */
            char path[100];
            sprintf(path, "%s/%s", folderPath, entry->d_name);

            /* Get file/folder information */
            if (stat(path, &fileStat) == -1) {
                printf("Unable to get file/folder information for %s\n", path);
                continue;
            }

            /* If it is a directory, recursively get total size */
            if (S_ISDIR(fileStat.st_mode)) {
                totalSize += getTotalSize(path);
            }

            /* Update total size */
            totalSize += fileStat.st_size;
        }

        /* Close directory */
        closedir(dir);
    } 
    /* If directory doesn't exist */
    else {
        printf("Unable to open directory %s\n", folderPath);
    }

    return totalSize;
}