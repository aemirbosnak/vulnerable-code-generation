//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//The function that generates the pixel art
void generatePixelArt(int size)
{
    //Create a random seed for variety in the art
    srand(time(NULL));

    //Create the 2D array to store the pixel art
    int pixelArt[size][size];

    //Loop through each row and column to randomly assign values
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            //Assign a 1 or a 0 randomly
            pixelArt[i][j] = rand() % 2;
        }
    }

    //Display the pixel art by looping through each row and column and representing 1's with '*' and 0's with ' '
    printf("\nPixel Art:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (pixelArt[i][j] == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int size;

    //Prompt the user for the size of the pixel art
    printf("Enter the size of the pixel art (e.g. 5 for a 5x5 art): ");
    scanf("%d", &size);

    //Generate and display the pixel art
    generatePixelArt(size);

    return 0;
}