//Falcon-180B DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH] = {0};
    int encrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int shift = (int) key[i % key_length] - 65;
            if (isupper(c)) {
                c = (char) (((c - 65) + shift) % 26 + 65);
            } else {
                c = (char) (((c - 97) + shift) % 26 + 97);
            }
        }
        encrypted_message[encrypted_message_length++] = c;
    }

    encrypted_message[encrypted_message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH] = {0};
    int decrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            int shift = (int) key[i % key_length] - 65;
            if (isupper(c)) {
                c = (char) (((c - 65) - shift + 26) % 26 + 65);
            } else {
                c = (char) (((c - 97) - shift + 26) % 26 + 97);
            }
        }
        decrypted_message[decrypted_message_length++] = c;
    }

    decrypted_message[decrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH] = {0};
    char key[MAX_KEY_LENGTH] = {0};

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}