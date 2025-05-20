//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An array of cipher alphabets, each representing a different key
char* cipherAlphabets[26];

// Function to generate all the cipher alphabets
void generateCipherAlphabets() {
    for (int i = 0; i < 26; i++) {
        cipherAlphabets[i] = malloc(26);
        for (int j = 0; j < 26; j++) {
            cipherAlphabets[i][j] = 'A' + (j + i) % 26;
        }
    }
}

// Function to encrypt a message using a given key
char* encrypt(char* message, int key) {
    char* encryptedMessage = malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                encryptedMessage[i] = cipherAlphabets[key][c - 'A'];
            } else {
                encryptedMessage[i] = cipherAlphabets[key][c - 'a'];
            }
        } else {
            encryptedMessage[i] = c;
        }
    }
    encryptedMessage[strlen(message)] = '\0';
    return encryptedMessage;
}

// Function to decrypt a message using a given key
char* decrypt(char* encryptedMessage, int key) {
    char* decryptedMessage = malloc(strlen(encryptedMessage) + 1);
    for (int i = 0; i < strlen(encryptedMessage); i++) {
        char c = encryptedMessage[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                for (int j = 0; j < 26; j++) {
                    if (cipherAlphabets[key][j] == c) {
                        decryptedMessage[i] = 'A' + j;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    if (cipherAlphabets[key][j] == c) {
                        decryptedMessage[i] = 'a' + j;
                        break;
                    }
                }
            }
        } else {
            decryptedMessage[i] = c;
        }
    }
    decryptedMessage[strlen(encryptedMessage)] = '\0';
    return decryptedMessage;
}

int main() {
    // Generate all the cipher alphabets
    generateCipherAlphabets();

    printf("Welcome to the esteemed establishment of cryptography, where secrets are enshrouded and mysteries unravel!\n");

    // Get the message to be encrypted from the user
    char message[100];
    printf("Enter the message you wish to conceal, esteemed client: ");
    fgets(message, sizeof(message), stdin);

    // Get the key to be used for encryption from the user
    int key;
    printf("Enter the numerical key that shall serve as the gateway to your encrypted message: ");
    scanf("%d", &key);

    // Encrypt the message using the given key
    char* encryptedMessage = encrypt(message, key);

    // Print the encrypted message
    printf("Behold, your message, now safely veiled in secrecy: %s\n", encryptedMessage);

    // Get the encrypted message to be decrypted from the user
    char encryptedMessage2[100];
    printf("Present me with the encrypted message that requires deciphering: ");
    fgets(encryptedMessage2, sizeof(encryptedMessage2), stdin);

    // Get the key to be used for decryption from the user
    int key2;
    printf("Enter the key that shall unlock the secrets concealed within the encrypted message: ");
    scanf("%d", &key2);

    // Decrypt the message using the given key
    char* decryptedMessage = decrypt(encryptedMessage2, key2);

    // Print the decrypted message
    printf("The message, now revealed in its original splendor: %s\n", decryptedMessage);

    return 0;
}