//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Helper function to get the size of a file
long get_file_size(const char *path) {
    struct stat stat_buf;
    if (stat(path, &stat_buf) == 0) {
        return stat_buf.st_size;
    }
    return -1;
}

// Recursive function to traverse a directory and calculate its total size
long get_dir_size(const char *path) {
    long total_size = 0;

    DIR *dir = opendir(path);
    if (dir) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char subpath[1024];
            snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);

            struct stat stat_buf;
            if (stat(subpath, &stat_buf) == 0) {
                if (S_ISDIR(stat_buf.st_mode)) {
                    total_size += get_dir_size(subpath);
                } else {
                    total_size += get_file_size(subpath);
                }
            }
        }
        closedir(dir);
    }

    return total_size;
}

int main() {
    // Get the user input for the path to analyze
    char path[1024];
    printf("Hello there! Let's analyze some disk space. Enter the path to your happy little directory: ");
    scanf("%s", path);

    // Calculate the total size of the directory
    long total_size = get_dir_size(path);

    // Print the results
    printf("Your directory '%s' has a total size of %ld bytes. That's a lot of bytes, isn't it? :)\n", path, total_size);

    return 0;
}