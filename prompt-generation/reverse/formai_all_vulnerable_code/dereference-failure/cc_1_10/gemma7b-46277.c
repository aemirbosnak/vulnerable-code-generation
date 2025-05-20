//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house_simulator()
{
    int i, j, r, c, haunted_room, selected_room, sound_effect;

    // Create a 2D array to store the haunted house layout
    int **haunted_house = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++)
    {
        haunted_house[i] = (int*)malloc(5 * sizeof(int));
    }

    // Populate the haunted house layout with rooms
    haunted_house[0][0] = 1;
    haunted_house[0][1] = 2;
    haunted_house[0][2] = 3;
    haunted_house[1][0] = 4;
    haunted_house[1][1] = 5;
    haunted_house[1][2] = 6;
    haunted_house[2][0] = 7;
    haunted_house[2][1] = 8;
    haunted_house[2][2] = 9;
    haunted_house[3][0] = 10;
    haunted_house[3][1] = 11;
    haunted_house[3][2] = 12;
    haunted_house[4][0] = 13;
    haunted_house[4][1] = 14;
    haunted_house[4][2] = 15;

    // Seed the random number generator
    srand(time(NULL));

    // Select a haunted room
    haunted_room = haunted_house[rand() % 5][rand() % 5];

    // Play a sound effect
    sound_effect = rand() % 3;

    // Display the haunted room
    printf("You are in room %d.\n", haunted_room);

    // Check if the room is haunted
    if (haunted_house[haunted_room][0] == 1)
    {
        printf("The room is haunted.\n");
    }

    // Free the memory allocated for the haunted house layout
    for (i = 0; i < 5; i++)
    {
        free(haunted_house[i]);
    }
    free(haunted_house);
}

int main()
{
    haunted_house_simulator();

    return 0;
}