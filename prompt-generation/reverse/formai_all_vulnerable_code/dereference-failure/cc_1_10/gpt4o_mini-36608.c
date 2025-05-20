//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define MAX_SIGNATURES 10

// Define the structure for virus signatures
typedef struct {
    char name[50];
    char signature[100];
} VirusSignature;

// Initialize some common virus signatures
VirusSignature virusSignatures[MAX_SIGNATURES] = {
    {"EICAR", "X5O!P%%PGAP)4”5,7*" },
    {"GenericVirus", "B03C0D0A0E0F0703DA0A" },
    {"Malware01", "4D414C5741524501" }
};

// Function prototypes
void scanDirectory(const char* dirPath);
void scanFile(const char* filePath);
int checkForVirus(const char* fileContents, size_t fileSize);
void printVirusReport(const char* filePath, const char* virusName);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    scanDirectory(argv[1]);
    return 0;
}

// Function to scan a directory
void scanDirectory(const char* dirPath) {
    struct dirent* entry;
    DIR* dp = opendir(dirPath);
    char fullPath[MAX_PATH_LENGTH];

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(fullPath, MAX_PATH_LENGTH, "%s/%s", dirPath, entry->d_name);

            if (entry->d_type == DT_DIR) {
                // Recursively scan directories
                scanDirectory(fullPath);
            } else {
                // Scan the file
                scanFile(fullPath);
            }
        }
    }
    closedir(dp);
}

// Function to scan a file for viruses
void scanFile(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    char* fileContents;
    size_t fileSize;
    
    if (file == NULL) {
        perror("fopen");
        return;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for file contents
    fileContents = (char*)malloc(fileSize + 1);
    if (fileContents == NULL) {
        perror("malloc");
        fclose(file);
        return;
    }

    // Read the file contents
    fread(fileContents, 1, fileSize, file);
    fileContents[fileSize] = '\0'; // Null-terminate the string

    // Check for viruses
    int foundVirusIndex = checkForVirus(fileContents, fileSize);
    if (foundVirusIndex >= 0) {
        printVirusReport(filePath, virusSignatures[foundVirusIndex].name);
    }

    // Clean up
    free(fileContents);
    fclose(file);
}

// Function to check file contents against virus signatures
int checkForVirus(const char* fileContents, size_t fileSize) {
    for (int i = 0; i < MAX_SIGNATURES; i++) {
        if (strstr(fileContents, virusSignatures[i].signature) != NULL) {
            return i; // Virus found
        }
    }
    return -1; // No virus found
}

// Function to print report of found virus
void printVirusReport(const char* filePath, const char* virusName) {
    printf("Virus '%s' found in file: %s\n", virusName, filePath);
}