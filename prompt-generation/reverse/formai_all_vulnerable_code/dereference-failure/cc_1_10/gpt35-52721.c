//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function declarations
char* encrypt(char*, int);
char* decrypt(char*, int);

// Main function
int main() {
    printf("Enter a message to be encrypted: ");
    char message[100];
    fgets(message, sizeof(message), stdin);

    printf("Enter a key for encryption: ");
    int key;
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}

// Function to encrypt the message using the key
char* encrypt(char* message, int key) {
    int length = strlen(message);

    // Allocate memory for the encrypted message
    char* encrypted = malloc(length * sizeof(char));

    // Loop through the message and apply the encryption algorithm
    for (int i = 0; i < length; i++) {
        if (message[i] == '\n') {
            encrypted[i] = '\n';
            break;
        }

        // Generate a key for this character based on the index
        int char_key = key + i;

        // Generate a random number between 1 and 10 to mask the character
        int mask_num = rand() % 10 + 1;

        // Apply the encryption algorithm
        int encrypted_char = ((int)message[i] * char_key) + mask_num;

        // Convert the encrypted character back to a character and store it
        encrypted[i] = (char)encrypted_char;
    }

    return encrypted;
}

// Function to decrypt the message using the key
char* decrypt(char* encrypted, int key) {
    int length = strlen(encrypted);

    // Allocate memory for the decrypted message
    char* decrypted = malloc(length * sizeof(char));

    // Loop through the message and apply the decryption algorithm
    for (int i = 0; i < length; i++) {
        if (encrypted[i] == '\n') {
            decrypted[i] = '\n';
            break;
        }

        // Generate a key for this character based on the index
        int char_key = key + i;

        // Extract the mask number from the encrypted character
        int mask_num = ((int)encrypted[i] % 10) + 1;

        // Apply the decryption algorithm
        int decrypted_char = ((int)encrypted[i] - mask_num) / char_key;

        // Convert the decrypted character back to a character and store it
        decrypted[i] = (char)decrypted_char;
    }

    return decrypted;
}