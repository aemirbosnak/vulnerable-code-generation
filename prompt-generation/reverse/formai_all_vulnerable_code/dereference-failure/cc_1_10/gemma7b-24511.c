//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

void draw_ascii_art(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the ASCII art: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    draw_ascii_art(arr, n);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}