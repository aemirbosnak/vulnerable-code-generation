//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define SIGNATURE_COUNT 3

// Struct to hold virus signature information
typedef struct {
    char *name;
    char *signature;
} VirusSignature;

// List of virus signatures
VirusSignature signatures[SIGNATURE_COUNT] = {
    {"EICAR", "X5O!P%%%$#"} , // Example signature
    {"FakeVir", "ABC12345EZ"}, 
    {"Malware", "XYZ7890!@#"}
};

// Function to scan a file for virus signatures
void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", file_path);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int foundVirus = 0;

    // Read the file in chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (memmem(buffer, bytesRead, signatures[i].signature, strlen(signatures[i].signature)) != NULL) {
                printf("Virus found: %s in file: %s\n", signatures[i].name, file_path);
                foundVirus = 1;
                break;
            }
        }
        if (foundVirus) {
            break;
        }
    }

    if (!foundVirus) {
        printf("No virus found in file: %s\n", file_path);
    }

    fclose(file);
}

// Function to scan a directory
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (dir == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[512];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

            if (entry->d_type == DT_DIR) {
                // Recur for directories
                scan_directory(full_path);
            } else {
                // Scan the file
                scan_file(full_path);
            }
        }
    }

    closedir(dir);
}

// Main function to initiate scanning
int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <directory-to-scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Gratefully initiating virus scan on directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Gratefully finished scanning directory: %s\n", argv[1]);

    return EXIT_SUCCESS;
}