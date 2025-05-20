//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Room types
enum room_type {
    EMPTY,
    BEDROOM,
    BATHROOM,
    KITCHEN,
    LIVING_ROOM,
    SECRET_ROOM
};

// Room struct
typedef struct room {
    enum room_type type;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

// Player struct
typedef struct player {
    room *current_room;
    int health;
} player;

// Function to create a new room
room *create_room(enum room_type type, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->type = type;
    new_room->description = description;
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

// Function to destroy a room
void destroy_room(room *room) {
    free(room->description);
    free(room);
}

// Function to create a new player
player *create_player(room *starting_room) {
    player *new_player = malloc(sizeof(player));
    new_player->current_room = starting_room;
    new_player->health = 100;
    return new_player;
}

// Function to destroy a player
void destroy_player(player *player) {
    free(player);
}

// Function to print the description of the current room
void print_room_description(player *player) {
    printf("%s\n", player->current_room->description);
}

// Function to move the player in a given direction
void move_player(player *player, char direction) {
    switch (direction) {
        case 'n':
            if (player->current_room->north != NULL) {
                player->current_room = player->current_room->north;
            } else {
                printf("You can't go that way.\n");
            }
            break;
        case 'e':
            if (player->current_room->east != NULL) {
                player->current_room = player->current_room->east;
            } else {
                printf("You can't go that way.\n");
            }
            break;
        case 's':
            if (player->current_room->south != NULL) {
                player->current_room = player->current_room->south;
            } else {
                printf("You can't go that way.\n");
            }
            break;
        case 'w':
            if (player->current_room->west != NULL) {
                player->current_room = player->current_room->west;
            } else {
                printf("You can't go that way.\n");
            }
            break;
        default:
            printf("Invalid direction.\n");
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the rooms
    room *bedroom = create_room(BEDROOM, "You are in a bedroom. There is a bed, a dresser, and a nightstand.");
    room *bathroom = create_room(BATHROOM, "You are in a bathroom. There is a toilet, a sink, and a bathtub.");
    room *kitchen = create_room(KITCHEN, "You are in a kitchen. There is a stove, a refrigerator, and a sink.");
    room *living_room = create_room(LIVING_ROOM, "You are in a living room. There is a couch, a chair, and a TV.");
    room *secret_room = create_room(SECRET_ROOM, "You are in a secret room. There is a treasure chest in the middle of the room.");

    // Connect the rooms
    bedroom->north = bathroom;
    bathroom->south = bedroom;
    bathroom->east = kitchen;
    kitchen->west = bathroom;
    kitchen->south = living_room;
    living_room->north = kitchen;
    living_room->east = secret_room;
    secret_room->west = living_room;

    // Create the player
    player *player = create_player(bedroom);

    // Game loop
    while (player->health > 0) {
        // Print the room description
        print_room_description(player);

        // Get the player's input
        char input;
        printf("What do you want to do? (n/e/s/w/q)\n");
        scanf(" %c", &input);

        // Handle the player's input
        switch (input) {
            case 'n':
            case 'e':
            case 's':
            case 'w':
                move_player(player, input);
                break;
            case 'q':
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }
    }

    // The player has died
    printf("You have died.\n");

    // Destroy the player and the rooms
    destroy_player(player);
    destroy_room(bedroom);
    destroy_room(bathroom);
    destroy_room(kitchen);
    destroy_room(living_room);
    destroy_room(secret_room);

    return 0;
}