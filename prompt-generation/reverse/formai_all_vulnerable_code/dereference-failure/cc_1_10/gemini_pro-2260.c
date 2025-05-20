//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: cheerful
// Let's have some cipher fun with C! 🏰🎉

// Import the necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare functions
char* encrypt(char*, char*);
char* decrypt(char*, char*);

int main() {
    // Let's encrypt a secret message! 🤫
    char plaintext[] = "Top secret: 🤫";
    char key[] = "MySuperSecureKey";

    printf("Encrypting message: %s\n", plaintext);
    char* ciphertext = encrypt(plaintext, key);
    printf("Encrypted message: %s\n", ciphertext);

    // Now, let's decrypt the encrypted message! 🔑
    char* decryptedtext = decrypt(ciphertext, key);
    printf("Decrypted message: %s\n", decryptedtext);

    // All done! Let's clean up. ✨
    free(ciphertext);
    free(decryptedtext);
    return 0;
}

// Encrypt the message using XOR cipher
char* encrypt(char* plaintext, char* key) {
    size_t len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    ciphertext[len] = '\0';

    return ciphertext;
}

// Decrypt the encrypted message using XOR cipher
char* decrypt(char* ciphertext, char* key) {
    size_t len = strlen(ciphertext);
    char* decryptedtext = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        decryptedtext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }
    decryptedtext[len] = '\0';

    return decryptedtext;
}