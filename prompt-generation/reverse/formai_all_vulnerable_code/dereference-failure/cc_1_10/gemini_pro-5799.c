//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 10
#define MAX_DESC_LEN 80

typedef struct room {
    char name[MAX_DESC_LEN];
    char description[MAX_DESC_LEN];
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room_t;

room_t *create_room(char *name, char *description) {
    room_t *room = malloc(sizeof(room_t));
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

void destroy_room(room_t *room) {
    free(room);
}

void connect_rooms(room_t *room1, room_t *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            break;
        case 'e':
            room1->east = room2;
            break;
        case 's':
            room1->south = room2;
            break;
        case 'w':
            room1->west = room2;
            break;
    }
}

void print_room(room_t *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
    printf("Exits:\n");
    if (room->north) printf("  North: %s\n", room->north->name);
    if (room->east) printf("  East: %s\n", room->east->name);
    if (room->south) printf("  South: %s\n", room->south->name);
    if (room->west) printf("  West: %s\n", room->west->name);
}

void play_game(room_t *start_room) {
    room_t *current_room = start_room;
    char input[80];

    while (1) {
        print_room(current_room);
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit\n") == 0) {
            break;
        } else if (strcmp(input, "n\n") == 0) {
            if (current_room->north) {
                current_room = current_room->north;
            } else {
                printf("There is no exit to the north.\n");
            }
        } else if (strcmp(input, "e\n") == 0) {
            if (current_room->east) {
                current_room = current_room->east;
            } else {
                printf("There is no exit to the east.\n");
            }
        } else if (strcmp(input, "s\n") == 0) {
            if (current_room->south) {
                current_room = current_room->south;
            } else {
                printf("There is no exit to the south.\n");
            }
        } else if (strcmp(input, "w\n") == 0) {
            if (current_room->west) {
                current_room = current_room->west;
            } else {
                printf("There is no exit to the west.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }
}

int main() {
    room_t *kitchen = create_room("Kitchen", "A small kitchen with a stove, oven, and refrigerator.");
    room_t *living_room = create_room("Living Room", "A cozy living room with a couch, armchair, and fireplace.");
    room_t *bedroom = create_room("Bedroom", "A bedroom with a bed, dresser, and nightstand.");
    room_t *bathroom = create_room("Bathroom", "A bathroom with a toilet, sink, and bathtub.");

    connect_rooms(kitchen, living_room, 'e');
    connect_rooms(living_room, bedroom, 'n');
    connect_rooms(bedroom, bathroom, 'e');
    connect_rooms(bathroom, kitchen, 's');

    play_game(kitchen);

    destroy_room(kitchen);
    destroy_room(living_room);
    destroy_room(bedroom);
    destroy_room(bathroom);

    return 0;
}