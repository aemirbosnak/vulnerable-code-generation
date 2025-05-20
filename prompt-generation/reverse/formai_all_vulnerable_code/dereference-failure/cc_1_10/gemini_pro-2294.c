//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Define the maximum depth of directory traversal
#define MAX_DEPTH 10

// Define the maximum size of a file path
#define MAX_PATH_SIZE 1024

// Define the structure to store directory information
typedef struct dir_info {
    char path[MAX_PATH_SIZE];
    int size;
    int depth;
} dir_info;

// Compare two directory information structures by size
int compare_dir_info(const void *a, const void *b) {
    const dir_info *a1 = (const dir_info *)a;
    const dir_info *b1 = (const dir_info *)b;
    return b1->size - a1->size;
}

// Recursively analyze the directory
void analyze_directory(const char *path, int depth) {
    if (depth >= MAX_DEPTH) {
        return;
    }

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the file or directory
        char fullpath[MAX_PATH_SIZE];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get the file or directory information
        struct stat statbuf;
        if (lstat(fullpath, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        // If it's a directory, recursively analyze it
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(fullpath, depth + 1);
        } else {
            // If it's a file, add it to the list of files
            dir_info info;
            strcpy(info.path, fullpath);
            info.size = statbuf.st_size;
            info.depth = depth;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze the directory
    analyze_directory(argv[1], 0);

    return EXIT_SUCCESS;
}