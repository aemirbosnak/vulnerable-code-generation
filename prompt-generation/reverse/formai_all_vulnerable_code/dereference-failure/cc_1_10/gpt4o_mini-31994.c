//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 256
#define SIGNATURE_COUNT 3

// List of known virus signatures (for demonstration purposes)
const char *known_signatures[SIGNATURE_COUNT] = {
    "VirusSignature1",
    "MalwareSignature2",
    "TrojanSignature3"
};

// Function to check if a file contains a known virus
bool contains_virus(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Could not open file");
        return false;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(line, known_signatures[i]) != NULL) {
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (!dp) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path
        char file_path[MAX_PATH_LENGTH];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        // Check if it's a file or a directory
        struct stat file_info;
        if (stat(file_path, &file_info) == 0) {
            if (S_ISDIR(file_info.st_mode)) {
                // Recursively scan the directory
                scan_directory(file_path);
            } else if (S_ISREG(file_info.st_mode)) {
                // Check for viruses in the file
                if (contains_virus(file_path)) {
                    printf("Virus detected in file: %s\n", file_path);
                }
            }
        } else {
            perror("Could not retrieve file info");
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start scanning the specified directory
    printf("Starting virus scan in directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Virus scan completed.\n");

    return EXIT_SUCCESS;
}