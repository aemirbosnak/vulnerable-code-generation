//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Function to calculate disk usage recursively
long long calculateDiskUsage(char *path)
{
    long long totalSize = 0;

    // Open directory
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);

    // Handle errors
    if (!dir)
    {
        printf("Error: Could not open directory %s\n", path);
        return 0;
    }

    // Loop through directory
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
        {
            // Ignore . and .. directories
            continue;
        }

        // Construct full path
        char fullPath[1000];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        // Get file stats
        struct stat statbuf;
        if (stat(fullPath, &statbuf) == -1)
        {
            printf("Error: Could not get file stats for %s\n", fullPath);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode))
        {
            // Recursively calculate size of subdirectory
            long long subdirectorySize = calculateDiskUsage(fullPath);
            totalSize += subdirectorySize;
        }
        else
        {
            // Add file size to total
            totalSize += statbuf.st_size;
        }
    }

    // Close directory
    closedir(dir);

    return totalSize;
}

int main()
{
    printf("Welcome to Castle Disk Space Analyzer!\n");
    printf("Please enter the path for the directory you would like to scan:\n");

    // Read user input
    char path[1000];
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0'; // Remove trailing newline character

    // Calculate disk usage
    long long totalSize = calculateDiskUsage(path);

    printf("\nDisk usage for %s:\n", path);

    if (totalSize < 1024)
    {
        printf("%lld bytes\n", totalSize);
    }
    else if (totalSize < 1024 * 1024)
    {
        printf("%.2f KB\n", (float)totalSize / 1024);
    }
    else if (totalSize < 1024 * 1024 * 1024)
    {
        printf("%.2f MB\n", (float)totalSize / (1024 * 1024));
    }
    else
    {
        printf("%.2f GB\n", (float)totalSize / (1024 * 1024 * 1024));
    }

    return 0;
}