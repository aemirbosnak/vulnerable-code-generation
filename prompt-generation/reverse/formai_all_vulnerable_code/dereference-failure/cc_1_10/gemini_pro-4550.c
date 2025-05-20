//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
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
    room *rooms[MAX_ROOMS];
    int num_rooms = 0;

    // Create the rooms
    rooms[num_rooms++] = create_room("Foyer", "You are in the foyer of a large house.");
    rooms[num_rooms++] = create_room("Living Room", "You are in the living room of a large house.");
    rooms[num_rooms++] = create_room("Dining Room", "You are in the dining room of a large house.");
    rooms[num_rooms++] = create_room("Kitchen", "You are in the kitchen of a large house.");
    rooms[num_rooms++] = create_room("Bedroom", "You are in the bedroom of a large house.");
    rooms[num_rooms++] = create_room("Bathroom", "You are in the bathroom of a large house.");
    rooms[num_rooms++] = create_room("Study", "You are in the study of a large house.");
    rooms[num_rooms++] = create_room("Library", "You are in the library of a large house.");
    rooms[num_rooms++] = create_room("Game Room", "You are in the game room of a large house.");
    rooms[num_rooms++] = create_room("Attic", "You are in the attic of a large house.");

    // Connect the rooms
    rooms[0]->north = rooms[1];
    rooms[0]->south = rooms[2];
    rooms[0]->east = rooms[3];
    rooms[0]->west = rooms[4];
    rooms[1]->south = rooms[0];
    rooms[1]->east = rooms[5];
    rooms[1]->west = rooms[6];
    rooms[2]->north = rooms[0];
    rooms[2]->east = rooms[7];
    rooms[2]->west = rooms[8];
    rooms[3]->west = rooms[0];
    rooms[3]->east = rooms[9];
    rooms[4]->east = rooms[0];
    rooms[5]->west = rooms[1];
    rooms[5]->east = rooms[10];
    rooms[6]->east = rooms[1];
    rooms[7]->west = rooms[2];
    rooms[8]->east = rooms[2];
    rooms[9]->west = rooms[3];
    rooms[10]->west = rooms[5];

    // Start the game
    room *current_room = rooms[0];
    char input[80];

    while (1) {
        print_room(current_room);

        printf("What do you want to do? ");
        fgets(input, 80, stdin);

        if (strcmp(input, "north\n") == 0) {
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "south\n") == 0) {
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "east\n") == 0) {
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "west\n") == 0) {
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "quit\n") == 0) {
            break;
        } else {
            printf("I don't understand what you want to do.\n");
        }
    }

    // Free the rooms
    for (int i = 0; i < num_rooms; i++) {
        free_room(rooms[i]);
    }

    return 0;
}