//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 512
#define MAX_SIGNATURES 5

// Array of known virus signatures (for demonstration purposes)
const char* virus_signatures[MAX_SIGNATURES] = {
    "VIRUS1_SIGNATURE",
    "VIRUS2_SIGNATURE",
    "MALWARE_SIGNATURE",
    "TROJAN_SIGNATURE",
    "WORM_SIGNATURE"
};

// Function to check if a file contains any known virus signatures
int contains_virus_signature(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }
    
    char buffer[256];
    
    // Read the file in chunks
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus signature found
            }
        }
    }
    
    fclose(file);
    return 0; // No virus signatures found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    
    if (!dp) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the current (.) and parent (..) directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path for the file or directory
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Check if the entry is a directory
        struct stat path_stat;
        stat(full_path, &path_stat);
        if (S_ISDIR(path_stat.st_mode)) {
            // Recursively scan the sub-directory
            scan_directory(full_path);
        } else {
            // If it's a file, check for viruses
            printf("Scanning file: %s\n", full_path);
            if (contains_virus_signature(full_path)) {
                printf("Virus detected in file: %s\n", full_path);
            } else {
                printf("No virus found in file: %s\n", full_path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    printf("Starting scan in directory: %s\n", directory_to_scan);
    scan_directory(directory_to_scan);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}