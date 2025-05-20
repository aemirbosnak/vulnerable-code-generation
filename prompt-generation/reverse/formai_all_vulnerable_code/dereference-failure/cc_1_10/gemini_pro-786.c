//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Define the maximum number of files to analyze
#define MAX_FILES 1000

// Define the structure to store file information
typedef struct {
    char *name;
    long size;
} FileInfo;

// Compare two FileInfo structs by size (descending)
int compareFileInfo(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

// Get the size of a directory
long getDirectorySize(const char *path) {
    long size = 0;
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    // Open the directory
    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir))) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file path
        char filepath[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(filepath, "%s/%s", path, entry->d_name);

        // Get the file stat
        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // Add the file size to the total size
        size += statbuf.st_size;
    }

    // Close the directory
    closedir(dir);

    return size;
}

// Get the file information for a directory
FileInfo *getDirectoryFileInfo(const char *path) {
    FileInfo *fileInfo = malloc(sizeof(FileInfo) * MAX_FILES);
    if (!fileInfo) {
        perror("malloc");
        return NULL;
    }

    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    int i = 0;

    // Open the directory
    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        free(fileInfo);
        return NULL;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir))) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file path
        char filepath[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(filepath, "%s/%s", path, entry->d_name);

        // Get the file stat
        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // Store the file information
        fileInfo[i].name = strdup(entry->d_name);
        fileInfo[i].size = statbuf.st_size;
        i++;
    }

    // Close the directory
    closedir(dir);

    // Sort the file information by size (descending)
    qsort(fileInfo, i, sizeof(FileInfo), compareFileInfo);

    return fileInfo;
}

// Print the file information
void printFileInfo(FileInfo *fileInfo, int numFiles) {
    printf("File Name\t\tSize (bytes)\n");
    printf("------------------------------------\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s\t\t%ld\n", fileInfo[i].name, fileInfo[i].size);
        free(fileInfo[i].name);
    }
    free(fileInfo);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the directory size
    long size = getDirectorySize(argv[1]);
    if (size == -1) {
        return EXIT_FAILURE;
    }

    // Get the file information
    FileInfo *fileInfo = getDirectoryFileInfo(argv[1]);
    if (!fileInfo) {
        return EXIT_FAILURE;
    }

    // Print the file information
    printFileInfo(fileInfo, MAX_FILES);

    return EXIT_SUCCESS;
}