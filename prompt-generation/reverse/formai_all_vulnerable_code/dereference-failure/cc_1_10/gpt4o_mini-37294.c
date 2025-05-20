//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_SIGNATURE_LENGTH 100

// Define a structure to hold virus signatures
typedef struct {
    char name[50];
    char signature[MAX_SIGNATURE_LENGTH];
} VirusSignature;

// Sample virus signatures
VirusSignature signatures[] = {
    {"EICAR Test Virus", "X5O!P%@AP[4\\PZX54(P^)7CC)"},
    {"Fake Virus", "F@KE_V1RUS_S1GN4TUR3"},
    {"Another Sample Virus", "S3MPLE_V1RUS_S1GN"}
};

int signature_count = sizeof(signatures) / sizeof(VirusSignature);

// Function to scan a single file
int scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return 0;
    }
    
    char buffer[1024];
    size_t bytesRead;

    // Check each signature against the file
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < signature_count; i++) {
            if (strstr(buffer, signatures[i].signature) != NULL) {
                fclose(file);
                printf("Virus detected in: %s - %s\n", filename, signatures[i].name);
                return 1; // Virus found
            }
        }
    }
    
    fclose(file);
    return 0; // No virus found
}

// Function to recursively scan directories
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory
        }

        char path[MAX_PATH_LENGTH];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively scan the directory
            scan_directory(path);
        } else if (entry->d_type == DT_REG) {
            // Scan the file
            scan_file(path);
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start scanning the specified directory
    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);

    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}