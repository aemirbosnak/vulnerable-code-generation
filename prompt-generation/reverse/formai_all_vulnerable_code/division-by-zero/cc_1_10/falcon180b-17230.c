//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256

int main() {
    char message[1000];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[1000];
    char decrypted_message[1000];
    int message_length, key_length, i, j, k;

    // Get message input from user
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    message_length = strlen(message);

    // Get key input from user
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    // Encrypt message using key
    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char letter = tolower(message[i]);
            char key_letter = tolower(key[j % key_length]);
            int offset = (int) (key_letter - 'a');
            encrypted_message[i] = (char) (((letter - 'a' + offset) % 26) + 'a');
            j++;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[message_length] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message using key
    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = tolower(encrypted_message[i]);
            char key_letter = tolower(key[j % key_length]);
            int offset = (int) (key_letter - 'a');
            decrypted_message[i] = (char) (((letter - 'a' - offset + 26) % 26) + 'a');
            j++;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[message_length] = '\0';

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}