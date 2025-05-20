//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void print_usage() {
    printf("Usage: disk_space_analyzer <directory_path>\n");
}

void analyze_directory(const char *path, int depth) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Add indentation for depth level
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }

    printf("Directory: %s\n", path);

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full path for file/sub-directory
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get file/directory information
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // If it is a directory, analyze recursively
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(full_path, depth + 1);
        } else {
            // Print file size
            for (int i = 0; i < depth + 1; i++) {
                printf("    ");
            }
            printf("File: %s, Size: %ld bytes\n", full_path, statbuf.st_size);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    struct stat statbuf;

    // Check if the provided path is a directory
    if (stat(directory, &statbuf) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "Error: %s is not a directory.\n", directory);
        return EXIT_FAILURE;
    }

    // Start analyzing the specified directory
    analyze_directory(directory, 0);

    return EXIT_SUCCESS;
}