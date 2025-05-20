//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_SIGN_LENGTH 64
#define MAX_PATH_LENGTH 512

// Function to check for a virus signature in a file
int check_for_virus(const char *filename, const char *signature) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file");
        return 0; // File couldn't be opened
    }

    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), file)) {
        if (strstr(buffer, signature) != NULL) {
            fclose(file);
            return 1; // Virus signature found
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to scan directory for files
void scan_directory(const char *dir_name, const char *signature) {
    DIR *dir = opendir(dir_name);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open directory");
        return; // Directory could not be opened
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Create full path for file
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, entry->d_name);

        // Check if it's a directory or file
        if (entry->d_type == DT_DIR) {
            // Recursive call to scan the subdirectory
            scan_directory(full_path, signature);
        } else {
            // Scan the file for virus signature
            if (check_for_virus(full_path, signature)) {
                printf("Virus found in: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

// Main function to initiate the scan
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <directory> <virus_signature>\n", argv[0]);
        return EXIT_FAILURE; // Exit with error code
    }

    const char *target_directory = argv[1];
    const char *virus_signature = argv[2];

    printf("Scanning directory: %s for virus signature: %s\n", target_directory, virus_signature);
    scan_directory(target_directory, virus_signature);

    printf("Scan completed.\n");
    return EXIT_SUCCESS; // Exit without errors
}