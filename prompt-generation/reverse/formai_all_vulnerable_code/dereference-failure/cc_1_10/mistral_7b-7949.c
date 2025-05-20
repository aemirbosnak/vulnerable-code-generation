//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1024 * 1024
#define KEY 3

void encryptByte(unsigned char *input, unsigned char *output) {
    for (int i = 0; i < 256; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' + KEY) % 26) + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' + KEY) % 26) + 'a';
        } else {
            output[i] = input[i];
        }
    }
}

bool encryptFile(char *fileName) {
    FILE *inputFile, *outputFile;
    unsigned char inputBuffer[MAX_FILE_SIZE];
    unsigned char outputBuffer[MAX_FILE_SIZE];

    if ((inputFile = fopen(fileName, "rb")) == NULL) {
        perror("Error opening input file.\n");
        return false;
    }

    if ((outputFile = fopen(strcat(fileName, ".enc"), "wb")) == NULL) {
        perror("Error opening output file.\n");
        fclose(inputFile);
        return false;
    }

    while (fread(inputBuffer, sizeof(unsigned char), sizeof(inputBuffer), inputFile) > 0) {
        encryptByte(inputBuffer, outputBuffer);
        fwrite(outputBuffer, sizeof(unsigned char), sizeof(inputBuffer), outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (!encryptFile(argv[1])) {
        return 1;
    }

    return 0;
}