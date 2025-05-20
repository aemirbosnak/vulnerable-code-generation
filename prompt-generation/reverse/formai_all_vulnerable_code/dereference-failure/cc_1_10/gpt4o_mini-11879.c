//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

// Struct to hold file information
typedef struct FileInfo {
    char path[MAX_PATH];
    long size;
} FileInfo;

// Function to compare FileInfo based on size
int compareSize(const void *a, const void *b) {
    return ((FileInfo *)b)->size - ((FileInfo *)a)->size;
}

// Function to get the size of a directory recursively
void analyzeDirectory(const char *dirPath, FileInfo **files, int *fileCount, int *capacity) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    if ((dir = opendir(dirPath)) == NULL) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        if (stat(fullPath, &statbuf) == -1) {
            perror("stat failed");
            continue;
        }

        // If it's a directory, analyze it recursively
        if (S_ISDIR(statbuf.st_mode)) {
            analyzeDirectory(fullPath, files, fileCount, capacity);
        } else { 
            // It's a file, record its size
            if (*fileCount >= *capacity) {
                *capacity *= 2;
                *files = realloc(*files, (*capacity) * sizeof(FileInfo));
                if (*files == NULL) {
                    perror("realloc failed");
                    closedir(dir);
                    exit(EXIT_FAILURE);
                }
            }
            snprintf((*files)[*fileCount].path, sizeof((*files)[*fileCount].path), "%s", fullPath);
            (*files)[*fileCount].size = statbuf.st_size;
            (*fileCount)++;
        }
    }
    closedir(dir);
}

// Main analysis function
void analyzeSpace(const char *rootPath) {
    FileInfo *files = malloc(10 * sizeof(FileInfo));
    int fileCount = 0;
    int capacity = 10;

    analyzeDirectory(rootPath, &files, &fileCount, &capacity);

    // Sort files by size
    qsort(files, fileCount, sizeof(FileInfo), compareSize);

    // Display results
    printf("\nDisk space analysis of '%s':\n", rootPath);
    printf("%-100s %s\n", "File/Directory Path", "Size (bytes)");
    printf("%-100s %s\n", "----------------------------------------", "---------");

    for (int i = 0; i < fileCount; i++) {
        printf("%-100s %ld\n", files[i].path, files[i].size);
    }

    // Free allocated memory
    free(files);
}

// Main program execution
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyzeSpace(argv[1]);

    return 0;
}