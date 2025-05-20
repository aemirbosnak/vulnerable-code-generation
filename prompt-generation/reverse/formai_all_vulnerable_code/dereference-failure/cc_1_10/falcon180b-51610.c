//Falcon-180B DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 16

char *encrypt(char *input, char *key) {
    int i, j, k;
    char *output = malloc(MAX_LENGTH);
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j++] = ((input[i] + key[k++ % KEY_LENGTH]) % 26) + 'A';
            } else {
                output[j++] = ((input[i] + key[k++ % KEY_LENGTH]) % 26) + 'a';
            }
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
    return output;
}

char *decrypt(char *input, char *key) {
    int i, j, k;
    char *output = malloc(MAX_LENGTH);
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j++] = ((input[i] - key[k++ % KEY_LENGTH]) % 26) + 'A';
            } else {
                output[j++] = ((input[i] - key[k++ % KEY_LENGTH]) % 26) + 'a';
            }
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
    return output;
}

int main() {
    srand(time(NULL));
    char *message = "Hello, World!";
    char *key = "futuristic_encryption_key";
    char *encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);
    char *decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}