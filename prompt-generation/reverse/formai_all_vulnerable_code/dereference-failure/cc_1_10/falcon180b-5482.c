//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define KEY 13

// Function to encrypt the message
void encrypt(char* message) {
    int i, j, k = 0;
    char* encrypted_message = (char*)malloc(MAX_LENGTH);
    memset(encrypted_message, 0, MAX_LENGTH);

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[k] = message[i] + KEY;
                if (encrypted_message[k] > 'Z') {
                    encrypted_message[k] = encrypted_message[k] - 26;
                }
            } else {
                encrypted_message[k] = message[i] + KEY;
                if (encrypted_message[k] > 'z') {
                    encrypted_message[k] = encrypted_message[k] - 26;
                }
            }
            k++;
        } else {
            encrypted_message[k] = message[i];
            k++;
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* message) {
    int i, j, k = 0;
    char* decrypted_message = (char*)malloc(MAX_LENGTH);
    memset(decrypted_message, 0, MAX_LENGTH);

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[k] = message[i] - KEY;
                if (decrypted_message[k] < 'A') {
                    decrypted_message[k] = decrypted_message[k] + 26;
                }
            } else {
                decrypted_message[k] = message[i] - KEY;
                if (decrypted_message[k] < 'a') {
                    decrypted_message[k] = decrypted_message[k] + 26;
                }
            }
            k++;
        } else {
            decrypted_message[k] = message[i];
            k++;
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char* message;
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Encrypted message:\n");
    encrypt(message);

    printf("\nDecrypted message:\n");
    decrypt(message);

    return 0;
}