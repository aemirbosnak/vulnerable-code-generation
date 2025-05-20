//Falcon-180B DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH + 1)

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[length] = '\0';
}

void encrypt(char* input, char* key, char* output) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            output[j++] = (key[i % strlen(key)] + input[i] - 'A' + 26) % 26 + 'A';
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

void decrypt(char* input, char* key, char* output) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            k = (key[i % strlen(key)] - 'A' + 26 - input[i] + 26) % 26;
            output[j++] = k < 0? 'Z' : 'A' + k;
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("Enter the input to encrypt: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    generate_key(key, strlen(key));
    encrypt(input, key, output);

    printf("Encrypted message: %s\n", output);

    decrypt(output, key, input);

    printf("Decrypted message: %s\n", input);

    return 0;
}