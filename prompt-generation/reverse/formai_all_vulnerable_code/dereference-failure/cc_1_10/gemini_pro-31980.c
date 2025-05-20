//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold virus signature and name
typedef struct VirusSignature {
    char *name;
    char *signature;
} VirusSignature;

// Array of known virus signatures
VirusSignature knownViruses[] = {
    {"Heartbreaker", "I_LOVE_YOU"},
    {"ILOVEYOU", "LOVE-LETTER-FOR-YOU"},
    {"Code Red", "Hacked By Chinese!"},
    {"Nimda", "NIMDA"},
    {"Conficker", "DOWNAD/Conficker"}
};

// Function to scan a file for viruses
int scanFile(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    char *buffer = malloc(fileSize);
    fread(buffer, fileSize, 1, file);
    fclose(file);

    // Scan the buffer for viruses
    for (int i = 0; i < sizeof(knownViruses) / sizeof(VirusSignature); i++) {
        if (strstr(buffer, knownViruses[i].signature) != NULL) {
            printf("File %s is infected with virus %s\n", filename, knownViruses[i].name);
            return 1;
        }
    }

    // No viruses found
    printf("File %s is clean\n", filename);
    free(buffer);
    return 0;
}

// Main function
int main() {
    // Get the filename from the user
    char filename[256];
    printf("Enter the filename to scan: ");
    scanf("%s", filename);

    // Scan the file
    int result = scanFile(filename);

    // Print the results
    if (result == 1) {
        printf("The file is infected. Please delete it immediately.\n");
    } else if (result == -1) {
        printf("Error scanning the file.\n");
    } else {
        printf("The file is clean.\n");
    }

    return 0;
}