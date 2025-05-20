//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a string
char* encrypt(char* input, int key) {
    // Initialize output string
    char* output = (char*) malloc(strlen(input) * sizeof(char));
    
    // Iterate through input string
    for (int i = 0; i < strlen(input); i++) {
        // XOR the ASCII value of the character with the key
        int asciiValue = input[i] - '0';
        output[i] = (char) (asciiValue ^ key);
    }
    
    // Return the encrypted string
    return output;
}

// Function to decrypt an encrypted string
char* decrypt(char* input, int key) {
    // Initialize output string
    char* output = (char*) malloc(strlen(input) * sizeof(char));
    
    // Iterate through input string
    for (int i = 0; i < strlen(input); i++) {
        // XOR the ASCII value of the character with the key
        int asciiValue = input[i] - '0';
        output[i] = (char) (asciiValue ^ key);
    }
    
    // Return the decrypted string
    return output;
}

int main() {
    // Example usage
    char* input = "Hello, World!";
    int key = 5;
    
    printf("Input: %s\n", input);
    
    char* encrypted = encrypt(input, key);
    printf("Encrypted: %s\n", encrypted);
    
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted: %s\n", decrypted);
    
    // Free memory
    free(encrypted);
    free(decrypted);
    
    return 0;
}