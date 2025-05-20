//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    char encrypted_message[MAX_SIZE];
    int i, j, k, n;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = '\0';

    // Get key from user
    printf("Enter encryption key: ");
    fgets(key, MAX_SIZE, stdin);

    // Remove newline character from key
    key[strcspn(key, "\n")] = '\0';

    // Convert key to uppercase
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt message using key
    n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = 'A' + ((message[i] - 'A' + key[i % strlen(key)]) % 26);
        } else {
            message[i] = message[i];
        }
    }

    // Convert message to uppercase
    for (i = 0; i < n; i++) {
        message[i] = toupper(message[i]);
    }

    // Display encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}