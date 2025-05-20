//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void generate_ascii_art(int rows, int cols, char **arr)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int rows = 5;
    int cols = 10;

    arr = (char **)malloc(rows * sizeof(char *));
    for (int r = 0; r < rows; r++)
    {
        arr[r] = (char *)malloc(cols * sizeof(char));
    }

    // Populate the array with ASCII art
    arr[0][0] = 'A';
    arr[0][1] = 'A';
    arr[0][2] = 'A';
    arr[0][3] = 'A';
    arr[0][4] = 'A';
    arr[0][5] = 'A';
    arr[0][6] = 'A';
    arr[0][7] = 'A';
    arr[0][8] = 'A';
    arr[0][9] = 'A';

    arr[1][0] = 'B';
    arr[1][1] = 'B';
    arr[1][2] = 'B';
    arr[1][3] = 'B';
    arr[1][4] = 'B';
    arr[1][5] = 'B';
    arr[1][6] = 'B';
    arr[1][7] = 'B';
    arr[1][8] = 'B';
    arr[1][9] = 'B';

    arr[2][0] = 'C';
    arr[2][1] = 'C';
    arr[2][2] = 'C';
    arr[2][3] = 'C';
    arr[2][4] = 'C';
    arr[2][5] = 'C';
    arr[2][6] = 'C';
    arr[2][7] = 'C';
    arr[2][8] = 'C';
    arr[2][9] = 'C';

    arr[3][0] = 'D';
    arr[3][1] = 'D';
    arr[3][2] = 'D';
    arr[3][3] = 'D';
    arr[3][4] = 'D';
    arr[3][5] = 'D';
    arr[3][6] = 'D';
    arr[3][7] = 'D';
    arr[3][8] = 'D';
    arr[3][9] = 'D';

    arr[4][0] = 'E';
    arr[4][1] = 'E';
    arr[4][2] = 'E';
    arr[4][3] = 'E';
    arr[4][4] = 'E';
    arr[4][5] = 'E';
    arr[4][6] = 'E';
    arr[4][7] = 'E';
    arr[4][8] = 'E';
    arr[4][9] = 'E';

    generate_ascii_art(rows, cols, arr);

    free(arr);
    return 0;
}