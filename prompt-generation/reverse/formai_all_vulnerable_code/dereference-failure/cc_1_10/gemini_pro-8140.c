//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the maximum number of exits per room
#define MAX_EXITS 3

// Define the possible exits from a room
#define EXIT_NORTH 1
#define EXIT_EAST  2
#define EXIT_SOUTH 3
#define EXIT_WEST  4

// Define the possible events that can occur in a room
#define EVENT_NONE      0
#define EVENT_GHOST     1
#define EVENT_CREATURE  2
#define EVENT_TRAP     3
#define EVENT_TREASURE 4

// Define the structure of a room
typedef struct room {
    int exits[MAX_EXITS];  // The exits from the room
    int events[MAX_EXITS]; // The events that can occur in the room
} room_t;

// Define the structure of the haunted house
typedef struct haunted_house {
    room_t rooms[MAX_ROOMS];  // The rooms in the haunted house
    int num_rooms;            // The number of rooms in the haunted house
} haunted_house_t;

// Create a new haunted house
haunted_house_t* create_haunted_house() {
    // Allocate memory for the haunted house
    haunted_house_t* haunted_house = malloc(sizeof(haunted_house_t));

    // Set the number of rooms in the haunted house
    haunted_house->num_rooms = rand() % MAX_ROOMS + 1;

    // Create the rooms in the haunted house
    for (int i = 0; i < haunted_house->num_rooms; i++) {
        // Set the exits from the room
        for (int j = 0; j < MAX_EXITS; j++) {
            haunted_house->rooms[i].exits[j] = rand() % 2;
        }

        // Set the events that can occur in the room
        for (int j = 0; j < MAX_EXITS; j++) {
            haunted_house->rooms[i].events[j] = rand() % 5;
        }
    }

    // Return the haunted house
    return haunted_house;
}

// Destroy a haunted house
void destroy_haunted_house(haunted_house_t* haunted_house) {
    // Free the memory allocated for the haunted house
    free(haunted_house);
}

// Print the haunted house
void print_haunted_house(haunted_house_t* haunted_house) {
    // Print the number of rooms in the haunted house
    printf("The haunted house has %d rooms.\n", haunted_house->num_rooms);

    // Print the rooms in the haunted house
    for (int i = 0; i < haunted_house->num_rooms; i++) {
        // Print the exits from the room
        printf("Room %d has the following exits:\n", i);
        for (int j = 0; j < MAX_EXITS; j++) {
            if (haunted_house->rooms[i].exits[j]) {
                printf(" - Exit %d\n", j + 1);
            }
        }

        // Print the events that can occur in the room
        printf("Room %d has the following events:\n", i);
        for (int j = 0; j < MAX_EXITS; j++) {
            switch (haunted_house->rooms[i].events[j]) {
                case EVENT_NONE:
                    printf(" - No event\n");
                    break;
                case EVENT_GHOST:
                    printf(" - Ghost\n");
                    break;
                case EVENT_CREATURE:
                    printf(" - Creature\n");
                    break;
                case EVENT_TRAP:
                    printf(" - Trap\n");
                    break;
                case EVENT_TREASURE:
                    printf(" - Treasure\n");
                    break;
            }
        }
    }
}

// Simulate a haunted house
void simulate_haunted_house(haunted_house_t* haunted_house) {
    // Initialize the player's position
    int player_room = 0;

    // Loop until the player exits the haunted house
    while (player_room != -1) {
        // Print the current room
        printf("You are in room %d.\n", player_room);

        // Get the exits from the current room
        int exits[MAX_EXITS];
        int num_exits = 0;
        for (int i = 0; i < MAX_EXITS; i++) {
            if (haunted_house->rooms[player_room].exits[i]) {
                exits[num_exits++] = i;
            }
        }

        // Get the player's input
        int input = 0;
        while (input < 1 || input > num_exits) {
            printf("Which exit do you want to take? (1-%d)", num_exits);
            scanf("%d", &input);
        }

        // Move the player to the next room
        player_room = exits[input - 1];

        // Check if an event occurred in the current room
        int event = haunted_house->rooms[player_room].events[input - 1];
        switch (event) {
            case EVENT_NONE:
                printf("Nothing happened.\n");
                break;
            case EVENT_GHOST:
                printf("You saw a ghost!\n");
                break;
            case EVENT_CREATURE:
                printf("You encountered a creature!\n");
                break;
            case EVENT_TRAP:
                printf("You fell into a trap!\n");
                break;
            case EVENT_TREASURE:
                printf("You found treasure!\n");
                break;
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a haunted house
    haunted_house_t* haunted_house = create_haunted_house();

    // Print the haunted house
    print_haunted_house(haunted_house);

    // Simulate the haunted house
    simulate_haunted_house(haunted_house);

    // Destroy the haunted house
    destroy_haunted_house(haunted_house);

    return 0;
}