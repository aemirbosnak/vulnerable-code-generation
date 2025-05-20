//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define HASH_SIZE 256

// Simple hash function to represent file content for comparison
unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_SIZE;
}

// List of known virus signatures (for demonstration purposes)
const char *virus_signatures[] = {
    "malicious_code_1",
    "malicious_code_2",
    "malicious_code_3",
    NULL
};

// Function to check if a file contains a known virus signature
int is_infected(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        return 0; // Unable to open file
    }

    unsigned char buffer[256];
    fread(buffer, sizeof(unsigned char), sizeof(buffer), file);
    fclose(file);

    unsigned long file_hash = hash(buffer);

    for (int i = 0; virus_signatures[i] != NULL; i++) {
        if (hash((unsigned char *)virus_signatures[i]) == file_hash) {
            return 1; // Infected
        }
    }
    return 0; // Not infected
}

// Function to scan a directory recursively for infected files
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_info;
    char full_path[MAX_PATH];
    DIR *directory = opendir(dir_path);

    if (directory == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_info) == -1) {
            perror("stat failed");
            continue;
        }

        if (S_ISDIR(file_info.st_mode)) {
            // Recursively scan subdirectory
            scan_directory(full_path);
        } else if (S_ISREG(file_info.st_mode)) {
            // Check if file is infected
            if (is_infected(full_path)) {
                printf("Infected file detected: %s\n", full_path);
            }
        }
    }

    closedir(directory);
}

// Main function to start the scanner
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);

    return 0;
}