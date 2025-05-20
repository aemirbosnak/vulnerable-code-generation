//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void createFilesAndDirectories(const char *basePath, int depth) {
    // Base case for recursion
    if (depth < 0) {
        return;
    }

    char dirPath[256];
    snprintf(dirPath, sizeof(dirPath), "%s/dir%d", basePath, depth);
    mkdir(dirPath, 0755); // Create a new directory with permissions

    // Create a file in the current directory
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/file%d.txt", dirPath, depth);
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }
    fprintf(file, "This is file %d in directory dir%d\n", depth, depth);
    fclose(file);

    // Recursive call to create subdirectories and files
    createFilesAndDirectories(dirPath, depth - 1);
}

void listFilesRecursively(const char *basePath) {
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    
    // Check if the directory can be opened
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            // Print the name of the file or directory
            printf("%s/%s\n", basePath, dp->d_name);

            // Create new path for recursion
            char newPath[512];
            snprintf(newPath, sizeof(newPath), "%s/%s", basePath, dp->d_name);

            // If it is a directory, recurse into it
            if (dp->d_type == DT_DIR) {
                listFilesRecursively(newPath);
            }
        }
    }

    closedir(dir);
}

int main() {
    const char *basePath = "testdir";

    // Create main directory
    mkdir(basePath, 0755);

    // Create nested directories and files
    createFilesAndDirectories(basePath, 3);
    
    // List the files and directories recursively
    printf("Listing files and directories:\n");
    listFilesRecursively(basePath);

    // Cleanup (optional): Uncomment to remove created directories and files
    // system("rm -rf testdir");

    return 0;
}