//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 4096
#define BUFFER_SIZE 256

// Structure to hold virus definitions
typedef struct Virus {
    char name[BUFFER_SIZE];
    char signature[BUFFER_SIZE];
} Virus;

// List of known viruses
Virus viruses[] = {
    {"EICAR", "X5O!P%PG&.PCE.<...>"}, // Simplified placeholder signature
    {"MyVirus", "MYSIG123456789"},
    {"FakeAV", "FAKEAVSIG123"}
};

int numViruses = sizeof(viruses) / sizeof(viruses[0]);

// Function declarations
void scanFile(const char *filePath);
void scanDirectory(const char *directoryPath);
int containsVirus(const char *filePath);
void printVirusReport(const char *filePath, int virusIndex);

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start scanning the directory
    scanDirectory(argv[1]);
    return EXIT_SUCCESS;
}

// Function to scan a directory and its files
void scanDirectory(const char *directoryPath) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directoryPath)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);

            // Check if the entry is a directory
            if (entry->d_type == DT_DIR) {
                // Recursive call to scan subdirectory
                scanDirectory(fullPath);
            } else if (entry->d_type == DT_REG) {
                // Scan the file
                scanFile(fullPath);
            }
        }
    }

    closedir(dir);
}

// Function to scan a single file for known viruses
void scanFile(const char *filePath) {
    if (containsVirus(filePath)) {
        printf("Virus found in: %s\n", filePath);
    }
}

// Function to check if a file contains a known virus signature
int containsVirus(const char *filePath) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    file = fopen(filePath, "rb");
    if (file == NULL) {
        perror("Error reading file");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < numViruses; i++) {
            if (strstr(buffer, viruses[i].signature) != NULL) {
                fclose(file);
                printVirusReport(filePath, i);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to print a report about the detected virus
void printVirusReport(const char *filePath, int virusIndex) {
    printf("Detected %s in %s\n", viruses[virusIndex].name, filePath);
}