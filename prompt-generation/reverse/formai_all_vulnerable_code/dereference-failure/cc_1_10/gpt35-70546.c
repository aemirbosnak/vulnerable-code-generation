//FormAI DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using a custom encryption algorithm
char* encrypt(char* message)
{
    int length = strlen(message);
    char* encryptedMessage = (char*) malloc(length * sizeof(char));
    
    for (int i = 0; i < length; i++)
    {
        if ((int) message[i] >= 65 && (int) message[i] <= 90) // Uppercase letters
        {
            encryptedMessage[i] = (char) ((int) message[i] + 5);
            if ((int) encryptedMessage[i] > 90)
            {
                encryptedMessage[i] = (char) ((int) encryptedMessage[i] - 26);
            }
        }
        else if ((int) message[i] >= 97 && (int) message[i] <= 122) // Lowercase letters
        {
            encryptedMessage[i] = (char) ((int) message[i] - 4);
            if ((int) encryptedMessage[i] < 97)
            {
                encryptedMessage[i] = (char) ((int) encryptedMessage[i] + 26);
            }
        }
        else // Non-alphabetic characters
        {
            encryptedMessage[i] = message[i];
        }
    }
    encryptedMessage[length] = '\0'; // Add null terminator
    
    return encryptedMessage;
}

int main()
{
    char message[100];
    printf("Welcome to my happy encryption program!\n");
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]%*c", message);
    
    char* encryptedMessage = encrypt(message);
    printf("Encrypted message: %s\n", encryptedMessage);
    
    free(encryptedMessage);
    return 0;
}