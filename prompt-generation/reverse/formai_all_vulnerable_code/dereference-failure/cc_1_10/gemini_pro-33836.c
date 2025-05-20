//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Colors for output
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

// Data structures
typedef struct {
    char *path;
    long long size;
} FileData;

typedef struct {
    FileData *files;
    int count;
    long long totalSize;
} FileDataList;

// Function declarations
FileDataList *getFileDataList(const char *directory);
void printFileDataList(FileDataList *list);
void freeFileDataList(FileDataList *list);

// Main function
int main(int argc, char *argv[]) {
    // Check if a directory was specified
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the file data list
    FileDataList *list = getFileDataList(argv[1]);
    if (list == NULL) {
        fprintf(stderr, "Error: Could not get file data list\n");
        return EXIT_FAILURE;
    }

    // Print the file data list
    printFileDataList(list);

    // Free the file data list
    freeFileDataList(list);

    return EXIT_SUCCESS;
}

// Gets the file data list for the specified directory
FileDataList *getFileDataList(const char *directory) {
    // Allocate memory for the file data list
    FileDataList *list = malloc(sizeof(FileDataList));
    if (list == NULL) {
        return NULL;
    }

    // Initialize the file data list
    list->files = NULL;
    list->count = 0;
    list->totalSize = 0;

    // Open the directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        free(list);
        return NULL;
    }

    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char *path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
        if (path == NULL) {
            closedir(dir);
            freeFileDataList(list);
            return NULL;
        }
        sprintf(path, "%s/%s", directory, entry->d_name);

        // Get the file size
        struct stat statbuf;
        if (stat(path, &statbuf) != 0) {
            free(path);
            continue;
        }

        // Add the file data to the list
        list->files = realloc(list->files, (list->count + 1) * sizeof(FileData));
        if (list->files == NULL) {
            free(path);
            closedir(dir);
            freeFileDataList(list);
            return NULL;
        }
        list->files[list->count].path = path;
        list->files[list->count].size = statbuf.st_size;
        list->count++;
        list->totalSize += statbuf.st_size;
    }

    // Close the directory
    closedir(dir);

    // Return the file data list
    return list;
}

// Prints the file data list
void printFileDataList(FileDataList *list) {
    // Print the header
    printf("%-50s %-10s\n", "File Name", "Size (bytes)");
    printf("%-50s %-10s\n", "--------------------------------------------------", "----------");

    // Print the file data
    for (int i = 0; i < list->count; i++) {
        printf("%-50s %-10lld\n", list->files[i].path, list->files[i].size);
    }

    // Print the total size
    printf("\nTotal size: %lld bytes (%s%.2f%s MB)\n", list->totalSize, GREEN, (double)list->totalSize / (1024 * 1024), RESET);
}

// Frees the file data list
void freeFileDataList(FileDataList *list) {
    // Free the file paths
    for (int i = 0; i < list->count; i++) {
        free(list->files[i].path);
    }

    // Free the file data list
    free(list->files);
    free(list);
}