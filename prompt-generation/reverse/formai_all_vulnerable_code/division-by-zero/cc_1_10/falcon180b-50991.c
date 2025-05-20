//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024
#define NUM_ROUNDS 10000

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int i, j, key_index;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (message[i] - 'a' + (int)key[j % strlen(key)]) % 26 + 'a';
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int i, j, key_index;
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = (encrypted_message[i] - (int)key[j % strlen(key)] + 26) % 26 + 'a';
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int i;

    srand(time(NULL));
    generate_key(key, strlen(key));

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}