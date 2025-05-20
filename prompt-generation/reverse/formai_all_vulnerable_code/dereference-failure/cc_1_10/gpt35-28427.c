//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to calculate the disk space used by a directory
long long int calculateDirSize(char* path) {
    long long int size = 0;
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;

    // Open the directory
    dir = opendir(path);

    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", path);
        return -1;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        char entryPath[4096];

        // Get the full path of the entry
        snprintf(entryPath, sizeof(entryPath), "%s/%s", path, entry->d_name);

        // Get the file statistics
        if (lstat(entryPath, &filestat) < 0) {
            fprintf(stderr, "Error getting file stats: %s\n", entryPath);
            continue;
        }

        // Add up the size if the entry is a file
        if (S_ISREG(filestat.st_mode)) {
            size += filestat.st_size;
        }

        // Recursively call the function if the entry is a directory
        else if (S_ISDIR(filestat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            size += calculateDirSize(entryPath);
        }
    }

    // Close the directory
    closedir(dir);

    return size;
}

// Main function
int main(int argc, char* argv[]) {
    char* path;

    // Check if the user provided a path as an argument
    if (argc == 1) {
        path = ".";
    } else if (argc == 2) {
        path = argv[1];
    } else {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        return -1;
    }

    // Calculate the disk space used by the directory
    long long int size = calculateDirSize(path);

    if (size < 0) {
        fprintf(stderr, "Error calculating directory size: %s\n", path);
        return -1;
    }

    // Display the size
    if (size < 1024) {
        printf("Size: %lli bytes\n", size);
    } else if (size < 1024*1024) {
        printf("Size: %lli KB\n", size/1024);
    } else if (size < 1024*1024*1024) {
        printf("Size: %lli MB\n", size/1024/1024);
    } else {
        printf("Size: %lli GB\n", size/1024/1024/1024);
    }

    return 0;
}