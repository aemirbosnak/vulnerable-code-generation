//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryData {
    unsigned char *data;
    size_t length;
} BinaryData;

void binaryToHex(unsigned char *binaryData, size_t length, char *hexData) {
    for (size_t i = 0; i < length; i++) {
        sprintf(hexData, "%s%02x", hexData, binaryData[i]);
        hexData += 3;
    }
    hexData[length * 2 + 1] = '\0';
}

void binaryToASCII(unsigned char *binaryData, size_t length, char *asciiData) {
    for (size_t i = 0; i < length; i++) {
        sprintf(asciiData, "%c", binaryData[i]);
        asciiData++;
    }
    asciiData[length] = '\0';
}

BinaryData readBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *binaryData = (unsigned char *)malloc(fileSize);
    if (!binaryData) {
        perror("Error allocating memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(binaryData, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(binaryData);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);

    BinaryData result = {binaryData, fileSize};
    return result;
}

void printHex(const char *hexData) {
    printf("Hex: ");
    puts(hexData);
}

void printASCII(const char *asciiData) {
    printf("ASCII: ");
    puts(asciiData);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    BinaryData binaryData = readBinaryFile(argv[1]);

    char hexData[2 * binaryData.length + 1];
    char asciiData[binaryData.length + 1];

    binaryToHex(binaryData.data, binaryData.length, hexData);
    binaryToASCII(binaryData.data, binaryData.length, asciiData);

    printHex(hexData);
    printASCII(asciiData);

    free(binaryData.data);

    return EXIT_SUCCESS;
}