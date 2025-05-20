//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Curious C Encryption Example Program by Chatbot

// Function to encrypt the message
char* curious_encrypt(char* message, int key)
{
    char* encrypted_message = (char*)malloc(sizeof(char) * (strlen(message) + 1));
    int i;

    for(i = 0; i < strlen(message); i++)
    {
        encrypted_message[i] = message[i] + key; // Add key to each character
    }

    encrypted_message[i] = '\0';

    return encrypted_message;
}

// Function to decrypt the message
char* curious_decrypt(char* message, int key)
{
    char* decrypted_message = (char*)malloc(sizeof(char) * (strlen(message) + 1));
    int i;

    for(i = 0; i < strlen(message); i++)
    {
        decrypted_message[i] = message[i] - key; // Subtract key from each character
    }

    decrypted_message[i] = '\0';

    return decrypted_message;
}

int main()
{
    int key;
    char* message = (char*)malloc(sizeof(char) * 100);

    printf("Welcome to the Curious C Encryption Example Program!\n");

    printf("Please enter a message to encrypt: ");
    scanf("%s", message);

    printf("Please enter a key for encryption: ");
    scanf("%d", &key);

    char* encrypted_message = curious_encrypt(message, key);
    printf("\nEncrypted message: %s\n\n", encrypted_message);

    char* decrypted_message = curious_decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n\n", decrypted_message);

    free(message);
    free(encrypted_message);
    free(decrypted_message);

    printf("Thank you for using the Curious C Encryption Example Program!\n");

    return 0;
}