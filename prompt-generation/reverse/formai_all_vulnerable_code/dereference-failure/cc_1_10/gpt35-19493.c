//FormAI DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_ASCII 33  // Minimum ASCII value for characters
#define MAX_ASCII 126 // Maximum ASCII value for characters
#define ENCRYPTION_KEY 7 // Encryption key, should be kept secret

// Function that encrypts a given plaintext
char* encrypt(char* plaintext) {
    srand(time(NULL)); // Initialize random number generator with current time
    int len = strlen(plaintext);
    char* ciphertext = (char*)malloc((len + 1) * sizeof(char));
    for(int i = 0; i < len; i++) {
        int ascii_val = (int)plaintext[i];
        int random_val = rand() % (MAX_ASCII - MIN_ASCII + 1) + MIN_ASCII; // Generate random number between MIN_ASCII and MAX_ASCII
        int encrypted_val = (ascii_val * ENCRYPTION_KEY + random_val) % MAX_ASCII; // Encrypt using given encryption key and random number
        ciphertext[i] = (char)encrypted_val;
    }
    ciphertext[len] = '\0'; // Add NULL terminator to end of string
    return ciphertext;
}

// Function that decrypts a given ciphertext
char* decrypt(char* ciphertext) {
    int len = strlen(ciphertext);
    char* plaintext = (char*)malloc((len + 1) * sizeof(char));
    for(int i = 0; i < len; i++) {
        int ascii_val = (int)ciphertext[i];
        int random_val = i + 1; // Use position of character as seed for random number generator
        srand(random_val);
        int decrypted_val = ((ascii_val - random_val + MAX_ASCII) / ENCRYPTION_KEY) % MAX_ASCII; // Decrypt using given encryption key and random number
        plaintext[i] = (char)decrypted_val;
    }
    plaintext[len] = '\0'; // Add NULL terminator to end of string
    return plaintext;
}

int main() {
	char input[100];

	printf("Enter a plaintext string:\n");
	fgets(input, 100, stdin); // Read input from user

	char* ciphertext = encrypt(input); // Encrypt input
	char* plaintext = decrypt(ciphertext); // Decrypt ciphertext

	printf("Plaintext: %s", input);
	printf("Ciphertext: %s", ciphertext);
	printf("Decrypted plaintext: %s", plaintext);

	free(ciphertext); // Free dynamically allocated memory
	free(plaintext);

	return 0;
}