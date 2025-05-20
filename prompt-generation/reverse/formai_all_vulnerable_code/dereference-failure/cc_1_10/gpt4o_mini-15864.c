//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void traverse_directory(const char *dir_name, int depth) {
    struct dirent *entry;
    struct stat info;
    
    // Open the directory
    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    // Print the current directory name with indentation based on depth
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Directory: %s\n", dir_name);
    
    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        char path[1024];

        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the new path
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        // Get information about the entry
        if (stat(path, &info) == -1) {
            perror("stat error");
            continue;
        }

        // Check if it's a directory or a file
        if (S_ISDIR(info.st_mode)) {
            // If it's a directory, recursively traverse it
            traverse_directory(path, depth + 1);
        } else {
            // If it's a file, print its name
            for (int i = 0; i < depth + 1; i++) {
                printf("  ");
            }
            printf("File: %s\n", path);
        }
    }

    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_name = argv[1];

    // Start traversing from the specified directory
    traverse_directory(directory_name, 0);
    
    return EXIT_SUCCESS;
}