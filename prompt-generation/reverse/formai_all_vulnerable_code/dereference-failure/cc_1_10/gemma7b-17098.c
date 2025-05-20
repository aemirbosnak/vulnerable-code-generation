//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paint_table(char **table, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", table[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int table_size = 17;
    char **table = malloc(table_size * sizeof(char *));
    for (int i = 0; i < table_size; i++)
    {
        table[i] = malloc(table_size * sizeof(char));
    }

    // Painting the table with ASCII art
    paint_table(table, table_size);

    // Filling the table with chemical symbols
    table[0][0] = 'H';
    table[0][1] = 'He';
    table[1][0] = 'Li';
    table[2][0] = 'Be';
    table[3][0] = 'Na';
    table[4][0] = 'Mg';
    table[5][0] = 'Al';
    table[6][0] = 'Si';
    table[7][0] = 'Ca';
    table[8][0] = 'Fe';
    table[9][0] = 'Ni';
    table[10][0] = 'Cu';
    table[11][0] = 'Zn';
    table[12][0] = 'Ga';
    table[13][0] = 'As';
    table[14][0] = 'Se';
    table[15][0] = 'Br';
    table[16][0] = 'Kr';

    // Painting the table with chemical symbols
    paint_table(table, table_size);

    // Freeing memory
    for (int i = 0; i < table_size; i++)
    {
        free(table[i]);
    }
    free(table);

    return 0;
}