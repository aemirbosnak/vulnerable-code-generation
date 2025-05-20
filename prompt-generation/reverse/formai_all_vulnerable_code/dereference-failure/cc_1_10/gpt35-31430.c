//FormAI DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform mod operation which supports negative integers
int mod(int a, int b) {
    return (a % b + b) % b;
}

// Function to perform Caesar Cipher Encryption
char* caesarCipherEncrypt(char* plainText, int key) {
    int length = strlen(plainText);
    char* cipherText = (char*) malloc((length + 1) * sizeof(char));
    for(int i = 0; i < length; i++) {
        // Only uppercase and lowercase alphabets are encrypted
        if(plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = ((plainText[i] - 'a') + key) % 26 + 'a';
        } else if(plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = ((plainText[i] - 'A') + key) % 26 + 'A';
        } else {
            cipherText[i] = plainText[i];
        }
    }
    cipherText[length] = '\0';
    return cipherText;
}

// Function to perform Vigenere Cipher Encryption
char* vigenereCipherEncrypt(char* plainText, char* key) {
    int length = strlen(plainText);
    int keyLength = strlen(key);
    char* cipherText = (char*) malloc((length + 1) * sizeof(char));
    for(int i = 0; i < length; i++) {
        // Only uppercase and lowercase alphabets are encrypted
        if(plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = mod((plainText[i] - 'a' + key[i % keyLength] - 'a'), 26) + 'a';
        } else if(plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = mod((plainText[i] - 'A' + key[i % keyLength] - 'A'), 26) + 'A';
        } else {
            cipherText[i] = plainText[i];
        }
    }
    cipherText[length] = '\0';
    return cipherText;
}

int main() {
    char plainText[100];
    char key[100];
    int choice, keyInt;
    char* cipherText;
    printf("Enter a string to encrypt: ");
    fgets(plainText, 100, stdin);
    printf("Enter the encryption technique to use:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter the key (an integer): ");
            scanf("%d", &keyInt);
            cipherText = caesarCipherEncrypt(plainText, keyInt);
            printf("Encrypted string: %s", cipherText);
            break;
        case 2:
            printf("Enter the key (a string): ");
            scanf("%s", key);
            cipherText = vigenereCipherEncrypt(plainText, key);
            printf("Encrypted string: %s", cipherText);
            break;
        default:
            printf("Invalid choice. Please choose a valid encryption technique.");
    }
    free(cipherText);
    return 0;
}