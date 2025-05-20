//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define VIRUS_SIGNATURE "VIRUS123"  // This is a fake virus signature for illustration
#define BUFFER_SIZE 1024              // Size for reading file chunks

// Function to scan a single file for the virus signature
int scan_file(const char *file_path) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file in chunks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (memmem(buffer, bytesRead, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) != NULL) {
            fclose(file);
            return 1;  // Virus found
        }
    }

    fclose(file);
    return 0;  // No virus found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // If entry is a directory, recursively scan it
        if (entry->d_type == DT_DIR) {
            printf("Scanning directory: %s\n", full_path);
            scan_directory(full_path);
        } else if (entry->d_type == DT_REG) {
            // Only scan regular files
            printf("Scanning file: %s\n", full_path);
            int result = scan_file(full_path);
            if (result == 1) {
                printf("Virus detected in file: %s\n", full_path);
            } else if (result == -1) {
                printf("Error scanning file: %s\n", full_path);
            } else {
                printf("No virus found in file: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    printf("Starting scan in directory: %s\n", directory);
    scan_directory(directory);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}