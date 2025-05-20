//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int message_length;
    int key_length;
    int i, j;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // Get key from user
    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    // Encrypt message using Caesar cipher
    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            if (isalpha(message[i])) {
                j = (message[i] - 'A') + (key[i % key_length] - 'A');
                if (j > 25) {
                    j = j - 26;
                } else if (j < 0) {
                    j = j + 26;
                }
                encrypted_message[i] = j + 'A';
            } else {
                encrypted_message[i] = message[i];
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}