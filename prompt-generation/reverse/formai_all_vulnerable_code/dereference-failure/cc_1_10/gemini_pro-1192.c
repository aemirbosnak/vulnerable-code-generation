//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

room* create_room(char* name, char* description) {
    room* new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

void free_room(room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

void print_room(room* room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
}

int main() {
    room* rooms[MAX_ROOMS];

    // Create the rooms
    rooms[0] = create_room("The Foyer", "You are in the foyer of a large house. A grand staircase leads up to the second floor.");
    rooms[1] = create_room("The Living Room", "You are in the living room. A large fireplace dominates one wall, and comfortable chairs are arranged around it.");
    rooms[2] = create_room("The Dining Room", "You are in the dining room. A long table with chairs is set for dinner.");
    rooms[3] = create_room("The Kitchen", "You are in the kitchen. A stove, oven, and refrigerator are all within reach.");
    rooms[4] = create_room("The Master Bedroom", "You are in the master bedroom. A large bed takes up most of the room, and a dresser and nightstands are arranged around it.");
    rooms[5] = create_room("The Guest Bedroom", "You are in the guest bedroom. A twin bed takes up most of the room, and a dresser and nightstand are arranged around it.");
    rooms[6] = create_room("The Bathroom", "You are in the bathroom. A toilet, sink, and bathtub are all within reach.");
    rooms[7] = create_room("The Library", "You are in the library. Bookshelves line the walls, and a large desk is in the center of the room.");
    rooms[8] = create_room("The Study", "You are in the study. A desk and chair are in the center of the room, and bookshelves line the walls.");
    rooms[9] = create_room("The Attic", "You are in the attic. Boxes and old furniture are scattered around the room.");

    // Set the room connections
    rooms[0]->north = rooms[1];
    rooms[0]->east = rooms[2];
    rooms[0]->south = rooms[3];
    rooms[0]->west = rooms[4];
    rooms[1]->south = rooms[0];
    rooms[1]->east = rooms[2];
    rooms[2]->west = rooms[1];
    rooms[2]->south = rooms[0];
    rooms[2]->east = rooms[3];
    rooms[3]->north = rooms[0];
    rooms[3]->west = rooms[2];
    rooms[3]->south = rooms[4];
    rooms[4]->north = rooms[3];
    rooms[4]->east = rooms[5];
    rooms[4]->west = rooms[0];
    rooms[5]->west = rooms[4];
    rooms[5]->south = rooms[6];
    rooms[6]->north = rooms[5];
    rooms[6]->east = rooms[7];
    rooms[6]->south = rooms[8];
    rooms[7]->west = rooms[6];
    rooms[7]->south = rooms[9];
    rooms[8]->north = rooms[6];
    rooms[8]->east = rooms[9];
    rooms[9]->north = rooms[7];
    rooms[9]->west = rooms[8];

    // Play the game
    room* current_room = rooms[0];
    while (1) {
        // Print the room description
        print_room(current_room);

        // Get the player's input
        char input[10];
        printf("> ");
        scanf("%s", input);

        // Parse the player's input
        if (strcmp(input, "n") == 0) {
            // Move north
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "e") == 0) {
            // Move east
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "s") == 0) {
            // Move south
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "w") == 0) {
            // Move west
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "look") == 0) {
            // Look around the room
            print_room(current_room);
        } else if (strcmp(input, "quit") == 0) {
            // Quit the game
            break;
        } else {
            // Invalid input
            printf("I don't understand.\n");
        }
    }

    // Free the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        free_room(rooms[i]);
    }

    return 0;
}