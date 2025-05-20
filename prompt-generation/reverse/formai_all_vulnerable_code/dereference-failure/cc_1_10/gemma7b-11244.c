//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include <stdio.h>

void main()
{
    int choice, room_num, treasure_found = 0;

    // Create a simple text-based map of rooms
    char **map = malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        map[i] = malloc(10 * sizeof(char));
    }

    // Initialize the rooms
    map[0][0] = 'A';
    map[0][1] = 'T';
    map[1][0] = 'B';
    map[1][1] = 'R';
    map[2][0] = 'C';
    map[2][1] = 'O';
    map[3][0] = 'D';
    map[3][1] = 'N';
    map[4][0] = 'E';
    map[4][1] = 'S';

    // The hero starts in room A
    room_num = 0;

    // Main game loop
    while (!treasure_found)
    {
        // Display the room description
        printf("You are in room %c.\n", map[room_num][0]);

        // Get the user's choice
        printf("Enter your choice (1-2): ");
        scanf("%d", &choice);

        // Move to the chosen room
        switch (choice)
        {
            case 1:
                room_num++;
                break;
            case 2:
                room_num--;
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Check if the treasure has been found
        if (map[room_num][1] == 'T')
        {
            treasure_found = 1;
            printf("You have found the treasure!\n");
        }
    }

    // Free the memory allocated for the map
    for (int i = 0; i < 5; i++)
    {
        free(map[i]);
    }
    free(map);

    return;
}