//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Define the maximum size for file paths and virus signatures
#define MAX_PATH_SIZE 1024
#define MAX_SIG_SIZE 128

// Virus signature list
const char *virus_signatures[] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!",
    // Add more virus signatures as needed
};
const int num_signatures = sizeof(virus_signatures) / sizeof(virus_signatures[0]);

// Function to check if a file contains a virus signature
int check_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        return -1; // Couldn't open file
    }

    char buffer[MAX_SIG_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < num_signatures; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory recursively
void scan_directory(const char *dirpath) {
    struct dirent *entry;
    struct stat statbuf;
    char filepath[MAX_PATH_SIZE];

    DIR *dir = opendir(dirpath);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
        if (stat(filepath, &statbuf) == -1) {
            perror("Unable to get file stats");
            continue;
        }

        // If it's a directory, recursively scan it
        if (S_ISDIR(statbuf.st_mode)) {
            scan_directory(filepath);
        } else {
            // Check for viruses in the file
            int result = check_file(filepath);
            if (result == 1) {
                printf("Virus found in: %s\n", filepath);
            } else if (result == -1) {
                printf("Error reading file: %s\n", filepath);
            }
        }
    }

    closedir(dir);
}

// Main function to run the scanner
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start scanning the provided directory
    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    
    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}