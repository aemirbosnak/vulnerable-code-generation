//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char* plaintext, char* key, int index) {
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    
    // Base case: if index is greater than or equal to plaintext length, return
    if (index >= plaintext_length) {
        return;
    }
    
    // Recursive case: encrypt current character of plaintext
    int encrypted_char = (plaintext[index] + key[index % key_length]) % 128;
    plaintext[index] = encrypted_char;
    
    // Recursively encrypt remaining characters of plaintext
    encrypt(plaintext, key, index+1);
}

void decrypt(char* encrypted, char* key, int index) {
    int encrypted_length = strlen(encrypted);
    int key_length = strlen(key);
    
    // Base case: if index is greater than or equal to encrypted length, return
    if (index >= encrypted_length) {
        return;
    }
    
    // Recursive case: decrypt current character of encrypted text
    int decrypted_char = (encrypted[index] - key[index % key_length] + 128) % 128;
    encrypted[index] = decrypted_char;
    
    // Recursively decrypt remaining characters of encrypted text
    decrypt(encrypted, key, index+1);
}

int main() {
    // Take input plaintext and key from user
    char plaintext[MAX_LENGTH];
    char key[MAX_LENGTH];
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    printf("Enter key: ");
    fgets(key, MAX_LENGTH, stdin);
    
    // Remove newline characters from input strings
    plaintext[strcspn(plaintext, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    // Encrypt plaintext using key
    encrypt(plaintext, key, 0);
    printf("Encrypted text: %s\n", plaintext);
    
    // Decrypt encrypted text using key
    decrypt(plaintext, key, 0);
    printf("Decrypted text: %s\n", plaintext);
    
    return 0;
}