//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

long long calculate_directory_size(char *dir_path);

int main(int argc, char **argv) {
    // Check if a directory path was provided as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];

    // Check if the provided path exists and is a directory
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        return 1;
    }

    // Calculate the size of the directory
    long long size = calculate_directory_size(dir_path);

    printf("Size of directory '%s': %lld bytes\n", dir_path, size);

    closedir(dir);

    return 0;
}

long long calculate_directory_size(char *dir_path) {
    long long size = 0;

    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        return 0;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        // Ignore the "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[256];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively calculate the size of the subdirectory
            size += calculate_directory_size(path);
        } else {
            // Get the size of the file
            FILE *file = fopen(path, "rb");
            if (file) {
                fseek(file, 0, SEEK_END);
                size += ftell(file);
                fclose(file);
            }
        }
    }

    closedir(dir);

    return size;
}