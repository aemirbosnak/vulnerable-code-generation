//FormAI DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt the message
char* encryptMessage(char* message, char key) {
    int len = strlen(message);
    char* encrypted = (char*)malloc(len+1);
    
    srand(time(NULL));
    int random = rand() % 50;

    for(int i=0; i<len; i++){
        if(i % 2 == 0){
            encrypted[i] = message[i] + key + random;
        } else {
            encrypted[i] = message[i] + key - random;
        }
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Function to decrypt the message
char* decryptMessage(char* encrypted, char key) {
    int len = strlen(encrypted);
    char* message = (char*)malloc(len+1);

    srand(time(NULL));
    int random = rand() % 50;

    for(int i=0; i<len; i++){
        if(i % 2 == 0){
            message[i] = encrypted[i] - key - random;
        } else {
            message[i] = encrypted[i] - key + random;
        }
    }
    message[len] = '\0';
    return message;
}

int main() {
    char* message = "This is a secret message";
    char key = 'Q';

    printf("Original message: %s\n", message);

    char* encrypted = encryptMessage(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decryptMessage(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}