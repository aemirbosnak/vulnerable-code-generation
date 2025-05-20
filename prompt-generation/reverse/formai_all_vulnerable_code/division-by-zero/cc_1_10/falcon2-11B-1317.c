//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
void encrypt(char* message, char* key) {
    int key_length = strlen(key);
    int message_length = strlen(message);

    int i = 0;
    while (i < message_length) {
        int shift = (key_length + i) % key_length;
        int c = message[i] + key[shift];
        if (c > 127) c -= 256;
        message[i] = c;
        i++;
    }
}

// Decryption function
void decrypt(char* message, char* key) {
    int key_length = strlen(key);
    int message_length = strlen(message);

    int i = 0;
    while (i < message_length) {
        int shift = (key_length + i) % key_length;
        int c = message[i] - key[shift];
        if (c < 0) c += 256;
        message[i] = c;
        i++;
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);
    decrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}