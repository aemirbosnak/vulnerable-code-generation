//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Happy Encryption Program
 *
 * This program encrypts a message using a simple caesar cipher algorithm.
 * It takes a string message and an integer encryption key as input, and returns an encrypted message.
 * 
 * The encryption function works by shifting each character of the message by the value of the key.
 * For example, if the key is 2, then the letter 'A' would become the letter 'C'.
 * 
 * This program uses the standard library functions string.h and stdlib.h for string manipulation and memory management.
 *
 * Compile with:
 * gcc encrypt.c -o encrypt
 * 
 * Usage:
 * ./encrypt [message] [encryption key]
 *
 * Written by HappyCoder, with love!
 */

char *encrypt(char *message, int key)
{
    int len = strlen(message);
    char *encrypted = (char*)malloc(len * sizeof(char));
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
    return encrypted;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s message key", argv[0]);
        return 1;
    }

    char *message = argv[1];
    int key = atoi(argv[2]);

    char *encrypted = encrypt(message, key);

    printf("Your original message: %s\n", message);
    printf("Your encrypted message: %s\n", encrypted);

    free(encrypted);

    return 0;
}