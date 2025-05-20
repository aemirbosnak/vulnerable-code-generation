//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void encrypt(char **a, int n);
void decrypt(char **a, int n);

int main()
{
    char **p = NULL;
    int n = 0;

    printf("Enter the number of secret messages you want to store: ");
    scanf("%d", &n);

    p = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the secret message: ");
        p[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", p[i]);
    }

    encrypt(p, n);

    for (int i = 0; i < n; i++)
    {
        printf("Your secret message (encrypted): ");
        printf("%s\n", p[i]);
    }

    decrypt(p, n);

    for (int i = 0; i < n; i++)
    {
        printf("Your secret message (decrypted): ");
        printf("%s\n", p[i]);
    }

    return 0;
}

void encrypt(char **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; a[i][j] != '\0'; j++)
        {
            a[i][j] = (a[i][j] - 'a') * 3 + 'a';
        }
    }
}

void decrypt(char **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; a[i][j] != '\0'; j++)
        {
            a[i][j] = (a[i][j] - 'a') / 3 + 'a';
        }
    }
}