//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1048576 // 1 MB
#define MAX_PATH_LENGTH 4096
#define HASH_SIZE 32

// Structure to hold the virus signature
typedef struct {
    char name[50];
    char hash[HASH_SIZE];
} VirusSignature;

// Sample virus signatures for demonstration purpose
VirusSignature virusSignatures[] = {
    {"EICAR", "275a0b9b344481c19382ab37c665e0218e70d4f1"}, // EICAR test file
    // Add more virus signatures here as needed
};

int numSignatures = sizeof(virusSignatures) / sizeof(VirusSignature);

// Function to compute the SHA-1 hash of a file
void computeSHA1(const char *filename, char *hashOutput) {
    char command[MAX_PATH_LENGTH + 50];
    snprintf(command, sizeof(command), "sha1sum %s | awk '{print $1}'", filename);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }
    if (fgets(hashOutput, HASH_SIZE, fp) == NULL) {
        perror("Failed to read hash output");
        pclose(fp);
        exit(EXIT_FAILURE);
    }
    hashOutput[strcspn(hashOutput, "\n")] = 0; // Remove newline character
    pclose(fp);
}

// Function to scan a file against known virus signatures
void scanFile(const char *filePath) {
    char computedHash[HASH_SIZE];
    struct stat buffer;

    if (stat(filePath, &buffer) != 0) {
        perror("Failed to get file status");
        return;
    }

    if (buffer.st_size > MAX_FILE_SIZE) {
        printf("File %s exceeds maximum size of %d bytes, skipping.\n", filePath, MAX_FILE_SIZE);
        return;
    }

    computeSHA1(filePath, computedHash);
    for (int i = 0; i < numSignatures; i++) {
        if (strcmp(computedHash, virusSignatures[i].hash) == 0) {
            printf("Virus detected! File: %s matches signature: %s\n", filePath, virusSignatures[i].name);
            return;
        }
    }
    printf("File %s is clean.\n", filePath);
}

// Recursive function to scan files in a directory
void scanDirectory(const char *directoryPath) {
    struct dirent *entry;
    DIR *dir = opendir(directoryPath);

    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char fullPath[MAX_PATH_LENGTH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);

        if (entry->d_type == DT_DIR) {
            scanDirectory(fullPath); // Recursive call for directories
        } else if (entry->d_type == DT_REG) {
            scanFile(fullPath); // Scan files
        }
    }

    closedir(dir);
}

// Main function to print usage and start the scanning process
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    printf("Starting virus scan in directory: %s\n", directoryPath);
    scanDirectory(directoryPath);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}