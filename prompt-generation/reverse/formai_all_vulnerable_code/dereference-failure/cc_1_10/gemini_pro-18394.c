//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define DELAY 10

void clearScreen()
{
    printf("\033[2J"); // Clear the screen
    printf("\033[0;0H"); // Move the cursor to the top-left corner
}

void drawFrame(int *fib, int size)
{
    clearScreen();

    // Calculate the maximum value in the Fibonacci sequence
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (fib[i] > max)
        {
            max = fib[i];
        }
    }

    // Scale the values to fit within the screen
    float scale = (float)HEIGHT / max;

    // Draw the Fibonacci sequence
    for (int i = 0; i < size; i++)
    {
        int height = round(fib[i] * scale);
        for (int j = 0; j < height; j++)
        {
            printf("%c", '#');
        }
        printf(" ");
    }

    // Print the current frame number
    printf("\nFrame: %d", size);

    // Sleep for a short period of time to create a delay effect
    usleep(DELAY * 1000);
}

int main()
{
    srand(time(NULL));

    int size = 1;
    int *fib = malloc(sizeof(int) * size);
    fib[0] = 0;

    // Generate the Fibonacci sequence
    for (int i = 1; i < size; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Animate the Fibonacci sequence
    while (1)
    {
        // Increase the size of the Fibonacci sequence
        size++;

        // Reallocate the array
        fib = realloc(fib, sizeof(int) * size);

        // Calculate the next Fibonacci number
        fib[size - 1] = fib[size - 2] + fib[size - 3];

        // Draw the current frame
        drawFrame(fib, size);
    }

    return 0;
}