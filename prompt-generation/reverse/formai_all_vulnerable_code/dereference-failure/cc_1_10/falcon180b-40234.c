//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16

void generate_key(char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *message, char *key) {
    char encrypted_message[1000];
    encrypted_message[0] = '\0';

    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int index = c - 'a';
            encrypted_message[i] = key[(index + (int)key[0] - 97) % KEY_SIZE];
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    char decrypted_message[1000];
    decrypted_message[0] = '\0';

    for (int i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = tolower(encrypted_message[i]);
            int index = c - 'a';
            int key_index = (index - (int)key[0] + 97) % KEY_SIZE;
            char decrypted_char = key[key_index];
            decrypted_message[i] = decrypted_char;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    char key[KEY_SIZE];

    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    generate_key(key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}