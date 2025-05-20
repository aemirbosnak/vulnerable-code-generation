//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void listDirectory(const char *path, int showSize) {
    struct dirent *entry;
    struct stat fileStat;
    char fullPath[1024];
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the . and .. entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        // Get file statistics
        if (stat(fullPath, &fileStat) == -1) {
            perror("stat");
            continue;
        }

        // Check if entry is a directory
        if (S_ISDIR(fileStat.st_mode)) {
            printf("Directory: %s\n", fullPath);
            // Recursive call to list subdirectory
            listDirectory(fullPath, showSize);
        } else {
            // If regular file, print the name and size if requested
            printf("File: %s", fullPath);
            if (showSize) {
                printf(" (Size: %lld bytes)", (long long)fileStat.st_size);
            }
            printf("\n");
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path> [show_size]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int showSize = 0;
    if (argc == 3 && strcmp(argv[2], "show") == 0) {
        showSize = 1;
    }

    listDirectory(argv[1], showSize);
    return EXIT_SUCCESS;
}