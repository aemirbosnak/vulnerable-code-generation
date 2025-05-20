//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* generateKey(char *key, int key_length) {
    char chars[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    int chars_length = strlen(chars);

    srand(time(0));
    for (int i = 0; i < key_length; i++) {
        int random_index = rand() % chars_length;
        key[i] = chars[random_index];
    }
    key[key_length] = '\0';

    return key;
}

void encrypt(char *message, int message_length, char *key, int key_length) {
    for (int i = 0; i < message_length; i++) {
        int j = i % key_length;
        message[i] = message[i] ^ key[j];
    }
}

void decrypt(char *message, int message_length, char *key, int key_length) {
    for (int i = 0; i < message_length; i++) {
        int j = i % key_length;
        message[i] = message[i] ^ key[j];
    }
}

int main() {
    char message[] = "this is a secret message";
    int message_length = strlen(message);

    char key[20];
    char *encrypted_message = malloc((message_length + 1) * sizeof(char));
    char *decrypted_message = malloc((message_length + 1) * sizeof(char));

    generateKey(key, 10);

    printf("Original message: %s\n", message);

    encrypt(message, message_length, key, strlen(key));
    strcpy(encrypted_message, message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(message, message_length, key, strlen(key));
    strcpy(decrypted_message, message);

    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}