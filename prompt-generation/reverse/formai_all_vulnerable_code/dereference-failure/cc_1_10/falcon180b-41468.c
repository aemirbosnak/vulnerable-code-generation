//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* plainText;
    char* cipherText;
} Message;

void encrypt(char* key, Message* message) {
    int keyLength = strlen(key);
    int messageLength = strlen(message->plainText);
    char* result = malloc(messageLength + 1);

    for (int i = 0; i < messageLength; i++) {
        char plainChar = message->plainText[i];
        char cipherChar = plainChar ^ key[i % keyLength];
        result[i] = cipherChar;
    }

    result[messageLength] = '\0';
    message->cipherText = result;
}

void decrypt(char* key, Message* message) {
    int keyLength = strlen(key);
    int messageLength = strlen(message->cipherText);
    char* result = malloc(messageLength + 1);

    for (int i = 0; i < messageLength; i++) {
        char cipherChar = message->cipherText[i];
        char plainChar = cipherChar ^ key[i % keyLength];
        result[i] = plainChar;
    }

    result[messageLength] = '\0';
    message->plainText = result;
}

void printMessage(Message* message) {
    printf("Plaintext: %s\n", message->plainText);
    printf("Ciphertext: %s\n", message->cipherText);
}

int main() {
    char* plainText = "The game is afoot!";
    char* key = "SherlockHolmes";
    Message message = { plainText, NULL };

    encrypt(key, &message);
    printMessage(&message);

    decrypt(key, &message);
    printMessage(&message);

    return 0;
}