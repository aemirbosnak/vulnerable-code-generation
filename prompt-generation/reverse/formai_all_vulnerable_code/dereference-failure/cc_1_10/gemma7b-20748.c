//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 6

int main()
{
    int number_rolled = 0;
    int roll_again = 1;
    int face_of_die = 0;

    // Allocate memory for the array of results
    int *results = (int *)malloc(MAX_NUMBER * sizeof(int));

    // Initialize the results array
    for (int i = 0; i < MAX_NUMBER; i++)
    {
        results[i] = 0;
    }

    // Loop until the user chooses to quit
    while (roll_again)
    {
        // Roll the die
        face_of_die = rand() % MAX_NUMBER + 1;

        // Increment the result for the face of the die
        results[face_of_die]++;

        // Display the face of the die
        printf("You rolled a %d.\n", face_of_die);

        // Ask the user if they want to roll again
        printf("Do you want to roll again? (y/n): ");
        char answer;
        scanf("%c", &answer);

        // Check if the user wants to roll again
        if (answer == 'y')
        {
            roll_again = 1;
        }
        else
        {
            roll_again = 0;
        }
    }

    // Print the results
    printf("The results are:\n");
    for (int i = 1; i <= MAX_NUMBER; i++)
    {
        printf("%d rolled %d times.\n", i, results[i]);
    }

    // Free the memory allocated for the results array
    free(results);

    return 0;
}