//Falcon-180B DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void encrypt(char* message, char* key) {
    int i = 0, j = 0;
    char plaintext[KEY_LENGTH + 1] = {0};
    char ciphertext[KEY_LENGTH + 1] = {0};

    strcpy(plaintext, message);

    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[j] = toupper(plaintext[i] + (key[i % KEY_LENGTH] - 'A'));
            }
            else {
                ciphertext[j] = tolower(plaintext[i] + (key[i % KEY_LENGTH] - 'a'));
            }
            j++;
        }
        else {
            ciphertext[j] = plaintext[i];
            j++;
        }
    }

    strcpy(message, ciphertext);
}

void decrypt(char* ciphertext, char* key) {
    int i = 0, j = 0;
    char plaintext[KEY_LENGTH + 1] = {0};
    char temp[KEY_LENGTH + 1] = {0};

    strcpy(temp, ciphertext);

    for (i = 0; i < strlen(temp); i++) {
        if (isalpha(temp[i])) {
            if (isupper(temp[i])) {
                plaintext[j] = 'A' + (temp[i] - key[i % KEY_LENGTH]);
            }
            else {
                plaintext[j] = 'a' + (temp[i] - key[i % KEY_LENGTH]);
            }
            j++;
        }
        else {
            plaintext[j] = temp[i];
            j++;
        }
    }

    strcpy(ciphertext, plaintext);
}

void generate_key(char* key) {
    int i;

    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

int main() {
    char message[1000] = {0};
    char key[KEY_LENGTH + 1] = {0};

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);

    generate_key(key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}