//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

int main()
{
    int current_room = 0;
    char input[100];

    // Create a room array
    char **rooms = (char **)malloc(MAX_ROOMS * sizeof(char *));
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        rooms[i] = (char *)malloc(100 * sizeof(char));
    }

    // Initialize the rooms
    rooms[0] = "You are in a cozy living room. There is a fireplace and a comfortable sofa.";
    rooms[1] = "You are in the kitchen. There is a stove, a fridge, and a dining table.";
    rooms[2] = "You are in the bedroom. There is a bed, a dresser, and a closet.";
    rooms[3] = "You are in the bathroom. There is a bathtub, a shower, and a toilet.";
    rooms[4] = "You are in the hallway. There is a door to each of the other rooms.";

    // Game loop
    while (1)
    {
        // Display the current room
        printf("%s\n", rooms[current_room]);

        // Get the user input
        printf("What do you want to do? ");
        scanf("%s", input);

        // Process the user input
        if (strcmp(input, "quit") == 0)
        {
            break;
        } else if (strcmp(input, "go north") == 0)
        {
            current_room++;
        } else if (strcmp(input, "go south") == 0)
        {
            current_room--;
        } else
        {
            printf("Invalid input.\n");
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        free(rooms[i]);
    }
    free(rooms);

    return 0;
}