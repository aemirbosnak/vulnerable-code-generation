//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key of given length
char* generate_key(int length) {
    char* key = (char*) malloc(length * sizeof(char));
    srand(time(NULL));  // seed random number generator
    for (int i=0; i<length; i++) {
        key[i] = (rand() % 256);  // generate a random byte value
    }
    return key;
}

// Function to perform encryption using one-time pad technique
char* encrypt(char* message, char* key, int length) {
    char* ciphertext = (char*) malloc(length * sizeof(char));
    for (int i=0; i<length; i++) {
        ciphertext[i] = message[i] ^ key[i];  // perform XOR operation
    }
    return ciphertext;
}

// Function to perform decryption using one-time pad technique
char* decrypt(char* ciphertext, char* key, int length) {
    char* message = (char*) malloc(length * sizeof(char));
    for (int i=0; i<length; i++) {
        message[i] = ciphertext[i] ^ key[i];  // perform XOR operation
    }
    return message;
}

int main() {
    char* message = "Hello world";  // plaintext message to be encrypted
    int length = strlen(message);
    
    char* key = generate_key(length);  // generate and print the key
    printf("Generated key: ");
    for (int i=0; i<length; i++) {
        printf("%x", key[i]);
    }
    printf("\n");
    
    char* ciphertext = encrypt(message, key, length);  // encrypt and print the ciphertext
    printf("Ciphertext: ");
    for (int i=0; i<length; i++) {
        printf("%x", ciphertext[i]);
    }
    printf("\n");
    
    char* decrypted = decrypt(ciphertext, key, length);  // decrypt and print the original message
    printf("Decrypted message: %s\n", decrypted);
    
    free(key);
    free(ciphertext);
    free(decrypted);
    
    return 0;
}