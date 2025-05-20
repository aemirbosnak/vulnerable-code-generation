//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void analyzeDirectory(const char *path, long long *totalSize) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    struct stat fileStat;

    while ((entry = readdir(directory)) != NULL) {
        // Skip the special directories '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Formulate the full path
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (stat(fullPath, &fileStat) == -1) {
            perror("Unable to retrieve file info");
            continue;
        }

        // If it's a directory, recursively analyze it
        if (S_ISDIR(fileStat.st_mode)) {
            analyzeDirectory(fullPath, totalSize);
        } else {
            // If it's a file, add its size to the total size
            *totalSize += fileStat.st_size;
        }
    }

    closedir(directory);
}

void printDiskUsage(const char *path) {
    long long totalSize = 0;
    printf("Gently analyzing disk usage for directory: %s\n", path);
    analyzeDirectory(path, &totalSize);
    printf("Total disk space used by '%s': %lld bytes\n", path, totalSize);
    printf("Peacefully completed the analysis.\n");
}

void displayInstructions() {
    printf("Welcome to the Disk Space Analyzer!\n");
    printf("This simple program will help you analyze the disk usage of directories in a calm and serene way.\n");
    printf("To use this program, simply provide the directory path as a command line argument.\n");
    printf("Enjoy your experience!\n");
}

int main(int argc, char *argv[]) {
    // Display instructions
    displayInstructions();
    
    // Ensure the user has provided an argument
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start the disk usage analysis
    printDiskUsage(argv[1]);

    return EXIT_SUCCESS;
}