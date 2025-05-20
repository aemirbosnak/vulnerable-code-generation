//GEMINI-pro DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];

    // Open the directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Read the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char *file_path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
        if (file_path == NULL) {
            perror("malloc");
            closedir(dir);
            return EXIT_FAILURE;
        }
        sprintf(file_path, "%s/%s", directory, entry->d_name);

        // Get the file size
        struct stat file_stat;
        if (stat(file_path, &file_stat) == -1) {
            perror("stat");
            free(file_path);
            closedir(dir);
            return EXIT_FAILURE;
        }

        // Print the file information
        printf("%s: %ld bytes\n", file_path, file_stat.st_size);

        // Free the file path
        free(file_path);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}