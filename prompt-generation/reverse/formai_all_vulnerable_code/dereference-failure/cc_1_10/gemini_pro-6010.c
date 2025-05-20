//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int len;
} Cipher;

Cipher *init_cipher(char *key) {
    Cipher *cipher = malloc(sizeof(Cipher));
    cipher->key = strdup(key);
    cipher->len = strlen(key);
    return cipher;
}

void free_cipher(Cipher *cipher) {
    free(cipher->key);
    free(cipher);
}

char *encrypt(Cipher *cipher, char *plaintext) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    int i, j;
    for (i = 0, j = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ cipher->key[j];
        j = (j + 1) % cipher->len;
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

char *decrypt(Cipher *cipher, char *ciphertext) {
    char *plaintext = malloc(strlen(ciphertext) + 1);
    int i, j;
    for (i = 0, j = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = ciphertext[i] ^ cipher->key[j];
        j = (j + 1) % cipher->len;
    }
    plaintext[i] = '\0';
    return plaintext;
}

int main() {
    char *key = "my secret key";
    char *plaintext = "Hello, world!";
    Cipher *cipher = init_cipher(key);

    char *ciphertext = encrypt(cipher, plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    char *decryptedtext = decrypt(cipher, ciphertext);
    printf("Decrypted text: %s\n", decryptedtext);

    free_cipher(cipher);
    free(ciphertext);
    free(decryptedtext);
    return 0;
}