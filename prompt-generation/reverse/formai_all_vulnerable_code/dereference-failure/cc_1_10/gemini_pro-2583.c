//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Type definitions
typedef struct file_info {
    char *name;
    long size;
    char *path;
} file_info;

// Function prototypes
file_info *get_file_info(char *path);
void print_file_info(file_info *info);
void free_file_info(file_info *info);
long get_dir_size(char *path);

// Main function
int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the directory size
    long dir_size = get_dir_size(argv[1]);

    // Print the directory size
    printf("Directory size: %ld bytes\n", dir_size);

    return 0;
}

// Get file information
file_info *get_file_info(char *path) {
    // Allocate memory for file info
    file_info *info = malloc(sizeof(file_info));

    // Get file size
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        return NULL;
    }
    info->size = statbuf.st_size;

    // Get file name
    info->name = malloc(strlen(path) + 1);
    strcpy(info->name, path);

    // Get file path
    info->path = malloc(strlen(path) + 1);
    strcpy(info->path, path);

    // Return file info
    return info;
}

// Print file information
void print_file_info(file_info *info) {
    printf("%s: %ld bytes\n", info->name, info->size);
}

// Free file information
void free_file_info(file_info *info) {
    free(info->name);
    free(info->path);
    free(info);
}

// Get directory size
long get_dir_size(char *path) {
    // Open directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Get directory size
    long size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get file info
        char *filepath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(filepath, "%s/%s", path, entry->d_name);
        file_info *info = get_file_info(filepath);
        free(filepath);

        // Add file size to directory size
        size += info->size;

        // Free file info
        free_file_info(info);
    }

    // Close directory
    closedir(dir);

    // Return directory size
    return size;
}