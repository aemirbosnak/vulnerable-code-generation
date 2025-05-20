//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void analyzeDirectory(const char *path, long long *totalSize, int level);
void printIndent(int level);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long totalSize = 0;
    analyzeDirectory(argv[1], &totalSize, 0);
    
    printf("Total size: %lld bytes\n", totalSize);
    return EXIT_SUCCESS;
}

void analyzeDirectory(const char *path, long long *totalSize, int level) {
    struct dirent *entry;
    struct stat fileStat;
    char fullPath[PATH_MAX];

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current and parent directory entries
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        if (stat(fullPath, &fileStat) < 0) {
            perror("stat failed");
            continue;
        }

        // Print file details
        printIndent(level);
        printf("Found: %s, Size: %lld bytes\n", fullPath, (long long)fileStat.st_size);
        *totalSize += fileStat.st_size; // Accumulate size

        if (S_ISDIR(fileStat.st_mode)) {
            // Recursive call for directories
            analyzeDirectory(fullPath, totalSize, level + 1);
        }
    }

    closedir(dir);
}

void printIndent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  "); // Indentation for directory levels
    }
}