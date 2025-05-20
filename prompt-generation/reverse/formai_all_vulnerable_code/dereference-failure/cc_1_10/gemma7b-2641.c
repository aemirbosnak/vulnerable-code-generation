//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

int main()
{
    int current_room = 0;
    int next_room = 0;
    char **rooms = malloc(MAX_ROOMS * sizeof(char *));

    // Allocate memory for each room
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        rooms[i] = malloc(20 * sizeof(char));
    }

    // Create a simple map of rooms
    rooms[0] = "You are in a cozy living room.";
    rooms[1] = "You are in a spacious kitchen.";
    rooms[2] = "You are in a mysterious attic.";
    rooms[3] = "You are in a dark and eerie basement.";

    // Set up the next room connections
    next_room = 1;
    rooms[0][1] = 'N';
    rooms[0][2] = 'S';

    next_room = 2;
    rooms[1][0] = 'W';
    rooms[1][3] = 'E';

    next_room = 3;
    rooms[2][0] = 'N';

    next_room = 4;
    rooms[3][2] = 'S';

    // Game loop
    while (current_room != MAX_ROOMS - 1)
    {
        printf("%s", rooms[current_room]);

        // Get the user's input
        char input[20];
        scanf("%s", input);

        // Check if the user's input matches the next room connection
        if (strcmp(input, rooms[current_room][next_room]) == 0)
        {
            current_room = next_room;
        }
    }

    // End game
    printf("You have reached the end of the adventure!");

    // Free memory
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        free(rooms[i]);
    }
    free(rooms);

    return 0;
}