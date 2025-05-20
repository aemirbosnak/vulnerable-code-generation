//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_TEXT_LENGTH = 1000;
const int MAX_KEY_LENGTH = 100;

char* encrypt(char* plainText, char* key) {
    int lenPlainText = strlen(plainText);
    int lenKey = strlen(key);
    
    char* cipherText = (char*) malloc(lenPlainText * sizeof(char));
    
    for (int i = 0; i < lenPlainText; i++) {
        cipherText[i] = (plainText[i] ^ key[i % lenKey]) + 5;
    }
    
    return cipherText;
}

char* decrypt(char* cipherText, char* key) {
    int lenCipherText = strlen(cipherText);
    int lenKey = strlen(key);
    
    char* plainText = (char*) malloc(lenCipherText * sizeof(char));
    
    for (int i = 0; i < lenCipherText; i++) {
        plainText[i] = (cipherText[i] - 5) ^ key[i % lenKey];
    }
    
    return plainText;
}

int main() {
    char plainText[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char* cipherText;
    char* decryptedText;
    
    printf("Enter the plain text: ");
    fgets(plainText, MAX_TEXT_LENGTH, stdin);
    plainText[strcspn(plainText, "\n")] = 0; // remove trailing newline
    
    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // remove trailing newline
    
    cipherText = encrypt(plainText, key);
    printf("Encrypted Text: %s\n", cipherText);
    
    decryptedText = decrypt(cipherText, key);
    printf("Decrypted Text: %s\n", decryptedText);
    
    free(cipherText);
    free(decryptedText);
    
    return 0;
}