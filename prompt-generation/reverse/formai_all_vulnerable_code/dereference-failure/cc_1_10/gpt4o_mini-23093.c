//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024
#define MAX_FILES 1000

typedef struct {
    char path[MAX_PATH_LEN];
    long size;
} FileInfo;

FileInfo files[MAX_FILES];
int fileCount = 0;

void addFile(const char *path, long size) {
    if (fileCount < MAX_FILES) {
        strncpy(files[fileCount].path, path, MAX_PATH_LEN);
        files[fileCount].size = size;
        fileCount++;
    } else {
        printf("Maximum file limit reached, not adding: %s\n", path);
    }
}

void analyzeDirectory(const char *path) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char fullPath[MAX_PATH_LEN];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(fullPath, &fileStat) == -1) {
                perror("stat");
                continue;
            }

            if (S_ISDIR(fileStat.st_mode)) {
                analyzeDirectory(fullPath); // Recursive call for directories
            }
            else {
                addFile(fullPath, fileStat.st_size);
            }
        }
    }
    closedir(dp);
}

void sortFiles() {
    for (int i = 0; i < fileCount - 1; i++) {
        for (int j = i + 1; j < fileCount; j++) {
            if (files[i].size < files[j].size) { // Sort descending
                FileInfo temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

void printReport() {
    printf("\n--- Disk Space Analyzer Report ---\n");
    printf("%-80s %s\n", "File Path", "Size (bytes)");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%-80s %ld\n", files[i].path, files[i].size);
    }
    printf("-------------------------------------------------------------\n");
    printf("Total number of files analyzed: %d\n", fileCount);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyzeDirectory(argv[1]);
    sortFiles();
    printReport();

    return EXIT_SUCCESS;
}