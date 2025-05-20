//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Define a structure to hold virus signature
typedef struct {
    char name[50];
    char signature[50];
} VirusSignature;

// Function to check if a file contains a virus
int isInfected(const char *filePath, const VirusSignature *signatures, int signatureCount) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("File opening failed");
        return 0;
    }

    char buffer[256];
    while (fread(buffer, sizeof(char), sizeof(buffer), file)) {
        for (int i = 0; i < signatureCount; i++) {
            if (strstr(buffer, signatures[i].signature) != NULL) {
                fclose(file);
                printf("Warning: File '%s' is infected with '%s'\n", filePath, signatures[i].name);
                return 1; // File is infected
            }
        }
    }
    
    fclose(file);
    return 0; // File is clean
}

// Function to scan a directory for files
void scanDirectory(const char *dirPath, const VirusSignature *signatures, int signatureCount) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Build the full path for each entry
        char fullPath[512];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        
        // Ignore special entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (entry->d_type == DT_DIR) {
                // If it's a directory, recursively scan it
                scanDirectory(fullPath, signatures, signatureCount);
            } else if (entry->d_type == DT_REG) {
                // If it's a regular file, check for infection
                isInfected(fullPath, signatures, signatureCount);
            }
        }
    }

    closedir(dir);
}

// Main function
int main() {
    // Define some sample virus signatures
    VirusSignature signatures[] = {
        {"Example Virus 1", "EICAR"},
        {"Example Virus 2", "VIRUS2!"},
        {"Example Virus 3", "INFECTED!"},
    };
    int signatureCount = sizeof(signatures) / sizeof(signatures[0]);

    printf("Starting Antivirus Scan...\n\n");
    
    // Scan the current directory
    scanDirectory(".", signatures, signatureCount);

    printf("\nAntivirus Scan Completed. Thank you for using our service!\n");
    return 0;
}