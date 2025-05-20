//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Structure to hold potential virus signatures
typedef struct {
    char *name;
    size_t length;
} VirusSignature;

// List of known virus signatures
VirusSignature known_signatures[] = {
    {"F00DBABE", 8},
    {"DEADBEEF", 8},
    {"BAADF00D", 8},
    {"CAFEBABE", 8}
};

// Function to check if a given file has a known virus signature
int hasVirus(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return 0;
    }

    unsigned char buffer[64];
    size_t bytesRead;

    // Read the first part of the file to search for signatures
    bytesRead = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    for (size_t i = 0; i < sizeof(known_signatures) / sizeof(VirusSignature); i++) {
        if (bytesRead >= known_signatures[i].length) {
            for (size_t j = 0; j <= bytesRead - known_signatures[i].length; j++) {
                // Compare the current slice of the buffer with the signature
                if (memcmp(buffer + j, known_signatures[i].name, known_signatures[i].length) == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to scan a directory for files
void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    struct stat fileStatus;
    DIR *directory = opendir(dirPath);

    if (directory == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[1024];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

            // Getting the file status
            if (stat(fullPath, &fileStatus) == -1) {
                perror("Failed to retrieve file status");
                continue;
            }

            // Check if it is a regular file
            if (S_ISREG(fileStatus.st_mode)) {
                printf("Scanning file: %s\n", fullPath);
                if (hasVirus(fullPath)) {
                    printf("ALERT: Virus detected in file: %s\n", fullPath);
                } else {
                    printf("File is clean: %s\n", fullPath);
                }
            }
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Welcome to the Curious C Antivirus Scanner!\n");
    printf("Scanning the directory: %s\n", argv[1]);
    
    scanDirectory(argv[1]);
    
    printf("Scanning completed. Stay safe!\n");
    return EXIT_SUCCESS;
}