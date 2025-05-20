//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
#define KEY "mysecretkey"

// Encrypts the given string using the Caesar cipher
char* encrypt(char* message) {
    char* result = (char*) malloc(strlen(message) + 1);
    int key_index = 0;

    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[i] = (char) ((message[i] - 'A' + key_index) % 26 + 'A');
            } else {
                result[i] = (char) ((message[i] - 'a' + key_index) % 26 + 'a');
            }
        } else {
            result[i] = message[i];
        }
    }

    return result;
}

// Decrypts the given string using the Caesar cipher
char* decrypt(char* message) {
    char* result = (char*) malloc(strlen(message) + 1);
    int key_index = 0;

    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[i] = (char) ((message[i] - 'A' - key_index + 26) % 26 + 'A');
            } else {
                result[i] = (char) ((message[i] - 'a' - key_index + 26) % 26 + 'a');
            }
        } else {
            result[i] = message[i];
        }
    }

    return result;
}

int main() {
    char* message = "Hello, world!";
    char* encrypted = encrypt(message);
    char* decrypted = decrypt(encrypted);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}