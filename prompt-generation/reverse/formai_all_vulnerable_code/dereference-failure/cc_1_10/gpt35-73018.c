//FormAI DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to encrypt string using a multi-variable encryption */
char* multivar_encrypt(char* string, int key1, int key2)
{
    int len = strlen(string);
    char* encrypted = malloc(len + 1);
    int i;

    /* Iterate through each character in the input string */
    for(i = 0; i < len; i++)
    {
        /* Apply first encryption key */
        encrypted[i] = string[i] + key1;

        /* Apply second encryption key */
        encrypted[i] = encrypted[i] * key2;

        /* Check if the character is a letter */
        if(isalpha(encrypted[i]))
        {
            /* Shift letter by encryption key */
            if(isupper(encrypted[i]))
            {
                encrypted[i] = ((encrypted[i] - 'A') + (key2 % 26)) % 26 + 'A';
            }
            else
            {
                encrypted[i] = ((encrypted[i] - 'a') + (key2 % 26)) % 26 + 'a';
            }
        }
    }

    encrypted[i] = '\0';
    return encrypted;
}

/* Main function */
int main()
{
    char input[100];
    int key1, key2;
    char* encrypted;

    /* Get input string from user */
    printf("Enter a string to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    /* Get encryption keys from user */
    printf("Enter an integer for encryption key 1: ");
    scanf("%d", &key1);
    printf("Enter an integer for encryption key 2: ");
    scanf("%d", &key2);

    /* Call multivar_encrypt function to encrypt the input string */
    encrypted = multivar_encrypt(input, key1, key2);

    /* Print the encrypted string */
    printf("Encrypted string: %s\n", encrypted);

    /* Free memory allocated for encrypted string */
    free(encrypted);

    return 0;
}