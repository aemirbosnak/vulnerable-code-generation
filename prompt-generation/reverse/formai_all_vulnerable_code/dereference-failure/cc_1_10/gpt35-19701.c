//FormAI DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100

char* encrypt(char* plaintext, int shift);

int main()
{
    char plaintext[MAX_STRING_SIZE], *ciphertext;
    int shift;

    printf("Enter a string to encrypt: ");
    fgets(plaintext, MAX_STRING_SIZE, stdin);

    printf("Enter a shift value for the encryption: ");
    scanf("%d", &shift);

    ciphertext = encrypt(plaintext, shift);

    printf("The ciphertext is: %s\n", ciphertext);

    free(ciphertext);

    return 0;
}

char* encrypt(char* plaintext, int shift)
{
    char* ciphertext = malloc(sizeof(char) * (strlen(plaintext) + 1));
    int i;
    
    for(i = 0; i < strlen(plaintext); i++)
    {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = (plaintext[i] - 'a' + shift) % 26 + 'a';
        }
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';

    return ciphertext;
}