//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ROOM_NAME_LEN 20
#define MAX_DESC_LEN 100

struct room {
    char name[MAX_ROOM_NAME_LEN];
    char desc[MAX_DESC_LEN];
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
};

struct player {
    char name[20];
    struct room *current_room;
};

struct room *create_room(char *name, char *desc) {
    struct room *new_room = malloc(sizeof(struct room));
    strcpy(new_room->name, name);
    strcpy(new_room->desc, desc);
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    return new_room;
}

struct player *create_player(char *name) {
    struct player *new_player = malloc(sizeof(struct player));
    strcpy(new_player->name, name);
    new_player->current_room = NULL;
    return new_player;
}

void print_room(struct room *room) {
    printf("\nYou are in the %s.\n", room->name);
    printf("%s\n", room->desc);
    if (room->north)
        printf("To the north, you see the %s.\n", room->north->name);
    if (room->south)
        printf("To the south, you see the %s.\n", room->south->name);
    if (room->east)
        printf("To the east, you see the %s.\n", room->east->name);
    if (room->west)
        printf("To the west, you see the %s.\n", room->west->name);
}

void play_game(struct player *player) {
    char input[20];

    while (1) {
        print_room(player->current_room);

        printf("What do you want to do?\n");
        gets(input);

        if (strcmp(input, "go north") == 0) {
            if (player->current_room->north)
                player->current_room = player->current_room->north;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(input, "go south") == 0) {
            if (player->current_room->south)
                player->current_room = player->current_room->south;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(input, "go east") == 0) {
            if (player->current_room->east)
                player->current_room = player->current_room->east;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(input, "go west") == 0) {
            if (player->current_room->west)
                player->current_room = player->current_room->west;
            else
                printf("You can't go that way.\n");
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }
}

int main() {
    struct room *room1 = create_room("The Foyer", "A grand foyer with a marble floor and a high ceiling.");
    struct room *room2 = create_room("The Living Room", "A cozy living room with a fireplace and a couch.");
    struct room *room3 = create_room("The Dining Room", "A formal dining room with a large table and chairs.");
    struct room *room4 = create_room("The Kitchen", "A spacious kitchen with a stove, oven, and refrigerator.");
    struct room *room5 = create_room("The Master Bedroom", "A large master bedroom with a king-sized bed and a dresser.");
    struct room *room6 = create_room("The Guest Bedroom", "A smaller guest bedroom with a twin bed and a nightstand.");
    struct room *room7 = create_room("The Bathroom", "A bathroom with a toilet, sink, and bathtub.");
    struct room *room8 = create_room("The Study", "A study with a desk, chair, and bookcase.");
    struct room *room9 = create_room("The Library", "A library with shelves full of books.");
    struct room *room10 = create_room("The Secret Passage", "A secret passage that leads to the outside world.");

    room1->north = room2;
    room1->south = room3;
    room1->east = room4;
    room1->west = room5;

    room2->south = room1;
    room2->east = room6;
    room2->west = room7;

    room3->north = room1;
    room3->east = room8;
    room3->west = room9;

    room4->west = room1;
    room4->east = room10;

    room5->east = room1;
    room5->west = room6;

    room6->north = room2;
    room6->east = room5;

    room7->east = room2;

    room8->west = room3;

    room9->east = room3;

    room10->west = room4;

    struct player *player = create_player("Alice");
    player->current_room = room1;

    play_game(player);

    return 0;
}