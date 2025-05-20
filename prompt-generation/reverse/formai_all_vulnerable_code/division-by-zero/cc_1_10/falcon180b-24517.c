//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1000

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_SIZE];

    if (message_length > MAX_MESSAGE_SIZE) {
        printf("Error: Message is too long.\n");
        exit(1);
    }

    int i = 0;
    for (int j = 0; j < message_length; j++) {
        char message_char = message[j];
        char key_char = key[i % key_length];

        if (isalpha(message_char)) {
            if (isupper(message_char)) {
                encrypted_message[j] = (char) (((int) message_char + (int) key_char - 65) % 26 + 65);
            } else {
                encrypted_message[j] = (char) (((int) message_char + (int) key_char - 97) % 26 + 97);
            }
        } else {
            encrypted_message[j] = message_char;
        }

        i++;
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_SIZE];

    if (message_length > MAX_MESSAGE_SIZE) {
        printf("Error: Message is too long.\n");
        exit(1);
    }

    int i = 0;
    for (int j = 0; j < message_length; j++) {
        char message_char = message[j];
        char key_char = key[i % key_length];

        if (isalpha(message_char)) {
            if (isupper(message_char)) {
                int decrypted_char = (int) message_char - (int) key_char + 65;
                if (decrypted_char < 65) {
                    decrypted_char += 26;
                }
                decrypted_message[j] = (char) decrypted_char;
            } else {
                int decrypted_char = (int) message_char - (int) key_char + 97;
                if (decrypted_char < 97) {
                    decrypted_char += 26;
                }
                decrypted_message[j] = (char) decrypted_char;
            }
        } else {
            decrypted_message[j] = message_char;
        }

        i++;
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_MESSAGE_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_MESSAGE_SIZE, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}