//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define a simple virus signature array
char *virus_signatures[] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "THIS_IS_ANOTHER_VIRUS_SIGNATURE",
    NULL
};

// Function to check if a file contains a virus signature
int contains_virus_signature(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 0; // File could not be read
    }

    char buffer[128]; // Buffer for reading file
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; virus_signatures[i] != NULL; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus signature found
            }
        }
    }

    fclose(file);
    return 0; // No signature found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(dir_path);

    if (!dp) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        char full_path[1024];

        // Skip the current and parent directory
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            perror("Could not get file stats");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            // Recursively scan directories
            scan_directory(full_path);
        } else if (S_ISREG(file_stat.st_mode)) {
            // Check regular files for virus signatures
            if (contains_virus_signature(full_path)) {
                printf("Virus found in: %s\n", full_path);
            }
        }
    }

    closedir(dp);
}

// Main function to run the antivirus scanner
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}