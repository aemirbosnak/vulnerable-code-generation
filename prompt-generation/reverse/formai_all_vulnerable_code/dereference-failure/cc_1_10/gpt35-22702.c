//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
/*
 * Cryptography Implementation in C
 * Designed and coded by (Your Name)
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <string.h>

/* The maximum number of characters allowed in the input message */
#define MAX_MESSAGE_LEN 1000

/* The maximum number of characters allowed in the encryption/decryption key */
#define MAX_KEY_LEN 100

/*
 * This function encrypts the given message using the given key
 * and returns the encrypted message.
 */
char *encrypt(char *message, char *key) 
{
    char *encrypted_message = (char *) malloc(sizeof(char) * MAX_MESSAGE_LEN);
    int message_len = strlen(message);
    int key_len = strlen(key);
    for (int i = 0; i < message_len; i++) 
    {
        encrypted_message[i] = message[i] ^ key[i % key_len];
    }
    encrypted_message[message_len] = '\0';
    return encrypted_message;
}

/*
 * This function decrypts the given message using the given key
 * and returns the decrypted message.
 */
char *decrypt(char *message, char *key) 
{
    return encrypt(message, key);
}

/*
 * The main function reads the input message and key from the user 
 * using the standard input and prints the encrypted and decrypted 
 * messages to the standard output.
 */
int main() 
{
    char message[MAX_MESSAGE_LEN], key[MAX_KEY_LEN];
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);

    /* Remove new line characters from the end of the input strings */
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    /* Encrypt and decrypt the message */
    char *encrypted_message = encrypt(message, key);
    char *decrypted_message = decrypt(encrypted_message, key);

    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}