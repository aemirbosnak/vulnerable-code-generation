//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s);

int main()
{
    int num, i, j, k, l, width, height, x, y;
    char **arr;

    printf("Enter the width and height of the ASCII art: ");
    scanf("%d %d", &width, &height);

    arr = (char **)malloc(height * sizeof(char *) + 1);
    for (i = 0; i < height; i++)
    {
        arr[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    printf("Enter the ASCII art: ");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("Here is your ASCII art:\n");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}

void itoa(int n, char *s)
{
    int i = 0;
    char num_str[11];

    itoa(n, num_str);

    while (num_str[i] != '\0')
    {
        s[i] = num_str[i];
        i++;
    }

    s[i] = '\0';
}