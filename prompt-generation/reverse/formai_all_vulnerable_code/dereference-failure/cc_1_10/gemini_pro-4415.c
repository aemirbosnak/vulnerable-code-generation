//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the data structure for a room
typedef struct room {
    int number;             // The room number
    char *description;      // A description of the room
    struct room *north;     // The room to the north
    struct room *east;      // The room to the east
    struct room *south;     // The room to the south
    struct room *west;      // The room to the west
} room;

// Define the data structure for the haunted house
typedef struct haunted_house {
    room *rooms[MAX_ROOMS];  // The array of rooms
    int num_rooms;           // The number of rooms in the house
} haunted_house;

// Create a new haunted house
haunted_house *create_haunted_house() {
    // Allocate memory for the haunted house
    haunted_house *house = malloc(sizeof(haunted_house));

    // Set the number of rooms in the house to 0
    house->num_rooms = 0;

    // Return the haunted house
    return house;
}

// Add a room to the haunted house
void add_room(haunted_house *house, room *room) {
    // Add the room to the array of rooms
    house->rooms[house->num_rooms] = room;

    // Increment the number of rooms in the house
    house->num_rooms++;
}

// Get a random room from the haunted house
room *get_random_room(haunted_house *house) {
    // Get a random number between 0 and the number of rooms in the house
    int random_number = rand() % house->num_rooms;

    // Return the room at the random index
    return house->rooms[random_number];
}

// Print the description of a room
void print_room_description(room *room) {
    // Print the room number and description
    printf("Room %d: %s\n", room->number, room->description);
}

// Explore a haunted house
void explore_haunted_house(haunted_house *house, room *current_room) {
    // Print the description of the current room
    print_room_description(current_room);

    // Get the exits from the current room
    room *north_exit = current_room->north;
    room *east_exit = current_room->east;
    room *south_exit = current_room->south;
    room *west_exit = current_room->west;

    // Get a random exit from the current room
    room *random_exit = NULL;
    int random_number = rand() % 4;
    switch (random_number) {
        case 0:
            random_exit = north_exit;
            break;
        case 1:
            random_exit = east_exit;
            break;
        case 2:
            random_exit = south_exit;
            break;
        case 3:
            random_exit = west_exit;
            break;
    }

    // If the random exit is not NULL, explore it
    if (random_exit != NULL) {
        explore_haunted_house(house, random_exit);
    }
}

// Free the memory allocated for a haunted house
void free_haunted_house(haunted_house *house) {
    // Free the memory allocated for each room in the house
    for (int i = 0; i < house->num_rooms; i++) {
        free(house->rooms[i]);
    }

    // Free the memory allocated for the haunted house
    free(house);
}

// Main function
int main() {
    // Create a new haunted house
    haunted_house *house = create_haunted_house();

    // Add rooms to the haunted house
    room *room1 = malloc(sizeof(room));
    room1->number = 1;
    room1->description = "A dark and dusty room with a single window.";
    add_room(house, room1);

    room *room2 = malloc(sizeof(room));
    room2->number = 2;
    room2->description = "A large and spacious room with a fireplace.";
    add_room(house, room2);

    room *room3 = malloc(sizeof(room));
    room3->number = 3;
    room3->description = "A small and cramped room with a single bed.";
    add_room(house, room3);

    room *room4 = malloc(sizeof(room));
    room4->number = 4;
    room4->description = "A long and narrow room with a high ceiling.";
    add_room(house, room4);

    room *room5 = malloc(sizeof(room));
    room5->number = 5;
    room5->description = "A circular room with a domed ceiling.";
    add_room(house, room5);

    room *room6 = malloc(sizeof(room));
    room6->number = 6;
    room6->description = "A secret room hidden behind a false wall.";
    add_room(house, room6);

    room *room7 = malloc(sizeof(room));
    room7->number = 7;
    room7->description = "A room filled with cobwebs and dust.";
    add_room(house, room7);

    room *room8 = malloc(sizeof(room));
    room8->number = 8;
    room8->description = "A room with a single door that is locked.";
    add_room(house, room8);

    room *room9 = malloc(sizeof(room));
    room9->number = 9;
    room9->description = "A room with a large window that overlooks the forest.";
    add_room(house, room9);

    room *room10 = malloc(sizeof(room));
    room10->number = 10;
    room10->description = "A room with a spiral staircase that leads to the roof.";
    add_room(house, room10);

    // Connect the rooms in the haunted house
    room1->north = room2;
    room1->east = room3;
    room1->south = room4;
    room1->west = NULL;

    room2->north = room3;
    room2->east = room4;
    room2->south = room5;
    room2->west = room1;

    room3->north = room4;
    room3->east = room5;
    room3->south = room6;
    room3->west = room2;

    room4->north = room5;
    room4->east = room6;
    room4->south = room7;
    room4->west = room3;

    room5->north = room6;
    room5->east = room7;
    room5->south = room8;
    room5->west = room4;

    room6->north = room7;
    room6->east = room8;
    room6->south = room9;
    room6->west = room5;

    room7->north = room8;
    room7->east = room9;
    room7->south = room10;
    room7->west = room6;

    room8->north = room9;
    room8->east = room10;
    room8->south = NULL;
    room8->west = room7;

    room9->north = room10;
    room9->east = NULL;
    room9->south = NULL;
    room9->west = room8;

    room10->north = NULL;
    room10->east = NULL;
    room10->south = NULL;
    room10->west = room9;

    // Get a random room from the haunted house
    room *current_room = get_random_room(house);

    // Explore the haunted house
    explore_haunted_house(house, current_room);

    // Free the memory allocated for the haunted house
    free_haunted_house(house);

    return 0;
}