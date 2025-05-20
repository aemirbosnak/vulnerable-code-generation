//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted_message = (char*) malloc(length + 1);
    int i, j;

    for (i = 0, j = 0; i < length; i++, j++) {
        if (j == key) {
            j = 0;
        }

        encrypted_message[i] = message[j];
    }

    encrypted_message[length] = '\0';
    return encrypted_message;
}

// Function to decrypt the message
char* decrypt(char* encrypted_message, int key) {
    int length = strlen(encrypted_message);
    char* decrypted_message = (char*) malloc(length + 1);
    int i, j;

    for (i = 0, j = 0; i < length; i++, j++) {
        if (j == key) {
            j = 0;
        }

        decrypted_message[i] = encrypted_message[j];
    }

    decrypted_message[length] = '\0';
    return decrypted_message;
}

int main() {
    char* message = "Hello, world!";
    int key = 3;

    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}