//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_SECRET_SIZE 1024

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *secret, char *key, char *encrypted) {
    int key_index = 0;
    for (int i = 0; i < strlen(secret); i++) {
        encrypted[i] = secret[i] ^ key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }
    encrypted[strlen(secret)] = '\0';
}

void decrypt(char *encrypted, char *key, char *decrypted) {
    int key_index = 0;
    for (int i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = encrypted[i] ^ key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }
    decrypted[strlen(encrypted)] = '\0';
}

int main() {
    char secret[MAX_SECRET_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted[MAX_SECRET_SIZE];
    char decrypted[MAX_SECRET_SIZE];

    printf("Enter a secret message: ");
    fgets(secret, MAX_SECRET_SIZE, stdin);

    generate_key(key, MAX_KEY_SIZE);

    encrypt(secret, key, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    decrypt(encrypted, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}