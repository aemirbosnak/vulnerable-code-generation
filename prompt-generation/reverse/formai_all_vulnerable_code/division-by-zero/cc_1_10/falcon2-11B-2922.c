//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
void encrypt(char* plaintext, char* key, char* ciphertext) {
    // Get the length of the plaintext
    int plaintextLen = strlen(plaintext);

    // Get the length of the key
    int keyLen = strlen(key);

    // Generate a random number
    int randomNum = rand() % keyLen;

    // Shift the plaintext characters based on the random number
    for (int i = 0; i < plaintextLen; i++) {
        int plaintextChar = plaintext[i] - 'A';
        int shiftedChar = plaintextChar + randomNum;

        // Wrap around if the shifted character exceeds the range of lowercase letters
        if (shiftedChar > 26) {
            shiftedChar -= 26;
        }

        // Convert the shifted character back to a character
        ciphertext[i] = shiftedChar + 'A';
    }
}

int main() {
    // Get the plaintext and key from the user
    char plaintext[100];
    char key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Convert the key to lowercase
    for (int i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }

    // Encrypt the plaintext using the key
    char ciphertext[100];
    encrypt(plaintext, key, ciphertext);

    // Print the encrypted text
    printf("The encrypted text is: %s\n", ciphertext);

    return 0;
}