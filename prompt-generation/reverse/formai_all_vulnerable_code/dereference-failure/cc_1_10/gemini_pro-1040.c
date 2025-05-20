//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// We're going on a data-scouting adventure with our cipher crew!
#define CIPHER_PARTY 1

// Our secret weapon: the versatile Vigenere cipher
#define CIPHER_TYPE VIGENERE

// Shhh, it's a secret! Our encryption key
#define KEY "ULTRA_SECRET"

// Cryptography is like a culinary masterpiece—it needs the right ingredients
char* encrypt(char* plaintext) {
    char* ciphertext = malloc(strlen(plaintext) + 1);
    int i, j;
    for (i = 0, j = 0; plaintext[i] != '\0'; i++, j++) {
        int key_idx = j % strlen(KEY);
        ciphertext[i] = (plaintext[i] + KEY[key_idx] - 2 * 'A') % 26 + 'A';
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

// Deciphering the secrets: let's crack the code!
char* decrypt(char* ciphertext) {
    char* plaintext = malloc(strlen(ciphertext) + 1);
    int i, j;
    for (i = 0, j = 0; ciphertext[i] != '\0'; i++, j++) {
        int key_idx = j % strlen(KEY);
        plaintext[i] = (ciphertext[i] - KEY[key_idx] + 26) % 26 + 'A';
    }
    plaintext[i] = '\0';
    return plaintext;
}

// Our mission control: coordinating the encryption and decryption operations
int main() {
    printf("Welcome to the Cipher Squadron, where data privacy takes flight! 🚀\n");

    // Let's grab a message from our adventurous user
    printf("Transmit your message, intrepid explorer: ");
    char plaintext[100];
    fgets(plaintext, 100, stdin);

    // Time to encrypt the message using our trusty Vigenere cipher
    printf("Encrypting your message like a master cryptographer... 🔒\n");
    char* ciphertext = encrypt(plaintext);

    // Displaying the encrypted message to our eager user
    printf("Behold, the encrypted treasure: %s\n✨", ciphertext);

    // And now, let's unlock the secrets with our decryption algorithm
    printf("Deciphering the encrypted message like a code-breaking ninja... 🥷\n");
    char* decryptedText = decrypt(ciphertext);

    // Presenting the decrypted message to our curious user
    printf("Ta-da! Your decrypted message is: %s\n🎉", decryptedText);

    // Freeing the memory allocated for our encrypted and decrypted messages
    free(ciphertext);
    free(decryptedText);

    printf("Mission complete, Cipher Squadron signing off! 🖖\n");
    return 0;
}