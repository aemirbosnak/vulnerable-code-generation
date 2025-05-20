//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt a given string using C encryption
char *encrypt(char *str, int key)
{
    int len = strlen(str);
    char *encrypted = (char *)malloc(len+1);

    for(int i=0; i<len; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            encrypted[i] = (str[i]-'a'+key)%26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            encrypted[i] = (str[i]-'A'+key)%26 + 'A';
        }
        else
        {
            encrypted[i] = str[i];
        }
    }
    encrypted[len] = '\0';

    return encrypted;
}

int main()
{
    char str[100];
    int key;

    printf("Enter a string to encrypt: ");
    scanf("%[^\n]s", str);
    getchar();

    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    char *encrypted = encrypt(str, key);

    printf("Encrypted string: %s", encrypted);

    free(encrypted);

    return 0;
}