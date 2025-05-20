//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define MAX_KEY_LENGTH 100

void generateKey(char* key, int keySize){
    int i;
    srand(time(NULL));
    for (i = 0; i < keySize; i++) {
        key[i] = rand() % 256;
    }
    key[i] = '\0';
}

void encrypt(char* message, char* key){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] = message[i] ^ key[i % strlen(key)];
    }
}

void decrypt(char* message, char* key){
    encrypt(message, key); // decryption is exactly the same as encryption
}

int main() {
    char* message = malloc(sizeof(char) * MAX_MESSAGE_LENGTH);
    char* key = malloc(sizeof(char) * MAX_KEY_LENGTH);
    
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline character
    
    int keySize;
    printf("Enter key size (max %d): ", MAX_KEY_LENGTH);
    scanf("%d", &keySize);
    getchar(); // remove newline character from input buffer
    
    generateKey(key, keySize); // generate random key
    printf("Key: ");
    int i;
    for(i = 0; i < strlen(key); i++){
        printf("%02X ", key[i] & 0xFF); // print key as hexadecimal values
    }
    printf("\n");
    
    encrypt(message, key);
    printf("Encrypted message: ");
    for(i = 0; i < strlen(message); i++){
        printf("%02X ", message[i] & 0xFF); // print encrypted message as hexadecimal values
    }
    printf("\n");
    
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    
    free(message);
    free(key);
    
    return 0;
}