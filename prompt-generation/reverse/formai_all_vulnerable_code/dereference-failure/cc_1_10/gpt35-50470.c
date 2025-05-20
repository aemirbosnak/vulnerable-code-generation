//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum length of input from user
#define MAX_INPUT_LENGTH 20

// Define maximum number of rooms in the haunted house
#define NUM_ROOMS 5

// Define structures for room and player
typedef struct Room {
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

typedef struct Player {
    Room* current_room;
} Player;

// Function prototypes
void create_rooms(Room* rooms[]);
void play_game(Player* player);
void move_player(Player* player, char* direction);
void print_room_description(Room* room);

// Main function
int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Create array of rooms
    Room* rooms[NUM_ROOMS];
    create_rooms(rooms);

    // Create player and set starting room
    Player player;
    player.current_room = rooms[rand() % NUM_ROOMS];

    // Play the game!
    play_game(&player);

    // Free memory used by rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        free(rooms[i]->description);
        free(rooms[i]);
    }

    return 0;
}

// Function to create rooms for the haunted house
void create_rooms(Room* rooms[]) {
    // Room 0
    rooms[0] = malloc(sizeof(Room));
    rooms[0]->description = strdup("You are in the entrance hall. There are doors to the north and east.");
    rooms[0]->north = NULL;
    rooms[0]->south = NULL;
    rooms[0]->east = rooms[1];
    rooms[0]->west = NULL;

    // Room 1
    rooms[1] = malloc(sizeof(Room));
    rooms[1]->description = strdup("You are in the library. There are books everywhere and a ladder to the south.");
    rooms[1]->north = rooms[3];
    rooms[1]->south = NULL;
    rooms[1]->east = NULL;
    rooms[1]->west = rooms[0];

    // Room 2
    rooms[2] = malloc(sizeof(Room));
    rooms[2]->description = strdup("You are in the kitchen. There is food on the stove and a door to the east.");
    rooms[2]->north = NULL;
    rooms[2]->south = NULL;
    rooms[2]->east = rooms[3];
    rooms[2]->west = NULL;

    // Room 3
    rooms[3] = malloc(sizeof(Room));
    rooms[3]->description = strdup("You are in the living room. There is a fireplace and doors to the north, south, east, and west.");
    rooms[3]->north = rooms[4];
    rooms[3]->south = rooms[1];
    rooms[3]->east = rooms[2];
    rooms[3]->west = rooms[0];

    // Room 4
    rooms[4] = malloc(sizeof(Room));
    rooms[4]->description = strdup("You are in the bedroom. There is a bed and a dresser with a mirror.");
    rooms[4]->north = NULL;
    rooms[4]->south = rooms[3];
    rooms[4]->east = NULL;
    rooms[4]->west = NULL;
}

// Function to play the game
void play_game(Player* player) {
    printf("Welcome to the haunted house! Let's get started...\n");
    print_room_description(player->current_room);

    // Loop until player reaches the bedroom (room 4)
    while (player->current_room != NULL && player->current_room != player->current_room->north) {
        // Get user input
        char input[MAX_INPUT_LENGTH];
        printf("Enter a direction (north/south/east/west): ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove newline character from input

        // Move player in specified direction
        move_player(player, input);

        // Print current room description
        print_room_description(player->current_room);
    }

    // Player has reached the bedroom
    printf("Congratulations, you made it to the bedroom! Sweet dreams.\n");
}

// Function to move player in specified direction
void move_player(Player* player, char* direction) {
    // Move player based on input
    if (strncmp(direction, "north", MAX_INPUT_LENGTH) == 0) {
        player->current_room = player->current_room->north;
    } else if (strncmp(direction, "south", MAX_INPUT_LENGTH) == 0) {
        player->current_room = player->current_room->south;
    } else if (strncmp(direction, "east", MAX_INPUT_LENGTH) == 0) {
        player->current_room = player->current_room->east;
    } else if (strncmp(direction, "west", MAX_INPUT_LENGTH) == 0) {
        player->current_room = player->current_room->west;
    } else {
        printf("Invalid direction. Try again.\n");
    }
}

// Function to print current room description
void print_room_description(Room* room) {
    printf("%s\n", room->description);
}