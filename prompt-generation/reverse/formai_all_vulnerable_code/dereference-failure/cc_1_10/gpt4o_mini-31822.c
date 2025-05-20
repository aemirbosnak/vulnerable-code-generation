//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIGNATURES 10
#define MAX_PATH 1024

// List of virus signatures
const char *virus_signatures[MAX_SIGNATURES] = {
    "malware_signature_01",
    "malware_signature_02",
    "malware_signature_03",
    "malware_signature_04",
    "malware_signature_05",
    "malware_signature_06",
    "malware_signature_07",
    "malware_signature_08",
    "malware_signature_09",
    "malware_signature_10"
};

// Function to scan a file for virus signatures
int scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1; // Error opening file
    }

    char buffer[1024];
    size_t bytes_read;
    int virus_found = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                printf("Virus signature found in file: %s, Signature: %s\n",
                       file_path, virus_signatures[i]);
                virus_found = 1; // Indicate a virus is found
            }
        }
    }

    fclose(file);
    return virus_found; // Return if any virus was found
}

// Function to scan a directory for files
void scan_directory(const char *directory_path) {
    struct dirent *entry;
    DIR *directory = opendir(directory_path);

    if (directory == NULL) {
        perror("Failed to open directory");
        return; // Exit if directory can't be opened
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);
            printf("Scanning file: %s\n", full_path);
            if (scan_file(full_path)) {
                printf("Infected file detected: %s\n", full_path);
            } else {
                printf("No infections found in: %s\n", full_path);
            }
        }
    }

    closedir(directory);
}

// Main function to execute the antivirus scanner
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE; // Exit if directory path is not provided
    }

    printf("Welcome to the Simple Antivirus Scanner!\n");
    printf("Scanning directory: %s\n", argv[1]);
    
    scan_directory(argv[1]);

    printf("Scanning complete. Thank you for using the scanner!\n");
    return EXIT_SUCCESS; // Successful completion
}