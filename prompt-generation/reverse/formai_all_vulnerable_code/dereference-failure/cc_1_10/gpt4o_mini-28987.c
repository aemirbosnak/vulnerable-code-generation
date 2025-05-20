//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BLOCK_SIZE 4096

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
    strcpy(list->files[list->count].path, path);
    list->files[list->count].size = size;
    list->count++;
}

unsigned long long getDirectorySize(const char *dirPath) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *directory = opendir(dirPath);
    unsigned long long totalSize = 0;

    if (directory == NULL) {
        perror("Error opening directory");
        return 0;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filePath[MAX_PATH];
            snprintf(filePath, MAX_PATH, "%s/%s", dirPath, entry->d_name);
            if (stat(filePath, &fileStat) == 0) {
                if (S_ISDIR(fileStat.st_mode)) {
                    totalSize += getDirectorySize(filePath);
                } else {
                    totalSize += fileStat.st_size;
                }
            }
        }
    }
    
    closedir(directory);
    return totalSize;
}

void analyzeSpace(const char *path, FileList *fileList) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *directory = opendir(path);

    if (directory == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char newPath[MAX_PATH];
            snprintf(newPath, MAX_PATH, "%s/%s", path, entry->d_name);
            if (stat(newPath, &fileStat) == 0) {
                if (S_ISDIR(fileStat.st_mode)) {
                    analyzeSpace(newPath, fileList);
                } else {
                    addFile(fileList, newPath, fileStat.st_size);
                }
            }
        }
    }

    closedir(directory);
}

void printFileList(const FileList *list) {
    printf("Analyzed Files:\n");
    printf("%-50s %10s\n", "File", "Size (Bytes)");
    printf("%-50s %10s\n", "--------------------", "------------");
    for (size_t i = 0; i < list->count; i++) {
        printf("%-50s %10llu\n", list->files[i].path, list->files[i].size);
    }
}

unsigned long long totalSize(const FileList *list) {
    unsigned long long size = 0;
    for (size_t i = 0; i < list->count; i++) {
        size += list->files[i].size;
    }
    return size;
}

void freeFileList(FileList *list) {
    free(list->files);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    FileList fileList;

    initFileList(&fileList);
    analyzeSpace(directoryPath, &fileList);
    printFileList(&fileList);

    unsigned long long dirSize = totalSize(&fileList);
    printf("\nTotal size of files in directory '%s': %llu Bytes\n", directoryPath, dirSize);

    freeFileList(&fileList);
    return EXIT_SUCCESS;
}