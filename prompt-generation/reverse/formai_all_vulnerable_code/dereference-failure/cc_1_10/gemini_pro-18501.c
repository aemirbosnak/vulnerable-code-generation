//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a character using a key
char encryptChar(char ch, int key) {
    return (ch + key) % 256;
}

// Function to encrypt a string using a key
char *encryptStr(char *str, int key) {
    int i;
    char *encryptedStr = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    for (i = 0; str[i] != '\0'; i++) {
        encryptedStr[i] = encryptChar(str[i], key);
    }
    encryptedStr[i] = '\0';
    return encryptedStr;
}

// Function to decrypt a character using a key
char decryptChar(char ch, int key) {
    return (ch - key + 256) % 256;
}

// Function to decrypt a string using a key
char *decryptStr(char *str, int key) {
    int i;
    char *decryptedStr = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    for (i = 0; str[i] != '\0'; i++) {
        decryptedStr[i] = decryptChar(str[i], key);
    }
    decryptedStr[i] = '\0';
    return decryptedStr;
}

// Main function
int main() {
    // Declare variables
    char str[] = "Hello, world!";
    int key = 3;
    char *encryptedStr, *decryptedStr;

    // Encrypt the string
    encryptedStr = encryptStr(str, key);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encryptedStr);

    // Decrypt the encrypted string
    decryptedStr = decryptStr(encryptedStr, key);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decryptedStr);

    // Free the allocated memory
    free(encryptedStr);
    free(decryptedStr);

    return 0;
}