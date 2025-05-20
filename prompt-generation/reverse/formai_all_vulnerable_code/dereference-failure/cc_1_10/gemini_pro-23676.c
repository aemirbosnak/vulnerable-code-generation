//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_EXITS 6

struct room {
    char name[20];
    char description[80];
    struct exit *exits[MAX_EXITS];
};

struct exit {
    char direction[20];
    struct room *destination;
};

struct player {
    char name[20];
    struct room *location;
};

struct game {
    struct room *rooms[MAX_ROOMS];
    struct player *player;
};

// Create a new game
struct game *new_game() {
    struct game *game = malloc(sizeof(struct game));
    game->player = malloc(sizeof(struct player));
    return game;
}

// Create a new room
struct room *new_room(char *name, char *description) {
    struct room *room = malloc(sizeof(struct room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    return room;
}

// Create a new exit
struct exit *new_exit(char *direction, struct room *destination) {
    struct exit *exit = malloc(sizeof(struct exit));
    strcpy(exit->direction, direction);
    exit->destination = destination;
    return exit;
}

// Add a room to the game
void add_room(struct game *game, struct room *room) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (game->rooms[i] == NULL) {
            game->rooms[i] = room;
            break;
        }
    }
}

// Add an exit to a room
void add_exit(struct room *room, struct exit *exit) {
    for (int i = 0; i < MAX_EXITS; i++) {
        if (room->exits[i] == NULL) {
            room->exits[i] = exit;
            break;
        }
    }
}

// Set the player's location
void set_player_location(struct game *game, struct room *room) {
    game->player->location = room;
}

// Get the player's location
struct room *get_player_location(struct game *game) {
    return game->player->location;
}

// Print the room's description
void print_room_description(struct room *room) {
    printf("%s\n", room->description);
}

// Print the room's exits
void print_room_exits(struct room *room) {
    printf("Exits:\n");
    for (int i = 0; i < MAX_EXITS; i++) {
        if (room->exits[i] != NULL) {
            printf("  %s\n", room->exits[i]->direction);
        }
    }
}

// Get the player's input
char *get_player_input() {
    char *input = malloc(20);
    scanf("%s", input);
    return input;
}

// Process the player's input
void process_player_input(struct game *game) {
    char *input = get_player_input();
    if (strcmp(input, "look") == 0) {
        print_room_description(get_player_location(game));
        print_room_exits(get_player_location(game));
    } else if (strcmp(input, "go") == 0) {
        char *direction = get_player_input();
        for (int i = 0; i < MAX_EXITS; i++) {
            if (get_player_location(game)->exits[i] != NULL && strcmp(get_player_location(game)->exits[i]->direction, direction) == 0) {
                set_player_location(game, get_player_location(game)->exits[i]->destination);
                break;
            }
        }
    } else {
        printf("I don't understand that command.\n");
    }
    free(input);
}

// Play the game
void play_game(struct game *game) {
    while (1) {
        process_player_input(game);
    }
}

// Free the game's memory
void free_game(struct game *game) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (game->rooms[i] != NULL) {
            free(game->rooms[i]);
        }
    }
    free(game->player);
    free(game);
}

int main() {
    struct game *game = new_game();

    // Create the rooms
    struct room *room1 = new_room("Room 1", "This is the first room.");
    struct room *room2 = new_room("Room 2", "This is the second room.");
    struct room *room3 = new_room("Room 3", "This is the third room.");

    // Add the rooms to the game
    add_room(game, room1);
    add_room(game, room2);
    add_room(game, room3);

    // Create the exits
    struct exit *exit1 = new_exit("north", room2);
    struct exit *exit2 = new_exit("south", room1);
    struct exit *exit3 = new_exit("east", room3);
    struct exit *exit4 = new_exit("west", room1);

    // Add the exits to the rooms
    add_exit(room1, exit1);
    add_exit(room1, exit2);
    add_exit(room2, exit3);
    add_exit(room2, exit4);

    // Set the player's location
    set_player_location(game, room1);

    // Play the game
    play_game(game);

    // Free the game's memory
    free_game(game);

    return 0;
}