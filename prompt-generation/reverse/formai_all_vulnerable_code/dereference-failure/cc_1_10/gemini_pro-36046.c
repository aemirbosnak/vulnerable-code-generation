//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define the maximum size of the path buffer
#define MAX_PATH_SIZE 4096

// Define the maximum number of files to store in the directory structure
#define MAX_FILES 10000

// Define the structure of a file
typedef struct File {
    char *name;
    char *path;
    long size;
} File;

// Define the structure of a directory
typedef struct Directory {
    char *name;
    char *path;
    long size;
    File files[MAX_FILES];
    int numFiles;
} Directory;

// Define the function to compare two files by size
int compareFilesBySize(const void *a, const void *b) {
    File *file1 = (File *)a;
    File *file2 = (File *)b;

    return file1->size - file2->size;
}

// Define the function to compare two directories by size
int compareDirectoriesBySize(const void *a, const void *b) {
    Directory *dir1 = (Directory *)a;
    Directory *dir2 = (Directory *)b;

    return dir1->size - dir2->size;
}

// Define the function to print the files in a directory
void printDirectory(Directory *dir) {
    printf("%s (%ld bytes):\n", dir->name, dir->size);

    for (int i = 0; i < dir->numFiles; i++) {
        printf("    %s (%ld bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

// Define the function to analyze the disk space usage
void analyzeDiskSpace(char *path) {
    // Create a new directory structure
    Directory *dir = malloc(sizeof(Directory));
    dir->name = path;
    dir->path = path;
    dir->size = 0;
    dir->numFiles = 0;

    // Open the directory
    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    // Read the directory entries
    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file path
        char *filePath = malloc(MAX_PATH_SIZE);
        snprintf(filePath, MAX_PATH_SIZE, "%s/%s", path, entry->d_name);

        // Get the file size
        struct stat sb;
        if (stat(filePath, &sb) == -1) {
            perror("stat");
            continue;
        }

        // Add the file to the directory structure
        File *file = &dir->files[dir->numFiles];
        file->name = entry->d_name;
        file->path = filePath;
        file->size = sb.st_size;
        dir->numFiles++;

        // Update the directory size
        dir->size += file->size;
    }

    // Close the directory
    closedir(dp);

    // Sort the files in the directory by size
    qsort(dir->files, dir->numFiles, sizeof(File), compareFilesBySize);

    // Print the directory
    printDirectory(dir);

    // Recursively analyze the subdirectories
    for (int i = 0; i < dir->numFiles; i++) {
        if (dir->files[i].size > 0 && dir->files[i].path != NULL) {
            analyzeDiskSpace(dir->files[i].path);
        }
    }

    // Free the directory structure
    free(dir);
}

int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s path\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze the disk space usage
    analyzeDiskSpace(argv[1]);

    return EXIT_SUCCESS;
}