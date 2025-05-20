//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random key */
char *generate_key(int key_length) {
    char *key = malloc((key_length+1)*sizeof(char)); // Allocate enough memory for the key
    int i;

    // Use current time as seed for random number generator
    srand((unsigned int) time(NULL)); 

    // Fill key with random characters
    for(i=0; i<key_length; i++) {
        key[i] = (rand() % 26) + 'A'; // Generate a random uppercase letter
    }
    key[i] = '\0'; // Add null terminator

    return key;
}

/* Function to encrypt a string */
char *encrypt(char *plaintext, char *key) {
    int i;
    int plaintext_length = strlen(plaintext);
    char *ciphertext = malloc((plaintext_length+1)*sizeof(char)); // Allocate enough memory for the ciphertext

    // Encrypt each character
    for(i=0; i<plaintext_length; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') + (key[i%strlen(key)] - 'A')) % 26 + 'A';
    }
    ciphertext[i] = '\0'; // Add null terminator

    return ciphertext;
}

/* Function to decrypt a string */
char *decrypt(char *ciphertext, char *key) {
    int i;
    int ciphertext_length = strlen(ciphertext);
    char *plaintext = malloc((ciphertext_length+1)*sizeof(char)); // Allocate enough memory for the plaintext

    // Decrypt each character
    for(i=0; i<ciphertext_length; i++) {
        plaintext[i] = ((ciphertext[i] - 'A') - (key[i%strlen(key)] - 'A'));
        if(plaintext[i] < 0) plaintext[i] += 26; // Handle wraparound
        plaintext[i] += 'A'; // Convert back to character
    }
    plaintext[i] = '\0'; // Add null terminator

    return plaintext;
}

int main() {
    char *key = generate_key(10); // Generate a random key of length 10
    char *plaintext = "HELLO WORLD"; // The message to encrypt
    char *ciphertext = encrypt(plaintext, key); // Encrypt the message
    char *decrypted_plaintext = decrypt(ciphertext, key); // Decrypt the ciphertext

    // Print out the results
    printf("Key: %s\n", key);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free memory
    free(key);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}