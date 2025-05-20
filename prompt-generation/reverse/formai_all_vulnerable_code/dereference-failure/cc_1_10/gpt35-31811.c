//FormAI DATASET v1.0 Category: Modern Encryption ; Style: dynamic
/* Dynamic Modern Encryption example program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

/* Function to encrypt a string using a dynamically generated key */
char* encryptString(char* message) {

    // Generate the encryption key
    char key[MAX_SIZE];
    int key_len = strlen(message);
    for (int i = 0; i < key_len; i++) {
        key[i] = (char) (rand() % 26 + 'a');
    }
    key[key_len] = '\0';

    // Encrypt the message
    char* encrypted_message = malloc(sizeof(char) * MAX_SIZE);
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = (char) (((message[i] - 'a' + key[i] - 'a') % 26) + 'a');
    }
    encrypted_message[strlen(message)] = '\0';

    // Combine the key and encrypted message as a single string
    char* full_message = malloc(sizeof(char) * MAX_SIZE);
    strcpy(full_message, key);
    strcat(full_message, encrypted_message);

    return full_message;
}

/* Function to decrypt a string using the key extracted from it */
char* decryptString(char* message) {

    // Extract the key from the message
    char key[MAX_SIZE];
    int key_len = strlen(message) / 2;
    strncpy(key, message, key_len);
    key[key_len] = '\0';

    // Decrypt the message
    char* decrypted_message = malloc(sizeof(char) * MAX_SIZE);
    for (int i = 0; i < strlen(message) / 2; i++) {
        decrypted_message[i] = (char) ((((message[i + key_len] - 'a') - (key[i] - 'a') + 26) % 26) + 'a');
    }
    decrypted_message[strlen(message) / 2] = '\0';

    return decrypted_message;
}

int main() {

    char message[MAX_SIZE];
    printf("Please enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    // Remove newline character from the end of the input string
    message[strcspn(message, "\n")] = 0;

    // Encrypt the message
    char* encrypted_message = encryptString(message);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char* decrypted_message = decryptString(encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    // Free memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}