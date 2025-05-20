//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void printArray(int *array, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int size = 10;
    int *array = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }

    shuffle(array, size);
    printf("Welcome to the Memory Game!\n");
    printf("Try to memorize the numbers being displayed.\n\n");

    // Display numbers
    printArray(array, size);
    printf("\n");

    printf("Okay, now enter the numbers in the exact sequence as displayed.\n\n");

    // User input
    int *userInput = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &userInput[i]);
    }

    // Check if user input matches original sequence
    int correct = 1;
    for (int i = 0; i < size; i++)
    {
        if (userInput[i] != array[i])
        {
            correct = 0;
            break;
        }
    }

    if (correct)
    {
        printf("\nCongratulations, you won!");
    }
    else
    {
        printf("\nSorry, you lost. Better luck next time!");
    }

    free(array);
    free(userInput);
    return 0;
}