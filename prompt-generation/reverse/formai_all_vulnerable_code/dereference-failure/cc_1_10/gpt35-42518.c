//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int key[100];

// Function to generate key
void generateKey(int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 128;
    }
}

// Function to encrypt message
char *encrypt(char *msg) {
    int length = strlen(msg);
    char *encryptedMsg = malloc(length + 1);
    generateKey(length);
    for (int i = 0; i < length; i++) {
        encryptedMsg[i] = msg[i] ^ key[i];
    }
    encryptedMsg[length] = '\0';
    return encryptedMsg;
}

// Function to decrypt message
char *decrypt(char *encryptedMsg) {
    int length = strlen(encryptedMsg);
    char *decryptedMsg = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        decryptedMsg[i] = encryptedMsg[i] ^ key[i];
    }
    decryptedMsg[length] = '\0';
    return decryptedMsg;
}

int main() {
    char *msg = "Hello, this is a sample message";
    char *encryptedMsg = encrypt(msg);
    char *decryptedMsg = decrypt(encryptedMsg);

    printf("Original message: %s\n", msg);
    printf("Encrypted message: %s\n", encryptedMsg);
    printf("Decrypted message: %s\n", decryptedMsg);

    free(encryptedMsg);
    free(decryptedMsg);
    return 0;
}