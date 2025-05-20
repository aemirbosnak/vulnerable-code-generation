//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *key, char *output) {
    int i, j;
    int inputLength = strlen(input);
    int keyLength = strlen(key);
    int outputLength;

    for (i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }

    output[inputLength] = '\0';

    outputLength = strlen(output);

    for (i = 0, j = outputLength - 1; i < j; i++, j--) {
        char temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}

void decrypt(char *input, char *key, char *output) {
    int i, j;
    int inputLength = strlen(input);
    int keyLength = strlen(key);
    int outputLength;

    for (i = 0, j = inputLength - 1; i < j; i++, j--) {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    for (i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }

    output[inputLength] = '\0';

    outputLength = strlen(output);
}

int main() {
    char *input = "This is a secret message";
    char *key = "secret_key";
    char output[100];

    printf("Before Encryption: %s\n", input);

    encrypt(input, key, output);

    printf("Encrypted Message: %s\n", output);

    decrypt(output, key, input);

    printf("Decrypted Message: %s\n", input);

    return 0;
}