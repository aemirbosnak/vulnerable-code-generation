//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Signature for a known virus (a simple example, in reality, this would be much more complex)
const char *knownVirusSignature = "malicious_code";

// Function to check if a file contains a known virus signature
int containsVirus(char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (memmem(buffer, bytesRead, knownVirusSignature, strlen(knownVirusSignature))) {
            fclose(file);
            return 1; // Virus found
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to traverse directories
void scanDirectory(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and the current/parent directories
        if (entry->d_name[0] == '.' || strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        
        // Check if entry is a directory or a file
        struct stat entryStat;
        if (stat(fullPath, &entryStat) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(entryStat.st_mode)) {
            // Recursively scan directories
            scanDirectory(fullPath);
        } else if (S_ISREG(entryStat.st_mode)) {
            // Scan files for viruses
            if (containsVirus(fullPath)) {
                printf("Virus detected in %s\n", fullPath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check for directory argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start scanning the specified directory
    printf("Scanning directory: %s\n", argv[1]);
    scanDirectory(argv[1]);
    
    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}