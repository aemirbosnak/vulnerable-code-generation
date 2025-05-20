//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the maximum number of exits per room
#define MAX_EXITS 4

// Define the probability of an exit being locked
#define LOCK_PROBABILITY 0.5

// Define the maximum number of items in a room
#define MAX_ITEMS 5

// Define the maximum length of an item name
#define MAX_ITEM_NAME_LENGTH 20

// Define the structure of a room
typedef struct {
    int exits[MAX_EXITS];
    int num_exits;
    int locked_exits[MAX_EXITS];
    int num_locked_exits;
    char *items[MAX_ITEMS];
    int num_items;
} Room;

// Define the structure of the haunted house
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} HauntedHouse;

// Create a new haunted house
HauntedHouse *create_haunted_house() {
    HauntedHouse *haunted_house = malloc(sizeof(HauntedHouse));
    haunted_house->num_rooms = 0;
    return haunted_house;
}

// Add a room to the haunted house
void add_room(HauntedHouse *haunted_house, Room room) {
    haunted_house->rooms[haunted_house->num_rooms] = room;
    haunted_house->num_rooms++;
}

// Generate a random room
Room generate_room() {
    Room room;

    // Generate a random number of exits
    room.num_exits = rand() % MAX_EXITS + 1;

    // Generate a random number of locked exits
    room.num_locked_exits = rand() % room.num_exits;

    // Generate a random number of items
    room.num_items = rand() % MAX_ITEMS;

    // Generate the exits
    for (int i = 0; i < room.num_exits; i++) {
        room.exits[i] = rand() % MAX_ROOMS;
    }

    // Generate the locked exits
    for (int i = 0; i < room.num_locked_exits; i++) {
        room.locked_exits[i] = rand() % room.num_exits;
    }

    // Generate the items
    for (int i = 0; i < room.num_items; i++) {
        room.items[i] = malloc(MAX_ITEM_NAME_LENGTH);
        sprintf(room.items[i], "Item %d", i + 1);
    }

    return room;
}

// Print the haunted house
void print_haunted_house(HauntedHouse *haunted_house) {
    for (int i = 0; i < haunted_house->num_rooms; i++) {
        Room room = haunted_house->rooms[i];

        printf("Room %d\n", i + 1);
        printf("Exits: ");
        for (int j = 0; j < room.num_exits; j++) {
            printf("%d ", room.exits[j] + 1);
        }
        printf("\n");

        printf("Locked exits: ");
        for (int j = 0; j < room.num_locked_exits; j++) {
            printf("%d ", room.locked_exits[j] + 1);
        }
        printf("\n");

        printf("Items: ");
        for (int j = 0; j < room.num_items; j++) {
            printf("%s ", room.items[j]);
        }
        printf("\n");
    }
}

// Free the haunted house
void free_haunted_house(HauntedHouse *haunted_house) {
    for (int i = 0; i < haunted_house->num_rooms; i++) {
        Room room = haunted_house->rooms[i];

        for (int j = 0; j < room.num_items; j++) {
            free(room.items[j]);
        }
    }

    free(haunted_house);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new haunted house
    HauntedHouse *haunted_house = create_haunted_house();

    // Generate 10 random rooms
    for (int i = 0; i < 10; i++) {
        Room room = generate_room();
        add_room(haunted_house, room);
    }

    // Print the haunted house
    print_haunted_house(haunted_house);

    // Free the haunted house
    free_haunted_house(haunted_house);

    return 0;
}