//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room descriptions
char *room_descriptions[] = {
    "You are in a dark, damp cave. The air is thick with the smell of mold.",
    "You are in a small, windowless room. The walls are covered in strange symbols.",
    "You are in a large, open field. The grass is green and the sky is blue.",
    "You are in a dense forest. The trees are tall and the leaves are thick.",
    "You are in a castle. The walls are made of stone and the towers are tall.",
};

// Room exits
int room_exits[][4] = {
    {1, 2, -1, -1},
    {0, 3, -1, -1},
    {0, 4, 1, -1},
    {1, 4, 2, -1},
    {2, 3, -1, -1},
};

// Item descriptions
char *item_descriptions[] = {
    "A rusty old sword",
    "A glowing orb",
    "A magical key",
    "A healing potion",
    "A map of the castle",
};

// Item locations
int item_locations[] = {
    0,
    1,
    2,
    3,
    4,
};

// Player inventory
char *player_inventory[5];

// Game state
int current_room = 0;
int game_over = 0;

// Function to print the room description
void print_room_description()
{
    printf("%s\n", room_descriptions[current_room]);
}

// Function to print the room exits
void print_room_exits()
{
    printf("Exits:");
    for (int i = 0; i < 4; i++)
    {
        if (room_exits[current_room][i] != -1)
        {
            printf(" %d", room_exits[current_room][i]);
        }
    }
    printf("\n");
}

// Function to print the player inventory
void print_player_inventory()
{
    printf("Inventory:");
    for (int i = 0; i < 5; i++)
    {
        if (player_inventory[i] != NULL)
        {
            printf(" %s", player_inventory[i]);
        }
    }
    printf("\n");
}

// Function to handle player input
void handle_input()
{
    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    // Check if the player wants to quit
    if (strcmp(input, "quit\n") == 0)
    {
        game_over = 1;
        return;
    }

    // Check if the player wants to move
    if (strcmp(input, "north\n") == 0)
    {
        current_room = room_exits[current_room][0];
    }
    else if (strcmp(input, "east\n") == 0)
    {
        current_room = room_exits[current_room][1];
    }
    else if (strcmp(input, "south\n") == 0)
    {
        current_room = room_exits[current_room][2];
    }
    else if (strcmp(input, "west\n") == 0)
    {
        current_room = room_exits[current_room][3];
    }

    // Check if the player wants to pick up an item
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(input, item_descriptions[i]) == 0)
        {
            if (item_locations[i] == current_room)
            {
                player_inventory[i] = item_descriptions[i];
                item_locations[i] = -1;
            }
            else
            {
                printf("You can't reach that item.\n");
            }
        }
    }

    // Check if the player wants to use an item
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(input, player_inventory[i]) == 0)
        {
            // TODO: Implement item usage
        }
    }
}

// Main game loop
int main()
{
    // Print the welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");

    // Print the room description
    print_room_description();

    // Print the room exits
    print_room_exits();

    // Print the player inventory
    print_player_inventory();

    // Handle player input
    while (!game_over)
    {
        handle_input();
    }

    // Print the game over message
    printf("Game over!\n");

    return 0;
}