//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// Define the maximum number of files to track
#define MAX_FILES 1000

// Define the structure to store file information
typedef struct file_info {
    char *path;
    long size;
} file_info;

// Define the comparison function for sorting files by size
int compare_files(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return (fa->size > fb->size) ? -1 : ((fa->size == fb->size) ? 0 : 1);
}

// Function to get the size of a file
long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    } else {
        return -1;
    }
}

// Function to scan a directory and add files to the list
void scan_directory(const char *path, file_info *files, int *num_files) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_REG) {
            files[*num_files].path = full_path;
            files[*num_files].size = get_file_size(full_path);
            (*num_files)++;
        } else if (entry->d_type == DT_DIR) {
            scan_directory(full_path, files, num_files);
        }

        free(full_path);
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    // Get the starting path from the command line arguments
    char *path = ".";
    if (argc > 1) {
        path = argv[1];
    }

    // Initialize the list of files
    file_info files[MAX_FILES];
    int num_files = 0;

    // Scan the starting path and add files to the list
    scan_directory(path, files, &num_files);

    // Sort the files by size
    qsort(files, num_files, sizeof(file_info), compare_files);

    // Print the list of files
    printf("Files sorted by size:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s: %ld bytes\n", files[i].path, files[i].size);
    }

    // Free the memory allocated for the files
    for (int i = 0; i < num_files; i++) {
        free(files[i].path);
    }

    return 0;
}