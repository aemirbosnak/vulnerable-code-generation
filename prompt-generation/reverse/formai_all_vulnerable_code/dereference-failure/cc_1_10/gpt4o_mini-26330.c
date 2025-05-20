//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

// Structure to hold file information
typedef struct {
    char name[MAX_PATH];
    off_t size;
} FileInfo;

// Function to compare two FileInfo structures for sorting
int compareSize(const void *a, const void *b) {
    FileInfo *fileA = (FileInfo *)a;
    FileInfo *fileB = (FileInfo *)b;
    return (fileB->size - fileA->size); // Sort in descending order
}

// Function to analyze the disk space usage for a given directory
void analyzeDirectory(const char *path, FileInfo **files, size_t *fileCount) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        // Get file stats
        if (stat(fullPath, &fileStat) == -1) {
            perror("stat");
            continue;
        }

        // If it's a regular file, record its information
        if (S_ISREG(fileStat.st_mode)) {
            strcpy((*files)[*fileCount].name, entry->d_name);
            (*files)[*fileCount].size = fileStat.st_size;
            (*fileCount)++;
        }
    }

    closedir(dp);
}

// Function to print the analyzed file information
void printFileInfo(FileInfo *files, size_t fileCount) {
    printf("File Name\t\tSize (Bytes)\n");
    printf("----------------------------------------\n");
    for (size_t i = 0; i < fileCount; i++) {
        printf("%-20s\t%ld\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    FileInfo *files = malloc(1000 * sizeof(FileInfo)); // Allocate space for file information
    if (files == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    size_t fileCount = 0;

    // Analyze the specified directory
    analyzeDirectory(directoryPath, &files, &fileCount);

    // Sort the files based on the size
    qsort(files, fileCount, sizeof(FileInfo), compareSize);

    // Print the sorted file information
    printFileInfo(files, fileCount);

    // Cleanup
    free(files);
    return EXIT_SUCCESS;
}