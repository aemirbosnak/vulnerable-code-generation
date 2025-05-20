//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a silly magic number for our encryption
#define MAGIC_NUMBER 42 
#define BUFFER_SIZE 1024

// Function for encryption, or as we like to call it: a "joke in progress"
void encrypt(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    
    if (inFile == NULL || outFile == NULL) {
        perror("Oops! The file could not be opened. Maybe it's playing hide and seek?");
        exit(EXIT_FAILURE);
    }
    
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Magic happens here - we turn bytes into gibberish!
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= MAGIC_NUMBER; // XOR magic to mix things up!
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("✨ Your file has been encrypted! Now it’s a secret agent. 🤫\n");
}

// Function for decryption, or as we like to call it: a "joke unveiled"
void decrypt(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    
    if (inFile == NULL || outFile == NULL) {
        perror("Oh no! The file is still MIA! Are you sure it exists?");
        exit(EXIT_FAILURE);
    }
    
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Magic undone - we reveal the secrets!
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= MAGIC_NUMBER; // XOR magic to retrieve the original!
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("🎉 Your file has been decrypted! The secrets are out! 🎊\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("🦄 Welcome to the File Encryptor & Decryptor! 🎩\n");
        printf("Usage: %s <encrypt|decrypt> <input file> <output file>\n", argv[0]);
        printf("Just what we need: more confusing instructions! 🤷‍♂️\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Uh-oh! Looks like someone doesn’t know how to follow instructions. 🤔\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}