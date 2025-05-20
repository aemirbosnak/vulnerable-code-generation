//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 100
#define FILE_NAME_SIZE 256

typedef struct {
    char name[FILE_NAME_SIZE];
    unsigned long size;
} File;

void analyzeDirectory(const char *dirPath, File *files, int *fileCount) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dir = opendir(dirPath);
    
    if (!dir) {
        printf("Captain DiskSpace cannot open the treasure chest (directory)! Arrr!\n");
        return;
    }
    
    printf("Ahoy! Inspecting the directory: %s\n", dirPath);
    
    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files
        if (entry->d_name[0] == '.') continue;
        
        char filePath[FILE_NAME_SIZE];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
        
        if (stat(filePath, &fileStat) == 0) {
            if (S_ISREG(fileStat.st_mode)) {
                if (*fileCount < MAX_FILES) {
                    strncpy(files[*fileCount].name, entry->d_name, FILE_NAME_SIZE);
                    files[*fileCount].size = fileStat.st_size;
                    (*fileCount)++;
                }
            }
        }
    }
    
    closedir(dir);
}

void sortFiles(File *files, int fileCount) {
    // Bubble sort to sort the files from largest to smallest
    for (int i = 0; i < fileCount - 1; i++) {
        for (int j = 0; j < fileCount - i - 1; j++) {
            if (files[j].size < files[j + 1].size) {
                File temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

void displayFiles(File *files, int fileCount) {
    printf("\nCaptain DiskSpace's Report:\n");
    printf("-------------------------------- \n");
    for (int i = 0; i < fileCount; i++) {
        printf("File: %s | Size: %lu bytes 🏴‍☠️\n", files[i].name, files[i].size);
    }
    printf("-------------------------------- \n");
}

int main() {
    File files[MAX_FILES];
    int fileCount = 0;

    printf("Welcome to the Captain DiskSpace Analyzer!\n");
    printf("Shiver me timbers! Let's find those pesky files!\n");

    const char *homeDir = getenv("HOME");
    if (!homeDir) {
        printf("Captain DiskSpace lost in the vast sea of directories! 🌊\n");
        return 1;
    }

    analyzeDirectory(homeDir, files, &fileCount);
    sortFiles(files, fileCount);
    displayFiles(files, fileCount);

    printf("Captain DiskSpace signing off! May your files be ever organized! ⚓️\n");
    return 0;
}