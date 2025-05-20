//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

#define MAX_COMMAND_SIZE 100
#define MAX_ROOM_DESC_SIZE 256
#define MAX_NUM_ROOMS 10

enum room_type {
    ROOM_START,
    ROOM_END,
    ROOM_NORMAL
};

struct room {
    char *description;
    enum room_type type;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
};

struct game {
    struct room *current_room;
    char *command_buffer;
    int running;
};

struct game game;

void init_game() {
    // Create the rooms
    struct room room_start = { "You are in the starting room.", ROOM_START, NULL, NULL, NULL, NULL };
    struct room room_end = { "You have reached the end of the game.", ROOM_END, NULL, NULL, NULL, NULL };
    struct room room_normal1 = { "This is a normal room.", ROOM_NORMAL, NULL, NULL, NULL, NULL };
    struct room room_normal2 = { "This is another normal room.", ROOM_NORMAL, NULL, NULL, NULL, NULL };

    // Link the rooms together
    room_start.north = &room_normal1;
    room_normal1.south = &room_start;
    room_normal1.east = &room_normal2;
    room_normal2.west = &room_normal1;
    room_normal2.north = &room_end;

    // Set the current room to the starting room
    game.current_room = &room_start;

    // Allocate memory for the command buffer
    game.command_buffer = malloc(MAX_COMMAND_SIZE);

    // Set the running flag to true
    game.running = 1;
}

void cleanup_game() {
    // Free the memory allocated for the command buffer
    free(game.command_buffer);
}

void handle_command(char *command) {
    if (strcmp(command, "quit") == 0) {
        game.running = 0;
    } else if (strcmp(command, "north") == 0) {
        if (game.current_room->north != NULL) {
            game.current_room = game.current_room->north;
        } else {
            printf("You cannot go north from this room.\n");
        }
    } else if (strcmp(command, "south") == 0) {
        if (game.current_room->south != NULL) {
            game.current_room = game.current_room->south;
        } else {
            printf("You cannot go south from this room.\n");
        }
    } else if (strcmp(command, "east") == 0) {
        if (game.current_room->east != NULL) {
            game.current_room = game.current_room->east;
        } else {
            printf("You cannot go east from this room.\n");
        }
    } else if (strcmp(command, "west") == 0) {
        if (game.current_room->west != NULL) {
            game.current_room = game.current_room->west;
        } else {
            printf("You cannot go west from this room.\n");
        }
    } else {
        printf("I don't understand that command.\n");
    }
}

void *input_thread(void *arg) {
    while (game.running) {
        printf("> ");
        fgets(game.command_buffer, MAX_COMMAND_SIZE, stdin);
        game.command_buffer[strcspn(game.command_buffer, "\n")] = '\0';
        handle_command(game.command_buffer);
    }

    return NULL;
}

void *output_thread(void *arg) {
    while (game.running) {
        printf("%s\n", game.current_room->description);
    }

    return NULL;
}

int main() {
    // Initialize the game
    init_game();

    // Create the input and output threads
    pthread_t input_thread_id;
    pthread_t output_thread_id;
    pthread_create(&input_thread_id, NULL, input_thread, NULL);
    pthread_create(&output_thread_id, NULL, output_thread, NULL);

    // Join the input and output threads
    pthread_join(input_thread_id, NULL);
    pthread_join(output_thread_id, NULL);

    // Cleanup the game
    cleanup_game();

    return 0;
}