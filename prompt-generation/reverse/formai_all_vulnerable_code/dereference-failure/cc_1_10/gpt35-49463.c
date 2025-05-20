//FormAI DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

int main() {
    char message[1000];
    int key, choice;

    printf("Enter a message to encrypt/decrypt (max 1000 characters):\n");
    fgets(message, 1000, stdin);

    do {
        printf("\nWould you like to:\n");
        printf("1. Encrypt the message\n");
        printf("2. Decrypt the message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a key for encryption: ");
                scanf("%d", &key);
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the key for decryption: ");
                scanf("%d", &key);
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void encrypt(char *plaintext, int key) {
    int i, len = strlen(plaintext);
    char encrypted[len];

    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) { // only encrypt alphabetic characters
            if (isupper(plaintext[i])) {// encrypt uppercase character
                encrypted[i] = ((int) plaintext[i] - 65 + key) % 26 + 65;
            } else { // encrypt lowercase character
                encrypted[i] = ((int) plaintext[i] - 97 + key) % 26 + 97;
            }
        } else { // leave non-alphabetic characters unencrypted
            encrypted[i] = plaintext[i];
        }
    }

    strcpy(plaintext, encrypted);
}

void decrypt(char *ciphertext, int key) {
    int i, len = strlen(ciphertext);
    char decrypted[len];

    for (i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) { // only decrypt alphabetic characters
            if (isupper(ciphertext[i])) { // decrypt uppercase character
                decrypted[i] = ((int) ciphertext[i] - 65 - key + 26) % 26 + 65;
            } else { // decrypt lowercase character
                decrypted[i] = ((int) ciphertext[i] - 97 - key + 26) % 26 + 97;
            }
        } else { // leave non-alphabetic characters decrypted
            decrypted[i] = ciphertext[i];
        }
    }

    strcpy(ciphertext, decrypted);
}