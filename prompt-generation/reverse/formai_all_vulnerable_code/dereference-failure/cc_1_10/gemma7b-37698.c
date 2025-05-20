//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int floor, currentFloor = 1, direction = 0;

    printf("Welcome to the Montague-Capulet Elevator!\n");

    // Loop until the user enters a floor or chooses to exit
    while (1)
    {
        printf("Enter the floor you want to go to (or press 'e' to exit): ");
        char input;
        scanf(" %c", &input);

        // Check if the user wants to exit
        if (input == 'e')
        {
            printf("Thank you for using the Montague-Capulet Elevator. Goodbye!\n");
            break;
        }

        // Convert the user's input into an integer
        floor = atoi(&input);

        // Check if the floor is valid
        if (floor < 1 || floor > 10)
        {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }

        // Calculate the direction of travel
        if (floor > currentFloor)
        {
            direction = 1;
        }
        else
        {
            direction = -1;
        }

        // Move the elevator to the specified floor
        currentFloor += direction;

        // Announce the current floor
        printf("The elevator is on floor %d.\n", currentFloor);
    }

    return 0;
}