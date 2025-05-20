//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 10

int main()
{
    int currentRoom = 0;
    int nextRoom = 0;
    char direction = ' ';

    // Create a room array
    char **rooms = (char**)malloc(MAX_ROOM * sizeof(char*));
    for (int i = 0; i < MAX_ROOM; i++)
    {
        rooms[i] = (char*)malloc(20 * sizeof(char));
    }

    // Initialize the rooms
    rooms[0] = "You are in a spaceship cockpit.";
    rooms[1] = "You are in a futuristic lounge.";
    rooms[2] = "You are in a holographic training room.";
    rooms[3] = "You are in a virtual reality arcade.";
    rooms[4] = "You are in a futuristic kitchen.";
    rooms[5] = "You are in a spaceship hangar.";
    rooms[6] = "You are in a secret room.";
    rooms[7] = "You are in a hidden chamber.";
    rooms[8] = "You are in a mysterious laboratory.";
    rooms[9] = "You are in a cosmic void.";

    // Seed the random number generator
    srand(time(NULL));

    // Start the adventure
    while (currentRoom != 9)
    {
        // Display the current room
        printf("%s\n", rooms[currentRoom]);

        // Get the direction of travel
        printf("Enter direction (N, S, E, W): ");
        scanf("%c", &direction);

        // Move to the next room
        switch (direction)
        {
            case 'N':
                nextRoom = (rand() % MAX_ROOM) + 1;
                break;
            case 'S':
                nextRoom = (rand() % MAX_ROOM) + 1;
                break;
            case 'E':
                nextRoom = (rand() % MAX_ROOM) + 1;
                break;
            case 'W':
                nextRoom = (rand() % MAX_ROOM) + 1;
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        // Check if the next room is valid
        if (nextRoom > MAX_ROOM || nextRoom <= 0)
        {
            printf("Invalid room number.\n");
            nextRoom = 0;
        }

        // Move to the next room
        currentRoom = nextRoom;
    }

    // End the adventure
    printf("You have reached the cosmic void.\n");

    // Free the memory
    for (int i = 0; i < MAX_ROOM; i++)
    {
        free(rooms[i]);
    }
    free(rooms);

    return 0;
}