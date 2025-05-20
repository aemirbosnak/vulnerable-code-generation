//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define a list of locations
    char **locations = malloc(10 * sizeof(char *));
    locations[0] = "The Old House";
    locations[1] = "The Forest";
    locations[2] = "The Mountain";
    locations[3] = "The River";
    locations[4] = "The Town";
    locations[5] = "The Cave";
    locations[6] = "The Temple";
    locations[7] = "The Tower";
    locations[8] = "The Bridge";
    locations[9] = "The Garden";

    // Define the current location
    char current_location = 'a';

    // Loop until the player chooses to quit
    while (current_location != 'q')
    {
        // Display the current location
        printf("You are currently in %s.\n", locations[current_location]);

        // Get the player's input
        char input = getchar();

        // Check if the player has chosen to move to a new location
        switch (input)
        {
            case 'n':
                current_location = 'b';
                break;
            case 's':
                current_location = 'c';
                break;
            case 'e':
                current_location = 'd';
                break;
            case 'w':
                current_location = 'e';
                break;
            case 'q':
                printf("Thank you for playing! Goodbye.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    // Free the memory allocated for the locations list
    free(locations);
}