//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

int showDirStats(char *path);

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LEN];
    if (argc < 2) {
        printf("Enter directory path: ");
        fgets(path, MAX_PATH_LEN, stdin);
        path[strcspn(path, "\n")] = 0; // remove newline character
    } else {
        strcpy(path, argv[1]);
    }

    printf("--- Disk space analyzer for %s ---\n", path);
    printf("Directory/File | Size in Bytes\n");
    printf("--------------------------------\n");
    showDirStats(path);

    return 0;
}

int showDirStats(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error: Unable to open directory %s\n", path);
        return -1;
    }

    struct dirent *dirEntry;
    struct stat dirStats;
    long long totalSize = 0;
    int numFiles = 0;

    // Read each entry in the directory
    while ((dirEntry = readdir(dir)) != NULL) {
        // Construct the full path of the entry
        char fullPath[MAX_PATH_LEN];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dirEntry->d_name);

        // Get the stats of the entry
        if (lstat(fullPath, &dirStats) == -1) {
            fprintf(stderr, "Error: Unable to get stats for %s\n", fullPath);
            continue;
        }

        if (S_ISDIR(dirStats.st_mode)) {
            // Recursively analyze subdirectories
            if (strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0) {
                showDirStats(fullPath);
            }
            continue;
        } else if (S_ISREG(dirStats.st_mode)) {
            totalSize += dirStats.st_size;
            printf("%s/%s | %lld\n", path, dirEntry->d_name, dirStats.st_size);
            numFiles++;
        } else {
            printf("%s/%s | Unknown filetype\n", path, dirEntry->d_name);
        }
    }

    closedir(dir);

    if (numFiles > 0) {
        printf("--- Summary for %s ---\n", path);
        printf("Total size of %d files: %lld bytes\n", numFiles, totalSize);
        printf("--------------------------------\n");
    }

    return 0;
}