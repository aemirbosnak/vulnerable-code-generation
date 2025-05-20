//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int red_team = 0;
    int blue_team = 0;
    int roll_result = 0;
    int round_num = 0;

    // Allocate memory for two arrays
    int *red_array = malloc(10 * sizeof(int));
    int *blue_array = malloc(10 * sizeof(int));

    // Initialize the arrays
    for (int i = 0; i < 10; i++)
    {
        red_array[i] = 0;
        blue_array[i] = 0;
    }

    // Start the game loop
    while (red_team < 5 && blue_team < 5)
    {
        // Roll the dice
        roll_result = rand() % 6 + 1;

        // Assign the roll result to the appropriate team
        if (roll_result % 2 == 0)
        {
            red_array[round_num] = roll_result;
            red_team++;
        }
        else
        {
            blue_array[round_num] = roll_result;
            blue_team++;
        }

        // Increment the round number
        round_num++;
    }

    // Print the results
    printf("Red Team:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", red_array[i]);
    }

    printf("\nBlue Team:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", blue_array[i]);
    }

    // Free the memory allocated for the arrays
    free(red_array);
    free(blue_array);

    return 0;
}