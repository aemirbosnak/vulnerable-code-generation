//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

// Define the maximum number of files to analyze
#define MAX_FILES 1000

// Define the structure to store file information
typedef struct file_info {
    char *name;
    long size;
    time_t mtime;
} file_info;

// Function to compare two file_info structures by size
int compare_file_info_by_size(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return fb->size - fa->size;
}

// Function to analyze a directory and store the file information in an array
int analyze_directory(const char *dir, file_info **files, int *num_files) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    int i = 0;

    // Open the directory
    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        return -1;
    }

    // Read the directory entries
    while ((entry = readdir(dp)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the file information
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            closedir(dp);
            return -1;
        }

        // Allocate memory for the file information
        files[i] = malloc(sizeof(file_info));
        if (files[i] == NULL) {
            perror("malloc");
            closedir(dp);
            return -1;
        }

        // Store the file information
        files[i]->name = strdup(entry->d_name);
        files[i]->size = statbuf.st_size;
        files[i]->mtime = statbuf.st_mtime;

        i++;
    }

    // Close the directory
    closedir(dp);

    *num_files = i;

    return 0;
}

// Function to print the file information
void print_file_info(const file_info *file) {
    printf("%s: %ld bytes, last modified on %s", file->name, file->size, ctime(&file->mtime));
}

int main() {
    // Allocate memory for the file information array
    file_info *files[MAX_FILES];

    // Initialize the number of files to 0
    int num_files = 0;

    // Analyze the current directory
    if (analyze_directory(".", files, &num_files) == -1) {
        return EXIT_FAILURE;
    }

    // Sort the file information array by size
    qsort(files, num_files, sizeof(file_info), compare_file_info_by_size);

    // Print the file information
    for (int i = 0; i < num_files; i++) {
        print_file_info(files[i]);
    }

    // Free the memory allocated for the file information array
    for (int i = 0; i < num_files; i++) {
        free(files[i]->name);
        free(files[i]);
    }

    return EXIT_SUCCESS;
}