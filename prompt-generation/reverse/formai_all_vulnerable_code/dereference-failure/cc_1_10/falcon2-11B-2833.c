//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Function to encrypt a message using Caesar Cipher
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* encrypted_message = (char*)malloc(len * sizeof(char));
    if (encrypted_message == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < len; i++)
    {
        int index = message[i] - 'a';
        index += key;
        if (index > 25)
            index -= 26;
        encrypted_message[i] = (char)index + 'a';
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}

// Function to decrypt an encrypted message
char* decrypt(char* encrypted_message, int key)
{
    int len = strlen(encrypted_message);
    char* decrypted_message = (char*)malloc(len * sizeof(char));
    if (decrypted_message == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < len; i++)
    {
        int index = encrypted_message[i] - 'a';
        index -= key;
        if (index < 0)
            index += 26;
        decrypted_message[i] = (char)index + 'a';
    }
    decrypted_message[len] = '\0';
    return decrypted_message;
}

int main()
{
    char* message = "Send me a letter, and I will write back.";
    int key = 13;

    printf("Original message: %s\n", message);
    char* encrypted_message = encrypt(message, key);
    if (encrypted_message!= NULL)
    {
        printf("Encrypted message: %s\n", encrypted_message);
        free(encrypted_message);
    }
    else
    {
        printf("Error encrypting the message.\n");
    }

    char* decrypted_message = decrypt(encrypted_message, key);
    if (decrypted_message!= NULL)
    {
        printf("Decrypted message: %s\n", decrypted_message);
        free(decrypted_message);
    }
    else
    {
        printf("Error decrypting the message.\n");
    }

    return 0;
}