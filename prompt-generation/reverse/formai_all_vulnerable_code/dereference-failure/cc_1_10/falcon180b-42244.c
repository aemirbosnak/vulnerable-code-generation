//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 100
#define ALPHABET_LENGTH 26

/* Function to generate a random key of length 'key_length' */
void generate_key(char *key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % ALPHABET_LENGTH + 'a';
    }
    key[key_length] = '\0';
}

/* Function to encrypt the message using the given key */
void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            int offset = (int)key[j] - 'A';
            if (isalpha(message[i])) {
                message[i] = (char)(((message[i] - 'A') + offset) % 26 + 'A');
            }
        }
        j = (j + 1) % strlen(key);
    }
}

/* Function to decrypt the message using the given key */
void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            int offset = (int)key[j] - 'A';
            if (isalpha(message[i])) {
                message[i] = (char)(((message[i] - 'A') - offset + 26) % 26 + 'A');
            }
        }
        j = (j + 1) % strlen(key);
    }
}

/* Function to generate a random message of length'message_length' */
void generate_message(char *message, int message_length) {
    int i;
    for (i = 0; i < message_length; i++) {
        message[i] = rand() % 26 + 'a';
    }
    message[message_length] = '\0';
}

/* Function to print the key and message in a formatted way */
void print_key_message(char *key, char *message) {
    printf("Key: ");
    int i;
    for (i = 0; i < strlen(key); i++) {
        printf("%c ", key[i]);
    }
    printf("\nMessage: %s\n", message);
}

int main() {
    srand(time(NULL));
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int message_length;
    printf("Enter the message length (maximum %d): ", MAX_MESSAGE_LENGTH);
    scanf("%d", &message_length);
    generate_key(key, strlen(key));
    generate_message(message, message_length);
    encrypt(message, key);
    printf("Encrypted message: ");
    print_key_message(key, message);
    decrypt(message, key);
    printf("Decrypted message: ");
    print_key_message(key, message);
    return 0;
}