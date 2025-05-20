//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>

int main() {
    struct dirent *entry;
    DIR *dir;
    struct stat statbuf;
    char path[PATH_MAX];
    size_t total_size = 0;
    size_t max_size = 0;
    char *max_path = NULL;

    // Open the current working directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the entry
        snprintf(path, sizeof(path), "%s/%s", ".", entry->d_name);

        // Get the file stat structure for the entry
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            return EXIT_FAILURE;
        }

        // Add the size of the entry to the total size
        total_size += statbuf.st_size;

        // Update the max size and max path if the entry is a file and is larger than the current max
        if (S_ISREG(statbuf.st_mode) && statbuf.st_size > max_size) {
            max_size = statbuf.st_size;
            max_path = strdup(path);
        }
    }

    // Close the directory
    closedir(dir);

    // Print the total size of the directory and the max size file
    printf("Total size of the directory: %zu bytes\n", total_size);
    printf("Max size file: %s (%zu bytes)\n", max_path, max_size);

    // Free the allocated memory
    free(max_path);

    return EXIT_SUCCESS;
}