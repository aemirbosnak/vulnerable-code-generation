//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to generate random key
char *generate_key(int key_length)
{
    char *key = (char *)malloc(key_length * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < key_length; i++)
    {
        key[i] = rand() % 256;
    }
    return key;
}

// function to encrypt the plaintext using key
char *encrypt(char *plaintext, char *key)
{
    int plaintext_length = strlen(plaintext);
    char *encrypted_text = (char *)malloc(plaintext_length * sizeof(char));
    for (int i = 0; i < plaintext_length; i++)
    {
        encrypted_text[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    return encrypted_text;
}

int main()
{
    char plaintext[] = "Hello World!"; // plaintext to be encrypted
    int key_length = 8; // length of the key
    char *key = generate_key(key_length); // generate random key of given length
    char *encrypted_text = encrypt(plaintext, key); // encrypt the plaintext using generated key
    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < key_length; i++)
    {
        printf("%d ", key[i]);
    }
    printf("\nEncrypted Text: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%d ", encrypted_text[i]);
    }
    printf("\n"); 
    free(key);
    free(encrypted_text);
    return 0;
}