//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define SIGNATURES_COUNT 3

// List of malicious signatures (simple strings for demonstration)
const char *malicious_signatures[SIGNATURES_COUNT] = {
    "malware_signature_1",
    "virus_signature_2",
    "trojan_signature_3"
};

// Function to check for malicious content
int check_file_for_malware(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1; // Error opening file
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < SIGNATURES_COUNT; i++) {
            if (strstr(line, malicious_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Found a malicious signature
            }
        }
    }

    fclose(file);
    return 0; // No malicious signatures found
}

// Function to scan a directory for files
void scan_directory(const char *directory_path) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    if ((dir = opendir(directory_path)) == NULL) {
        perror("Could not open directory");
        return;
    }

    // Read entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full file path
        char full_path[MAX_FILENAME_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        if (entry->d_type == DT_REG) { // Check if it's a regular file
            printf("Scanning file: %s\n", full_path);
            int result = check_file_for_malware(full_path);
            if (result == 1) {
                printf("ALERT: Malware detected in file: %s\n", full_path);
            } else if (result == 0) {
                printf("Clean file: %s\n", full_path);
            }
        } else if (entry->d_type == DT_DIR) { // Recurse into directories
            printf("Entering directory: %s\n", full_path);
            scan_directory(full_path);
        }
    }

    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting the antivirus scan on directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed!\n");

    return EXIT_SUCCESS;
}