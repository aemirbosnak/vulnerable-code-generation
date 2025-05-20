//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Structure to store directory and file information
typedef struct {
    char *name;
    long size;
    struct dirent *dirent;
} dir_file;

// Function to compare two directory or file structures by size
int compare_dir_file(const void *a, const void *b) {
    const dir_file *da = (const dir_file *)a;
    const dir_file *db = (const dir_file *)b;
    return (da->size - db->size);
}

// Function to recursively traverse a directory and calculate the size of all files and directories
long calculate_directory_size(char *path) {
    long total_size = 0;

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Read each directory entry
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the file or directory
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        // Get the file or directory size
        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            free(full_path);
            closedir(dir);
            return -1;
        }

        // Add the size to the total size
        if (S_ISDIR(statbuf.st_mode)) {
            long subdir_size = calculate_directory_size(full_path);
            if (subdir_size == -1) {
                free(full_path);
                closedir(dir);
                return -1;
            }
            total_size += subdir_size;
        } else {
            total_size += statbuf.st_size;
        }

        // Free the allocated memory
        free(full_path);
    }

    // Close the directory
    closedir(dir);

    // Return the total size
    return total_size;
}

// Function to print the directory and file sizes in a sorted order
void print_directory_sizes(char *path) {
    // Get the directory size
    long total_size = calculate_directory_size(path);
    if (total_size == -1) {
        perror("calculate_directory_size");
        return;
    }

    // Allocate an array of directory and file structures
    dir_file *dir_files = malloc(sizeof(dir_file) * 1024);
    if (dir_files == NULL) {
        perror("malloc");
        return;
    }

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        free(dir_files);
        return;
    }

    // Read each directory entry
    int num_dir_files = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the file or directory
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        // Get the file or directory size
        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            free(full_path);
            closedir(dir);
            free(dir_files);
            return;
        }

        // Store the directory or file information
        dir_files[num_dir_files].name = entry->d_name;
        dir_files[num_dir_files].size = statbuf.st_size;
        dir_files[num_dir_files].dirent = entry;
        num_dir_files++;

        // Free the allocated memory
        free(full_path);
    }

    // Close the directory
    closedir(dir);

    // Sort the directory and file structures by size
    qsort(dir_files, num_dir_files, sizeof(dir_file), compare_dir_file);

    // Print the directory and file sizes
    printf("Directory and File Sizes for %s:\n", path);
    for (int i = 0; i < num_dir_files; i++) {
        printf("%-20s %10ld bytes\n", dir_files[i].name, dir_files[i].size);
    }

    // Free the allocated memory
    free(dir_files);
}

int main(int argc, char *argv[]) {
    // Check if a path was specified
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Print the directory and file sizes
    print_directory_sizes(argv[1]);

    return EXIT_SUCCESS;
}