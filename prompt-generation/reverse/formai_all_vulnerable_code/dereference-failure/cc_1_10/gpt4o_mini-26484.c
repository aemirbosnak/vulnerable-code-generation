//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_SIGNATURES 10
#define MAX_FILENAME 256
#define MAX_SIGNATURE_LENGTH 64

// Function to check if a file contains a known virus signature
int contains_signature(const char *filename, const char *signatures[], int sig_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < sig_count; i++) {
            if (strstr(buffer, signatures[i])) {
                fclose(file);
                return 1; // Signature found
            }
        }
    }
    
    fclose(file);
    return 0; // No signatures found
}

// Function to scan a directory for files
void scan_directory(const char *dir_name, const char *signatures[], int sig_count) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        char full_path[MAX_FILENAME];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, entry->d_name);
        
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            printf("Scanning file: %s\n", full_path);
            if (contains_signature(full_path, signatures, sig_count)) {
                printf("Warning: Virus signature found in %s!\n", full_path);
            } else {
                printf("No virus signatures found in %s.\n", full_path);
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Recur for directories
            printf("Entering directory: %s\n", full_path);
            scan_directory(full_path, signatures, sig_count);
        }
    }
    
    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    // Predefined virus signatures for testing
    const char *virus_signatures[MAX_SIGNATURES] = {
        "VIRUS123", 
        "BADFILE", 
        "MALWARE", 
        "INFECTED", 
        "DANGEROUS", 
        "SHADOW", 
        "TROJAN", 
        "WORM", 
        "RAT", 
        "BACKDOOR"
    };

    // Check if directory path is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_to_scan = argv[1];
    
    // Start scanning the directory
    printf("Starting scan in directory: %s\n", dir_to_scan);
    scan_directory(dir_to_scan, virus_signatures, MAX_SIGNATURES);
    
    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}