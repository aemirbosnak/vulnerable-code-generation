//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char* name;
    char* description;
    int num_exits;
    int* exits;
} Room;

typedef struct {
    Room* rooms[MAX_ROOMS];
    int current_room;
} Game;

// Create a new room
Room* create_room(char* name, char* description, int num_exits, int* exits) {
    Room* room = malloc(sizeof(Room));
    room->name = malloc(strlen(name) + 1);
    strcpy(room->name, name);
    room->description = malloc(strlen(description) + 1);
    strcpy(room->description, description);
    room->num_exits = num_exits;
    room->exits = malloc(sizeof(int) * num_exits);
    for (int i = 0; i < num_exits; i++) {
        room->exits[i] = exits[i];
    }
    return room;
}

// Create a new game
Game* create_game() {
    Game* game = malloc(sizeof(Game));
    game->current_room = 0;
    return game;
}

// Print the current room
void print_room(Game* game) {
    Room* room = game->rooms[game->current_room];
    printf("%s\n", room->name);
    printf("%s\n", room->description);
}

// Get the user's input
char* get_input() {
    char* input = malloc(100);
    scanf("%s", input);
    return input;
}

// Play the game
void play_game(Game* game) {
    while (1) {
        print_room(game);
        printf("> ");
        char* input = get_input();
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "north") == 0) {
            game->current_room = game->rooms[game->current_room]->exits[0];
        } else if (strcmp(input, "south") == 0) {
            game->current_room = game->rooms[game->current_room]->exits[1];
        } else if (strcmp(input, "east") == 0) {
            game->current_room = game->rooms[game->current_room]->exits[2];
        } else if (strcmp(input, "west") == 0) {
            game->current_room = game->rooms[game->current_room]->exits[3];
        }
    }
}

// Free the game
void free_game(Game* game) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        free(game->rooms[i]->name);
        free(game->rooms[i]->description);
        free(game->rooms[i]->exits);
        free(game->rooms[i]);
    }
    free(game);
}

int main() {
    // Create the rooms
    Room* room1 = create_room("Room 1", "This is room 1.", 4, (int[]){2, 3, 4, 5});
    Room* room2 = create_room("Room 2", "This is room 2.", 2, (int[]){1, 3});
    Room* room3 = create_room("Room 3", "This is room 3.", 3, (int[]){1, 2, 4});
    Room* room4 = create_room("Room 4", "This is room 4.", 2, (int[]){1, 3});
    Room* room5 = create_room("Room 5", "This is room 5.", 1, (int[]){1});

    // Create the game
    Game* game = create_game();
    game->rooms[0] = room1;
    game->rooms[1] = room2;
    game->rooms[2] = room3;
    game->rooms[3] = room4;
    game->rooms[4] = room5;

    // Play the game
    play_game(game);

    // Free the game
    free_game(game);

    return 0;
}