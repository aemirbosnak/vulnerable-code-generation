//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 512
#define MAX_SIG 256

// Simple signature structure for known viruses
typedef struct {
    char name[50];
    unsigned char signature[MAX_SIG];
} VirusSignature;

// Sample virus signatures (in real scenario these should be actual byte sequences)
VirusSignature virusSignatures[] = {
    {"EICAR-Test-File", {0x68, 0x65, 0x6c, 0x6c, 0x6f}}, // This is just a placeholder signature
    {"Generic-Virus-A", {0x90, 0x90, 0x90}}, // Replace with actual virus signatures
};

// Function prototypes
void scanFile(const char *filePath);
void scanDirectory(const char *directory);
int matchSignature(const unsigned char *buffer, size_t size);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting virus scan on directory: %s\n", argv[1]);
    scanDirectory(argv[1]);
    
    printf("Virus scan completed.\n");
    return EXIT_SUCCESS;
}

void scanDirectory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    char path[MAX_PATH];

    if (dp == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", directory);
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') 
            continue;

        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            // Recursively scan subdirectories
            scanDirectory(path);
        } else {
            // Scan file for viruses
            scanFile(path);
        }
    }
    
    closedir(dp);
}

void scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    unsigned char *buffer;
    size_t fileSize;

    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filePath);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Allocate memory for the file buffer
    buffer = (unsigned char *)malloc(fileSize);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed for file: %s\n", filePath);
        fclose(file);
        return;
    }

    // Read the entire file into the buffer
    fread(buffer, 1, fileSize, file);
    fclose(file);

    // Check for virus signatures
    if (matchSignature(buffer, fileSize)) {
        printf("Warning: Potential virus detected in file: %s\n", filePath);
    }

    free(buffer);
}

int matchSignature(const unsigned char *buffer, size_t size) {
    for (int i = 0; i < sizeof(virusSignatures) / sizeof(VirusSignature); i++) {
        VirusSignature *virus = &virusSignatures[i];
        size_t sigLength = sizeof(virus->signature) / sizeof(virus->signature[0]);
        
        if (size < sigLength) 
            continue;

        // Search for the virus signature in the buffer
        for (size_t j = 0; j <= size - sigLength; j++) {
            if (memcmp(&buffer[j], virus->signature, sigLength) == 0) {
                return 1; // Virus signature matched
            }
        }
    }
    return 0; // No virus found
}