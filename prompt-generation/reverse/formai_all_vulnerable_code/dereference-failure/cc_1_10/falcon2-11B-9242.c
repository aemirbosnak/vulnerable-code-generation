//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10

// Function to generate a random key
char* generateKey() {
    char key[KEY_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    return key;
}

// Function to encrypt a message using the key
char* encrypt(char* message, char* key) {
    char encrypted[strlen(message) + 1];
    int i = 0;
    for (int j = 0; j < strlen(message); j++) {
        encrypted[i] = (char)(message[j] + key[j % KEY_SIZE] - 'a');
        i++;
    }
    encrypted[i] = '\0';
    return encrypted;
}

// Function to decrypt a message using the key
char* decrypt(char* encrypted, char* key) {
    char decrypted[strlen(encrypted) + 1];
    int i = 0;
    for (int j = 0; j < strlen(encrypted); j++) {
        decrypted[i] = (char)('a' + encrypted[j] - key[(j - i) % KEY_SIZE]);
        i++;
    }
    decrypted[i] = '\0';
    return decrypted;
}

int main() {
    char* key = generateKey();
    char message[] = "Hello, world!";
    char encrypted[strlen(message) + 1];
    char decrypted[strlen(encrypted) + 1];

    printf("Message: %s\n", message);
    printf("Encrypted message: %s\n", encrypt(message, key));
    printf("Decrypted message: %s\n", decrypt(encrypted, key));

    free(key);
    return 0;
}