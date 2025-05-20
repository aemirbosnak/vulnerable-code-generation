//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

void draw_ascii_art(char **arr, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int w, h;

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &w);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    arr = (char **)malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        arr[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    // Get the ASCII art input from the user
    printf("Enter the ASCII art: ");
    char input[MAX_WIDTH * MAX_HEIGHT];
    scanf("%s", input);

    // Parse the input and fill the array
    int idx = 0;
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            arr[r][c] = input[idx];
            idx++;
        }
    }

    draw_ascii_art(arr, w, h);

    // Free the memory
    for (int i = 0; i < h; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}