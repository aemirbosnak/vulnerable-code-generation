//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define CHECKSUM_LENGTH 16

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    unsigned char checksum[CHECKSUM_LENGTH];
} FileChecksum;

static void calculateChecksum(const char* fileName, unsigned char* checksum) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", fileName);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char buffer[4096];
    size_t readBytes;
    while ((readBytes = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < readBytes; i++) {
            checksum[i % CHECKSUM_LENGTH] ^= buffer[i];
        }
    }

    fclose(file);
}

static void printChecksum(const unsigned char* checksum) {
    for (int i = 0; i < CHECKSUM_LENGTH; i++) {
        printf("%02X", checksum[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FileChecksum fileChecksum;
    strcpy(fileChecksum.fileName, argv[1]);

    unsigned char checksum[CHECKSUM_LENGTH];
    calculateChecksum(argv[1], checksum);

    printChecksum(checksum);

    return 0;
}