//FormAI DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LENGTH 32
#define BLOCK_SIZE 1024

typedef struct {
    char *key;
    int keylen;
} Key;

void generateKey(Key *key);
void encryptFile(char *inFilename, char *outFilename, Key *key);
void decryptFile(char *inFilename, char *outFilename, Key *key);

int main(int argc, char **argv) {
    Key key;
    char *inFilename, *outFilename;

    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <encryption|decryption>\n", argv[0]);
        exit(1);
    }

    inFilename = argv[1];
    outFilename = argv[2];

    if (strcmp(argv[3], "encryption") == 0) {
        generateKey(&key);
        encryptFile(inFilename, outFilename, &key);
        printf("Encryption complete! Key: %s\n", key.key);
    } else if (strcmp(argv[3], "decryption") == 0) {
        printf("Please enter the key: ");
        scanf("%s", key.key);
        key.keylen = strlen(key.key);
        decryptFile(inFilename, outFilename, &key);
        printf("Decryption complete!\n");
    } else {
        printf("Invalid operation. Please specify 'encryption' or 'decryption'.\n");
        exit(1);
    }

    return 0;
}

void generateKey(Key *key) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int len = strlen(charset);
    srand(time(NULL));
    int i;

    key->key = malloc(KEY_LENGTH + 1);
    key->keylen = KEY_LENGTH;

    for (i = 0; i < KEY_LENGTH; i++) {
        key->key[i] = charset[rand() % len];
    }
    key->key[i] = '\0';
}

void encryptFile(char *inFilename, char *outFilename, Key *key) {
    FILE *inFile, *outFile;
    char buffer[BLOCK_SIZE];
    int i, j, nread, remaining;
    unsigned char keychar;

    inFile = fopen(inFilename, "rb");
    outFile = fopen(outFilename, "wb");

    if (inFile == NULL || outFile == NULL) {
        printf("Error: Could not open file(s).\n");
        exit(1);
    }

    while ((nread = fread(buffer, 1, BLOCK_SIZE, inFile)) > 0) {
        remaining = nread;
        for (i = 0; i < nread; i++) {
            keychar = key->key[i % key->keylen];
            for (j = 0; j < 8 && j < remaining; j++) {
                buffer[i+j] ^= (keychar & (1 << j)) >> j;
            }
            remaining -= j;
        }
        fwrite(buffer, 1, nread, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(char *inFilename, char *outFilename, Key *key) {
    FILE *inFile, *outFile;
    char buffer[BLOCK_SIZE];
    int i, j, nread, remaining;
    unsigned char keychar;

    inFile = fopen(inFilename, "rb");
    outFile = fopen(outFilename, "wb");

    if (inFile == NULL || outFile == NULL) {
        printf("Error: Could not open file(s).\n");
        exit(1);
    }

    while ((nread = fread(buffer, 1, BLOCK_SIZE, inFile)) > 0) {
        remaining = nread;
        for (i = 0; i < nread; i++) {
            keychar = key->key[i % key->keylen];
            for (j = 0; j < 8 && j < remaining; j++) {
                buffer[i+j] ^= (keychar & (1 << j)) >> j;
            }
            remaining -= j;
        }
        fwrite(buffer, 1, nread, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}