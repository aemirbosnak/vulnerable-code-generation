//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_NAME 256

void analyzeDirectory(const char *path, int depth);

void printIndent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
}

long getDirectorySize(const char *path) {
    struct stat info;
    long totalSize = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                long dirSize = getDirectorySize(fullPath);
                if (dirSize >= 0) {
                    totalSize += dirSize;
                }
            }
        } else if (entry->d_type == DT_REG) {
            if (stat(fullPath, &info) == 0) {
                totalSize += info.st_size;
            }
        }
    }
    closedir(dir);
    return totalSize;
}

void analyzeDirectory(const char *path, int depth) {
    long dirSize = getDirectorySize(path);
    if (dirSize >= 0) {
        printIndent(depth);
        printf("Directory: %s - Size: %ld bytes\n", path, dirSize);
    }

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                analyzeDirectory(fullPath, depth + 1);
            }
        }
    }
    closedir(dir);
}

void displayUsage(const char *programName) {
    printf("Usage: %s <directory>\n", programName);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage(argv[0]);
    }

    const char *startPath = argv[1];
    analyzeDirectory(startPath, 0);
    return 0;
}