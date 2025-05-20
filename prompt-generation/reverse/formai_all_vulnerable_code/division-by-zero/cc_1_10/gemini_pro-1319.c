//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple encryption algorithm that uses XOR with a secret key
unsigned char *encrypt(unsigned char *plaintext, size_t plaintext_len, unsigned char *key, size_t key_len)
{
    unsigned char *ciphertext = malloc(plaintext_len);
    if (ciphertext == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    return ciphertext;
}

// A simple decryption algorithm that uses XOR with the same secret key
unsigned char *decrypt(unsigned char *ciphertext, size_t ciphertext_len, unsigned char *key, size_t key_len)
{
    unsigned char *plaintext = malloc(ciphertext_len);
    if (plaintext == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    return plaintext;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s plaintext key ciphertext\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the plaintext from the first argument
    FILE *plaintext_file = fopen(argv[1], "r");
    if (plaintext_file == NULL) {
        perror("Error opening plaintext file");
        return EXIT_FAILURE;
    }

    fseek(plaintext_file, 0, SEEK_END);
    size_t plaintext_len = ftell(plaintext_file);
    rewind(plaintext_file);

    unsigned char *plaintext = malloc(plaintext_len);
    if (plaintext == NULL) {
        fclose(plaintext_file);
        perror("Error allocating memory for plaintext");
        return EXIT_FAILURE;
    }

    fread(plaintext, 1, plaintext_len, plaintext_file);
    fclose(plaintext_file);

    // Read the key from the second argument
    FILE *key_file = fopen(argv[2], "r");
    if (key_file == NULL) {
        perror("Error opening key file");
        return EXIT_FAILURE;
    }

    fseek(key_file, 0, SEEK_END);
    size_t key_len = ftell(key_file);
    rewind(key_file);

    unsigned char *key = malloc(key_len);
    if (key == NULL) {
        fclose(key_file);
        free(plaintext);
        perror("Error allocating memory for key");
        return EXIT_FAILURE;
    }

    fread(key, 1, key_len, key_file);
    fclose(key_file);

    // Encrypt the plaintext using the key
    unsigned char *ciphertext = encrypt(plaintext, plaintext_len, key, key_len);
    if (ciphertext == NULL) {
        free(plaintext);
        free(key);
        perror("Error encrypting plaintext");
        return EXIT_FAILURE;
    }

    // Write the ciphertext to the third argument
    FILE *ciphertext_file = fopen(argv[3], "w");
    if (ciphertext_file == NULL) {
        free(plaintext);
        free(key);
        free(ciphertext);
        perror("Error opening ciphertext file");
        return EXIT_FAILURE;
    }

    fwrite(ciphertext, 1, plaintext_len, ciphertext_file);
    fclose(ciphertext_file);

    // Free the allocated memory
    free(plaintext);
    free(key);
    free(ciphertext);

    return EXIT_SUCCESS;
}