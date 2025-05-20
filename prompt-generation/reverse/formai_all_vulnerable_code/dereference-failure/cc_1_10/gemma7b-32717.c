//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROLL 10

int main()
{
    int roll_count = 0;
    int total_roll = 0;
    int number_rolled = 0;
    int roll_result = 0;
    int highest_roll = 0;

    // Allocate memory for the roll results
    int *roll_results = malloc(MAX_ROLL * sizeof(int));

    // Initialize the roll results
    for (int i = 0; i < MAX_ROLL; i++)
    {
        roll_results[i] = 0;
    }

    // Loop until the user has rolled the desired number of times
    while (roll_count < MAX_ROLL)
    {
        // Roll the dice
        roll_result = rand() % 6 + 1;

        // Store the roll result
        roll_results[roll_count] = roll_result;

        // Increment the roll count
        roll_count++;

        // Update the total roll
        total_roll += roll_result;

        // Update the highest roll
        if (roll_result > highest_roll)
        {
            highest_roll = roll_result;
        }
    }

    // Print the results
    printf("Total roll: %d\n", total_roll);
    printf("Highest roll: %d\n", highest_roll);

    // Free the memory allocated for the roll results
    free(roll_results);

    return 0;
}