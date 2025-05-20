//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 1024
#define KEY_SIZE 25

typedef struct {
    char key[KEY_SIZE];
} EncryptionKey;

void generateKey(EncryptionKey *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key->key[i] = rand() % 128;
    }
}

void printKey(EncryptionKey key) {
    int i;
    printf("Encryption Key: ");
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%c ", key.key[i]);
    }
    printf("\n");
}

void readFile(FILE *file, char *buffer) {
    fread(buffer, 1, FILE_SIZE, file);
}

void writeFile(FILE *file, char *buffer) {
    fwrite(buffer, 1, FILE_SIZE, file);
}

void encryptFile(char *inputFile, char *outputFile, EncryptionKey key) {
    FILE *input, *output;
    char buffer[FILE_SIZE];
    int i, j;

    input = fopen(inputFile, "rb");
    output = fopen(outputFile, "wb");

    if (input == NULL || output == NULL) {
        perror("Error opening files.");
        exit(1);
    }

    while (fread(buffer, 1, FILE_SIZE, input) > 0) {
        for (i = 0; i < FILE_SIZE; i++) {
            buffer[i] = buffer[i] ^ key.key[i % KEY_SIZE];
        }

        fwrite(buffer, 1, FILE_SIZE, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char *inputFile = "input.txt";
    char *outputFile = "output.txt";
    EncryptionKey key;

    srand(time(NULL));
    generateKey(&key);
    printKey(key);

    remove(outputFile);
    encryptFile(inputFile, outputFile, key);

    remove(inputFile);
    unlink(inputFile);

    return 0;
}