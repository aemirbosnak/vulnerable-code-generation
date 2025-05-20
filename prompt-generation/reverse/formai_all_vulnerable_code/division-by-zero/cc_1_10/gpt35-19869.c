//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 128

void encrypt(char *input, char *key, char *output);
void decrypt(char *input, char *key, char *output);

int main() {
    char input[MAX_STRING_LENGTH];
    char key[MAX_STRING_LENGTH];
    char output[MAX_STRING_LENGTH];
    
    printf("Enter string to encrypt: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    printf("Enter encryption key: ");
    fgets(key, MAX_STRING_LENGTH, stdin);
    
    // Remove newline characters from input and key
    input[strcspn(input, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    // Encrypt input using key
    encrypt(input, key, output);
    
    printf("Encrypted string: %s\n", output);
    
    // Decrypt output using key
    decrypt(output, key, input);
    
    printf("Decrypted string: %s\n", input);
    
    return 0;
}

void encrypt(char *input, char *key, char *output) {
    // Cyberpunk-style encryption algorithm
    int input_len = strlen(input);
    int key_len = strlen(key);
    
    for (int i = 0; i < input_len; i++) {
        output[i] = input[i] + key[i % key_len];
        output[i] %= 128;  // limit output to ASCII character set
    }
}

void decrypt(char *input, char *key, char *output) {
    // Cyberpunk-style decryption algorithm
    int input_len = strlen(input);
    int key_len = strlen(key);
    
    for (int i = 0; i < input_len; i++) {
        output[i] = input[i] - key[i % key_len];
        output[i] %= 128;  // limit output to ASCII character set
    }
}