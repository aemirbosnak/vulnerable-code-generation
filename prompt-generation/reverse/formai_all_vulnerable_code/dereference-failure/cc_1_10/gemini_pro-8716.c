//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Custom data types
typedef struct {
    char *name;
    long size;
} FileInfo;

// Function prototypes
long get_dir_size(const char *dir_path);
long get_file_size(const char *file_path);
FileInfo *get_file_info(const char *file_path);
void free_file_info(FileInfo *file_info);

// Main function
int main(int argc, char **argv) {
    // Parse command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        return 1;
    }

    // Get the directory size
    long dir_size = get_dir_size(argv[1]);

    // Print the directory size
    printf("Directory size: %ld bytes\n", dir_size);

    // Get a list of files in the directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        // Ignore hidden files
        if (dirent->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char file_path[strlen(argv[1]) + strlen(dirent->d_name) + 2];
        sprintf(file_path, "%s/%s", argv[1], dirent->d_name);

        // Get the file size
        long file_size = get_file_size(file_path);

        // Print the file size
        printf("%s: %ld bytes\n", dirent->d_name, file_size);
    }

    closedir(dir);

    return 0;
}

// Get the size of a directory
long get_dir_size(const char *dir_path) {
    // Initialize the directory size
    long dir_size = 0;

    // Open the directory
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }

    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        // Ignore hidden files
        if (dirent->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char file_path[strlen(dir_path) + strlen(dirent->d_name) + 2];
        sprintf(file_path, "%s/%s", dir_path, dirent->d_name);

        // Get the file size
        long file_size = get_file_size(file_path);

        // Add the file size to the directory size
        dir_size += file_size;
    }

    closedir(dir);

    return dir_size;
}

// Get the size of a file
long get_file_size(const char *file_path) {
    // Get the file info
    struct stat statbuf;
    if (stat(file_path, &statbuf) != 0) {
        perror("Error getting file info");
        return -1;
    }

    // Return the file size
    return statbuf.st_size;
}

// Get the file info
FileInfo *get_file_info(const char *file_path) {
    // Allocate memory for the file info
    FileInfo *file_info = malloc(sizeof(FileInfo));
    if (file_info == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    // Get the file name
    file_info->name = strdup(file_path);
    if (file_info->name == NULL) {
        perror("Error allocating memory");
        free(file_info);
        return NULL;
    }

    // Get the file size
    file_info->size = get_file_size(file_path);
    if (file_info->size == -1) {
        free(file_info->name);
        free(file_info);
        return NULL;
    }

    // Return the file info
    return file_info;
}

// Free the file info
void free_file_info(FileInfo *file_info) {
    // Free the file name
    free(file_info->name);

    // Free the file info
    free(file_info);
}