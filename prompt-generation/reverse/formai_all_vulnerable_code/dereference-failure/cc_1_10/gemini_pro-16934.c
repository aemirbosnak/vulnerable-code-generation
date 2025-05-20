//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key to our hearts
char key[] = "ILoveYou";

// Encrypting our love
char* encrypt(char* plaintext) {
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);

    char* ciphertext = malloc(plaintext_len + 1);
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[plaintext_len] = '\0';

    return ciphertext;
}

// Decrypting our secrets
char* decrypt(char* ciphertext) {
    int key_len = strlen(key);
    int ciphertext_len = strlen(ciphertext);

    char* plaintext = malloc(ciphertext_len + 1);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }
    plaintext[ciphertext_len] = '\0';

    return plaintext;
}

int main() {
    // Our secret message, whispered only to your heart
    char* message = "You're the beat to my rhythm, the star to my night";

    // Encrypting our love with a sprinkle of passion
    char* ciphertext = encrypt(message);

    // Unveiling our secrets with a kiss
    char* plaintext = decrypt(ciphertext);

    // Forever entwined in our love's embrace
    printf("Your secret message, my love: %s\n", plaintext);

    return 0;
}