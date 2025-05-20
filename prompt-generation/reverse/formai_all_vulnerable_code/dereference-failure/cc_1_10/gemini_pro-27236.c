//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 256

// Encryption function
char* encrypt(char* plaintext, char* key) {
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);

    // Check if key is too long
    if (key_len > MAX_KEY_LEN) {
        printf("Error: Key is too long. Maximum length is %d characters.\n", MAX_KEY_LEN);
        return NULL;
    }

    // Create ciphertext buffer
    char* ciphertext = (char*)malloc(plaintext_len + 1);
    if (ciphertext == NULL) {
        printf("Error: Unable to allocate memory for ciphertext.\n");
        return NULL;
    }

    // Encrypt plaintext using key
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Terminate ciphertext with null character
    ciphertext[plaintext_len] = '\0';

    // Return ciphertext
    return ciphertext;
}

// Decryption function
char* decrypt(char* ciphertext, char* key) {
    int key_len = strlen(key);
    int ciphertext_len = strlen(ciphertext);

    // Create plaintext buffer
    char* plaintext = (char*)malloc(ciphertext_len + 1);
    if (plaintext == NULL) {
        printf("Error: Unable to allocate memory for plaintext.\n");
        return NULL;
    }

    // Decrypt ciphertext using key
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Terminate plaintext with null character
    plaintext[ciphertext_len] = '\0';

    // Return plaintext
    return plaintext;
}

// Key generation function
char* generate_key(int key_len) {
    // Check if key length is valid
    if (key_len <= 0) {
        printf("Error: Key length must be positive.\n");
        return NULL;
    }

    // Create key buffer
    char* key = (char*)malloc(key_len + 1);
    if (key == NULL) {
        printf("Error: Unable to allocate memory for key.\n");
        return NULL;
    }

    // Generate random key
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 256;
    }

    // Terminate key with null character
    key[key_len] = '\0';

    // Return key
    return key;
}

// Parse command line arguments
int parse_args(int argc, char* argv[], char** plaintext, char** key, int* key_len) {
    // Check if there are enough arguments
    if (argc < 4) {
        printf("Usage: %s <plaintext> <key> <key_len>\n", argv[0]);
        return 1;
    }

    // Get plaintext
    *plaintext = argv[1];

    // Get key
    *key = argv[2];

    // Get key length
    *key_len = atoi(argv[3]);

    // Return success
    return 0;
}

// Main function
int main(int argc, char* argv[]) {
    // Parse command line arguments
    char* plaintext;
    char* key;
    int key_len;
    int args_parsed = parse_args(argc, argv, &plaintext, &key, &key_len);
    if (args_parsed != 0) {
        return args_parsed;
    }

    // Encrypt plaintext
    char* ciphertext = encrypt(plaintext, key);
    if (ciphertext == NULL) {
        return 1;
    }

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext
    char* decrypted_plaintext = decrypt(ciphertext, key);
    if (decrypted_plaintext == NULL) {
        return 1;
    }

    // Print decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    // Return success
    return 0;
}