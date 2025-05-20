//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to get directory size
int getDirSize(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;

    int size = 0;

    // Open directory
    dir = opendir(path);

    if (dir == NULL) {
        perror ("Error: Cannot open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Avoid infinite loop
        if (strcmp(entry->d_name,".") == 0 || 
            strcmp(entry->d_name,"..") == 0)
            continue;

        // Get file path
        char filePath[256];
        snprintf(filePath, 256, "%s/%s", path, entry->d_name);

        // Get file status
        if (stat(filePath, &filestat) < 0) {
            perror ("Error: Cannot get file status");
            continue;
        }

        if (S_ISDIR(filestat.st_mode))
            // Recursive call for subdirectories
            size += getDirSize(filePath);

        else
            // Add file size to total size
            size += filestat.st_size;
    }

    // Close directory
    closedir(dir);

    return size;
}

int main(int argc, char *argv[]) {
    char path[256];

    // Accept path argument
    if (argc == 2)
        strncpy(path, argv[1], 256);
    else {
        printf("Enter path: ");
        scanf("%s", path);
    }

    // Get directory size
    int size = getDirSize(path);

    // Convert to human-readable format
    char sizeStr[20];

    if (size < 1024)
        snprintf(sizeStr, 20, "%dB", size);
    else if (size < 1048576)
        snprintf(sizeStr, 20, "%.2fKB", (float) size / 1024);
    else if (size < 1073741824)
        snprintf(sizeStr, 20, "%.2fMB", (float) size / 1048576);
    else
        snprintf(sizeStr, 20, "%.2fGB", (float) size / 1073741824);

    // Output result
    printf("Directory size: %s\n", sizeStr);

    return 0;
}