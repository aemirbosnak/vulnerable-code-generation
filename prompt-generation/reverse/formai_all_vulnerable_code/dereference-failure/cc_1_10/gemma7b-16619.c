//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand(time(NULL));

    // Create a haunted house structure
    struct haunted_house
    {
        char **rooms;
        int num_rooms;
        int current_room;
    } haunted_house_t = {NULL, 0, 0};

    // Allocate memory for the rooms
    haunted_house_t.rooms = (char **)malloc(sizeof(char *) * 3);
    haunted_house_t.rooms[0] = "The Living Room";
    haunted_house_t.rooms[1] = "The Dining Room";
    haunted_house_t.rooms[2] = "The Master Bedroom";

    // Set the number of rooms
    haunted_house_t.num_rooms = 3;

    // Set the current room
    haunted_house_t.current_room = 0;

    // Start the haunted house simulation
    while (1)
    {
        // Display the current room
        printf("You are currently in the %s.\n", haunted_house_t.rooms[haunted_house_t.current_room]);

        // Get the user's input
        char input[20];
        printf("Enter a command: ");
        scanf("%s", input);

        // Process the user's input
        if (strcmp(input, "go") == 0)
        {
            // Move to the next room
            haunted_house_t.current_room++;

            // Check if the user has reached the end of the house
            if (haunted_house_t.current_room >= haunted_house_t.num_rooms - 1)
            {
                // You have reached the end of the house!
                printf("You have reached the end of the house. Congratulations!");
                break;
            }

            // Display the next room
            printf("You have moved to the %s.\n", haunted_house_t.rooms[haunted_house_t.current_room]);
        }
        else if (strcmp(input, "quit") == 0)
        {
            // Quit the game
            break;
        }
        else
        {
            // Invalid command
            printf("Invalid command. Please try again.\n");
        }
    }

    // Free the memory allocated for the rooms
    free(haunted_house_t.rooms);

    return 0;
}