//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

// Define room descriptions
char **room_descriptions = NULL;

// Define room connections
int **room_connections = NULL;

// Define the player's current room
int current_room = 0;

void initialize_game()
{
    // Allocate memory for room descriptions and connections
    room_descriptions = malloc(MAX_ROOM_NUM * sizeof(char *));
    room_connections = malloc(MAX_ROOM_NUM * MAX_ROOM_NUM * sizeof(int));

    // Create room descriptions
    room_descriptions[0] = "You are in a cozy living room. There is a comfortable couch and a coffee table in the center of the room.";
    room_descriptions[1] = "You are in a spacious kitchen. There is a fridge, a stove, and a table in the room.";
    room_descriptions[2] = "You are in a bedroom. There is a bed, a dresser, and a window in the room.";
    room_descriptions[3] = "You are in a bathroom. There is a sink, a bathtub, and a mirror in the room.";
    room_descriptions[4] = "You are in a hallway. There are doors to the other rooms in the house.";

    // Create room connections
    room_connections[0][1] = 1;
    room_connections[0][2] = 1;
    room_connections[1][2] = 1;
    room_connections[1][3] = 1;
    room_connections[2][3] = 1;
    room_connections[2][4] = 1;
    room_connections[3][4] = 1;
}

void play_game()
{
    // Display the current room description
    printf("%s", room_descriptions[current_room]);

    // Get the player's input
    char input[20];
    printf("What do you want to do? ");
    scanf("%s", input);

    // Check if the input is valid
    if (input[0] >= 'a' && input[0] <= 'z')
    {
        // Execute the player's action
        switch (input[0])
        {
            case 'n':
                current_room = room_connections[current_room][0];
                play_game();
                break;
            case 's':
                current_room = room_connections[current_room][1];
                play_game();
                break;
            case 'e':
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                play_game();
                break;
        }
    }
    else
    {
        printf("Invalid input.\n");
        play_game();
    }
}

int main()
{
    initialize_game();
    play_game();

    return 0;
}