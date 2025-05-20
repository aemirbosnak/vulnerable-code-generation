//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room struct
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* south;
    struct room* east;
    struct room* west;
} Room;

// Player struct
typedef struct player {
    char* name;
    Room* current_room;
    int health;
} Player;

// Create a new room
Room* create_room(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

// Create a new player
Player* create_player(char* name, Room* starting_room) {
    Player* player = malloc(sizeof(Player));
    player->name = strdup(name);
    player->current_room = starting_room;
    player->health = 100;
    return player;
}

// Print the room description
void print_room_description(Room* room) {
    printf("\nYou are in the %s.\n", room->name);
    printf("%s\n", room->description);
}

// Process player input
void process_input(Player* player) {
    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    // Check for valid commands
    if (strcmp(input, "north") == 0) {
        if (player->current_room->north != NULL) {
            player->current_room = player->current_room->north;
            print_room_description(player->current_room);
        } else {
            printf("There is no door to the north.\n");
        }
    } else if (strcmp(input, "south") == 0) {
        if (player->current_room->south != NULL) {
            player->current_room = player->current_room->south;
            print_room_description(player->current_room);
        } else {
            printf("There is no door to the south.\n");
        }
    } else if (strcmp(input, "east") == 0) {
        if (player->current_room->east != NULL) {
            player->current_room = player->current_room->east;
            print_room_description(player->current_room);
        } else {
            printf("There is no door to the east.\n");
        }
    } else if (strcmp(input, "west") == 0) {
        if (player->current_room->west != NULL) {
            player->current_room = player->current_room->west;
            print_room_description(player->current_room);
        } else {
            printf("There is no door to the west.\n");
        }
    } else if (strcmp(input, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

// Main game loop
void game_loop(Player* player) {
    while (player->health > 0) {
        print_room_description(player->current_room);
        process_input(player);
    }
}

// Main function
int main() {
    // Create rooms
    Room* room1 = create_room("Room 1", "This is the first room.");
    Room* room2 = create_room("Room 2", "This is the second room.");
    Room* room3 = create_room("Room 3", "This is the third room.");

    // Connect rooms
    room1->north = room2;
    room2->south = room1;
    room2->east = room3;
    room3->west = room2;

    // Create player
    Player* player = create_player("Player", room1);

    // Start game loop
    game_loop(player);

    // Free memory
    free(room1);
    free(room2);
    free(room3);
    free(player);

    return 0;
}