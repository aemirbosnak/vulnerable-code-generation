//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt using Caesar Cipher
char* caesarCipher(char* message, int key)
{
    int i;
    char* result;

    result = (char *) malloc(sizeof(char) * (strlen(message) + 1));

    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z')
            result[i] = 'A' + (message[i] - 'a' + key) % 26;
        else if (message[i] >= 'A' && message[i] <= 'Z')
            result[i] = 'a' + (message[i] - 'A' + key) % 26;
        else
            result[i] = message[i];
    }

    result[i] = '\0';
    return result;
}

// Function to decrypt using Caesar Cipher
char* caesarDecrypt(char* message, int key)
{
    int i;
    char* result;

    result = (char *) malloc(sizeof(char) * (strlen(message) + 1));

    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z')
            result[i] = 'A' + (message[i] - 'a' - key + 26) % 26;
        else if (message[i] >= 'A' && message[i] <= 'Z')
            result[i] = 'a' + (message[i] - 'A' - key + 26) % 26;
        else
            result[i] = message[i];
    }

    result[i] = '\0';
    return result;
}

int main()
{
    char* message = "Hello, how are you today?";
    char* encryptedMessage;
    char* decryptedMessage;
    int key = 3;

    encryptedMessage = caesarCipher(message, key);
    decryptedMessage = caesarDecrypt(encryptedMessage, key);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}