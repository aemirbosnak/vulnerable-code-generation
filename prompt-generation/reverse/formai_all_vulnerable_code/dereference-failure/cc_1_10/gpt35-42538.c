//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES 10000

// Struct for storing file information
typedef struct {
    char name[MAX_PATH_LENGTH];
    long int size;
} file_info;

// Global variables
file_info files[MAX_FILES];
int num_files = 0;
long int total_size = 0;

// Function for recursively scanning directories and adding files to the list
void scan_directory(char *path) {

    DIR *dir;
    struct dirent *dp;

    if ((dir = opendir(path)) == NULL) {
        printf("Unable to open directory: %s\n", path);
        exit(EXIT_FAILURE);
    }

    while ((dp = readdir(dir)) != NULL) {

        char file_path[MAX_PATH_LENGTH];
        struct stat s;

        // Ignore current and parent directories
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        // Construct full path of file/directory
        snprintf(file_path, MAX_PATH_LENGTH, "%s/%s", path, dp->d_name);

        if (stat(file_path, &s) == -1) {
            printf("Unable to get file information for: %s\n", file_path);
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(s.st_mode)) {
            // Recursively call function if entry is a directory
            scan_directory(file_path);
        } else if (S_ISREG(s.st_mode)) {
            // Add file to list if entry is a regular file
            file_info f;
            strncpy(f.name, file_path, MAX_PATH_LENGTH);
            f.size = s.st_size;
            files[num_files++] = f;
            total_size += f.size;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {

    // Check for command line argument
    if (argc != 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];

    // Check for invalid directory path
    struct stat s;
    if (stat(path, &s) == -1 || !S_ISDIR(s.st_mode)) {
        printf("Invalid directory path: %s\n", path);
        exit(EXIT_FAILURE);
    }

    // Scan directory recursively and generate list of files
    scan_directory(path);

    // Sort files by size in descending order
    for (int i = 0; i < num_files - 1; i++) {
        for (int j = i + 1; j < num_files; j++) {
            if (files[i].size < files[j].size) {
                file_info temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Print results
    printf("Total size of directory: %ld bytes\n", total_size);
    printf("Top 10 largest files:\n");
    for (int i = 0; i < 10 && i < num_files; i++) {
        printf("%s - %ld bytes\n", files[i].name, files[i].size);
    }

    // Clear list of files
    memset(files, 0, sizeof(files));
    num_files = 0;
    total_size = 0;

    return 0;
}