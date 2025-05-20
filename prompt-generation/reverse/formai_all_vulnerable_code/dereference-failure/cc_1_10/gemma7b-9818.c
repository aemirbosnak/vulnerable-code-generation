//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 20
#define MAX_COLS 20

void generate_ascii_art(char **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 26 + 65;
        }
    }
}

int main()
{
    char **arr = NULL;
    int n, m;

    printf("Enter the number of lines: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *) + 1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char) + 1);
    }

    generate_ascii_art(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}