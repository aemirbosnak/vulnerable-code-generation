//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Intimate whispers of love: a simple XOR encryption function
void encrypt(const char *input, const char *output, char key) {
    FILE *inFile = fopen(input, "rb");
    FILE *outFile = fopen(output, "wb");

    if (inFile == NULL || outFile == NULL) {
        fprintf(stderr, "Ah, my dear! I cannot open these files... \n");
        exit(EXIT_FAILURE);
    }

    // Lovers' dance through files: reading and writing encrypted content
    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // A sweet touch of encryption
    }

    fclose(inFile);
    fclose(outFile);
}

// A gentle touch to decrypt the heart: Same function for decryption
void decrypt(const char *input, const char *output, char key) {
    // Decryption is but a rekindling of the same flame
    encrypt(input, output, key);
}

int main(int argc, char *argv[]) {
    // A romantic evening requires proper preparations
    if (argc != 5) {
        fprintf(stderr, "Beloved, please provide these: <encrypt/decrypt> <inputfile> <outputfile> <key>\n");
        exit(EXIT_FAILURE);
    }

    char *mode = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    char key = argv[4][0]; // A single character key, like a tender kiss

    // Choosing whether to encrypt or decrypt our lover's message
    if (strcmp(mode, "encrypt") == 0) {
        printf("Infusing our love letter with enchantment...\n");
        encrypt(inputFile, outputFile, key);
        printf("Your love letter has been enchanted and sealed with care!\n");
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Revealing the secrets hidden in shadows...\n");
        decrypt(inputFile, outputFile, key);
        printf("The secrets have been unveiled, dear wanderer of the heart!\n");
    } else {
        fprintf(stderr, "My love, the choice is unclear... please choose 'encrypt' or 'decrypt'\n");
        exit(EXIT_FAILURE);
    }

    // A sweet farewell until the next cherished encounter
    return 0;
}