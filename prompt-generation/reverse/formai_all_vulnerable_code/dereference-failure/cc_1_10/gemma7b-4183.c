//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number;
    int result;
    char symbol;

    // Allocates memory for the array
    int *rolls = (int *)malloc(10 * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Number of rolls
    printf("Enter the number of rolls: ");
    scanf("%d", &roll_number);

    // Roll the dice
    for (int i = 0; i < roll_number; i++)
    {
        result = rand() % 6 + 1;
        rolls[i] = result;
    }

    // Print the results
    printf("Results:\n");
    for (int i = 0; i < roll_number; i++)
    {
        printf("%d ", rolls[i]);
    }

    // Find the maximum roll
    int max_roll = rolls[0];
    for (int i = 1; i < roll_number; i++)
    {
        if (rolls[i] > max_roll)
        {
            max_roll = rolls[i];
        }
    }

    // Print the maximum roll
    printf("\nMaximum roll: %d", max_roll);

    // Free the allocated memory
    free(rolls);

    return 0;
}