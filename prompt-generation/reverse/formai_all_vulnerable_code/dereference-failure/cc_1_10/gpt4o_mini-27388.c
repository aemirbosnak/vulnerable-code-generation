//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SUSPICIOUS_EXTENSIONS 5

const char *suspicious_extensions[SUSPICIOUS_EXTENSIONS] = {
    ".exe",
    ".scr",
    ".bat",
    ".js",
    ".vbs"
};

// Check if a file has a suspicious extension
int is_suspicious(const char *filename) {
    for (int i = 0; i < SUSPICIOUS_EXTENSIONS; i++) {
        if (strstr(filename, suspicious_extensions[i]) != NULL) {
            return 1; // Suspicious file found!
        }
    }
    return 0; // File is safe.
}

// Scan a directory for suspicious files
void scan_directory(const char *dir_path) {
    struct dirent *dir_entry;
    DIR *d = opendir(dir_path);
    
    if (d == NULL) {
        perror("Failed to open the directory");
        return;
    }

    while ((dir_entry = readdir(d)) != NULL) {
        char full_path[MAX_PATH];
        struct stat path_stat;

        // Skip the current and parent directory entries
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, dir_entry->d_name);
        if (stat(full_path, &path_stat) == -1) {
            perror("Error reading file info");
            continue;
        }

        if (S_ISDIR(path_stat.st_mode)) {
            // Recursively scan subdirectories
            printf("Scanning directory: %s\n", full_path);
            scan_directory(full_path);
        } else {
            // Check for suspicious files
            if (is_suspicious(full_path)) {
                printf("Suspicious file detected: %s\n", full_path);
            } else {
                printf("Safe file: %s\n", full_path);
            }
        }
    }
    closedir(d);
}

// Intake the scanning directory from the user
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("🎉 Welcome to the Enthusiastic C Antivirus Scanner! 🎉\n");
    printf("Scanning directory: %s\n", argv[1]);

    // Start scanning the specified directory
    scan_directory(argv[1]);

    printf("🚀 Scan completed! Stay safe and keep your files protected! 🚀\n");
    return EXIT_SUCCESS;
}