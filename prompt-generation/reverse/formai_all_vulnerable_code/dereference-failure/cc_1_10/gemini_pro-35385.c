//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Structure to store file information
typedef struct FileInfo {
    char name[256];
    unsigned long long size;
} FileInfo;

// Comparison function for qsort()
int compareFiles(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;

    return (fa->size > fb->size) ? -1 : (fa->size < fb->size) ? 1 : 0;
}

// Function to get the size of a directory
unsigned long long getDirectorySize(const char *path) {
    unsigned long long size = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullpath[256];
        sprintf(fullpath, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            size += getDirectorySize(fullpath);
        } else {
            FILE *file = fopen(fullpath, "rb");
            if (file == NULL) {
                continue;
            }

            fseek(file, 0, SEEK_END);
            size += ftell(file);
            fclose(file);
        }
    }

    closedir(dir);

    return size;
}

int main() {
    // Get the current working directory
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        printf("Error getting current working directory\n");
        return 1;
    }

    // Get the size of the current working directory
    unsigned long long size = getDirectorySize(cwd);

    // Create an array of FileInfo structures
    FileInfo files[1000];

    // Recursively traverse the directory and store the file information in the array
    int numFiles = 0;
    DIR *dir = opendir(cwd);
    if (dir == NULL) {
        printf("Error opening current working directory\n");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullpath[256];
        sprintf(fullpath, "%s/%s", cwd, entry->d_name);

        if (entry->d_type == DT_DIR) {
            files[numFiles].size = getDirectorySize(fullpath);
        } else {
            FILE *file = fopen(fullpath, "rb");
            if (file == NULL) {
                continue;
            }

            fseek(file, 0, SEEK_END);
            files[numFiles].size = ftell(file);
            fclose(file);
        }

        strcpy(files[numFiles].name, entry->d_name);
        numFiles++;
    }

    closedir(dir);

    // Sort the files by size
    qsort(files, numFiles, sizeof(FileInfo), compareFiles);

    // Print the file information
    for (int i = 0; i < numFiles; i++) {
        printf("%s: %llu bytes\n", files[i].name, files[i].size);
    }

    // Print the total size of the directory
    printf("Total size: %llu bytes\n", size);

    return 0;
}