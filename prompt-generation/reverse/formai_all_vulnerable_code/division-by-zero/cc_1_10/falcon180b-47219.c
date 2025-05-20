//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_INPUT_LENGTH 1000

void encrypt(char *input, char *key, char *output) {
    int i, j, len = strlen(input);
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j] = 'A' + ((input[i] - 'A' + key[j % strlen(key)]) % 26);
            } else {
                output[j] = 'a' + ((input[i] - 'a' + key[j % strlen(key)]) % 26);
            }
        } else {
            output[j] = input[i];
        }
        j++;
    }
    output[j] = '\0';
}

void decrypt(char *input, char *key, char *output) {
    int i, j, len = strlen(input);
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j] = 'A' + ((input[i] - 'A' + 26 - key[j % strlen(key)]) % 26);
            } else {
                output[j] = 'a' + ((input[i] - 'a' + 26 - key[j % strlen(key)]) % 26);
            }
        } else {
            output[j] = input[i];
        }
        j++;
    }
    output[j] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH], key[MAX_KEY_LENGTH], output[MAX_INPUT_LENGTH];

    printf("Enter a string to encrypt: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("Enter a key (up to %d characters): ", MAX_KEY_LENGTH - 1);
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(input, key, output);

    printf("Encrypted string: %s\n", output);

    decrypt(output, key, input);

    printf("Decrypted string: %s\n", input);

    return 0;
}