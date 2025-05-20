//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* message, char* key) {
    int i, j, key_index = 0;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) ((int) message[i] + (int) key[key_index]);
            if (encrypted_message[i] > 'z') {
                encrypted_message[i] -= 26;
            }
            else if (encrypted_message[i] < 'a') {
                encrypted_message[i] += 26;
            }
            key_index = (key_index + 1) % strlen(key);
        }
        else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int i, j, key_index = 0;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            decrypted_message[i] = (char) ((int) message[i] - (int) key[key_index]);
            if (decrypted_message[i] < 'a') {
                decrypted_message[i] += 26;
            }
            else if (decrypted_message[i] > 'z') {
                decrypted_message[i] -= 26;
            }
            key_index = (key_index + 1) % strlen(key);
        }
        else {
            decrypted_message[i] = message[i];
        }
    }

    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}