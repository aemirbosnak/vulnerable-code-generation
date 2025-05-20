//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1MB

void scanFile(char* fileName);
int checkVirus(char* buffer, int size);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./antivirus <filename>\n");
        return 1;
    }
    scanFile(argv[1]);
    return 0;
}

void scanFile(char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", fileName);
        return;
    }
    printf("Scanning file: %s\n", fileName);

    // Get file size
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate buffer for file
    char* buffer = (char*) malloc(sizeof(char) * fileSize);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        return;
    }

    // Read file contents into buffer
    fread(buffer, sizeof(char), fileSize, file);

    // Close file
    fclose(file);

    if (checkVirus(buffer, fileSize)) {
        printf("WARNING: Virus detected!\n");
    } else {
        printf("No viruses detected.\n");
    }

    // Free memory
    free(buffer);
}

int checkVirus(char* buffer, int size) {
    char* virusSignature = "BAD_CODE";
    int virusSize = strlen(virusSignature);
    for (int i = 0; i < size - virusSize; i++) {
        // Check for virus signature
        if (memcmp(buffer + i, virusSignature, virusSize) == 0) {
            return 1; // Virus detected
        }
    }
    return 0; // No virus detected
}