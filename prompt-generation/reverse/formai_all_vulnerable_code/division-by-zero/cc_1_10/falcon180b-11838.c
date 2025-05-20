//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_BLOCK_SIZE 16
#define MAX_ROUNDS 100

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    int rounds;
} encryption_params;

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char* plaintext, encryption_params* params) {
    int i, j, round;
    char* ciphertext = malloc(strlen(plaintext) + 1);
    char* key = params->key;
    int key_length = params->key_length;
    int rounds = params->rounds;
    int block_size = strlen(plaintext) / rounds;

    for (i = 0; i < rounds; i++) {
        for (j = i * block_size; j < (i + 1) * block_size && j < strlen(plaintext); j++) {
            ciphertext[j] = plaintext[j];
        }

        for (j = 0; j < strlen(ciphertext); j++) {
            ciphertext[j] = ciphertext[j] ^ key[i % key_length];
        }
    }

    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char* ciphertext, encryption_params* params) {
    int i, j, round;
    char* plaintext = malloc(strlen(ciphertext) + 1);
    char* key = params->key;
    int key_length = params->key_length;
    int rounds = params->rounds;
    int block_size = strlen(ciphertext) / rounds;

    for (i = 0; i < rounds; i++) {
        for (j = i * block_size; j < (i + 1) * block_size && j < strlen(ciphertext); j++) {
            plaintext[j] = ciphertext[j];
        }

        for (j = 0; j < strlen(plaintext); j++) {
            plaintext[j] = plaintext[j] ^ key[i % key_length];
        }
    }

    printf("Plaintext: %s\n", plaintext);
}

int main() {
    encryption_params params;
    int choice;
    char* plaintext;
    char* ciphertext;

    srand(time(NULL));

    printf("Enter key length (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &params.key_length);

    generate_key(params.key, params.key_length);

    printf("Key: %s\n", params.key);

    printf("Enter number of rounds (between 1 and %d): ", MAX_ROUNDS);
    scanf("%d", &params.rounds);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, &params);
    decrypt(ciphertext, &params);

    return 0;
}