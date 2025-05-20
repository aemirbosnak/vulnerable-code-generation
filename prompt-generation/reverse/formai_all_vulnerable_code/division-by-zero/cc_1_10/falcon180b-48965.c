//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main() {
    char message[SIZE];
    char key[SIZE];

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, SIZE, stdin);

    // Get key from user
    printf("Enter encryption key: ");
    fgets(key, SIZE, stdin);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
        }
        message[i] += key[j];
        j = (j + 1) % strlen(key);
    }
}

void decrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
        }
        message[i] -= key[j];
        j = (j + 1) % strlen(key);
    }
}