//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constant values for encryption and decryption
const int MAX = 1000;
const int KEY = 3;

// function prototypes
char* encrypt(char* message);
char* decrypt(char* message);

// main function
int main() {
    char message[MAX];
    
    printf("Enter your message to encrypt: ");
    fgets(message, MAX, stdin);
    
    printf("\nEncrypting message...");
    char* encrypted_message = encrypt(message);
    printf("\nEncrypted message: %s", encrypted_message);
    
    printf("\nDecrypting message...");
    char* decrypted_message = decrypt(encrypted_message);
    printf("\nDecrypted message: %s", decrypted_message);
    
    free(encrypted_message);
    free(decrypted_message);
    
    return 0;
}

// function to encrypt a message with caesar cipher
char* encrypt(char* message) {
    char* encrypted_message = (char*)malloc(sizeof(char) * MAX);
    int length = strlen(message);
    
    for (int i = 0; i < length; i++) {
        if (message[i] != ' ') {
            int ascii = ((int)message[i] + KEY - 65) % 26 + 65;
            encrypted_message[i] = (char)ascii;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    
    return encrypted_message;
}

// function to decrypt a message encrypted with caesar cipher
char* decrypt(char* message) {
    char* decrypted_message = (char*)malloc(sizeof(char) * MAX);
    int length = strlen(message);
    
    for (int i = 0; i < length; i++) {
        if (message[i] != ' ') {
            int ascii = ((int)message[i] - KEY - 65 + 26) % 26 + 65;
            decrypted_message[i] = (char)ascii;
        } else {
            decrypted_message[i] = message[i];
        }
    }
    
    return decrypted_message;
}