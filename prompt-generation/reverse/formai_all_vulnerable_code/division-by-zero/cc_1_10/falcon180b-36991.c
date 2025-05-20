//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

int encrypt(char* message, char* key, char* result) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int result_length = 0;
    int i = 0;

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            result[result_length] = toupper(message[i]) + key[i % key_length];
            result_length++;
        } else {
            result[result_length] = message[i];
            result_length++;
        }
    }

    result[result_length] = '\0';

    return result_length;
}

int decrypt(char* message, char* key, char* result) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int result_length = 0;
    int i = 0;

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int letter_index = tolower(message[i]) - key[i % key_length];

            if (letter_index < 0) {
                letter_index += 26;
            }

            result[result_length] = letter_index % 26 + 'a';
            result_length++;
        } else {
            result[result_length] = message[i];
            result_length++;
        }
    }

    result[result_length] = '\0';

    return result_length;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    int encrypted_length = encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    int decrypted_length = decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}