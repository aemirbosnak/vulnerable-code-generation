//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26

// Function to generate a random key
char *generateKey() 
{
    char *key = (char *) malloc(ALPHABET_SIZE);

    // Initialize the key with all unique characters
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        key[i] = 'a' + i;
    }

    // Shuffle the key
    srand(time(NULL));
    for (int i = ALPHABET_SIZE - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }

    return key;
}

// Function to encrypt a message using the key
char *encrypt(char *message, char *key) 
{
    int message_length = strlen(message);
    char *encrypted_message = (char *) malloc(message_length + 1);

    // Encrypt each character using the key
    for (int i = 0; i < message_length; i++) 
    {
        if (message[i] >= 'a' && message[i] <= 'z') 
        {
            encrypted_message[i] = key[message[i] - 'a'];
        } 
        else if (message[i] >= 'A' && message[i] <= 'Z') 
        {
            encrypted_message[i] = key[message[i] - 'A'] - 32;
        } 
        else 
        {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';
    return encrypted_message;
}

// Function to decrypt an encrypted message using the key
char *decrypt(char *encrypted_message, char *key) 
{
    int message_length = strlen(encrypted_message);
    char *decrypted_message = (char *) malloc(message_length + 1);

    // Decrypt each character using the key
    for (int i = 0; i < message_length; i++) 
    {
        if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z') 
        {
            decrypted_message[i] = 'a' + (strchr(key, encrypted_message[i]) - key);
        } 
        else if (encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z') 
        {
            decrypted_message[i] = 'A' + (strchr(key, encrypted_message[i] + 32) - key);
        } 
        else 
        {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[message_length] = '\0';
    return decrypted_message;
}

int main() 
{
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0';

    char *key = generateKey();
    printf("Generated key: %s\n", key);

    char *encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char *decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(key);
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}