//FormAI DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* plainText, int key)
{
    int length = strlen(plainText);
    char* cipherText = (char*)malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++)
    {
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            cipherText[i] = 'a' + (plainText[i] - 'a' + key) % 26;
        }
        else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            cipherText[i] = 'A' + (plainText[i] - 'A' + key) % 26;
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }

    cipherText[length] = '\0';

    printf("Encrypted Text: %s\n", cipherText);

    free(cipherText);
}

int main()
{
    printf("Welcome to my super cool C Encryption Program!\n");
    printf("Enter the text you want to encrypt: ");

    char plainText[100];
    fgets(plainText, sizeof(plainText), stdin);

    int key = rand() % 26 + 1;

    printf("Your random encryption key is: %d\n", key);
    printf("Encrypting your text now...\n");

    encrypt(plainText, key);

    printf("Thanks for using my program! Have a great day!\n");

    return 0;
}