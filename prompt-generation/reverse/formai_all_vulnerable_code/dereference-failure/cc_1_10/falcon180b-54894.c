//Falcon-180B DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int key_size;
    int rounds;
} encryption_params;

void generate_key(char *key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *input, encryption_params *params) {
    int input_size = strlen(input);
    char *output = malloc(input_size + 1);

    for (int i = 0; i < input_size; i++) {
        int key_index = i % params->key_size;
        int ascii_value = toupper(input[i]) - 65;
        ascii_value = (ascii_value + params->key[key_index]) % 26 + 65;
        output[i] = ascii_value;
    }

    output[input_size] = '\0';

    printf("Encrypted message: %s\n", output);
}

int main() {
    encryption_params params;
    params.key = malloc(MAX_SIZE);
    params.key_size = 0;
    params.rounds = 0;

    generate_key(params.key, MAX_SIZE);
    params.key_size = strlen(params.key);

    int rounds;
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);
    params.rounds = rounds;

    char input[MAX_SIZE];
    printf("Enter the message to be encrypted: ");
    scanf("%s", input);

    encrypt(input, &params);

    free(params.key);
    free(input);

    return 0;
}