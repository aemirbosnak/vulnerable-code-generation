//Falcon-180B DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
#define KEY 5

void encrypt(char* message, char* key) {
    int i, j;
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    char* encrypted_message = malloc(strlen(message) + 1);
    
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            for (j = 0; j < strlen(alphabet); j++) {
                if (message[i] == alphabet[j]) {
                    message[i] = alphabet[j + KEY % SIZE];
                    break;
                }
            }
        }
    }
    
    strcpy(encrypted_message, message);
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int i, j;
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    char* decrypted_message = malloc(strlen(message) + 1);
    
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            for (j = 0; j < strlen(alphabet); j++) {
                if (message[i] == alphabet[j]) {
                    message[i] = alphabet[j - KEY % SIZE];
                    break;
                }
            }
        }
    }
    
    strcpy(decrypted_message, message);
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char* message = "Hello, world!";
    char* key = "secret";
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}