//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void alien_translator(char **arr, int n)
{
    int i, j, k;
    char temp[100];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                for (k = 0; arr[i][k] && arr[j][k] && k < 100; k++)
                {
                    if (arr[i][k] == arr[j][k])
                    {
                        temp[k] = 1;
                    }
                }
            }
        }
    }
    for (i = 0; temp[i] != '\0'; i++)
    {
        printf("%c", temp[i]);
    }
    printf("\n");
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of alien languages: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    printf("Enter the alien language phrases: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    alien_translator(arr, n);

    return 0;
}