//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char *encrypt(char *message, char *key) {
    int length = strlen(message);
    int key_length = strlen(key);
    char *encrypted_message = malloc(length + 1);

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = 'A' + ((message[i] - 'A' + key_length) % 26);
            } else {
                encrypted_message[i] = 'a' + ((message[i] - 'a' + key_length) % 26);
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[length] = '\0';
    return encrypted_message;
}

char *decrypt(char *message, char *key) {
    int length = strlen(message);
    int key_length = strlen(key);
    char *decrypted_message = malloc(length + 1);

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = 'A' + (((message[i] - 'A' - key_length + 26) % 26));
            } else {
                decrypted_message[i] = 'a' + (((message[i] - 'a' - key_length + 26) % 26));
            }
        } else {
            decrypted_message[i] = message[i];
        }
    }

    decrypted_message[length] = '\0';
    return decrypted_message;
}

int main() {
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter key: ");
    fgets(key, MAX_LENGTH, stdin);

    char *encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char *decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}