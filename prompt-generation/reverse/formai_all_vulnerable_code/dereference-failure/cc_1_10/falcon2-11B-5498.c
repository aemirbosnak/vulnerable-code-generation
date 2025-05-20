//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Set the size of the window
    int windowSize = 800;

    // Set the number of iterations
    int iterations = 5;

    // Set the color of the window
    int color = 0;

    // Initialize the window
    unsigned char* window = malloc(sizeof(unsigned char) * windowSize * windowSize);
    for (int i = 0; i < windowSize * windowSize; i++)
        window[i] = 255;

    // Generate the fractal
    for (int i = 0; i < iterations; i++)
    {
        int x = windowSize / 2 - 1;
        int y = windowSize / 2 - 1;

        // Move to the center
        x += (windowSize - 1) / 2;
        y += (windowSize - 1) / 2;

        // Set the color to the center of the window
        color = window[y * windowSize + x];

        // Draw a line from the center to the edge
        for (int j = 0; j < windowSize / 2; j++)
        {
            window[y * windowSize + x + j] = color;
            window[y * windowSize + x - j] = color;
        }

        // Draw a line from the center to the edge
        for (int j = 0; j < windowSize / 2; j++)
        {
            window[y * windowSize + x + j] = color;
            window[y * windowSize + x - j] = color;
        }
    }

    // Display the fractal
    for (int i = 0; i < windowSize * windowSize; i++)
    {
        printf("%3d", window[i]);
        if ((i + 1) % windowSize == 0)
            printf("\n");
    }

    printf("\n");

    free(window);

    return 0;
}