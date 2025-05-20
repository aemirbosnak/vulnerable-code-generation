//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <math.h>

#define SIGNATURE_COUNT 4
#define FILE_NAME_LENGTH 256
#define BUFFER_SIZE 1024

// Predefined virus signatures (representing checksums)
const unsigned long known_signatures[SIGNATURE_COUNT] = {
    0x5EB63B13, // Sample virus signature 1
    0xABCD1234, // Sample virus signature 2
    0xDEADBEEF, // Sample virus signature 3
    0xCAFEBABE  // Sample virus signature 4
};

// Function to calculate a simple checksum of a file
unsigned long calculate_checksum(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Could not open file");
        return 0;
    }

    unsigned long checksum = 0;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            checksum += (unsigned char)buffer[i];
        }
        checksum %= ULONG_MAX; // Prevent overflow
    }

    fclose(file);
    return checksum;
}

// Function to determine if a checksum matches a known virus signature
int is_virus(unsigned long checksum) {
    for (int i = 0; i < SIGNATURE_COUNT; i++) {
        if (checksum == known_signatures[i]) {
            return 1; // Virus detected
        }
    }
    return 0; // No virus
}

// Function to scan a directory for files and check their checksums
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[FILE_NAME_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Check if it is a regular file
        if (entry->d_type == DT_REG) {
            unsigned long checksum = calculate_checksum(full_path);
            printf("Checking file: %s, Checksum: %lu\n", full_path, checksum);

            if (is_virus(checksum)) {
                printf("ALERT: Virus detected in file: %s\n", full_path);
            } else {
                printf("File is clean: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    printf("Scanning directory: %s\n", directory_path);
    
    scan_directory(directory_path);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}