//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom XOR encryption function
char* xor_encrypt(char* plaintext, char* key) {
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(key);
    char* ciphertext = malloc(plaintext_len + 1);

    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    ciphertext[plaintext_len] = '\0';
    return ciphertext;
}

// Custom XOR decryption function
char* xor_decrypt(char* ciphertext, char* key) {
    size_t ciphertext_len = strlen(ciphertext);
    size_t key_len = strlen(key);
    char* plaintext = malloc(ciphertext_len + 1);

    for (size_t i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    plaintext[ciphertext_len] = '\0';
    return plaintext;
}

// Custom encryption function using Caesar cipher and XOR encryption
char* my_encrypt(char* plaintext, char* key) {
    int key_value = atoi(key);
    char* shifted_text = malloc(strlen(plaintext) + 1);

    // Caesar shift
    for (int i = 0; i < strlen(plaintext); i++) {
        shifted_text[i] = (plaintext[i] + key_value - 'a') % 26 + 'a';
    }

    // XOR encryption
    return xor_encrypt(shifted_text, key);
}

// Custom decryption function using Caesar cipher and XOR decryption
char* my_decrypt(char* ciphertext, char* key) {
    int key_value = atoi(key);
    char* shifted_text = malloc(strlen(ciphertext) + 1);

    // XOR decryption
    char* decrypted_text = xor_decrypt(ciphertext, key);

    // Caesar shift reversal
    for (int i = 0; i < strlen(decrypted_text); i++) {
        shifted_text[i] = (decrypted_text[i] - key_value - 'a') % 26 + 'a';
    }

    return shifted_text;
}

int main() {
    char plaintext[] = "This is a secret message.";
    char key[] = "MySecret";

    // Encrypt using custom encryption function
    printf("Encrypted ciphertext: %s\n", my_encrypt(plaintext, key));

    // Decrypt using custom decryption function
    printf("Decrypted plaintext: %s\n", my_decrypt(my_encrypt(plaintext, key), key));

    return 0;
}