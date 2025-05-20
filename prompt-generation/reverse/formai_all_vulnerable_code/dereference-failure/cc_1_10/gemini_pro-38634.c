//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define the maximum length of a file or directory name
#define MAX_NAME_LENGTH 256

// Define the structure to store information about a file or directory
typedef struct file_info {
    char name[MAX_NAME_LENGTH]; // The name of the file or directory
    long long size;             // The size of the file or directory in bytes
    int is_directory;           // A flag indicating whether the file or directory is a directory
} file_info;

// Define the function to compare two file_info structures by size
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return fb->size - fa->size;
}

// Define the function to analyze the disk space usage of a directory
long long analyze_directory(const char *path) {
    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Initialize the total size of the directory
    long long total_size = 0;

    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the file or directory
        char full_path[MAX_NAME_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get the file or directory information
        struct stat st;
        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        // Create a file_info structure
        file_info file_info;
        strcpy(file_info.name, entry->d_name);
        file_info.size = st.st_size;
        file_info.is_directory = S_ISDIR(st.st_mode);

        // Add the size of the file or directory to the total size
        total_size += file_info.size;

        // If the file or directory is a directory, recursively analyze it
        if (file_info.is_directory) {
            total_size += analyze_directory(full_path);
        }
    }

    // Close the directory
    closedir(dir);

    // Return the total size of the directory
    return total_size;
}

// Define the main function
int main(int argc, char **argv) {
    // Check if the user has specified a path to analyze
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the path to analyze
    char *path = argv[1];

    // Analyze the disk space usage of the path
    long long total_size = analyze_directory(path);

    // Print the results
    printf("Total size of %s: %lld bytes\n", path, total_size);

    // Exit successfully
    exit(EXIT_SUCCESS);
}