//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 260
#define BUFFER_SIZE 1024

// Structure to store virus signatures
typedef struct {
    char *name;
    char *signature;
} VirusSignature;

// Sample virus signatures database
VirusSignature virus_db[] = {
    {"EICAR_TEST", "X5O!P%@AP[S[gGO0x]}0"} // Example signature
};

// Function prototype
void scan_file(const char *file_path);
void scan_directory(const char *directory);
int check_signature(const char *file_content, const char *signature);

// Debugging macro
#define DEBUG_PRINT(x) printf("DEBUG: %s\n", (x))

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    DEBUG_PRINT("Starting the scanning process...");
    scan_directory(argv[1]);
    DEBUG_PRINT("Scanning process completed!");

    return 0;
}

// Function to scan files in a directory
void scan_directory(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;
    
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                scan_directory(path); // Recursive call for subdirectories
            }
        } else {
            DEBUG_PRINT("Scanning file...");
            scan_file(path);
        }
    }

    closedir(dir);
}

// Function to scan a specific file for viruses
void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < sizeof(virus_db) / sizeof(virus_db[0]); i++) {
            if (check_signature(buffer, virus_db[i].signature)) {
                printf("Virus detected! File: %s - Virus: %s\n", file_path, virus_db[i].name);
            }
        }
    }

    fclose(file);
}

// Function to check if the file content contains the virus signature
int check_signature(const char *file_content, const char *signature) {
    return strstr(file_content, signature) != NULL;
}