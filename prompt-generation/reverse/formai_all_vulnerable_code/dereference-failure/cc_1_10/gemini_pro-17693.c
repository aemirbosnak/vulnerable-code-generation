//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's stats
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Player;

// Define the game world
typedef struct {
    char *name;
    char **description;
    int num_exits;
    char **exits;
    int **destinations;
} Room;

// Create the player
Player *create_player(char *name) {
    Player *player = malloc(sizeof(Player));
    player->name = name;
    player->health = 100;
    player->attack = 10;
    player->defense = 10;
    return player;
}

// Create a room
Room *create_room(char *name, char **description, int num_exits, char **exits, int **destinations) {
    Room *room = malloc(sizeof(Room));
    room->name = name;
    room->description = description;
    room->num_exits = num_exits;
    room->exits = exits;
    room->destinations = destinations;
    return room;
}

// Print the room description
void print_room_description(Room *room) {
    for (int i = 0; i < room->num_exits; i++) {
        printf("%s: %s\n", room->exits[i], room->description[i]);
    }
}

// Get the player's input
char *get_player_input() {
    char *input = malloc(1024);
    fgets(input, 1024, stdin);
    return input;
}

// Parse the player's input
int parse_player_input(char *input, Room *room) {
    char *command = strtok(input, " ");
    if (strcmp(command, "go") == 0) {
        char *exit = strtok(NULL, " ");
        for (int i = 0; i < room->num_exits; i++) {
            if (strcmp(exit, room->exits[i]) == 0) {
                return room->destinations[i];
            }
        }
        printf("Invalid exit\n");
        return -1;
    } else if (strcmp(command, "look") == 0) {
        print_room_description(room);
        return -1;
    } else if (strcmp(command, "quit") == 0) {
        return -2;
    } else {
        printf("Invalid command\n");
        return -1;
    }
}

// Main game loop
int main() {
    // Create the player
    Player *player = create_player("Player");

    // Create the game world
    Room *room1 = create_room("Room 1", (char *[]) {"This is a small room with a single door.", NULL}, 1, (char *[]) {"east"}, (int *[]) {{2}});
    Room *room2 = create_room("Room 2", (char *[]) {"This is a larger room with two doors.", NULL}, 2, (char *[]) {"west", "east"}, (int *[]) {{1, 3}});
    Room *room3 = create_room("Room 3", (char *[]) {"This is a small room with a single door.", NULL}, 1, (char *[]) {"west"}, (int *[]) {{2}});

    // Set the player's starting room
    Room *current_room = room1;

    // Main game loop
    while (1) {
        print_room_description(current_room);

        char *input = get_player_input();
        int next_room = parse_player_input(input, current_room);
        if (next_room < 0) {
            continue;
        } else if (next_room == -2) {
            break;
        } else {
            current_room = next_room;
        }
    }

    // Free the memory
    free(player);
    free(room1);
    free(room2);
    free(room3);

    return 0;
}