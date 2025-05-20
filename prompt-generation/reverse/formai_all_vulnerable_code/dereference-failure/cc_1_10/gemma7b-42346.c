//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int m;
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    char ***arr = (char ***)malloc(n * sizeof(char **));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char **)malloc(m * sizeof(char *));
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = (char *)malloc(10 * sizeof(char));
        }
    }

    printf("Enter the characters: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j][0]);
        }
    }

    printf("Here is your ASCII art:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                printf("%c", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}