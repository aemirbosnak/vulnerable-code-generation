//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to perform encryption
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* encrypted = (char*)malloc(len + 1);
    
    // Apply Caesar cipher to each character
    for(int i = 0; i < len; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            encrypted[i] = 'a' + ((message[i] - 'a' + key) % 26);
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            encrypted[i] = 'A' + ((message[i] - 'A' + key) % 26);
        }
        else
        {
            encrypted[i] = message[i];
        }
    }
    encrypted[len] = '\0';
    
    // Return the encrypted message
    return encrypted;
}

// Function to perform decryption
char* decrypt(char* message, int key)
{
    int len = strlen(message);
    char* decrypted = (char*)malloc(len + 1);
    
    // Apply reverse Caesar cipher to each character
    for(int i = 0; i < len; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            decrypted[i] = 'a' + ((message[i] - 'a' - key + 26) % 26);
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            decrypted[i] = 'A' + ((message[i] - 'A' - key + 26) % 26);
        }
        else
        {
            decrypted[i] = message[i];
        }
    }
    decrypted[len] = '\0';
    
    // Return the decrypted message
    return decrypted;
}

int main()
{
    // Initiate Key for Caesar Cipher
    int key = 5;
    
    // Original Message
    char message[] = "Hello World!";
    
    // Encrypt the message
    char* ciphertext = encrypt(message, key);
    printf("Encrypted message: %s\n", ciphertext);
    
    // Decrypt the message
    char* plaintext = decrypt(ciphertext, key);
    printf("Decrypted message: %s\n", plaintext);
    
    // Free the memory
    free(ciphertext);
    free(plaintext);

    return 0;
}