//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if a file is a potential malware by its extension
int is_malware(const char *filename) {
    const char *malicious_extensions[] = {".exe", ".bat", ".cmd", ".js", ".vbs", ".scr", ".pif", ".com", NULL};
    
    for (int i = 0; malicious_extensions[i] != NULL; i++) {
        if (strstr(filename, malicious_extensions[i]) != NULL) {
            return 1; // Detected potential malware
        }
    }
    return 0; // Safe file
}

// Function to scan a directory recursively
void scan_directory(const char *dir_path) {
    DIR *d;
    struct dirent *entry;
    struct stat file_stat;

    d = opendir(dir_path);
    if (!d) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(d)) != NULL) {
        // Ignore . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Get file status
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                // It's a directory, recurse into it
                printf("Scanning directory: %s\n", full_path);
                scan_directory(full_path);
            } else if (S_ISREG(file_stat.st_mode)) {
                // It's a regular file, check for malware
                if (is_malware(entry->d_name)) {
                    printf("WARNING: Potential malware detected: %s\n", full_path);
                } else {
                    printf("Safe: %s\n", full_path);
                }
            }
        } else {
            perror("Could not get file status");
        }
    }

    closedir(d);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting antivirus scan on: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}