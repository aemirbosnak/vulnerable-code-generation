//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store virus signatures and their names
typedef struct {
    char *signature;
    char *name;
} VirusSignature;

// Array of known virus signatures
VirusSignature knownViruses[] = {
    { "E3 A5 49 00 00 00 00 00", "Zeus Virus" },
    { "55 8B EC 83 E4 F0 83 C4 04", "CryptoLocker Virus" },
    { "4D 5A 90 00 03 00 00 00", "WannaCry Virus" },
    { "7F 45 4C 46 01 01 01 00", "Petya Virus" },
    { "4D 5A 90 00 03 00 00 00", "NotPetya Virus" }
};

// Function to scan a file for viruses
int scanFile(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    char *buffer = malloc(fileSize);
    fread(buffer, 1, fileSize, file);
    fclose(file);

    // Scan the buffer for virus signatures
    for (int i = 0; i < sizeof(knownViruses) / sizeof(VirusSignature); i++) {
        char *signature = knownViruses[i].signature;
        int signatureLength = strlen(signature);
        for (int j = 0; j < fileSize - signatureLength; j++) {
            if (memcmp(&buffer[j], signature, signatureLength) == 0) {
                printf("Virus detected: %s\n", knownViruses[i].name);
                free(buffer);
                return 1;
            }
        }
    }

    // No viruses found
    printf("No viruses detected.\n");
    free(buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Scan the file for viruses
    int result = scanFile(argv[1]);

    if (result == 1) {
        printf("The file is infected with a virus. Please delete it immediately.\n");
    } else if (result == -1) {
        printf("Error scanning file. Please try again.\n");
    } else {
        printf("The file is clean.\n");
    }

    return 0;
}