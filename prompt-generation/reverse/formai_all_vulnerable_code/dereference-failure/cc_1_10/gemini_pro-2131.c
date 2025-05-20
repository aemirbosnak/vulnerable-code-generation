//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the data structure for a room
typedef struct room {
    int north; // The room to the north
    int south; // The room to the south
    int east;  // The room to the east
    int west;  // The room to the west
    int visited; // Whether or not the room has been visited
} room;

// Define the data structure for the haunted house
typedef struct haunted_house {
    room rooms[MAX_ROOMS]; // The array of rooms
    int current_room; // The current room the player is in
} haunted_house;

// Create a new haunted house
haunted_house* create_haunted_house() {
    // Allocate memory for the haunted house
    haunted_house* house = malloc(sizeof(haunted_house));

    // Initialize the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        house->rooms[i].north = -1;
        house->rooms[i].south = -1;
        house->rooms[i].east = -1;
        house->rooms[i].west = -1;
        house->rooms[i].visited = 0;
    }

    // Set the current room to the first room
    house->current_room = 0;

    // Return the haunted house
    return house;
}

// Destroy a haunted house
void destroy_haunted_house(haunted_house* house) {
    // Free the memory for the haunted house
    free(house);
}

// Print the current room
void print_room(haunted_house* house) {
    // Get the current room
    room* current_room = &house->rooms[house->current_room];

    // Print the room description
    printf("You are in a room.\n");
    if (current_room->north != -1) {
        printf("There is a door to the north.\n");
    }
    if (current_room->south != -1) {
        printf("There is a door to the south.\n");
    }
    if (current_room->east != -1) {
        printf("There is a door to the east.\n");
    }
    if (current_room->west != -1) {
        printf("There is a door to the west.\n");
    }
}

// Move the player to a new room
void move_player(haunted_house* house, int direction) {
    // Get the current room
    room* current_room = &house->rooms[house->current_room];

    // Move the player to the new room
    switch (direction) {
        case 'n':
            house->current_room = current_room->north;
            break;
        case 's':
            house->current_room = current_room->south;
            break;
        case 'e':
            house->current_room = current_room->east;
            break;
        case 'w':
            house->current_room = current_room->west;
            break;
    }
}

// Generate a random haunted house
void generate_haunted_house(haunted_house* house) {
    // Seed the random number generator
    srand(time(NULL));

    // Create a list of all the rooms
    int rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = i;
    }

    // Shuffle the list of rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        int j = rand() % MAX_ROOMS;
        int temp = rooms[i];
        rooms[i] = rooms[j];
        rooms[j] = temp;
    }

    // Connect the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        int room1 = rooms[i];
        int room2 = rooms[(i + 1) % MAX_ROOMS];
        house->rooms[room1].east = room2;
        house->rooms[room2].west = room1;
    }
}

// Print the haunted house
void print_haunted_house(haunted_house* house) {
    // Print the current room
    print_room(house);

    // Print the visited rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (house->rooms[i].visited) {
            printf("Room %d has been visited.\n", i);
        }
    }
}

// Main function
int main() {
    // Create a new haunted house
    haunted_house* house = create_haunted_house();

    // Generate a random haunted house
    generate_haunted_house(house);

    // Play the game
    while (1) {
        // Print the haunted house
        print_haunted_house(house);

        // Get the player's input
        char input;
        printf("What do you want to do? (n/s/e/w/q) ");
        scanf(" %c", &input);

        // Quit the game
        if (input == 'q') {
            break;
        }

        // Move the player
        move_player(house, input);
    }

    // Destroy the haunted house
    destroy_haunted_house(house);

    return 0;
}