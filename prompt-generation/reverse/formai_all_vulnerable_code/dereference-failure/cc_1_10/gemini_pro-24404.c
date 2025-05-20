//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the number of rooms in the haunted house
#define NUM_ROOMS 10

// Define the possible events that can occur in a room
#define EVENT_NONE 0
#define EVENT_CREAK 1
#define EVENT_GROAN 2
#define EVENT_BANG 3
#define EVENT_SCREAM 4

// Define the possible states of the player
#define STATE_ALIVE 0
#define STATE_DEAD 1

// Define the structure of a room
typedef struct {
    int event;  // The event that occurs in the room
    bool visited;  // Whether the player has visited the room
} Room;

// Define the structure of the player
typedef struct {
    int state;  // The state of the player
    int num_visited;  // The number of rooms the player has visited
} Player;

// Create a new haunted house
Room* create_haunted_house() {
    // Allocate memory for the haunted house
    Room* haunted_house = malloc(sizeof(Room) * NUM_ROOMS);

    // Initialize the rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        haunted_house[i].event = EVENT_NONE;
        haunted_house[i].visited = false;
    }

    // Return the haunted house
    return haunted_house;
}

// Destroy the haunted house
void destroy_haunted_house(Room* haunted_house) {
    // Free the memory allocated for the haunted house
    free(haunted_house);
}

// Create a new player
Player* create_player() {
    // Allocate memory for the player
    Player* player = malloc(sizeof(Player));

    // Initialize the player
    player->state = STATE_ALIVE;
    player->num_visited = 0;

    // Return the player
    return player;
}

// Destroy the player
void destroy_player(Player* player) {
    // Free the memory allocated for the player
    free(player);
}

// Get a random event
int get_random_event() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 4
    int random_number = rand() % 5;

    // Return the event corresponding to the random number
    return random_number;
}

// Visit a room
void visit_room(Room* haunted_house, Player* player, int room_number) {
    // Get the event that occurs in the room
    int event = haunted_house[room_number].event;

    // Increment the number of rooms the player has visited
    player->num_visited++;

    // Handle the event
    switch (event) {
        case EVENT_NONE:
            // Nothing happens
            break;
        case EVENT_CREAK:
            // The floor creaks beneath the player's feet
            printf("The floor creaks beneath your feet.\n");
            break;
        case EVENT_GROAN:
            // A groan is heard from the darkness
            printf("A groan is heard from the darkness.\n");
            break;
        case EVENT_BANG:
            // Something bangs against the wall
            printf("Something bangs against the wall.\n");
            break;
        case EVENT_SCREAM:
            // A scream echoes through the house
            printf("A scream echoes through the house.\n");
            break;
    }

    // If the player has visited all the rooms, they win
    if (player->num_visited == NUM_ROOMS) {
        printf("You have visited all the rooms and escaped the haunted house!\n");
        player->state = STATE_ALIVE;
    }

    // If the player has heard a scream, they die
    if (event == EVENT_SCREAM) {
        printf("You hear a scream and die of fright.\n");
        player->state = STATE_DEAD;
    }
}

// Play the game
void play_game(Room* haunted_house, Player* player) {
    // While the player is alive, keep playing the game
    while (player->state == STATE_ALIVE) {
        // Get a random room number
        int room_number = rand() % NUM_ROOMS;

        // Visit the room
        visit_room(haunted_house, player, room_number);
    }
}

// Main function
int main() {
    // Create a haunted house
    Room* haunted_house = create_haunted_house();

    // Create a player
    Player* player = create_player();

    // Play the game
    play_game(haunted_house, player);

    // Destroy the haunted house and the player
    destroy_haunted_house(haunted_house);
    destroy_player(player);

    return 0;
}