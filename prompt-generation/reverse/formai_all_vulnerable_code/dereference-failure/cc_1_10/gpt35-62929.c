//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scientific
/* 
 * C Antivirus Scanner
 * by [Your Name Here]
 *
 * This program scans a directory and its subdirectories for potentially harmful files
 * and notifies the user if any such files are found.
 *
 */

#include <stdio.h>    // for printf(), perror()
#include <stdlib.h>   // for EXIT_SUCCESS, EXIT_FAILURE, calloc()
#include <dirent.h>   // for opendir(), readdir(), closedir()
#include <sys/stat.h> // for stat(), S_ISREG()
#include <string.h>   // for strcmp()

// Define allowed file extensions
const char *ALLOWED_EXTENSIONS[] = {".txt", ".doc", ".pdf", ".jpg", ".png", ".exe"};

/**
 * Function to check if a file has an allowed extension
 * @return 1 if extension is allowed, otherwise 0
 */
int is_allowed_extension(char *filename) {
    for (int i = 0; i < sizeof(ALLOWED_EXTENSIONS) / sizeof(ALLOWED_EXTENSIONS[0]); i++) {
        if (strstr(filename, ALLOWED_EXTENSIONS[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

/**
 * Function to scan a directory and its subdirectories recursively for files with
 * potentially harmful extensions
 * @returns 1 if harmful file(s) found, otherwise 0
 */
int scan_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *dir_entry;
    struct stat file_stats;

    int harmful_files_found = 0;

    // Open directory
    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // Scan directory and its subdirectories recursively
    while ((dir_entry = readdir(dir)) != NULL) {
        char entry_path[512];
        sprintf(entry_path, "%s/%s", dir_path, dir_entry->d_name);

        // Get file stats
        if (stat(entry_path, &file_stats) == -1) {
            perror("Error getting file stats");
            exit(EXIT_FAILURE);
        }

        // Check if entry is a regular file and has an allowed extension
        if (S_ISREG(file_stats.st_mode) && is_allowed_extension(dir_entry->d_name)) {
            printf("Harmful file found: %s\n", dir_entry->d_name);
            harmful_files_found = 1;
        }

        // Recursively scan subdirectories
        if (S_ISDIR(file_stats.st_mode) && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            if (scan_directory(entry_path) == 1) {
                harmful_files_found = 1;
            }
        }
    }

    // Close directory
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        exit(EXIT_FAILURE);
    }

    return harmful_files_found;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Scan directory recursively
    if (scan_directory(argv[1])) {
        printf("Potentially harmful file(s) found.\n");
        return EXIT_FAILURE;
    } else {
        printf("Directory is free of potentially harmful files.\n");
        return EXIT_SUCCESS;
    }
}