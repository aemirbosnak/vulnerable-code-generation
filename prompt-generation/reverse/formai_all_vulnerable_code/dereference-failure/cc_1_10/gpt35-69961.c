//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

long long calculateSize(char* path);

int main(int argc, char* argv[]) {
    char* path = "."; // Default path is current directory.
    if (argc > 1) {
        path = argv[1]; // Custom path provided by user.
    }
    long long totalSize = calculateSize(path);

    // Print the result in human-readable format.
    char* unit;
    double size;
    if (totalSize >= (1LL << 50)) {
        unit = "TB";
        size = totalSize / (double)(1LL << 40);
    } else if (totalSize >= (1LL << 40)) {
        unit = "GB";
        size = totalSize / (double)(1LL << 30);
    } else if (totalSize >= (1LL << 30)) {
        unit = "MB";
        size = totalSize / (double)(1LL << 20);
    } else if (totalSize >= (1LL << 20)) {
        unit = "kB";
        size = totalSize / (double)(1LL << 10);
    } else {
        unit = "B";
        size = totalSize;
    }
    printf("Total size of %s: %.2f %s\n", path, size, unit);

    return 0;
}

long long calculateSize(char* path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        fprintf(stderr, "Failed to stat %s\n", path);
        exit(EXIT_FAILURE);
    }
    if (S_ISREG(st.st_mode)) { // Regular file.
        return st.st_size;
    } else if (S_ISDIR(st.st_mode)) { // Directory.
        DIR* dirp = opendir(path);
        if (dirp == NULL) {
            fprintf(stderr, "Failed to open directory %s\n", path);
            exit(EXIT_FAILURE);
        }

        long long totalSize = 0;
        struct dirent* entry;
        while ((entry = readdir(dirp)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char* childPath = (char*)malloc(strlen(path) + 1 + strlen(entry->d_name) + 1);
            strcpy(childPath, path);
            strcat(childPath, "/");
            strcat(childPath, entry->d_name);
            totalSize += calculateSize(childPath);
            free(childPath);
        }

        closedir(dirp);
        return totalSize;
    } else { // Not a file or directory.
        fprintf(stderr, "Invalid path: %s\n", path);
        exit(EXIT_FAILURE);
    }
}