//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A function to encrypt a character using a Caesar cipher
char encrypt(char c, int key) {
    int encryptedChar = (int)c + key;

    // Handle the case when the encrypted character goes beyond 'z'
    if (encryptedChar > 'z') {
        encryptedChar -= 26;
    }

    return (char)encryptedChar;
}

// A function to decrypt a character using a Caesar cipher
char decrypt(char c, int key) {
    int decryptedChar = (int)c - key;

    // Handle the case when the decrypted character goes below 'a'
    if (decryptedChar < 'a') {
        decryptedChar += 26;
    }

    return (char)decryptedChar;
}

// A function to encrypt a string using a Caesar cipher
char* encryptString(char* str, int key) {
    int strLen = strlen(str);
    char* encryptedStr = malloc(strLen + 1);

    for (int i = 0; i < strLen; i++) {
        encryptedStr[i] = encrypt(str[i], key);
    }

    encryptedStr[strLen] = '\0';

    return encryptedStr;
}

// A function to decrypt a string using a Caesar cipher
char* decryptString(char* str, int key) {
    int strLen = strlen(str);
    char* decryptedStr = malloc(strLen + 1);

    for (int i = 0; i < strLen; i++) {
        decryptedStr[i] = decrypt(str[i], key);
    }

    decryptedStr[strLen] = '\0';

    return decryptedStr;
}

int main() {
    // The secret message that we want to encrypt
    char* message = "I love you, my dearest.";

    // The encryption key
    int key = 3;

    // Encrypt the message
    char* encryptedMessage = encryptString(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the encrypted message
    char* decryptedMessage = decryptString(encryptedMessage, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}