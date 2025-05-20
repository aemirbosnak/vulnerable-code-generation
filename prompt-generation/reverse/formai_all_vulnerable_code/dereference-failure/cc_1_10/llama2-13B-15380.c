//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char *key;
    char *message;
} encrypt_params;

void encrypt(encrypt_params *params);
void decrypt(encrypt_params *params);

int main() {
    encrypt_params params;
    params.key = (char *)malloc(KEY_SIZE * sizeof(char));
    params.message = (char *)malloc(MAX_MESSAGE_LENGTH * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        params.key[i] = (char)rand() % 26 + 'a';
    }

    printf("Enter message: ");
    fgets(params.message, MAX_MESSAGE_LENGTH, stdin);

    encrypt(&params);
    decrypt(&params);

    free(params.key);
    free(params.message);

    return 0;
}

void encrypt(encrypt_params *params) {
    int i, j, k;
    char temp[BLOCK_SIZE];

    for (i = 0; i < strlen(params->message); i++) {
        temp[i] = params->message[i];
    }

    for (j = 0; j < KEY_SIZE; j++) {
        for (k = 0; k < BLOCK_SIZE; k++) {
            temp[k] = temp[k] ^ params->key[j];
        }
    }

    params->message = (char *)malloc(strlen(temp) * sizeof(char));
    strcpy(params->message, temp);
}

void decrypt(encrypt_params *params) {
    int i, j, k;
    char temp[BLOCK_SIZE];

    for (i = 0; i < strlen(params->message); i++) {
        temp[i] = params->message[i];
    }

    for (j = 0; j < KEY_SIZE; j++) {
        for (k = 0; k < BLOCK_SIZE; k++) {
            temp[k] = temp[k] ^ params->key[j];
        }
    }

    params->message = (char *)malloc(strlen(temp) * sizeof(char));
    strcpy(params->message, temp);
}