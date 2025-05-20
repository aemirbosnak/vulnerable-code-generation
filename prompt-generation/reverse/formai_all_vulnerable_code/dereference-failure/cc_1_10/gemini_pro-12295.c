//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Structure to store file information
typedef struct FileInfo {
    char *name;
    size_t size;
} FileInfo;

// Function to compare two FileInfo structures by size
int compareFileInfo(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return (fa->size - fb->size);
}

// Function to get the size of a file
size_t getFileSize(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    }
    return 0;
}

// Function to get the files in a directory
FileInfo *getFilesInDirectory(const char *path, size_t *numFiles) {
    DIR *dir;
    struct dirent *entry;
    FileInfo *files = NULL;
    size_t numFilesAllocated = 0;

    *numFiles = 0;

    dir = opendir(path);
    if (dir == NULL) {
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        size_t size = getFileSize(entry->d_name);
        if (size == 0) {
            continue;
        }

        if (*numFiles >= numFilesAllocated) {
            numFilesAllocated += 100;
            files = realloc(files, sizeof(FileInfo) * numFilesAllocated);
            if (files == NULL) {
                closedir(dir);
                return NULL;
            }
        }

        files[*numFiles].name = strdup(entry->d_name);
        files[*numFiles].size = size;
        (*numFiles)++;
    }

    closedir(dir);

    return files;
}

// Function to print the files in a directory
void printFilesInDirectory(const char *path) {
    size_t numFiles;
    FileInfo *files = getFilesInDirectory(path, &numFiles);
    if (files == NULL) {
        printf("Error getting files in directory: %s\n", path);
        return;
    }

    qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);

    for (size_t i = 0; i < numFiles; i++) {
        printf("%s: %lu bytes\n", files[i].name, files[i].size);
    }

    for (size_t i = 0; i < numFiles; i++) {
        free(files[i].name);
    }
    free(files);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printFilesInDirectory(argv[1]);

    return EXIT_SUCCESS;
}