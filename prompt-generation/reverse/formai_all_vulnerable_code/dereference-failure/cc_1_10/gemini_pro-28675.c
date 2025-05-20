//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char* encrypt(char* plaintext, int key) {
    int plaintext_len = strlen(plaintext);
    char* ciphertext = (char*)malloc(plaintext_len + 1);
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] + key;
    }
    ciphertext[plaintext_len] = '\0';
    return ciphertext;
}

// Custom decryption function
char* decrypt(char* ciphertext, int key) {
    int ciphertext_len = strlen(ciphertext);
    char* plaintext = (char*)malloc(ciphertext_len + 1);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] - key;
    }
    plaintext[ciphertext_len] = '\0';
    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Get the encryption key from the user
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the plaintext using the custom encryption function
    char* ciphertext = encrypt(plaintext, key);

    // Print the encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the custom decryption function
    char* decrypted_plaintext = decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}