//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1000

// Function to shift the character by the given amount
char shift(char c, int amount) {
    char result = (char) (c + amount);
    if (result > 'z') {
        result -= 26;
    } else if (result < 'a') {
        result += 26;
    }
    return result;
}

// Function to encrypt the message using the given key
void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    // Validate the key length
    if (key_length > MAX_KEY_LENGTH) {
        fprintf(stderr, "Error: Key length should not exceed %d characters.\n", MAX_KEY_LENGTH);
        exit(1);
    }

    // Validate the message length
    if (message_length > MAX_MESSAGE_LENGTH) {
        fprintf(stderr, "Error: Message length should not exceed %d characters.\n", MAX_MESSAGE_LENGTH);
        exit(1);
    }

    // Create a new string to store the encrypted message
    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypted_message[0] = '\0';

    // Encrypt the message character by character
    for (i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int index = tolower(key[i % key_length]) - 'a';
            if (index >= 0 && index < 26) {
                c = shift(c, index);
            } else {
                fprintf(stderr, "Error: Invalid key character at position %d.\n", i);
                exit(1);
            }
        }
        strcat(encrypted_message, c);
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove the newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Get the key from the user
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove the newline character from the key
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message using the given key
    encrypt(message, key);

    return 0;
}