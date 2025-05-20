//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 1000
#define MAX_MESSAGE_LENGTH 1000

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int key_length, message_length;
    int i, j;

    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // Encrypt message
    for (i = 0, j = 0; i < message_length; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            encrypted_message[j++] = (char) ((int) c + (int) key[i % key_length]);
        } else if (c >= 'A' && c <= 'Z') {
            encrypted_message[j++] = (char) ((int) c + (int) key[i % key_length] - 26);
        } else {
            encrypted_message[j++] = c;
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    for (i = 0, j = 0; i < message_length; i++) {
        char c = encrypted_message[i];
        if (c >= 'a' && c <= 'z') {
            decrypted_message[j++] = (char) ((int) c - (int) key[i % key_length]);
        } else if (c >= 'A' && c <= 'Z') {
            decrypted_message[j++] = (char) ((int) c - (int) key[i % key_length] + 26);
        } else {
            decrypted_message[j++] = c;
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}