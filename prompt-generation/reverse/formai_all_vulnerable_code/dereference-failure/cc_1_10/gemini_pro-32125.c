//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A curious key generator that XORs the input with a sequence of prime numbers
unsigned long long generateKey(unsigned long long input) {
    unsigned long long key = 0;
    int prime = 2;
    while (input > 0) {
        if (input % prime == 0) {
            key ^= prime;
            input /= prime;
        } else {
            prime++;
        }
    }
    return key;
}

// Encrypts a file using the generated key
void encryptFile(const char *inputFile, const char *outputFile, unsigned long long key) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    unsigned char buffer[1024];
    size_t nread;
    while((nread = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (size_t i = 0; i < nread; i++) {
            buffer[i] ^= (key >> (8 * i)) & 0xFF;
        }
        fwrite(buffer, 1, nread, output);
    }

    fclose(input);
    fclose(output);
}

// Decrypts a file using the generated key
void decryptFile(const char *inputFile, const char *outputFile, unsigned long long key) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    unsigned char buffer[1024];
    size_t nread;
    while((nread = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (size_t i = 0; i < nread; i++) {
            buffer[i] ^= (key >> (8 * i)) & 0xFF;
        }
        fwrite(buffer, 1, nread, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s encrypt/decrypt inputFile outputFile key\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long long key = generateKey(atoi(argv[4]));
    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(argv[2], argv[3], key);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(argv[2], argv[3], key);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}