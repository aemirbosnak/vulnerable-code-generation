//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int key_length = strlen(key);
    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: key is too long.\n");
        exit(1);
    }
    for (int i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt(char *message, char *key, char *ciphertext) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: message is too long.\n");
        exit(1);
    }
    for (int i = 0; i < message_length; i++) {
        char plaintext = tolower(message[i]);
        char keynum = key[i % key_length];
        ciphertext[i] = plaintext ^ keynum;
    }
}

void decrypt(char *ciphertext, char *key, char *message) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);
    if (ciphertext_length > MAX_MESSAGE_LENGTH) {
        printf("Error: ciphertext is too long.\n");
        exit(1);
    }
    for (int i = 0; i < ciphertext_length; i++) {
        char ciphertext_char = ciphertext[i];
        char keynum = key[i % key_length];
        message[i] = ciphertext_char ^ keynum;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char ciphertext[MAX_MESSAGE_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    generate_key(key);
    encrypt(message, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, message);
    printf("Decrypted message: %s\n", message);
    return 0;
}