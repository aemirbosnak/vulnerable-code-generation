//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1000

char *encrypt(char *message, char *key) {
    int i, j, n = strlen(message);
    char *result = malloc(n + 1);
    memset(result, 0, n + 1);

    for (i = 0, j = 0; i < n; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c += key[j % MAX_KEY_SIZE];
            if (isupper(c)) {
                result[i] = toupper(c);
            } else {
                result[i] = tolower(c);
            }
            j++;
        } else {
            result[i] = message[i];
        }
    }

    return result;
}

char *decrypt(char *message, char *key) {
    int i, j, n = strlen(message);
    char *result = malloc(n + 1);
    memset(result, 0, n + 1);

    for (i = 0, j = 0; i < n; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c -= key[j % MAX_KEY_SIZE];
            if (isupper(c)) {
                result[i] = toupper(c);
            } else {
                result[i] = tolower(c);
            }
            j++;
        } else {
            result[i] = message[i];
        }
    }

    return result;
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char *encrypted_message;
    char *decrypted_message;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}