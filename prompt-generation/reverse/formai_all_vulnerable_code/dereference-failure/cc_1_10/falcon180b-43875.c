//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(char* message, char* encrypted_message) {
    int i, j;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    int message_length = strlen(message);
    int encrypted_message_length = message_length + 1;
    strcpy(encrypted_message, "");
    for (i = 0; i < message_length; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        strncpy(block, message + i, BLOCK_SIZE);
        block[BLOCK_SIZE - 1] = '\0';
        for (j = 0; j < strlen(block); j++) {
            char c = block[j];
            int k = c - 'A';
            k = (k + key[j % strlen(key)]) % 26;
            c = k + 'A';
            strncat(encrypted_message, &c, 1);
        }
    }
    strncat(encrypted_message, "\0", 1);
}

void decrypt(char* encrypted_message, char* message) {
    int i, j;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    int encrypted_message_length = strlen(encrypted_message);
    int message_length = encrypted_message_length - 1;
    strcpy(message, "");
    for (i = 0; i < encrypted_message_length; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        strncpy(block, encrypted_message + i, BLOCK_SIZE);
        block[BLOCK_SIZE - 1] = '\0';
        for (j = 0; j < strlen(block); j++) {
            char c = block[j];
            int k = c - 'A';
            k = (k - key[j % strlen(key)]) % 26;
            if (k < 0) {
                k += 26;
            }
            c = k + 'A';
            strncat(message, &c, 1);
        }
    }
    strncat(message, "\0", 1);
}

int main() {
    char message[100] = "Hello, world!";
    char encrypted_message[200];
    char decrypted_message[200];
    encrypt(message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    decrypt(encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}