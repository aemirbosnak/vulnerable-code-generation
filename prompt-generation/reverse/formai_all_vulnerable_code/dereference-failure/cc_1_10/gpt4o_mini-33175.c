//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define a virus signature to look for
#define VIRUS_SIGNATURE "malicious_code"

// Function to scan a file for a virus signature
int scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return 0;
    }

    char *line = NULL;
    size_t len = 0;
    int found = 0;

    while (getline(&line, &len, file) != -1) {
        if (strstr(line, VIRUS_SIGNATURE) != NULL) {
            found = 1;
            break;
        }
    }

    free(line);
    fclose(file);
    return found;
}

// Function to recursively scan a directory
void scan_directory(const char *path) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *dp = opendir(path);

    if (!dp) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Check if it's a directory or a file
        if (stat(full_path, &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                // It's a directory, scan it
                scan_directory(full_path);
            } else if (S_ISREG(fileStat.st_mode)) {
                // It's a regular file, scan it for viruses
                if (scan_file(full_path)) {
                    printf("Virus found in file: %s\n", full_path);
                }
            }
        }
    }

    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}