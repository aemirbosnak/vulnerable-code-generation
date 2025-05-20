//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Define the maximum number of files to be analyzed.
#define MAX_FILES 1000

// Structure to store information about a file.
typedef struct file_info {
    char *name;
    long size;
} file_info;

// Function to compare two file_info structures by size in descending order.
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return fb->size - fa->size;
}

// Function to analyze the space occupied by the files in a directory.
void analyze_directory(char *directory_name, file_info *files, int *num_files) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory.
    dir = opendir(directory_name);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Iterate over the files in the directory.
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Allocate memory for the file information.
        files[*num_files].name = malloc(strlen(entry->d_name) + 1);
        if (files[*num_files].name == NULL) {
            perror("malloc");
            closedir(dir);
            return;
        }

        // Copy the file name.
        strcpy(files[*num_files].name, entry->d_name);

        // Get the file size.
        files[*num_files].size = entry->d_ino;

        // Increment the number of files.
        (*num_files)++;

        // Check if the maximum number of files has been reached.
        if (*num_files >= MAX_FILES) {
            break;
        }
    }

    // Close the directory.
    closedir(dir);
}

// Function to print the space occupied by the files in descending order.
void print_files(file_info *files, int num_files) {
    // Sort the files by size in descending order.
    qsort(files, num_files, sizeof(file_info), compare_file_info);

    // Print the files.
    for (int i = 0; i < num_files; i++) {
        printf("%s: %ld bytes\n", files[i].name, files[i].size);
    }
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the user has specified a directory name.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate memory for the file information.
    file_info files[MAX_FILES];

    // Initialize the number of files to 0.
    int num_files = 0;

    // Analyze the space occupied by the files in the directory.
    analyze_directory(argv[1], files, &num_files);

    // Print the space occupied by the files in descending order.
    print_files(files, num_files);

    // Free the memory allocated for the file information.
    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }

    return EXIT_SUCCESS;
}