//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Key for encryption and decryption */
#define KEY "sophisticated"

/* Function to encrypt a string */
void encrypt(char message[])
{
    int i, j = 0;
    int key_length = strlen(KEY);
    int message_length = strlen(message);
    char encrypted_message[message_length];

    for (i = 0; i < message_length; i++)
    {
        /* Perform encryption only for alphabets */
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            encrypted_message[i] = ((message[i] - 'A') + (KEY[j] - 'a')) % 26 + 'A';
            j = (j + 1) % key_length;
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            encrypted_message[i] = ((message[i] - 'a') + (KEY[j] - 'a')) % 26 + 'a';
            j = (j + 1) % key_length;
        }
        else
        {
            encrypted_message[i] = message[i];
        }
    }

    /* Null terminate the encrypted message */
    encrypted_message[i] = '\0';

    /* Print the encrypted message */
    printf("\nEncrypted message: %s\n", encrypted_message);

    /* Overwrite the original message with the encrypted message */
    strcpy(message, encrypted_message);
}

/* Function to decrypt a string */
void decrypt(char message[])
{
    int i, j = 0;
    int key_length = strlen(KEY);
    int message_length = strlen(message);
    char decrypted_message[message_length];

    for (i = 0; i < message_length; i++)
    {
        /* Perform decryption only for alphabets */
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            decrypted_message[i] = ((message[i] - 'A') - (KEY[j] - 'a') + 26) % 26 + 'A';
            j = (j + 1) % key_length;
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            decrypted_message[i] = ((message[i] - 'a') - (KEY[j] - 'a') + 26) % 26 + 'a';
            j = (j + 1) % key_length;
        }
        else
        {
            decrypted_message[i] = message[i];
        }
    }

    /* Null terminate the decrypted message */
    decrypted_message[i] = '\0';

    /* Print the decrypted message */
    printf("\nDecrypted message: %s\n", decrypted_message);

    /* Overwrite the original message with the decrypted message */
    strcpy(message, decrypted_message);
}

int main()
{
    char message[1000];

    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);

    /* Remove trailing newline */
    message[strcspn(message, "\n")] = 0;

    printf("Original message: %s\n", message);

    encrypt(message);

    decrypt(message);

    return 0;
}