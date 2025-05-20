//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024      // Maximum length of path name
#define MAX_FILES 100000   // Maximum number of files to process

// Structure for holding file data
typedef struct {
    char name[MAX_PATH];    // File name
    long size;              // File size
} FileData;

// Function declarations
int cmpSize(const void *a, const void *b);
void analyzeDirectory(const char* path, FileData* files, int* numFiles, long* totalSize);
void printResult(FileData* files, int numFiles, long totalSize);

int main(int argc, char** argv) {
    if(argc < 2) {  // Check if path argument is provided
        printf("Usage: %s <path to analyze>\n", argv[0]);
        return 1;
    }
    char path[MAX_PATH];
    strncpy(path, argv[1], MAX_PATH);

    FileData files[MAX_FILES];
    int numFiles = 0;
    long totalSize = 0;

    analyzeDirectory(path, files, &numFiles, &totalSize);
    qsort(files, numFiles, sizeof(FileData), cmpSize);

    printResult(files, numFiles, totalSize);

    return 0;
}

// Compare function for qsort
int cmpSize(const void *a, const void *b) {
    long diff = ((FileData*)b)->size - ((FileData*)a)->size;
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

// Analyze directory recursively for files and subdirs
void analyzeDirectory(const char* path, FileData* files, int* numFiles, long* totalSize) {
    struct stat st;
    if(stat(path, &st) != 0) {  // Check if file/directory exists
        printf("Error: %s does not exist\n", path);
        return;
    }
    if(S_ISREG(st.st_mode)) {  // If input is a file, add it to the array
        if(*numFiles >= MAX_FILES) {
            printf("Warning: Maximum number of files reached (%d)\n", MAX_FILES);
            return;
        }
        FileData* f = &files[*numFiles];
        strncpy(f->name, path, MAX_PATH);
        f->size = st.st_size;
        (*totalSize) += st.st_size;
        (*numFiles)++;
    }
    else if(S_ISDIR(st.st_mode)) {  // If input is a directory, analyze its contents
        DIR* dp = opendir(path);
        if(dp == NULL) {
            printf("Error: Cannot open directory %s\n", path);
            return;
        }
        struct dirent* de;
        while((de = readdir(dp)) != NULL) {
            if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
                continue;  // Ignore current dir (.) and parent dir (..)
            }
            char nextPath[MAX_PATH];
            snprintf(nextPath, MAX_PATH, "%s/%s", path, de->d_name);
            analyzeDirectory(nextPath, files, numFiles, totalSize);  // Recurse into subdir or file
        }
        closedir(dp);
    }
}

// Print the results from analyzing the directory
void printResult(FileData* files, int numFiles, long totalSize) {
    printf("Total size: %ld bytes\n", totalSize);
    printf("%-50s %s\n", "File name", "Size (bytes)");
    printf("--------------------------------------------------\n");
    for(int i = 0; i < numFiles; i++) {
        FileData* f = &files[i];
        printf("%-50s %ld\n", f->name, f->size);
    }
}