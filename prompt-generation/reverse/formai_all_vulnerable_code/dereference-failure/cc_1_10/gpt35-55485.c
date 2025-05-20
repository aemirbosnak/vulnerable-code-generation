//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char *path = "."; // Default path is current directory

    // Use argument to set path if provided
    if (argc > 1) {
        path = argv[1];
    }

    DIR *dir = opendir(path); // Open directory
    if (dir == NULL) { // Check if directory exists
        printf("Error: couldn't open directory %s\n", path);
        exit(1);
    }

    // Variables to keep track of disk space usage
    int total_size = 0;
    int dir_count = 0;
    int file_count = 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) { // Loop through directory entries
        struct stat st;

        char entry_path[256]; // Max path length is 255
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Get file/directory stats
        if (stat(entry_path, &st) == -1) {
            printf("Error: couldn't stat file %s\n", entry_path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) { // Check if entry is a directory
            dir_count++;
            // Recursively analyze subdirectory
            char sub_path[256];
            snprintf(sub_path, sizeof(sub_path), "%s/%s", path, entry->d_name);
            main(argc, sub_path);
        } else { // Entry is a file
            file_count++;
            total_size += st.st_size;
        }
    }

    closedir(dir); // Close directory when done

    // Print disk space usage report
    printf("Disk space usage for %s:\n", path);
    printf("%d directories and %d files\n", dir_count, file_count);
    printf("Total disk space used: %d bytes\n", total_size);

    return 0;
}