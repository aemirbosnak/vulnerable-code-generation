//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

// Configuration options
#define MAX_DEPTH 10
#define MAX_FILES 1000
#define MAX_PATH_LENGTH 1024

// Data structures
typedef struct FileInfo {
    char path[MAX_PATH_LENGTH];
    size_t size;
} FileInfo;

typedef struct DirectoryInfo {
    char path[MAX_PATH_LENGTH];
    size_t size;
} DirectoryInfo;

// Function prototypes
size_t analyze_directory(const char *path, FileInfo *files, size_t *num_files, DirectoryInfo *directories, size_t *num_directories, int depth);
void print_results(const FileInfo *files, size_t num_files, const DirectoryInfo *directories, size_t num_directories);

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate memory for data structures
    FileInfo files[MAX_FILES];
    DirectoryInfo directories[MAX_FILES];

    // Analyze the directory
    size_t num_files = 0;
    size_t num_directories = 0;
    size_t size = analyze_directory(argv[1], files, &num_files, directories, &num_directories, 0);

    // Print the results
    print_results(files, num_files, directories, num_directories);

    // Free memory
    free(files);
    free(directories);

    return EXIT_SUCCESS;
}

// Function to analyze a directory
size_t analyze_directory(const char *path, FileInfo *files, size_t *num_files, DirectoryInfo *directories, size_t *num_directories, int depth) {
    // Check depth
    if (depth >= MAX_DEPTH) {
        return 0;
    }

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 0;
    }

    size_t size = 0;

    // Get the current working directory
    char cwd[MAX_PATH_LENGTH];
    if (getcwd(cwd, MAX_PATH_LENGTH) == NULL) {
        perror("getcwd");
        closedir(dir);
        return 0;
    }

    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the entry
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        // Get the file size
        struct stat st;
        if (stat(full_path, &st) == -1) {
            perror("stat");
            continue;
        }

        // If the entry is a file, add it to the list of files
        if (S_ISREG(st.st_mode)) {
            if (*num_files >= MAX_FILES) {
                fprintf(stderr, "Error: Too many files. Increase MAX_FILES.\n");
                closedir(dir);
                return 0;
            }

            files[*num_files].size = st.st_size;
            strcpy(files[*num_files].path, full_path);
            (*num_files)++;

            size += st.st_size;
        }
        // If the entry is a directory, add it to the list of directories
        else if (S_ISDIR(st.st_mode)) {
            if (*num_directories >= MAX_FILES) {
                fprintf(stderr, "Error: Too many directories. Increase MAX_FILES.\n");
                closedir(dir);
                return 0;
            }

            directories[*num_directories].size = 0;
            strcpy(directories[*num_directories].path, full_path);
            (*num_directories)++;

            // Recursively analyze the directory
            size += analyze_directory(full_path, files, num_files, directories, num_directories, depth + 1);
        }
    }

    // Close the directory
    closedir(dir);

    return size;
}

// Function to print the results
void print_results(const FileInfo *files, size_t num_files, const DirectoryInfo *directories, size_t num_directories) {
    printf("Files:\n");
    for (size_t i = 0; i < num_files; i++) {
        printf("%s: %zu bytes\n", files[i].path, files[i].size);
    }

    printf("\nDirectories:\n");
    for (size_t i = 0; i < num_directories; i++) {
        printf("%s: %zu bytes\n", directories[i].path, directories[i].size);
    }
}