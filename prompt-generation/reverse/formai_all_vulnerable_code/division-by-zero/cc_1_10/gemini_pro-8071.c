//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
// Ada Lovelace's Encryption Engine

// Greetings, esteemed patrons! I present to thee an encryption engine of my own design.

// First, let us gather the necessary components:
#include <stdio.h>
#include <stdlib.h>

// A key to guide our encryption and decryption endeavors:
char key[100];

// The plaintext, waiting to be transformed:
char plaintext[100];

// The ciphertext, the encrypted form of our plaintext:
char ciphertext[100];

// Now, let the encryption ceremony commence!
void encrypt() {
    int i, key_length;

    // Obtain the length of the key:
    key_length = strlen(key);

    // Iterate through each character of the plaintext:
    for (i = 0; plaintext[i] != '\0'; i++) {
        // Perform the encryption using the key:
        ciphertext[i] = plaintext[i] ^ key[(i % key_length)];
    }

    // Terminate the ciphertext:
    ciphertext[i] = '\0';
}

// And now, the decryption ritual to unveil the hidden plaintext:
void decrypt() {
    int i, key_length;

    // Obtain the length of the key:
    key_length = strlen(key);

    // Iterate through each character of the ciphertext:
    for (i = 0; ciphertext[i] != '\0'; i++) {
        // Perform the decryption using the key:
        plaintext[i] = ciphertext[i] ^ key[(i % key_length)];
    }

    // Terminate the plaintext:
    plaintext[i] = '\0';
}

// A grand entrance for our user interaction:
void user_interface() {
    // Greet our esteemed user:
    printf("Welcome to the Ada Lovelace Encryption Engine!\n");

    // Prompt for the key:
    printf("Enter your encryption key: ");
    scanf("%s", key);

    // Prompt for the plaintext:
    printf("Enter the plaintext to be encrypted: ");
    scanf("%s", plaintext);

    // Invoke the encryption ceremony:
    encrypt();

    // Display the encrypted ciphertext:
    printf("Behold, the ciphertext: %s\n", ciphertext);

    // Prompt for the ciphertext:
    printf("Enter the ciphertext to be decrypted: ");
    scanf("%s", ciphertext);

    // Invoke the decryption ritual:
    decrypt();

    // Reveal the decrypted plaintext:
    printf("And the decrypted plaintext is: %s\n", plaintext);
}

// The grand finale:
int main() {
    // Engage the user interface:
    user_interface();

    return 0;
}