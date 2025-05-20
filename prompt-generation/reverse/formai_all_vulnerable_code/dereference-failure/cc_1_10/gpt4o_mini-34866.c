//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define MALICIOUS_STRING "malware"

// Function to check if a file contains a malicious string
int contains_malicious_content(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Failed to open file");
        return 0; // Consider unscanned files as safe
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, MALICIOUS_STRING)) {
            fclose(file);
            return 1; // Malicious content found
        }
    }

    fclose(file);
    return 0; // No malicious content
}

// Function to scan a specified directory
void scan_directory(const char *dir_path) {
    DIR *directory = opendir(dir_path);
    struct dirent *entry;

    if (!directory) {
        perror("Failed to open directory");
        return;
    }

    // Tranquil scanning begins
    printf("Gently scanning the directory: %s\n", dir_path);
    while ((entry = readdir(directory)) != NULL) {
        // Avoiding hidden files and current/parent directory entries
        if (entry->d_name[0] == '.' || entry->d_type != DT_REG) {
            continue;
        }

        char file_path[512];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
        printf("Analyzing file: %s\n", file_path);

        if (contains_malicious_content(file_path)) {
            printf("Alert: Malicious content detected in %s\n", file_path);
        } else {
            printf("Safe: %s is clear.\n", file_path);
        }
    }

    printf("Scanning completed in directory: %s\n", dir_path);
    closedir(directory);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}