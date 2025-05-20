//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // The address of 221B Baker Street
    int x_baker = 51;
    int y_baker = 10;

    // The current location of the detective
    int x_detective = 20;
    int y_detective = 15;

    // The map of London
    char **map = (char **)malloc(10 * sizeof(char *));
    for(int i = 0; i < 10; i++)
    {
        map[i] = (char *)malloc(20 * sizeof(char));
        for(int j = 0; j < 20; j++)
        {
            map[i][j] = ' ';
        }
    }

    // Mark the location of 221B Baker Street and the detective
    map[x_baker][y_baker] = 'B';
    map[x_detective][y_detective] = 'D';

    // Print the map
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    // Calculate the direction of travel
    int direction = 0;
    if(x_baker - x_detective > 0)
    {
        direction = 1;
    }
    else if(x_baker - x_detective < 0)
    {
        direction = 3;
    }
    else if(y_baker - y_detective > 0)
    {
        direction = 2;
    }
    else if(y_baker - y_detective < 0)
    {
        direction = 4;
    }

    // Print the direction of travel
    printf("The direction of travel is: %d\n", direction);

    // Free the memory allocated for the map
    for(int i = 0; i < 10; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}