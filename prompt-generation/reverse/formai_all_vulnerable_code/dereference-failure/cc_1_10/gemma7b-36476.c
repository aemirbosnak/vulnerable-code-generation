//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **art, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", art[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char **art = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        art[i] = malloc(sizeof(char) * MAX_WIDTH);
    }

    art[0][0] = 'A';
    art[0][1] = 'B';
    art[0][2] = 'C';
    art[0][3] = 'D';
    art[0][4] = 'E';

    art[1][0] = 'F';
    art[1][1] = 'G';
    art[1][2] = 'H';
    art[1][3] = 'I';
    art[1][4] = 'J';

    art[2][0] = 'K';
    art[2][1] = 'L';
    art[2][2] = 'M';
    art[2][3] = 'N';
    art[2][4] = 'O';

    art[3][0] = 'P';
    art[3][1] = 'Q';
    art[3][2] = 'R';
    art[3][3] = 'S';
    art[3][4] = 'T';

    art[4][0] = 'U';
    art[4][1] = 'V';
    art[4][2] = 'W';
    art[4][3] = 'X';
    art[4][4] = 'Y';

    draw_ascii_art(art, 5, MAX_WIDTH);

    for (int i = 0; i < 5; i++)
    {
        free(art[i]);
    }
    free(art);

    return 0;
}