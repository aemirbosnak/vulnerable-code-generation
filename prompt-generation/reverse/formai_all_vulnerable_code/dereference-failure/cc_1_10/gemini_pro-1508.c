//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

room *rooms[MAX_ROOMS];
int num_rooms = 0;

void create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    rooms[num_rooms++] = new_room;
}

void connect_rooms(room *room1, room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

void print_room(room *room) {
    printf("You are in the %s.\n", room->name);
    printf("%s\n", room->description);
    if (room->north != NULL) {
        printf("To the north, you see the %s.\n", room->north->name);
    }
    if (room->east != NULL) {
        printf("To the east, you see the %s.\n", room->east->name);
    }
    if (room->south != NULL) {
        printf("To the south, you see the %s.\n", room->south->name);
    }
    if (room->west != NULL) {
        printf("To the west, you see the %s.\n", room->west->name);
    }
}

int main() {
    srand(time(NULL));

    // Create the rooms
    create_room("Foyer", "A large, open room with a grand staircase leading up to the second floor.");
    create_room("Living Room", "A cozy room with a fireplace and a large couch.");
    create_room("Dining Room", "A formal room with a long table and chairs.");
    create_room("Kitchen", "A large room with a stove, oven, and refrigerator.");
    create_room("Bedroom", "A small room with a bed, dresser, and nightstand.");
    create_room("Bathroom", "A small room with a toilet, sink, and shower.");
    create_room("Study", "A small room with a desk, chair, and bookshelves.");
    create_room("Attic", "A large, dusty room with boxes and old furniture.");
    create_room("Basement", "A dark, damp room with a dirt floor and cobwebs.");
    create_room("Secret Passage", "A narrow, winding passage that leads to a hidden room.");

    // Connect the rooms
    connect_rooms(rooms[0], rooms[1], 'n');
    connect_rooms(rooms[0], rooms[2], 'e');
    connect_rooms(rooms[0], rooms[3], 's');
    connect_rooms(rooms[0], rooms[4], 'w');
    connect_rooms(rooms[1], rooms[5], 'e');
    connect_rooms(rooms[1], rooms[6], 'w');
    connect_rooms(rooms[2], rooms[7], 'n');
    connect_rooms(rooms[3], rooms[8], 'n');
    connect_rooms(rooms[4], rooms[9], 'e');

    // Choose a starting room
    room *current_room = rooms[rand() % num_rooms];

    // Main game loop
    while (1) {
        // Print the current room
        print_room(current_room);

        // Get the player's input
        char input[80];
        printf("> ");
        fgets(input, 80, stdin);

        // Parse the player's input
        char command[80];
        char argument[80];
        sscanf(input, "%s %s", command, argument);

        // Handle the player's input
        if (strcmp(command, "go") == 0) {
            // Move to the specified room
            if (strcmp(argument, "north") == 0) {
                current_room = current_room->north;
            } else if (strcmp(argument, "east") == 0) {
                current_room = current_room->east;
            } else if (strcmp(argument, "south") == 0) {
                current_room = current_room->south;
            } else if (strcmp(argument, "west") == 0) {
                current_room = current_room->west;
            } else {
                printf("Invalid direction.\n");
            }
        } else if (strcmp(command, "look") == 0) {
            // Print the current room's description
            print_room(current_room);
        } else if (strcmp(command, "quit") == 0) {
            // Exit the game
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Free the allocated memory
    for (int i = 0; i < num_rooms; i++) {
        free(rooms[i]->name);
        free(rooms[i]->description);
        free(rooms[i]);
    }

    return 0;
}