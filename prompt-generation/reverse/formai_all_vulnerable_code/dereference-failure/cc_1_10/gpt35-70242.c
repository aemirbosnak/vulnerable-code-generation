//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the total size of a directory
long int calculate_directory_size(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    long int total_size = 0;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: cannot open directory %s\n", path);
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Construct the full path to the file
        char file_path[1024];
        sprintf(file_path, "%s/%s", path, entry->d_name);

        // Get the file info
        stat(file_path, &file_info);
        if (S_ISDIR(file_info.st_mode)) {
            // Recursively calculate the size of subdirectories
            total_size += calculate_directory_size(file_path);
        } else {
            // Add the size of the file to the total size
            total_size += file_info.st_size;
        }
    }

    closedir(dir);
    return total_size;
}

int main() {
    char path[1024];
    printf("Enter the path to the directory: ");
    scanf("%s", path);

    long int total_size = calculate_directory_size(path);
    printf("Total size of files in %s: %ld bytes\n", path, total_size);

    return 0;
}