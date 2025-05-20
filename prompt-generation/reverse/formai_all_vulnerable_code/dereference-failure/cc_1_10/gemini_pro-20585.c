//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the structure of a room
typedef struct room {
    int number;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

// Define the structure of the haunted house
typedef struct haunted_house {
    room *rooms[MAX_ROOMS];
    int num_rooms;
} haunted_house;

// Create a new haunted house
haunted_house *create_haunted_house() {
    haunted_house *house = malloc(sizeof(haunted_house));
    house->num_rooms = 0;
    return house;
}

// Add a new room to the haunted house
void add_room(haunted_house *house, room *room) {
    house->rooms[house->num_rooms++] = room;
}

// Get a random room from the haunted house
room *get_random_room(haunted_house *house) {
    return house->rooms[rand() % house->num_rooms];
}

// Print the description of a room
void print_room_description(room *room) {
    printf("You are in room %d.\n", room->number);
    printf("%s\n", room->description);
}

// Get a random direction
int get_random_direction() {
    return rand() % 4;
}

// Move to a new room
room *move_room(room *room) {
    int direction = get_random_direction();
    switch (direction) {
        case 0:
            return room->north;
        case 1:
            return room->east;
        case 2:
            return room->south;
        case 3:
            return room->west;
    }
    return room;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new haunted house
    haunted_house *house = create_haunted_house();

    // Add some rooms to the haunted house
    room *room1 = malloc(sizeof(room));
    room1->number = 1;
    room1->description = "A dark and musty room with a single window.";
    room1->north = NULL;
    room1->east = NULL;
    room1->south = NULL;
    room1->west = NULL;
    add_room(house, room1);

    room *room2 = malloc(sizeof(room));
    room2->number = 2;
    room2->description = "A large and spacious room with a high ceiling.";
    room2->north = NULL;
    room2->east = NULL;
    room2->south = NULL;
    room2->west = room1;
    add_room(house, room2);

    room *room3 = malloc(sizeof(room));
    room3->number = 3;
    room3->description = "A small and cramped room with a low ceiling.";
    room3->north = NULL;
    room3->east = room2;
    room3->south = NULL;
    room3->west = NULL;
    add_room(house, room3);

    room *room4 = malloc(sizeof(room));
    room4->number = 4;
    room4->description = "A long and narrow room with a winding staircase.";
    room4->north = NULL;
    room4->east = NULL;
    room4->south = room3;
    room4->west = NULL;
    add_room(house, room4);

    room *room5 = malloc(sizeof(room));
    room5->number = 5;
    room5->description = "A large and open room with a fireplace.";
    room5->north = room4;
    room5->east = NULL;
    room5->south = NULL;
    room5->west = NULL;
    add_room(house, room5);

    // Get a starting room
    room *room = get_random_room(house);

    // Loop until the player quits
    while (1) {
        // Print the description of the current room
        print_room_description(room);

        // Get a command from the player
        char command[80];
        printf("Enter a command (move, quit): ");
        scanf("%s", command);

        // Handle the command
        if (strcmp(command, "move") == 0) {
            // Move to a new room
            room = move_room(room);
        } else if (strcmp(command, "quit") == 0) {
            // Quit the game
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Free the memory allocated for the haunted house
    for (int i = 0; i < house->num_rooms; i++) {
        free(house->rooms[i]);
    }
    free(house);

    return 0;
}