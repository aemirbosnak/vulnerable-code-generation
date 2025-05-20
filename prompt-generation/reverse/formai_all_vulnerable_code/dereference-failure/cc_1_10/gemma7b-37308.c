//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int i, j, n, m, count = 0, flag = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *) + m * sizeof(char));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the characters: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("Enter the search character: ");
    char searchChar;
    scanf("%c", &searchChar);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == searchChar)
            {
                count++;
            }
        }
    }

    if (count > 0)
    {
        printf("The character %c was found %d times.", searchChar, count);
    }
    else
    {
        printf("The character %c was not found.", searchChar);
    }

    free(arr);

    return 0;
}