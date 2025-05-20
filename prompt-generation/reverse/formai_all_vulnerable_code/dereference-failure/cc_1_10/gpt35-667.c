//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *key, int key_len);
void decrypt(char *input, char *key, int key_len);

int main() {
    char input[100];
    char key[100];
    int key_len;

    printf("Enter input (max 100 characters): ");
    fgets(input, 100, stdin);

    printf("Enter key (max 100 characters): ");
    fgets(key, 100, stdin);

    key_len = strlen(key);
    key[key_len-1] = '\0'; // Remove newline character

    printf("\nInput: %s\nKey: %s\n\n", input, key);

    encrypt(input, key, key_len);
    printf("Encrypted output: %s\n", input);

    decrypt(input, key, key_len);
    printf("Decrypted output: %s\n", input);

    return 0;
}

void encrypt(char *input, char *key, int key_len) {
    int i, j;
    int input_len = strlen(input);
    char *output = malloc((input_len+1) * sizeof(char));

    for (i = 0, j = 0; i < input_len; i++, j++) {
        if (j == key_len)
            j = 0;
        output[i] = ((input[i] + key[j]) % 26) + 'A';
    }

    output[i] = '\0';
    strcpy(input, output);
    free(output);
}

void decrypt(char *input, char *key, int key_len) {
    int i, j;
    int input_len = strlen(input);
    char *output = malloc((input_len+1) * sizeof(char));

    for (i = 0, j = 0; i < input_len; i++, j++) {
        if (j == key_len)
            j = 0;
        output[i] = (((input[i] - key[j]) + 26) % 26) + 'A';
    }

    output[i] = '\0';
    strcpy(input, output);
    free(output);
}