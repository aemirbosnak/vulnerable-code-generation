//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
} room;

room *create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    return new_room;
}

void free_room(room *room) {
    free(room->name);
    free(room->description);
    free(room);
}

void print_room(room *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
}

int main() {
    // Create the rooms.
    room *kitchen = create_room("Kitchen", "A warm and inviting room with a large stove and a cozy fireplace.");
    room *living_room = create_room("Living Room", "A spacious room with a comfortable couch and a large TV.");
    room *dining_room = create_room("Dining Room", "A formal room with a large table and a set of chairs.");
    room *bedroom = create_room("Bedroom", "A cozy room with a large bed and a dresser.");
    room *bathroom = create_room("Bathroom", "A small room with a toilet, a sink, and a bathtub.");

    // Connect the rooms.
    kitchen->north = living_room;
    living_room->south = kitchen;
    living_room->east = dining_room;
    dining_room->west = living_room;
    dining_room->north = bedroom;
    bedroom->south = dining_room;
    bedroom->east = bathroom;
    bathroom->west = bedroom;

    // Start the player in the kitchen.
    room *current_room = kitchen;

    // Play the game.
    while (1) {
        // Print the current room.
        print_room(current_room);

        // Get the player's input.
        char input[80];
        printf("> ");
        fgets(input, 80, stdin);

        // Parse the player's input.
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Execute the player's command.
        if (strcmp(command, "go") == 0) {
            if (strcmp(argument, "north") == 0) {
                if (current_room->north != NULL) {
                    current_room = current_room->north;
                } else {
                    printf("You can't go that way.\n");
                }
            } else if (strcmp(argument, "south") == 0) {
                if (current_room->south != NULL) {
                    current_room = current_room->south;
                } else {
                    printf("You can't go that way.\n");
                }
            } else if (strcmp(argument, "east") == 0) {
                if (current_room->east != NULL) {
                    current_room = current_room->east;
                } else {
                    printf("You can't go that way.\n");
                }
            } else if (strcmp(argument, "west") == 0) {
                if (current_room->west != NULL) {
                    current_room = current_room->west;
                } else {
                    printf("You can't go that way.\n");
                }
            } else {
                printf("I don't understand that direction.\n");
            }
        } else if (strcmp(command, "look") == 0) {
            print_room(current_room);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }

    // Free the rooms.
    free_room(kitchen);
    free_room(living_room);
    free_room(dining_room);
    free_room(bedroom);
    free_room(bathroom);

    return 0;
}