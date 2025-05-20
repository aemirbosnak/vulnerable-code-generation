//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ROOM_DESC_LEN 256

typedef struct room {
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

typedef struct player {
    char* name;
    room* current_room;
} player;

// Create a new room with the given description.
room* create_room(char* description) {
    room* r = malloc(sizeof(room));
    r->description = strdup(description);
    r->north = NULL;
    r->east = NULL;
    r->south = NULL;
    r->west = NULL;
    return r;
}

// Create a new player with the given name.
player* create_player(char* name) {
    player* p = malloc(sizeof(player));
    p->name = strdup(name);
    p->current_room = NULL;
    return p;
}

// Connect two rooms in the given direction.
void connect_rooms(room* r1, room* r2, char direction) {
    switch (direction) {
        case 'n':
            r1->north = r2;
            break;
        case 'e':
            r1->east = r2;
            break;
        case 's':
            r1->south = r2;
            break;
        case 'w':
            r1->west = r2;
            break;
    }
}

// Print the description of the given room.
void print_room_description(room* r) {
    printf("%s\n", r->description);
}

// Print the available exits from the given room.
void print_room_exits(room* r) {
    printf("Exits:");
    if (r->north) printf(" n");
    if (r->east) printf(" e");
    if (r->south) printf(" s");
    if (r->west) printf(" w");
    printf("\n");
}

// Get the next command from the player.
char* get_command() {
    char* command = malloc(MAX_NAME_LEN);
    scanf("%s", command);
    return command;
}

// Execute the given command.
void execute_command(player* p, char* command) {
    if (strcmp(command, "look") == 0) {
        print_room_description(p->current_room);
        print_room_exits(p->current_room);
    } else if (strcmp(command, "go") == 0) {
        char* direction = get_command();
        room* next_room = NULL;
        switch (direction[0]) {
            case 'n':
                next_room = p->current_room->north;
                break;
            case 'e':
                next_room = p->current_room->east;
                break;
            case 's':
                next_room = p->current_room->south;
                break;
            case 'w':
                next_room = p->current_room->west;
                break;
        }
        if (next_room) {
            p->current_room = next_room;
            print_room_description(next_room);
            print_room_exits(next_room);
        } else {
            printf("No exit in that direction.\n");
        }
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    // Create the rooms.
    room* foyer = create_room("You are standing in a small foyer.");
    room* living_room = create_room("You are standing in a spacious living room.");
    room* kitchen = create_room("You are standing in a cozy kitchen.");
    room* dining_room = create_room("You are standing in a formal dining room.");
    room* garden = create_room("You are standing in a beautiful garden.");

    // Connect the rooms.
    connect_rooms(foyer, living_room, 'e');
    connect_rooms(foyer, kitchen, 'w');
    connect_rooms(living_room, dining_room, 'e');
    connect_rooms(dining_room, garden, 's');

    // Create the player.
    player* p = create_player("Player");

    // Start the game.
    p->current_room = foyer;
    print_room_description(foyer);
    print_room_exits(foyer);

    while (1) {
        char* command = get_command();
        execute_command(p, command);
    }

    return 0;
}