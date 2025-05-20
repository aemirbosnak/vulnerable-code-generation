//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 256
#define MAX_SIGNATURES 10
#define MAX_SIGNATURE_LENGTH 50

// Virus signatures to search for
const char *signatures[MAX_SIGNATURES] = {
    "virus123",
    "malware456",
    "trojan789",
    "worm001",
    "hacktool002"
};

// Function to check a file for virus signatures
int scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[256];

    if (file == NULL) {
        perror("Could not open file");
        return 0; // Could not open file
    }

    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(line, signatures[i]) != NULL) {
                printf("Virus signature found in file: %s -> %s\n", filename, signatures[i]);
                fclose(file);
                return 1; // Found a signature
            }
        }
    }

    fclose(file);
    return 0; // No signature found
}

// Function to scan a directory for files
void scan_directory(const char *dir_name) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // If it's a regular file
            char filepath[MAX_FILENAME_LENGTH];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_name, entry->d_name);
            printf("Scanning file: %s\n", filepath);
            scan_file(filepath);
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

    printf("Retro Antivirus Scanner\n");
    printf("========================\n");
    printf("Scanning directory: %s\n", argv[1]);
    
    scan_directory(argv[1]);
    
    printf("Scan complete!\n");
    return EXIT_SUCCESS;
}