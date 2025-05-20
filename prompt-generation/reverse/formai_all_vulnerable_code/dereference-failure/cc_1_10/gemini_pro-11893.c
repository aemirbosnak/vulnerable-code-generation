//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

// Struct to store file information
typedef struct FileInfo {
    char *path;
    unsigned long size;
} FileInfo;

// Function to compare FileInfo structs by size
int compareFileInfo(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return (fa->size > fb->size) ? -1 : 1;
}

// Function to print FileInfo structs
void printFileInfo(const FileInfo *file) {
    printf("%8lu %s\n", file->size, file->path);
}

// Function to get the files in a directory
FileInfo *getFilesInDirectory(const char *path, int *numFiles) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    FileInfo *files = NULL;
    int i = 0;

    *numFiles = 0;

    // Open the directory
    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return NULL;
    }

    // Get the number of files in the directory
    while ((entry = readdir(dir)) != NULL) {
        (*numFiles)++;
    }

    // Allocate memory for the files
    files = malloc(sizeof(FileInfo) * *numFiles);
    if (!files) {
        perror("malloc");
        closedir(dir);
        return NULL;
    }

    // Rewind the directory stream
    rewinddir(dir);

    // Get the files in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Get the file's path
        files[i].path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (!files[i].path) {
            perror("malloc");
            closedir(dir);
            free(files);
            return NULL;
        }
        strcpy(files[i].path, path);
        strcat(files[i].path, "/");
        strcat(files[i].path, entry->d_name);

        // Get the file's size
        if (stat(files[i].path, &statbuf) < 0) {
            perror("stat");
            closedir(dir);
            free(files[i].path);
            free(files);
            return NULL;
        }
        files[i].size = statbuf.st_size;

        i++;
    }

    // Close the directory
    closedir(dir);

    return files;
}

// Function to free the memory allocated for the files
void freeFiles(FileInfo *files, int numFiles) {
    for (int i = 0; i < numFiles; i++) {
        free(files[i].path);
    }
    free(files);
}

int main(int argc, char *argv[]) {
    int numFiles;
    FileInfo *files;

    // Get the files in the directory
    files = getFilesInDirectory(".", &numFiles);
    if (!files) {
        return EXIT_FAILURE;
    }

    // Sort the files by size
    qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);

    // Print the files
    for (int i = 0; i < numFiles; i++) {
        printFileInfo(&files[i]);
    }

    // Free the memory allocated for the files
    freeFiles(files, numFiles);

    return EXIT_SUCCESS;
}