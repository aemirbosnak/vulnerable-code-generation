//Falcon-180B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int rounds;
} encryption_parameters_t;

void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char* message, char* key, int key_length, int rounds) {
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c + key_length) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c + key_length - 26) % 26 + 'A';
        }
        message[i] = c;
    }
}

int main() {
    encryption_parameters_t params;
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key length (1-32): ");
    scanf("%d", &params.key_length);

    generate_key(params.key, params.key_length);

    printf("Enter number of rounds (1-100): ");
    scanf("%d", &params.rounds);

    encrypt(message, params.key, params.key_length, params.rounds);

    printf("Encrypted message: %s\n", message);

    return 0;
}