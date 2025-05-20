//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void analyzeFolder(char *folderPath, int depth, int *totalSize)
{
    DIR *folder;
    struct dirent *entry;
    struct stat fileStat;
    char filePath[256];

    // Open the folder
    folder = opendir(folderPath);
    if (folder == NULL) {
        perror("Unable to read directory");
        return;
    }

    // Print folder path and depth
    for (int i=0; i<depth; i++) {
        printf("  ");
    }
    printf("[%s]\n", folderPath);

    // Loop through the folder entries
    while ((entry = readdir(folder)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build the file path
        snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, entry->d_name);

        // Get the file stats
        if (stat(filePath, &fileStat) < 0) {
            perror("Unable to get file stats");
            return;
        }

        // Print file name and size
        for (int i=0; i<depth+1; i++) {
            printf("  ");
        }
        printf("%s (%ld bytes)\n", entry->d_name, fileStat.st_size);

        // Add file size to total size
        *totalSize += fileStat.st_size;

        // Recursively analyze subfolders
        if (S_ISDIR(fileStat.st_mode)) {
            analyzeFolder(filePath, depth+1, totalSize);
        }
    }

    // Close the folder
    closedir(folder);
}

int main(int argc, char *argv[])
{
    char *folderPath;
    int totalSize = 0;

    // Get folder path from command line argument
    if (argc == 2) {
        folderPath = argv[1];
    } else {
        fprintf(stderr, "Usage: %s folder\n", argv[0]);
        return -1;
    }

    // Analyze the folder
    analyzeFolder(folderPath, 0, &totalSize);

    // Print total size
    printf("Total size: %d bytes\n", totalSize);

    return 0;
}