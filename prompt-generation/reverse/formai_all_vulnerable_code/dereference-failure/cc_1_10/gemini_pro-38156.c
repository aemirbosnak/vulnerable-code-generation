//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Sherlock's File System Simulation

int main(int argc, char *argv[]) {

    // Initialize the file system
    char *rootDirectory = "/home/sherlock";
    DIR *root = opendir(rootDirectory);
    if (root == NULL) {
        perror("opendir");
        return -1;
    }

    // Investigate the root directory
    printf("Inspecting the root directory:\n");
    struct dirent *entry;
    while ((entry = readdir(root)) != NULL) {

        // Determine the file type
        struct stat fileStat;
        char *path = malloc(strlen(rootDirectory) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", rootDirectory, entry->d_name);
        if (stat(path, &fileStat) == -1) {
            perror("stat");
            free(path);
            continue;
        }

        // Display the file information
        printf("  - %s (%ld bytes)", entry->d_name, fileStat.st_size);
        if (S_ISDIR(fileStat.st_mode)) {
            printf(" [Directory]");
        } else if (S_ISREG(fileStat.st_mode)) {
            printf(" [File]");
        } else {
            printf(" [Unknown]");
        }
        printf("\n");

        free(path);
    }

    closedir(root);

    return 0;
}