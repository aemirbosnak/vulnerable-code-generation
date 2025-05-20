//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

void printUsage(const char *path, struct stat *statbuf) {
    printf("Analyzing %s...\n", path);
    printf("Total Size: %.2f MB\n", statbuf->st_size / (1024.0 * 1024.0));
    printf("Permissions: %o\n", statbuf->st_mode & 0777);
    printf("-----------------------------------------------------\n");
}

void analyzeDirectory(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    struct stat statbuf;

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char fullPath[PATH_MAX];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        if (stat(fullPath, &statbuf) == -1) {
            perror("Error getting file status");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // It's a directory, we will analyze further
            printUsage(fullPath, &statbuf);
            analyzeDirectory(fullPath);
        } else {
            // It's a file, let’s print its information
            printUsage(fullPath, &statbuf);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a directory path to analyze.\n");
        return EXIT_FAILURE;
    }

    printf("Welcome to the Disk Space Analyzer!\n");
    printf("Let's get started with your journey to understand your disk usage and be grateful for the space you have!\n");
    printf("-----------------------------------------------------\n");

    analyzeDirectory(argv[1]);

    printf("Thank you for using the Disk Space Analyzer!\n");
    printf("Remember to cherish every byte of your space!\n");
    return EXIT_SUCCESS;
}