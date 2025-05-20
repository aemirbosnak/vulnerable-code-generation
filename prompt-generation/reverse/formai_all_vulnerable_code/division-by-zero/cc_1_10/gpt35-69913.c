//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform XOR encryption on a message */
void encrypt(char message[], char key[]) {
    int keyLen = strlen(key);
    int messageLen = strlen(message);
    int i;

    for(i=0; i<messageLen; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }
}

/* Function to perform XOR decryption on a message */
void decrypt(char message[], char key[]) {
    int keyLen = strlen(key);
    int messageLen = strlen(message);
    int i;

    for(i=0; i<messageLen; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter message to encrypt (max 100 characters): \n");
    fgets(message, 100, stdin);

    printf("Enter key (max 100 characters): \n");
    fgets(key, 100, stdin);

    /* Remove newline characters from the inputs */
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}