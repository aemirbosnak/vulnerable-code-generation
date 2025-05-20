//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void analyze_directory(const char *path, int depth) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(path);
    
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Store total size of files in the current directory
    long total_size = 0;

    printf("%*sDirectory: %s\n", depth * 4, "", path);

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get file status
        if (stat(fullpath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(fullpath, depth + 1);
        } else {
            // If it's a file, print its size and add to total
            printf("%*sFile: %s (Size: %ld bytes)\n", (depth + 1) * 4, "", entry->d_name, statbuf.st_size);
            total_size += statbuf.st_size;
        }
    }

    closedir(dir);
    
    // Print the total size for this directory
    printf("%*sTotal size of files in '%s': %ld bytes\n", depth * 4, "", path, total_size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_path = argv[1];

    // Start analyzing the specified directory
    analyze_directory(dir_path, 0);

    return EXIT_SUCCESS;
}