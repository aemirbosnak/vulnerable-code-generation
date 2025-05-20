//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

room *create_room(char *name, char *description) {
    room *r = malloc(sizeof(room));
    r->name = strdup(name);
    r->description = strdup(description);
    r->north = NULL;
    r->east = NULL;
    r->south = NULL;
    r->west = NULL;
    return r;
}

void free_room(room *r) {
    free(r->name);
    free(r->description);
    free(r);
}

void print_room(room *r) {
    printf("%s\n%s\n", r->name, r->description);
}

int main() {
    room *start = create_room("The Starting Room", "This is the starting room of the game.");
    room *end = create_room("The End Room", "This is the end room of the game.");

    // Link the rooms together.
    start->north = end;
    end->south = start;

    // Create a player.
    char *player_name = "Player";

    // Start the game.
    room *current_room = start;
    while (current_room != end) {
        // Print the current room.
        print_room(current_room);

        // Get the player's input.
        char input[256];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Parse the player's input.
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        // Execute the player's command.
        if (strcmp(command, "go") == 0) {
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
            print_room(current_room);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Free the rooms.
    free_room(start);
    free_room(end);

    return 0;
}