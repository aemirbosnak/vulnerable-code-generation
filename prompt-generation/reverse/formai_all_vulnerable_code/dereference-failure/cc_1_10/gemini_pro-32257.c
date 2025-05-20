//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room definitions
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

// Item definitions
typedef struct item {
    char* name;
    char* description;
} item;

// Player definition
typedef struct player {
    room* location;
    item* inventory[10];
} player;

// Create a new room
room* create_room(char* name, char* description) {
    room* new_room = malloc(sizeof(room));
    new_room->name = name;
    new_room->description = description;
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

// Create a new item
item* create_item(char* name, char* description) {
    item* new_item = malloc(sizeof(item));
    new_item->name = name;
    new_item->description = description;
    return new_item;
}

// Create a new player
player* create_player(room* starting_room) {
    player* new_player = malloc(sizeof(player));
    new_player->location = starting_room;
    for (int i = 0; i < 10; i++) {
        new_player->inventory[i] = NULL;
    }
    return new_player;
}

// Print the description of the current room
void print_room_description(player* player) {
    printf("%s\n", player->location->description);
}

// Get the user's input
char* get_input() {
    char* input = malloc(100);
    scanf("%s", input);
    return input;
}

// Quit the game
void quit_game() {
    exit(0);
}

// Main game loop
int main() {
    // Create the rooms
    room* kitchen = create_room("Kitchen", "A small kitchen with a stove, oven, and refrigerator.");
    room* living_room = create_room("Living Room", "A cozy living room with a couch, TV, and fireplace.");
    room* bedroom = create_room("Bedroom", "A bedroom with a bed, dresser, and nightstand.");
    room* bathroom = create_room("Bathroom", "A bathroom with a sink, toilet, and shower.");
    
    // Connect the rooms
    kitchen->north = living_room;
    living_room->east = bedroom;
    bedroom->south = bathroom;
    bathroom->west = kitchen;
    
    // Create the player
    player* player = create_player(kitchen);
    
    // Main game loop
    while (1) {
        // Print the room description
        print_room_description(player);
    
        // Get the user's input
        char* input = get_input();
    
        // Parse the input
        if (strcmp(input, "quit") == 0) {
            quit_game();
        } else if (strcmp(input, "north") == 0) {
            if (player->location->north != NULL) {
                player->location = player->location->north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            if (player->location->east != NULL) {
                player->location = player->location->east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (player->location->south != NULL) {
                player->location = player->location->south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "west") == 0) {
            if (player->location->west != NULL) {
                player->location = player->location->west;
            } else {
                printf("You can't go that way.\n");
            }
        } else {
            printf("I don't understand that command.\n");
        }
    }
    
    return 0;
}