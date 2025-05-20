//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_SIGNATURES 10
#define MAX_FILENAME_LENGTH 256
#define MAX_DIR_LENGTH 512
#define SIGNATURE_LENGTH 16

// Virus signatures array
const unsigned char virus_signatures[MAX_SIGNATURES][SIGNATURE_LENGTH] = {
    {0x90, 0x90, 0x90, 0x90}, // Signature for virus A
    {0xEB, 0xFE}, // Signature for virus B
    {0x68, 0x65, 0x6C, 0x6C}, // Signature for virus C
    {0x6F, 0x72, 0x6C}, // Signature for virus D
    {0xCC}, // Signature for virus E
    {0xF0, 0x0F, 0xB6}, // Signature for virus F
    {0xBA, 0xAD, 0xF0, 0x0D}, // Signature for virus G
    {0x8B, 0xEC}, // Signature for virus H
    {0xC3}, // Signature for virus I
    {0x53, 0x57}  // Signature for virus J
};

// Function to check if a file contains a virus signature
int contains_virus_signature(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    unsigned char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (memmem(buffer, bytesRead, virus_signatures[i], SIGNATURE_LENGTH) != NULL) {
                fclose(file);
                return 1; // Virus signature found
            }
        }
    }

    fclose(file);
    return 0; // No signature found
}

// Function to scan a directory for files
void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char filepath[MAX_DIR_LENGTH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            printf("Scanning %s...\n", filepath);

            if (contains_virus_signature(filepath)) {
                printf("WARNING: Virus signature found in %s!\n", filepath);
            } else {
                printf("No virus found in %s\n", filepath);
            }
        }
        // Add more conditions here for subdirectories (DT_DIR) if needed
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting the antivirus scan on directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}