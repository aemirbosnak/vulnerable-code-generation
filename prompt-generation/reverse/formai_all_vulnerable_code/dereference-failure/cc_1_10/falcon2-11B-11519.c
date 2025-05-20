//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Function to encrypt a message using Caesar cipher
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* encrypted_message = (char*)malloc(len + 1);

    // Encrypt each character
    for (int i = 0; i < len; i++)
    {
        int char_val = (int)message[i];
        char_val += key;
        char_val = char_val % 26;
        if (char_val < 'a')
        {
            char_val += 'a' - 'A';
        }
        else if (char_val < 'A')
        {
            char_val += 'A' - 'a';
        }
        encrypted_message[i] = (char)char_val;
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}

// Function to decrypt a message using Caesar cipher
char* decrypt(char* message, int key)
{
    int len = strlen(message);
    char* decrypted_message = (char*)malloc(len + 1);

    // Decrypt each character
    for (int i = 0; i < len; i++)
    {
        int char_val = (int)message[i];
        char_val -= key;
        char_val = char_val % 26;
        if (char_val < 'a')
        {
            char_val += 'a' - 'A';
        }
        else if (char_val < 'A')
        {
            char_val += 'A' - 'a';
        }
        decrypted_message[i] = (char)char_val;
    }
    decrypted_message[len] = '\0';
    return decrypted_message;
}

int main()
{
    char message[] = "This is a secret message";
    int key = 3;
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);
    return 0;
}