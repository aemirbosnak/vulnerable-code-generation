//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_ascii_art(char **arr)
{
    int i, j, k;
    for (i = 0; arr[i] != NULL; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            switch (arr[i][j])
            {
                case '.':
                    printf("%c ", 167);
                    break;
                case '-':
                    printf("%c ", 163);
                    break;
                case '/':
                    printf("%c ", 164);
                    break;
                case '(':
                    printf("%c ", 166);
                    break;
                case ')':
                    printf("%c ", 165);
                    break;
                default:
                    printf("%c ", arr[i][j]);
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    arr = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = malloc(20 * sizeof(char));
    }

    // Write your ASCII art here, for example:
    arr[0] = "           /\n"
                 "\\/\\_/_/";

    arr[1] = "           /\n"
                 "\\/\\_/_/";

    draw_ascii_art(arr);

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}