//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_VIRUSES 100
#define MAX_FILENAME_LENGTH 256

// Structure to hold virus information
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char signature[MAX_FILENAME_LENGTH];
} Virus;

// Define some imaginary viruses
Virus knownViruses[MAX_VIRUSES] = {
    {"Heartbreak", "H33R7BR34K"},
    {"SoulSucker", "S0UL5UCK3R"},
    {"LoveBug", "L0V3BUG007"},
    {"TearDrop", "T34RDR0P01"}
};

int virusCount = 4;

// Function to scan a file for viruses
int scanFile(const char *filename) {
    FILE *file;
    char buffer[MAX_FILENAME_LENGTH];

    // Open the file in read mode
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Darling, I couldn't reach your loving words in %s\n", filename);
        return 0;
    }

    // Read content and scan for virus signatures
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < virusCount; i++) {
            if (strstr(buffer, knownViruses[i].signature) != NULL) {
                printf("Oh no! My heart just shattered! I found a %s in %s\n", knownViruses[i].name, filename);
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    printf("Sweetheart, your love letters in %s are safe and pure.\n", filename);
    fclose(file);
    return 0; // No virus found
}

// Function to scan a directory for files
void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    DIR *dp = opendir(dirPath);

    if (dp == NULL) {
        fprintf(stderr, "Oh my love, the path %s seems lost... I cannot find it.\n", dirPath);
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_FILENAME_LENGTH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

            // Check if it's a directory or a file
            if (entry->d_type == DT_DIR) {
                printf("Venturing into the enchanted forest of %s...\n", fullPath);
                scanDirectory(fullPath); // Recurse into directories
            } else if (entry->d_type == DT_REG) {
                scanFile(fullPath); // Scan regular files
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    // Check for proper arguments
    if (argc != 2) {
        fprintf(stderr, "My beloved, use me gracefully like: %s <directory-to-scan>\n", argv[0]);
        return 1;
    }

    printf("My darling, I will protect your heart from all digital harm...\n");
    scanDirectory(argv[1]);

    printf("Forever yours, I remain vigilant in love.\n");
    return 0;
}