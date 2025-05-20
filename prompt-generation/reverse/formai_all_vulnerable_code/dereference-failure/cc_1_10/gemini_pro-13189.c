//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char *name;
    char *description;
    int num_exits;
    int *exits;
} room;

room rooms[MAX_ROOMS];

int current_room;

void create_room(char *name, char *description, int num_exits, int *exits) {
    room *new_room = &rooms[current_room];

    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->num_exits = num_exits;
    new_room->exits = malloc(sizeof(int) * num_exits);
    memcpy(new_room->exits, exits, sizeof(int) * num_exits);

    current_room++;
}

void describe_room(room *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
    printf("Exits:");
    for (int i = 0; i < room->num_exits; i++) {
        printf(" %d", room->exits[i]);
    }
    printf("\n");
}

int main() {
    // Create the rooms.
    create_room("The Foyer", "You are in a large foyer with a high ceiling.", 2, (int[]){1, 2});
    create_room("The Living Room", "You are in a cozy living room with a fireplace.", 2, (int[]){0, 3});
    create_room("The Dining Room", "You are in a formal dining room with a large table.", 2, (int[]){0, 4});
    create_room("The Kitchen", "You are in a large kitchen with a stove and oven.", 2, (int[]){2, 5});
    create_room("The Study", "You are in a small study with a desk and bookshelves.", 1, (int[]){3});

    // Start the game.
    current_room = 0;
    while (1) {
        // Describe the current room.
        describe_room(&rooms[current_room]);

        // Get the player's input.
        char input[100];
        printf("> ");
        scanf("%s", input);

        // Parse the player's input.
        if (strcmp(input, "n") == 0) {
            // Go north.
            if (current_room == 0) {
                printf("You can't go north from here.\n");
            } else {
                current_room = rooms[current_room].exits[0];
            }
        } else if (strcmp(input, "s") == 0) {
            // Go south.
            if (current_room == 2) {
                printf("You can't go south from here.\n");
            } else {
                current_room = rooms[current_room].exits[1];
            }
        } else if (strcmp(input, "e") == 0) {
            // Go east.
            if (current_room == 0 || current_room == 2) {
                printf("You can't go east from here.\n");
            } else {
                current_room = rooms[current_room].exits[2];
            }
        } else if (strcmp(input, "w") == 0) {
            // Go west.
            if (current_room == 1 || current_room == 3) {
                printf("You can't go west from here.\n");
            } else {
                current_room = rooms[current_room].exits[3];
            }
        } else if (strcmp(input, "q") == 0) {
            // Quit the game.
            break;
        } else {
            // Invalid input.
            printf("Invalid input.\n");
        }
    }

    // Free the memory allocated for the rooms.
    for (int i = 0; i < current_room; i++) {
        free(rooms[i].name);
        free(rooms[i].description);
        free(rooms[i].exits);
    }

    return 0;
}