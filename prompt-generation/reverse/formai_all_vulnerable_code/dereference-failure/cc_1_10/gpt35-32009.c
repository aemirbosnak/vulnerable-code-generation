//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to implement Caesar Cipher
char *caesar_cipher(char *plaintext, int key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    int len = strlen(plaintext);
    int i;

    for (i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Function to implement Vigenere Cipher
char *vigenere_cipher(char *plaintext, char *key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    int keylen = strlen(key);
    int len = strlen(plaintext);
    int i, j;

    for (i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + key[i%keylen] - 'a') % 26;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + key[i%keylen] - 'a') % 26;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

int main() {
    char plaintext[100], key[100], option;
    int key_value;

    printf("Welcome to the Cryptography Program!\n");
    printf("Please choose a cryptography algorithm:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    
    do {
        printf("Enter your option (1 or 2): ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                printf("Enter your plaintext: ");
                scanf(" %[^\n]s", plaintext);

                printf("Enter your key (an integer value): ");
                scanf("%d", &key_value);

                printf("Ciphertext: %s", caesar_cipher(plaintext, key_value));
                break;
                
            case '2':
                printf("Enter your plaintext: ");
                scanf(" %[^\n]s", plaintext);

                printf("Enter your key (a string of alphabets): ");
                scanf(" %[^\n]s", key);

                printf("Ciphertext: %s", vigenere_cipher(plaintext, key));
                break;

            default:
                printf("Invalid option, please choose again.\n");
        }
    } while (option != '1' && option != '2');
    
    return 0;
}