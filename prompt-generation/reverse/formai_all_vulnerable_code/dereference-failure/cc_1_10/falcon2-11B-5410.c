//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_SIZE 256

// Function to generate a random key of size MAX_KEY_SIZE
char* generate_key(void) {
    char* key = (char*)malloc(MAX_KEY_SIZE + 1);
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = (char)rand() % 256;
    }
    key[MAX_KEY_SIZE] = '\0';
    return key;
}

// Function to encrypt a message using the public key
char* encrypt(const char* key, const char* message) {
    char* ciphertext = (char*)malloc(MAX_MESSAGE_SIZE + 1);
    for (int i = 0; i < strlen(message); i++) {
        ciphertext[i] = (char)(message[i] ^ key[i % MAX_KEY_SIZE]);
    }
    ciphertext[strlen(message)] = '\0';
    return ciphertext;
}

// Function to decrypt a ciphertext using the private key
char* decrypt(const char* key, const char* ciphertext) {
    char* plaintext = (char*)malloc(MAX_MESSAGE_SIZE + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = (char)(ciphertext[i] ^ key[i % MAX_KEY_SIZE]);
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    char* key = generate_key();
    char* message = "Hello, World!";
    char* ciphertext = encrypt(key, message);
    char* decrypted = decrypt(key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);
    free(key);
    free(message);
    free(ciphertext);
    free(decrypted);
    return 0;
}