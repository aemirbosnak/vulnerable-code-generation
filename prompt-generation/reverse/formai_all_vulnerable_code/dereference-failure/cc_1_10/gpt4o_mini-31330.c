//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 256

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} FileInfo;

typedef struct {
    FileInfo *files;
    size_t count;
    size_t capacity;
} FileList;

void initFileList(FileList *list) {
    list->count = 0;
    list->capacity = 10;
    list->files = (FileInfo *)malloc(list->capacity * sizeof(FileInfo));
}

void addFile(FileList *list, const char *path, unsigned long long size) {
    if (list->count == list->capacity) {
        list->capacity *= 2;
        list->files = (FileInfo *)realloc(list->files, list->capacity * sizeof(FileInfo));
    }

    strncpy(list->files[list->count].path, path, MAX_PATH);
    list->files[list->count].size = size;
    list->count++;
}

void freeFileList(FileList *list) {
    free(list->files);
}

unsigned long long getDirectorySize(const char *path) {
    unsigned long long totalSize = 0;
    DIR *dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", path);
        return totalSize;
    }

    struct dirent *entry;
    struct stat statbuf;
    char fullPath[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
            if (stat(fullPath, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    totalSize += getDirectorySize(fullPath);
                } else {
                    totalSize += statbuf.st_size;
                }
            }
        }
    }

    closedir(dir);
    return totalSize;
}

void printFiles(FileList *list) {
    printf("%-50s %12s\n", "File/Directory", "Size (Bytes)");
    printf("-----------------------------------------------------\n");
    for (size_t i = 0; i < list->count; i++) {
        printf("%-50s %12llu\n", list->files[i].path, list->files[i].size);
    }
}

void analyzeDirectory(const char *path, FileList *fileList) {
    DIR *dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", path);
        return;
    }

    struct dirent *entry;
    char fullPath[MAX_PATH];
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
            struct stat statbuf;
            if (stat(fullPath, &statbuf) == 0) {
                addFile(fileList, fullPath, statbuf.st_size);
            }
        }
    }

    closedir(dir);
}

void analyzeDiskUsage(const char *directory) {
    FileList fileList;
    initFileList(&fileList);

    analyzeDirectory(directory, &fileList);
    printFiles(&fileList);
    
    // Calculate total size
    unsigned long long totalSize = 0;
    for (size_t i = 0; i < fileList.count; i++) {
        totalSize += fileList.files[i].size;
    }

    printf("-----------------------------------------------------\n");
    printf("Total Size: %llu bytes\n", totalSize);

    freeFileList(&fileList);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyzeDiskUsage(argv[1]);
    return EXIT_SUCCESS;
}