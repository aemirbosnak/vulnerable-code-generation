//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    system("color 2");

    int i, j;
    char **table = malloc(sizeof(char *) * 17);
    for (i = 0; i < 17; i++)
    {
        table[i] = malloc(sizeof(char) * 18);
    }

    // Table header
    table[0][0] = 'H';
    table[0][1] = 'He';
    table[0][2] = 'Li';
    table[0][3] = 'Be';
    table[0][4] = 'Na';
    table[0][5] = 'Mg';
    table[0][6] = 'Al';
    table[0][7] = 'Si';
    table[0][8] = 'Ar';
    table[0][9] = 'K';
    table[0][10] = 'Ca';
    table[0][11] = 'Sc';
    table[0][12] = 'Ti';
    table[0][13] = 'V';
    table[0][14] = 'Cr';
    table[0][15] = 'Mn';
    table[0][16] = 'Fe';

    // Table body
    for (i = 1; i < 17; i++)
    {
        for (j = 0; j < 18; j++)
        {
            table[i][j] = ' ';
        }
    }

    // Print table
    for (i = 0; i < 17; i++)
    {
        for (j = 0; j < 18; j++)
        {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    free(table);
    return 0;
}