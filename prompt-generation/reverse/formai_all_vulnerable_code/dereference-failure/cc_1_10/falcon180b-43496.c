//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256

char *generate_key(int length) {
    char key[MAX_KEY_LENGTH];
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
    return strdup(key);
}

char *encrypt(char *message, char *key) {
    int i, j;
    char *result = malloc(strlen(message) + 1);
    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            result[j++] = (message[i] + key[i % strlen(key)] - 'a' + 26) % 26 + 'a';
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
    return result;
}

char *decrypt(char *message, char *key) {
    int i, j;
    char *result = malloc(strlen(message) + 1);
    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            result[j++] = (message[i] - key[i % strlen(key)] + 26) % 26 + 'a';
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char *message = "Hello, world!";
    char *key = generate_key(strlen(message));
    char *encrypted = encrypt(message, key);
    char *decrypted = decrypt(encrypted, key);
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
    free(message);
    free(key);
    free(encrypted);
    free(decrypted);
    return 0;
}