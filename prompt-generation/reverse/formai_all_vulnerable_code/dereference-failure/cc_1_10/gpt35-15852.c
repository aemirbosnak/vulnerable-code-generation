//FormAI DATASET v1.0 Category: Modern Encryption ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* encrypt(char* plain_text, int key);
char* decrypt(char* cipher_text, int key);

int main()
{
    char* text = "Hello, World!";
    int key = 7;

    printf("Original Text: %s\n", text);

    char* cipher_text = encrypt(text, key);
    printf("Cipher Text: %s\n", cipher_text);

    char* decrypted_text = decrypt(cipher_text, key);
    printf("Decrypted Text: %s\n", decrypted_text);

    free(cipher_text);
    free(decrypted_text);

    return 0;
}

char* encrypt(char* plain_text, int key)
{
    int length = strlen(plain_text);
    char* cipher_text = malloc(length + 1);

    for(int i = 0; i < length; i++)
    {
        if(isalpha(plain_text[i]))
            cipher_text[i] = ((plain_text[i] - 'A' + key) % 26) + 'A';
        else
            cipher_text[i] = plain_text[i];
    }

    cipher_text[length] = '\0';

    return cipher_text;
}

char* decrypt(char* cipher_text, int key)
{
    int length = strlen(cipher_text);
    char* decrypted_text = malloc(length + 1);

    for(int i = 0; i < length; i++)
    {
        if(isalpha(cipher_text[i]))
        {
            int temp = (cipher_text[i] - 'A' - key) % 26;
            if(temp < 0)
                temp += 26;

            decrypted_text[i] = temp + 'A';
        }
        else
            decrypted_text[i] = cipher_text[i];
    }

    decrypted_text[length] = '\0';

    return decrypted_text;
}