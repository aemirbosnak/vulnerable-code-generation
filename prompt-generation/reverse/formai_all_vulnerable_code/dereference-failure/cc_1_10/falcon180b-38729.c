//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
} message_t;

void generate_key(char* key, int key_size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
}

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int j = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key[j];
        j++;
        if (j == key_length) {
            j = 0;
        }
    }
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int j = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key[j];
        j++;
        if (j == key_length) {
            j = 0;
        }
    }
}

int main() {
    message_t message;
    char key[MAX_KEY_SIZE];
    generate_key(key, MAX_KEY_SIZE);
    printf("Enter message to encrypt: ");
    scanf("%s", message.message);
    encrypt(message.message, key);
    printf("Encrypted message: %s\n", message.message);
    decrypt(message.message, key);
    printf("Decrypted message: %s\n", message.message);
    return 0;
}