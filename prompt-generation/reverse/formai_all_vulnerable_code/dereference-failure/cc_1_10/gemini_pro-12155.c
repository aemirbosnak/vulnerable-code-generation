//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Colors for terminal output
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// Structure to hold file information
typedef struct FileInfo {
    char* name;
    long size;
    char* path;
} FileInfo;

// Compares two FileInfo structures by size
int compareFileInfo(const void* a, const void* b) {
    FileInfo* fileA = (FileInfo*)a;
    FileInfo* fileB = (FileInfo*)b;
    return fileB->size - fileA->size;
}

// Prints a FileInfo structure
void printFileInfo(FileInfo* file) {
    printf("%s%-20s%s%10ld%s%s\n", YELLOW, file->name, RESET, file->size, " bytes", file->path);
}

// Recursively scans a directory and adds all files to an array of FileInfo structures
int scanDirectory(char* path, FileInfo** files, int* numFiles) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char* fullPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(fullPath, "%s/%s", path, entry->d_name);

        struct stat fileStat;
        if (stat(fullPath, &fileStat) == -1) {
            free(fullPath);
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            scanDirectory(fullPath, files, numFiles);
        } else {
            FileInfo* file = malloc(sizeof(FileInfo));
            file->name = strdup(entry->d_name);
            file->size = fileStat.st_size;
            file->path = strdup(fullPath);
            files[*numFiles] = file;
            (*numFiles)++;
        }

        free(fullPath);
    }

    closedir(dir);
    return 0;
}

// Prints a list of the largest files in a directory, sorted by size
void printLargestFiles(char* path, int numFiles) {
    FileInfo** files = malloc(sizeof(FileInfo*) * numFiles);
    int numFilesFound = 0;

    if (scanDirectory(path, files, &numFilesFound) == -1) {
        printf("Error opening directory %s\n", path);
        return;
    }

    // Sort the files by size
    qsort(files, numFilesFound, sizeof(FileInfo*), compareFileInfo);

    // Print the largest files
    printf("\nThe %d largest files in %s are:\n", numFiles, path);
    for (int i = 0; i < numFiles; i++) {
        printFileInfo(files[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < numFilesFound; i++) {
        free(files[i]->name);
        free(files[i]->path);
        free(files[i]);
    }
    free(files);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory> <number of files>\n", argv[0]);
        return 1;
    }

    int numFiles = atoi(argv[2]);
    if (numFiles <= 0 || numFiles > 100) {
        printf("Please enter a valid number of files (1-100)\n");
        return 1;
    }

    printLargestFiles(argv[1], numFiles);
    return 0;
}