//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sides = 6;
    int roll_count = 0;
    int result = 0;
    int number_of_rolls = 0;

    // Allocate memory for the roll results
    int *roll_results = malloc(sizeof(int) * sides);

    // Initialize the roll results
    for (int i = 0; i < sides; i++)
    {
        roll_results[i] = 0;
    }

    // Loop until the user has rolled the desired number of times
    while (number_of_rolls < 10)
    {
        // Roll the dice
        result = rand() % sides + 1;

        // Increment the roll result
        roll_results[result - 1]++;

        // Increment the roll count
        roll_count++;

        // Display the result
        printf("Roll %d: %d\n", roll_count, result);

        // Ask the user if they want to roll again
        char answer;
        printf("Do you want to roll again? (Y/N): ");
        scanf("%c", &answer);

        // Check if the user wants to roll again
        if (answer == 'Y')
        {
            number_of_rolls++;
        }
    }

    // Free the memory allocated for the roll results
    free(roll_results);

    // Print the roll results
    printf("Roll results:\n");
    for (int i = 0; i < sides; i++)
    {
        printf("Side %d: %d\n", i + 1, roll_results[i]);
    }

    return 0;
}