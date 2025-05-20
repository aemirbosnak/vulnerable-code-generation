//Gemma-7B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = NULL;
    int n = 0, i, j, k, l, found = 0;
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    arr = (char**)malloc(MAX * sizeof(char*));

    for (i = 0; str[i] != '\0'; i++)
    {
        arr[n] = (char*)malloc(MAX * sizeof(char));
        arr[n][0] = str[i];
        n++;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            for (k = 0; k < n; k++)
            {
                for (l = 0; arr[k][l] != '\0'; l++)
                {
                    if (arr[i][j] == arr[k][l] && i != k)
                    {
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    if (found)
    {
        printf("Found repeated character.\n");
    }
    else
    {
        printf("No repeated character found.\n");
    }

    free(arr);

    return 0;
}