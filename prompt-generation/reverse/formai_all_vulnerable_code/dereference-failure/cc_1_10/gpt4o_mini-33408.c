//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

// Function to get size of a file/directory
long get_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    }
    return 0;
}

// Function to analyze directory
void analyze_directory(const char *dir_path) {
    struct dirent *dir_entry;
    DIR *dir = opendir(dir_path);
    long total_size = 0;

    if (!dir) {
        fprintf(stderr, "Error: Unable to open directory %s\n", dir_path);
        return;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, dir_entry->d_name);
        long size = get_size(full_path);

        // Check if it's a directory or a file
        if (dir_entry->d_type == DT_DIR) {
            printf("Directory: %s (size: %ld bytes)\n", full_path, size);
            analyze_directory(full_path); // Recursive call
        } else {
            printf("File: %s (size: %ld bytes)\n", full_path, size);
            total_size += size;
        }
    }

    closedir(dir);
    printf("Total size in directory %s: %ld bytes\n", dir_path, total_size);
}

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_path = argv[1];
    analyze_directory(dir_path);

    return EXIT_SUCCESS;
}