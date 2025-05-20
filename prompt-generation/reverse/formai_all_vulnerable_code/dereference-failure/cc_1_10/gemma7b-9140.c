//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 118

int main()
{
    char **table = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        table[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Initialize the table
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            table[r][c] = ' ';
        }
    }

    // Create the header row
    table[0][0] = 'H';
    table[0][1] = 'A';
    table[0][2] = 'T';
    table[0][3] = 'O';
    table[0][4] = 'G';

    // Create the column headers
    table[1][0] = 'No.';
    table[2][0] = 'Symbol';
    table[3][0] = 'Name';
    table[4][0] = 'Atomic No.';
    table[5][0] = 'Mass No.';
    table[6][0] = 'State';
    table[7][0] = 'Melting Point';
    table[8][0] = 'Boiling Point';

    // Fill the table with data
    table[2][1] = 'Na';
    table[3][1] = "Sodium";
    table[4][1] = 11;
    table[5][1] = 23;
    table[6][1] = 'Solid';
    table[7][1] = 851;
    table[8][1] = 853;

    // Print the table
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", table[r][c]);
        }
        printf("\n");
    }

    free(table);
    return 0;
}