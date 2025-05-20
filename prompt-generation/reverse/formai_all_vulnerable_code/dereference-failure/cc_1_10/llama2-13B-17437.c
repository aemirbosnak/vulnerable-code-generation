//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

void encryption(char *message, char *key);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int i, j, k;

    printf("Welcome to the C encryption program!\n");

    // Prompt user for message and key
    printf("Enter your message (up to %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[MAX_MESSAGE_LENGTH - 1] = '\0'; // Truncate excess input

    printf("Enter your encryption key (up to %d characters): ", MAX_KEY_LENGTH);
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[MAX_KEY_LENGTH - 1] = '\0'; // Truncate excess input

    // Encrypt the message
    encryption(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}

void encryption(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j, k;

    // Create a randomized substitution cipher
    for (i = 0; i < 256; i++) {
        char random_char = (char) (i % 9 + 'A'); // Substitute each letter with a random letter within the range A-Z
        key[i] = random_char;
    }

    for (i = 0; i < message_length; i++) {
        char current_char = message[i];
        int index = current_char - 'A';
        if (index >= 0 && index < key_length) {
            char substitute_char = key[index];
            message[i] = substitute_char;
        } else {
            message[i] = current_char;
        }
    }
}