//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

int main()
{
    int currentRoom = 0;
    char direction;

    // Create a map of rooms
    char **rooms = (char**)malloc(MAX_ROOM * sizeof(char*));
    for(int i = 0; i < MAX_ROOM; i++)
    {
        rooms[i] = (char*)malloc(20 * sizeof(char));
    }

    // Initialize the rooms
    rooms[0] = "You are in a crumbling city hall. There is a broken window to the east and a door to the south.";
    rooms[1] = "You are in a deserted apartment building. There is a broken elevator shaft to the west and a door to the north.";
    rooms[2] = "You are in a ruined shopping mall. There is a broken fountain to the east and a door to the south.";
    rooms[3] = "You are in a mysterious cave. There is a locked door to the north and a door to the east.";
    rooms[4] = "You have reached the center of the city. There is nothing here.";

    // Game loop
    while(currentRoom != MAX_ROOM - 1)
    {
        // Display the current room
        printf("%s", rooms[currentRoom]);

        // Get the direction of travel
        printf("Enter direction (N/S/E/W): ");
        scanf("%c", &direction);

        // Move in the direction
        switch(direction)
        {
            case 'N':
                currentRoom++;
                break;
            case 'S':
                currentRoom--;
                break;
            case 'E':
                currentRoom++;
                break;
            case 'W':
                currentRoom--;
                break;
        }

        // Check if the room has a door to the next room
        if(rooms[currentRoom][0] == 'D')
        {
            // Open the door and move to the next room
            printf("You open the door and enter the next room.\n");
            currentRoom++;
        }
        else
        {
            // There is no door to the next room, so you have reached the end of the game
            printf("You have reached the end of the game.\n");
            currentRoom = MAX_ROOM - 1;
        }
    }

    // Free the memory allocated for the rooms
    for(int i = 0; i < MAX_ROOM; i++)
    {
        free(rooms[i]);
    }
    free(rooms);

    return 0;
}