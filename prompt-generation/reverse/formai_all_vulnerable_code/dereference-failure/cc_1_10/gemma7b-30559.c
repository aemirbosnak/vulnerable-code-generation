//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROLL 10

int main()
{
    int roll_count = 0;
    int total_sum = 0;
    int current_roll = 0;
    int face_value = 0;

    // Allocate memory for the roll history
    int *roll_history = (int *)malloc(MAX_ROLL * sizeof(int));

    // Loop until the user wants to quit
    while (1)
    {
        // Get the user's input
        char input = getchar();

        // Check if the user wants to roll the dice
        if (input == 'r')
        {
            // Roll the dice
            face_value = rand() % 6 + 1;

            // Add the face value to the current roll
            current_roll += face_value;

            // Store the current roll in the roll history
            roll_history[roll_count] = current_roll;

            // Increment the roll count
            roll_count++;

            // Print the face value
            printf("You rolled a %d.\n", face_value);

            // Print the current roll total
            printf("Your current total is %d.\n", current_roll);

            // Print the roll history
            printf("Your roll history:\n");
            for (int i = 0; i < roll_count; i++)
            {
                printf("%d ", roll_history[i]);
            }
            printf("\n");
        }

        // Check if the user wants to quit
        else if (input == 'q')
        {
            // Free the memory allocated for the roll history
            free(roll_history);

            // Print the final total
            printf("Your final total is %d.\n", total_sum);

            // Exit the program
            exit(0);
        }

        // Check for invalid input
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}