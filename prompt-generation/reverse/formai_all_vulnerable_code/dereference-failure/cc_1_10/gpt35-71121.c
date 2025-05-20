//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576
#define VIRUS_SIGNATURE_SIZE 20
#define MAX_VIRUS_SIGNATURES 100

unsigned char virusSignature[MAX_VIRUS_SIGNATURES][VIRUS_SIGNATURE_SIZE];
int virusSignaturesCount = 0;

int scanFile(unsigned char *fileContents, unsigned int fileSize);
void addVirusSignature(unsigned char *virusSignature);
void printVirusFound(unsigned int position);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fileHandle = fopen(argv[1], "rb");
    if (!fileHandle) {
        printf("Error opening file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    fseek(fileHandle, 0, SEEK_END);
    unsigned int fileSize = ftell(fileHandle);
    fseek(fileHandle, 0, SEEK_SET);

    if (fileSize > MAX_FILE_SIZE) {
        printf("Error: file too large\n");
        return EXIT_FAILURE;
    }

    unsigned char *fileContents = malloc(fileSize);
    if (!fileContents) {
        printf("Error allocating memory for file contents\n");
        return EXIT_FAILURE;
    }

    fread(fileContents, sizeof(unsigned char), fileSize, fileHandle);
    fclose(fileHandle);

    int infected = scanFile(fileContents, fileSize);

    free(fileContents);
    
    if (infected) {
        printf("Virus found!\n");
        return EXIT_FAILURE;
    } else {
        printf("File is clean\n");
        return EXIT_SUCCESS;
    }
}

int scanFile(unsigned char *fileContents, unsigned int fileSize) {
    int infected = 0;

    for (unsigned int i = 0; i < fileSize - VIRUS_SIGNATURE_SIZE; i++) {
        for (int j = 0; j < virusSignaturesCount; j++) {
            if (memcmp(fileContents + i, virusSignature[j], VIRUS_SIGNATURE_SIZE) == 0) {
                printVirusFound(i);
                infected = 1;
            }
        }
    }

    return infected;
}

void addVirusSignature(unsigned char *virusSignature) {
    if (virusSignaturesCount >= MAX_VIRUS_SIGNATURES) {
        printf("Error: maximum number of virus signatures reached\n");
        return;
    }

    memcpy(virusSignature + virusSignaturesCount * VIRUS_SIGNATURE_SIZE, virusSignature, VIRUS_SIGNATURE_SIZE);
    virusSignaturesCount++;
}

void printVirusFound(unsigned int position) {
    printf("Virus found at position %d\n", position);
}