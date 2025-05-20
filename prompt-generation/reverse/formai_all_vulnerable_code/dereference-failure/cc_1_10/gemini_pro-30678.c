//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

typedef struct {
    unsigned int key;
    int mode;
} Config;

void encrypt(char *plaintext, unsigned int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        plaintext[i] ^= key;
    }
}

void decrypt(char *ciphertext, unsigned int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        ciphertext[i] ^= key;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <config file> <plaintext/ciphertext> <action>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse config file
    Config config;
    FILE *config_file = fopen(argv[1], "r");
    if (config_file == NULL) {
        perror("Error opening config file");
        return EXIT_FAILURE;
    }
    fscanf(config_file, "%u %d", &config.key, &config.mode);
    fclose(config_file);

    // Encrypt or decrypt
    if (config.mode == ENCRYPT) {
        encrypt(argv[2], config.key);
    } else if (config.mode == DECRYPT) {
        decrypt(argv[2], config.key);
    } else {
        printf("Invalid mode\n");
        return EXIT_FAILURE;
    }

    // Print result
    printf("%s\n", argv[2]);

    return EXIT_SUCCESS;
}