//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using a shift cipher
char *shift_encryption(char *message, int key)
{
    int n = strlen(message);
    char *encrypted_message = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        // Shifting the character by the key value
        if (message[i] >= 'a' && message[i] <= 'z')
            encrypted_message[i] = (((message[i] - 'a') + key) % 26) + 'a';
        else if (message[i] >= 'A' && message[i] <= 'Z')
            encrypted_message[i] = (((message[i] - 'A') + key) % 26) + 'A';
        else
            encrypted_message[i] = message[i];
    }
    encrypted_message[n] = '\0';
    return encrypted_message;
}

// Function to decrypt the message using a shift cipher
char *shift_decryption(char *encrypted_message, int key)
{
    int n = strlen(encrypted_message);
    char *decrypted_message = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        // Reversing the shift to get the original character
        if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z')
            decrypted_message[i] = (((encrypted_message[i] - 'a') - key + 26) % 26) + 'a';
        else if (encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z')
            decrypted_message[i] = (((encrypted_message[i] - 'A') - key + 26) % 26) + 'A';
        else
            decrypted_message[i] = encrypted_message[i];
    }
    decrypted_message[n] = '\0';
    return decrypted_message;
}

// Driver code
int main()
{
    int key = 3;
    char message[100], *encrypted_message, *decrypted_message;

    // Reading the message from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    message[strlen(message) - 1] = '\0';

    // Encrypting the message using shift cipher
    encrypted_message = shift_encryption(message, key);

    // Printing the encrypted message
    printf("\nEncrypted message: %s\n", encrypted_message);

    // Decrypting the message using shift cipher
    decrypted_message = shift_decryption(encrypted_message, key);

    // Printing the decrypted message
    printf("\nDecrypted message: %s\n", decrypted_message);

    // Freeing the memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}