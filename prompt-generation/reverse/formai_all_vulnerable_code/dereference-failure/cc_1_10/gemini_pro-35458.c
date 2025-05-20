//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The secret key for our super-secret encryption algorithm
int secret_key = 42;

// Our super-secret encryption function
char *encrypt(char *plaintext) {
    int plaintext_length = strlen(plaintext);
    char *ciphertext = malloc(plaintext_length + 1);
    for (int i = 0; i < plaintext_length; i++) {
        ciphertext[i] = plaintext[i] ^ secret_key;
    }
    ciphertext[plaintext_length] = '\0';
    return ciphertext;
}

// Our super-secret decryption function
char *decrypt(char *ciphertext) {
    int ciphertext_length = strlen(ciphertext);
    char *plaintext = malloc(ciphertext_length + 1);
    for (int i = 0; i < ciphertext_length; i++) {
        plaintext[i] = ciphertext[i] ^ secret_key;
    }
    plaintext[ciphertext_length] = '\0';
    return plaintext;
}

int main() {
    // A message from our top-secret agent
    char *message = "The launch codes are: 007";

    // Encrypt the message using our super-secret algorithm
    char *encrypted_message = encrypt(message);

    // Send the encrypted message to our secret lair
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message at our secret lair
    char *decrypted_message = decrypt(encrypted_message);

    // The launch codes are now safely in our hands
    printf("Decrypted message: %s\n", decrypted_message);

    // Mission accomplished!
    printf("Top-secret launch codes received. Prepare for world domination!\n");

    return 0;
}