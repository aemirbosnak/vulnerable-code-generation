//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum length of a file path
#define MAX_PATH_LEN 1024

// Define a structure to store the file size and path
typedef struct file_size {
    long size;
    char path[MAX_PATH_LEN];
} file_size;

// Create a function to compare two file_size structs by size in descending order
int compare_file_size(const void *a, const void *b) {
    file_size *fa = (file_size *)a;
    file_size *fb = (file_size *)b;
    return fb->size - fa->size;
}

// Create a function to recursively traverse the directory and calculate the file sizes
void traverse_directory(char *dirname, file_size *files, long *total_size, int *file_count) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH_LEN];
        snprintf(path, MAX_PATH_LEN, "%s/%s", dirname, entry->d_name);

        struct stat statbuf;
        if (lstat(path, &statbuf) != 0) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            traverse_directory(path, files, total_size, file_count);
        } else {
            files[*file_count].size = statbuf.st_size;
            strcpy(files[*file_count].path, path);
            (*total_size) += statbuf.st_size;
            (*file_count)++;
        }
    }

    closedir(dir);
}

int main() {
    // Get the current working directory
    char cwd[MAX_PATH_LEN];
    if (!getcwd(cwd, MAX_PATH_LEN)) {
        perror("getcwd");
        return EXIT_FAILURE;
    }

    // Create an array to store the file sizes
    file_size files[10000];

    // Initialize the variables
    long total_size = 0;
    int file_count = 0;

    // Traverse the directory
    traverse_directory(cwd, files, &total_size, &file_count);

    // Sort the files by size in descending order
    qsort(files, file_count, sizeof(file_size), compare_file_size);

    // Print the results
    printf("Total size: %ld bytes\n", total_size);
    printf("File count: %d\n", file_count);
    printf("\nLargest files:\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s: %ld bytes\n", files[i].path, files[i].size);
    }

    return EXIT_SUCCESS;
}