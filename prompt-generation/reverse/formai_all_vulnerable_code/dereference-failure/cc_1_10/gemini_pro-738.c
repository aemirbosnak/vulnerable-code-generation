//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption key
const char key[] = "This is a secret key";

// Define the encryption function
char* encrypt(char* plaintext) {
    // Allocate memory for the ciphertext
    char* ciphertext = (char*)malloc(strlen(plaintext) + 1);

    // Encrypt the plaintext using XOR encryption
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Define the decryption function
char* decrypt(char* ciphertext) {
    // Allocate memory for the plaintext
    char* plaintext = (char*)malloc(strlen(ciphertext) + 1);

    // Decrypt the ciphertext using XOR encryption
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }

    // Terminate the plaintext with a null character
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    gets(plaintext);

    // Encrypt the plaintext
    char* ciphertext = encrypt(plaintext);

    // Print the ciphertext to the console
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext
    char* decryptedText = decrypt(ciphertext);

    // Print the decrypted text to the console
    printf("The decrypted text is: %s\n", decryptedText);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedText);

    // Return 0 to indicate successful execution
    return 0;
}