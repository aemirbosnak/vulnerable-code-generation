//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME 256
#define MAX_SIGNATURES 10
#define SIGNATURE_LENGTH 50

// List of signatures to look for (e.g., simplified example patterns)
const char *signatures[MAX_SIGNATURES] = {
    "malware_signature_1",
    "malware_signature_2",
    "malware_signature_3",
    "malware_signature_4",
    "malware_signature_5",
    "malware_signature_6",
    "malware_signature_7",
    "malware_signature_8",
    "malware_signature_9",
    "malware_signature_10"
};

// Function prototypes
void scan_file(const char *file_path);
void scan_directory(const char *dir_path);
int check_signature(const char *buffer);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}

// Function to scan a file for signatures
void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    char buffer[1024];
    size_t bytes_read;

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (check_signature(buffer)) {
            printf("Malware signature detected in file: %s\n", file_path);
            fclose(file);
            return;
        }
    }

    fclose(file);
}

// Function to check for known signatures in the content
int check_signature(const char *buffer) {
    for (int i = 0; i < MAX_SIGNATURES; i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            return 1; // Signature found
        }
    }
    return 0; // No signature found
}

// Function to scan a directory for files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (!dp) {
        fprintf(stderr, "Error opening directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char file_path[MAX_FILENAME];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            struct stat file_stat;
            
            // Check if the path is a file
            if (stat(file_path, &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
                printf("Scanning file: %s\n", file_path);
                scan_file(file_path);
            } else if (S_ISDIR(file_stat.st_mode)) {
                // If it's a directory, recurse into it
                scan_directory(file_path);
            }
        }
    }

    closedir(dp);
}