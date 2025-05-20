//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 25
#define MESSAGE_LENGTH 100

void print_usage() {
    printf("Usage: ./modern_encrypt message key\n");
    printf("Where message is the plaintext to be encrypted and key is the encryption key.\n");
    printf("This program uses Chili Cheese Modern Encryption, a highly secure and delicious encryption algorithm.\n");
}

void check_args(int argc, char** argv) {
    if (argc != 3) {
        print_usage();
        exit(1);
    }

    if (strlen(argv[1]) > MESSAGE_LENGTH || strlen(argv[2]) > KEY_LENGTH) {
        printf("Error: message and key must be less than %d and %d characters respectively.\n", MESSAGE_LENGTH, KEY_LENGTH);
        exit(1);
    }
}

void encrypt(char* message, char* key) {
    int i, j;
    char encrypted_message[MESSAGE_LENGTH];

    for (i = 0; message[i] != '\0'; i++) {
        encrypted_message[i] = message[i];
        for (j = 0; key[j] != '\0'; j++) {
            encrypted_message[i] ^= key[j];
        }
    }

    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int i;
    char decrypted_message[MESSAGE_LENGTH];

    for (i = 0; encrypted_message[i] != '\0'; i++) {
        decrypted_message[i] = encrypted_message[i];
        for (int j = 0; key[j] != '\0'; j++) {
            decrypted_message[i] ^= key[j];
        }
    }

    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main(int argc, char** argv) {
    check_args(argc, argv);

    char* message = argv[1];
    char* key = argv[2];

    encrypt(message, key);
    char encrypted_message[MESSAGE_LENGTH];
    strcpy(encrypted_message, message);
    decrypt(encrypted_message, key);

    return 0;
}