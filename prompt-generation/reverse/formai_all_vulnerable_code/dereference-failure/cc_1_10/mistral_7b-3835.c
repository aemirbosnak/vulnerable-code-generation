//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define SEED_SIZE 10
#define BLOCK_SIZE 16
#define ALPHABET_SIZE 26
#define KEY_SIZE (SEED_SIZE + ALPHABET_SIZE)

typedef struct {
    int seed[SEED_SIZE];
    char alphabet[ALPHABET_SIZE];
} EncryptKey;

void initKey(EncryptKey *key) {
    int i;

    for (i = 0; i < SEED_SIZE; i++) {
        key->seed[i] = (int) rand();
    }

    for (i = 0; i < ALPHABET_SIZE; i++) {
        key->alphabet[i] = (char) ('a' + i);
    }
}

void encryptFile(const char *inputPath, const char *outputPath, const EncryptKey *key) {
    FILE *inputFile, *outputFile;
    char inputBuffer[BLOCK_SIZE];
    char outputBuffer[BLOCK_SIZE];
    int i, j;
    int encryptedBlock[BLOCK_SIZE];

    inputFile = fopen(inputPath, "rb");
    outputFile = fopen(outputPath, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    initKey(key);

    while (fread(inputBuffer, sizeof(char), BLOCK_SIZE, inputFile)) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            encryptedBlock[i] = inputBuffer[i] ^ key->seed[i % SEED_SIZE] ^ key->alphabet[(int) inputBuffer[i] % ALPHABET_SIZE];
            outputBuffer[i] = (char) encryptedBlock[i];
        }

        fwrite(outputBuffer, sizeof(char), BLOCK_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <seed>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    EncryptKey key;
    srand(atoi(argv[3]));

    encryptFile(argv[1], argv[2], &key);

    printf("File encrypted with seed: %s\n", argv[3]);

    return EXIT_SUCCESS;
}