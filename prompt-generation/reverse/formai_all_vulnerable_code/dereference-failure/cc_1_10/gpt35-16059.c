//FormAI DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using the given key
char *encryptMessage(char *message, char *key)
{
    int messageLen = strlen(message), keyLen = strlen(key), i, j;
    char *encryptedMessage = (char *)malloc(sizeof(char) * (messageLen + 1));

    for (i = 0, j = 0; i < messageLen; ++i, ++j)
    {
        if (j == keyLen)
            j = 0;
        encryptedMessage[i] = ((message[i] + key[j]) % 26) + 'A';
    }

    encryptedMessage[i] = '\0';
    return encryptedMessage;
}

// Function to decrypt the message using the given key
char *decryptMessage(char *encryptedMessage, char *key)
{
    int messageLen = strlen(encryptedMessage), keyLen = strlen(key), i, j;
    char *decryptedMessage = (char *)malloc(sizeof(char) * (messageLen + 1));

    for (i = 0, j = 0; i < messageLen; ++i, ++j)
    {
        if (j == keyLen)
            j = 0;
        decryptedMessage[i] = (((encryptedMessage[i] - key[j]) + 26) % 26) + 'A';
    }

    decryptedMessage[i] = '\0';
    return decryptedMessage;
}

// Function to get the input message from the user
char *getMessage()
{
    char *message = (char *)malloc(sizeof(char) * 1000);
    printf("Enter the message you want to encrypt: ");
    scanf("%[^\n]s", message);
    getchar();
    return message;
}

// Function to get the encryption key from the user
char *getKey()
{
    char *key = (char *)malloc(sizeof(char) * 100);
    printf("Enter the encryption key: ");
    scanf("%[^\n]s", key);
    getchar();
    return key;
}

int main()
{
    char *message, *key, *encryptedMessage, *decryptedMessage;

    message = getMessage();
    key = getKey();

    encryptedMessage = encryptMessage(message, key);
    printf("\nEncrypted message: %s\n", encryptedMessage);

    decryptedMessage = decryptMessage(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    free(message);
    free(key);
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}