//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Constants
#define MAX_PATH 4096

// Data structures
typedef struct FileInfo {
    char *path;
    off_t size;
} FileInfo;

// Function declarations
int compare_files(const void *a, const void *b);
void print_file_info(const FileInfo *file);
void analyze_directory(const char *path, FileInfo **files, int *num_files);
void free_file_info(FileInfo **files, int num_files);

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the directory path
    char *path = argv[1];

    // Initialize the file info array
    FileInfo **files = NULL;
    int num_files = 0;

    // Analyze the directory
    analyze_directory(path, files, &num_files);

    // Sort the files by size
    qsort(files, num_files, sizeof(FileInfo *), compare_files);

    // Print the file info
    for (int i = 0; i < num_files; i++) {
        print_file_info(files[i]);
    }

    // Free the file info
    free_file_info(files, num_files);

    return EXIT_SUCCESS;
}

// Compare two files by size
int compare_files(const void *a, const void *b) {
    const FileInfo *file1 = *(const FileInfo **)a;
    const FileInfo *file2 = *(const FileInfo **)b;

    return file2->size - file1->size;
}

// Print the file info
void print_file_info(const FileInfo *file) {
    printf("%s: %ld bytes\n", file->path, file->size);
}

// Analyze a directory
void analyze_directory(const char *path, FileInfo **files, int *num_files) {
    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Read the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char *file_path = malloc(MAX_PATH);
        if (file_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        snprintf(file_path, MAX_PATH, "%s/%s", path, entry->d_name);

        // Get the file size
        struct stat statbuf;
        if (lstat(file_path, &statbuf) != 0) {
            perror("lstat");
            free(file_path);
            continue;
        }

        // Allocate memory for the file info
        FileInfo *file = malloc(sizeof(FileInfo));
        if (file == NULL) {
            perror("malloc");
            free(file_path);
            continue;
        }

        // Initialize the file info
        file->path = file_path;
        file->size = statbuf.st_size;

        // Add the file info to the array
        files[*num_files] = file;
        *num_files += 1;
    }

    // Close the directory
    closedir(dir);
}

// Free the file info
void free_file_info(FileInfo **files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        free(files[i]->path);
        free(files[i]);
    }

    free(files);
}