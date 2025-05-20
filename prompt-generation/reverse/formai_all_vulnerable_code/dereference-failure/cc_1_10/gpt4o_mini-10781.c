//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void list_files(const char *base_path, int depth) {
    struct dirent *dp;
    struct stat statbuf;
    char path[MAX_PATH];
    DIR *dir = opendir(base_path);

    // Check if the directory can be opened
    if (!dir) {
        perror("opendir failed");
        return;
    }

    // Indentation for depth representation
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("Directory: %s\n", base_path);
    
    while ((dp = readdir(dir)) != NULL) {
        // Skip the special entries: "." and ".."
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", base_path, dp->d_name);
        
        // Get status of the file
        if (stat(path, &statbuf) == -1) {
            perror("stat failed");
            continue;
        }

        // Print file information based on type
        if (S_ISDIR(statbuf.st_mode)) {
            // If it's a directory, call the function recursively
            list_files(path, depth + 1);
        } else {
            // If it's a file, print its name
            for (int i = 0; i <= depth; i++) {
                printf("  ");
            }
            printf("File: %s\n", path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start listing files from the given directory
    list_files(argv[1], 0);
    
    return EXIT_SUCCESS;
}