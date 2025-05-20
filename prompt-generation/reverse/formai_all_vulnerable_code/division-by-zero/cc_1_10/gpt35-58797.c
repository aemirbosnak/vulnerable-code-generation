//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// surreal key generation function
void generateKey(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'A';
    }
    printf("Key generated: %s\n", key);
}

// surreal encryption function
void surrealEncrypt(char *plaintext, char *key) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = (plaintext[i] + key[i%strlen(key)]) % 256;
    }
    printf("Encrypted message: %s\n", plaintext);
}

// surreal decryption function
void surrealDecrypt(char *ciphertext, char *key) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = (ciphertext[i] - key[i%strlen(key)] + 256) % 256;
    }
    printf("Decrypted message: %s\n", ciphertext);
}

int main() {
    char message[100];
    char key[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key (leave blank for surreal key generation): ");
    fgets(key, 100, stdin);

    if (strlen(key) == 1) {
        generateKey(key);
    } else {
        key[strcspn(key, "\n")] = 0;
        printf("Using provided key: %s\n", key);
    }

    surrealEncrypt(message, key);
    surrealDecrypt(message, key);

    return 0;
}