//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

int main()
{
    char plaintext[100];
    char key[100];
    char ciphertext[100];

    //Taking input for plaintext and key
    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);

    //Removing trailing newline character from plaintext and key
    plaintext[strcspn(plaintext, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    //Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("\nEncrypted text is: %s", ciphertext);

    //Decrypt the ciphertext
    decrypt(ciphertext, key, plaintext);
    printf("\nDecrypted text is: %s", plaintext);

    return 0;
}

void encrypt(char *plaintext, char *key, char *ciphertext)
{
    int i;
    int keylen = strlen(key);

    //Encrypting the plaintext using the key
    for(i=0; i<strlen(plaintext); i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i%keylen];
    }

    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext)
{
    int i;
    int keylen = strlen(key);

    //Decrypting the ciphertext using the key
    for(i=0; i<strlen(ciphertext); i++)
    {
        plaintext[i] = ciphertext[i] ^ key[i%keylen];
    }

    plaintext[i] = '\0';
}