//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define the maximum length of a file path
#define MAX_PATH_LENGTH 1024

// Define the maximum number of files to be analyzed
#define MAX_FILES 1000

// Define the structure of a file
typedef struct {
    char path[MAX_PATH_LENGTH];
    long size;
} File;

// Declare the global variables
File files[MAX_FILES];
int num_files = 0;

// Function to compare two files by size
int compare_files(const void *a, const void *b) {
    File *file1 = (File *)a;
    File *file2 = (File *)b;
    return file2->size - file1->size;
}

// Function to analyze the disk space usage
void analyze_disk_space() {
    // Get the current working directory
    char cwd[MAX_PATH_LENGTH];
    getcwd(cwd, sizeof(cwd));

    // Open the current working directory
    DIR *dir = opendir(cwd);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Iterate over the files in the current working directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current directory and the parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file path
        char path[MAX_PATH_LENGTH];
        snprintf(path, sizeof(path), "%s/%s", cwd, entry->d_name);

        // Get the file size
        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        // Add the file to the array of files
        if (num_files < MAX_FILES) {
            strcpy(files[num_files].path, path);
            files[num_files].size = statbuf.st_size;
            num_files++;
        }
    }

    // Close the current working directory
    closedir(dir);

    // Sort the files by size
    qsort(files, num_files, sizeof(File), compare_files);

    // Print the files in descending order of size
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%ld\n", files[i].path, files[i].size);
    }
}

// Main function
int main() {
    // Analyze the disk space usage
    analyze_disk_space();

    return EXIT_SUCCESS;
}