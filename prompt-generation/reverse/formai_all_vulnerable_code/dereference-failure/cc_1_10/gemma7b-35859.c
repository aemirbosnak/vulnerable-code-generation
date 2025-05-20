//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(int difficulty)
{
    int rooms_visited = 0;
    int current_room = 0;
    char **rooms = malloc(sizeof(char *) * 5);

    for (int i = 0; i < 5; i++)
    {
        rooms[i] = malloc(sizeof(char) * 20);
    }

    // Populate the rooms with spooky descriptions
    rooms[0] = "The Foyer: A cold wind whispers secrets through the decaying grandeur of this hall.";
    rooms[1] = "The Living Room: A chilling scent of decay and blood permeates this room.";
    rooms[2] = "The Dining Hall: The table is set for a feast, but the food is cold and the candles are flickering.";
    rooms[3] = "The Study: Books are strewn about the floor and the air is thick with the scent of burnt parchment.";
    rooms[4] = "The Master Bedroom: The bed is shrouded in mystery and the air is thick with the scent of fear.";

    // Create a spooky atmosphere
    srand(time(NULL));
    int ambient_noise = rand() % 3;
    switch (ambient_noise)
    {
        case 0:
            printf("A sinister hum echoes through the halls.\n");
            break;
        case 1:
            printf("The wind howls and screams through the trees.\n");
            break;
        case 2:
            printf("The pipes squeal with an unsettling whine.\n");
            break;
    }

    // Simulate exploration of the haunted house
    while (rooms_visited < 5)
    {
        // Prompt the player to choose a direction
        printf("Please choose a direction (N, S, E, W): ");
        char direction = getchar();

        // Move the player to the next room
        switch (direction)
        {
            case 'N':
                current_room++;
                break;
            case 'S':
                current_room--;
                break;
            case 'E':
                current_room++;
                break;
            case 'W':
                current_room--;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the player has visited the room
        if (rooms_visited == current_room)
        {
            printf("%s\n", rooms[current_room]);
        }

        // Increment the number of rooms visited
        rooms_visited++;
    }

    // Free the memory allocated for the rooms
    for (int i = 0; i < 5; i++)
    {
        free(rooms[i]);
    }
    free(rooms);
}

int main()
{
    play_haunted_house(3);

    return 0;
}