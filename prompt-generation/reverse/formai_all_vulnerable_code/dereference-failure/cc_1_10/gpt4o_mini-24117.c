//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_INPUT 100
#define MAX_DESC 200

typedef struct {
    char description[MAX_DESC];
    int visited;
} Room;

typedef struct {
    Room *rooms;
    int current_room;
} GameState;

void *get_input(void *arg) {
    char input[MAX_INPUT];
    GameState *state = (GameState *)arg;

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline

        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            exit(0);
        } else if (strcmp(input, "look") == 0) {
            if (!state->rooms[state->current_room].visited) {
                printf("%s\n", state->rooms[state->current_room].description);
                state->rooms[state->current_room].visited = 1; // Mark as visited
            } else {
                printf("You've already been here.\n");
            }
        } else if (strcmp(input, "north") == 0) {
            if (state->current_room < 2) {
                state->current_room++;
                printf("You moved north.\n");
            } else {
                printf("You can't go further north!\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (state->current_room > 0) {
                state->current_room--;
                printf("You moved south.\n");
            } else {
                printf("You can't go further south!\n");
            }
        } else if (strlen(input) > 0) {
            printf("Unknown command.\n");
        }
    }
}

int main() {
    GameState state;
    state.rooms = malloc(3 * sizeof(Room));
    state.current_room = 0;

    // Initialize rooms
    strncpy(state.rooms[0].description, "You are in a dark forest. Paths lead north and south.", MAX_DESC);
    state.rooms[0].visited = 0;
    strncpy(state.rooms[1].description, "You have reached a serene lake. The only way back is south.", MAX_DESC);
    state.rooms[1].visited = 0;
    strncpy(state.rooms[2].description, "You stand at the edge of a cliff. The world stretches below you.", MAX_DESC);
    state.rooms[2].visited = 0;

    pthread_t input_thread;
    pthread_create(&input_thread, NULL, get_input, (void *)&state);

    // Game loop
    printf("Welcome to Adventure Game!\n");
    printf("Type 'look' to explore your surroundings, 'north' to go north, 'south' to go south, and 'quit' to exit.\n");

    // Main game loop does nothing, just waits for input thread to provide interaction
    while (1) {
        sleep(1);
    }

    free(state.rooms);
    return 0;
}