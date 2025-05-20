//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAGIC_KEY 0xDEADBEEF
#define SALT "NaCl"

int xor_encrypt(char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ MAGIC_KEY;
    }
    return len;
}

int salify(char *plaintext, int len) {
    int salt_len = strlen(SALT);
    for (int i = 0; i < len; i++) {
        plaintext[i] += SALT[i % salt_len];
    }
    return len;
}

int enigma(char *plaintext, int len) {
    int key = rand() % len;
    for (int i = 0; i < len; i++) {
         plaintext[i] += key;
    }
    return len;
}

int main() {
    // Initialize the secret message
    char *plaintext = "Top secret message!";
    int len = strlen(plaintext);

    // Step 1: Salting the message
    salify(plaintext, len);

    // Step 2: XOR encryption
    char *ciphertext = malloc(len + 1);
    xor_encrypt(plaintext, ciphertext);
    ciphertext[len] = '\0';

    // Step 3: Enigma rotation
    enigma(ciphertext, len);

    // Display the encrypted message
    printf("Encrypted message: %s\n", ciphertext);

    // Step 4: Enigma reverse rotation
    enigma(ciphertext, len);

    // Step 5: XOR decryption
    xor_encrypt(ciphertext, plaintext);

    // Step 6: Desalting the message
    salify(plaintext, len);
    plaintext[len] = '\0';

    // Display the decrypted message
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}