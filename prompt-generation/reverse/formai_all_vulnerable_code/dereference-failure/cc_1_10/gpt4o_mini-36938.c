//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIGNATURES 5
#define BUFFER_SIZE 1024

// Define virus signatures
const char *virus_signatures[MAX_SIGNATURES] = {
    "ELF-STUB", // Example signatures
    "MALICIOUS_CODE_1",
    "VIRUS_SIGNATURE_1",
    "DANGEROUS_PAYLOAD_1",
    "SCRIPT_KIDDIE_CODE"
};

// Function to check if a file contains a virus
int contains_virus(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read file in chunks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        // For each signature
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory and its files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[512];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            printf("Scanning: %s\n", file_path);
            if (contains_virus(file_path) == 1) {
                printf("!!! Virus detected in: %s !!!\n", file_path);
            } else {
                printf("No virus in: %s\n", file_path);
            }
        } else if (entry->d_type == DT_DIR) { // Directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir[512];
                snprintf(sub_dir, sizeof(sub_dir), "%s/%s", dir_path, entry->d_name);
                scan_directory(sub_dir);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_to_scan = argv[1];
    printf("Starting scan in directory: %s\n", dir_to_scan);
    
    // Start scanning the directory
    scan_directory(dir_to_scan);
    
    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}