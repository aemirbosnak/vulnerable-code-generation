//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void ascii_art(char **arr, int n, int m);

int main()
{
    char **arr = NULL;
    int n = 0, m = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *) + m * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the text you want to convert: ");
    getline(arr, &n, stdin);

    ascii_art(arr, n, m);

    free(arr);

    return 0;
}

void ascii_art(char **arr, int n, int m)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = ' ';
        }
    }

    char *str = arr[0];

    int len = strlen(str);

    for (i = 0; i < len; i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'A':
                arr[0][j] = '@';
                break;
            case 'b':
            case 'B':
                arr[0][j] = 'B';
                break;
            case 'c':
            case 'C':
                arr[0][j] = '$';
                break;
            case 'd':
            case 'D':
                arr[0][j] = '#';
                break;
            case 'e':
            case 'E':
                arr[0][j] = '%';
                break;
            default:
                arr[0][j] = str[i];
                break;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}