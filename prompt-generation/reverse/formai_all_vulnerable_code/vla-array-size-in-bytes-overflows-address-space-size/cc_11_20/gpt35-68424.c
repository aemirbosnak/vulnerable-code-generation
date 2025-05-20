//FormAI DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define PI 3.14159265

int main()
{
    int size, level, mid, i, j, k, count;
    double angle, x, y;

    // Take user input for size and level
    printf("Enter the size of the fractal: ");
    scanf("%d", &size);
    printf("Enter the level of the fractal: ");
    scanf("%d", &level);

    // Initialize the array
    char fractal[size][size];
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            fractal[i][j] = ' ';
        }
    }

    // Set the middle of the array
    mid = size / 2;
    fractal[mid][mid] = '*';

    // Loop through the levels
    for(k = 0; k < level; k++)
    {
        // Count the number of stars in previous level
        count = 0;
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(fractal[i][j] == '*')
                {
                    count++;
                }
            }
        }

        // Loop through the stars in previous level
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(fractal[i][j] == '*')
                {
                    // Calculate the angle and distance
                    angle = 2 * PI * count * (j - mid) / size;
                    x = cos(angle);
                    y = sin(angle);

                    // Set the new stars
                    fractal[mid + (int)(x * (i - mid))][mid + (int)(y * (i - mid))] = '*';
                }
            }
        }
    }

    // Print the fractal
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%c ", fractal[i][j]);
        }
        printf("\n");
    }

    return 0;
}