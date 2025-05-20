//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 10

typedef struct room {
    char *name;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
} room_t;

room_t *create_room(char *name) {
    room_t *room = malloc(sizeof(room_t));
    room->name = name;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void destroy_room(room_t *room) {
    free(room->name);
    free(room);
}

void connect_rooms(room_t *room1, room_t *room2, char direction) {
    assert(room1 != NULL);
    assert(room2 != NULL);
    assert(direction == 'n' || direction == 's' || direction == 'e' || direction == 'w');

    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

void print_room(room_t *room) {
    assert(room != NULL);

    printf("You are in the %s.\n", room->name);

    if (room->north != NULL) {
        printf("To the north, you see the %s.\n", room->north->name);
    }
    if (room->south != NULL) {
        printf("To the south, you see the %s.\n", room->south->name);
    }
    if (room->east != NULL) {
        printf("To the east, you see the %s.\n", room->east->name);
    }
    if (room->west != NULL) {
        printf("To the west, you see the %s.\n", room->west->name);
    }
}

int main() {
    srand(time(NULL));

    // Create the rooms
    room_t *rooms[ROOM_COUNT];
    for (int i = 0; i < ROOM_COUNT; i++) {
        char *name = malloc(16);
        sprintf(name, "Room %d", i);
        rooms[i] = create_room(name);
    }

    // Connect the rooms
    for (int i = 0; i < ROOM_COUNT; i++) {
        int num_connections = rand() % 4;
        for (int j = 0; j < num_connections; j++) {
            int direction = rand() % 4;
            room_t *room1 = rooms[i];
            room_t *room2 = rooms[rand() % ROOM_COUNT];
            if (room1 != room2) {
                connect_rooms(room1, room2, direction);
            }
        }
    }

    // Start the game
    room_t *current_room = rooms[rand() % ROOM_COUNT];
    while (1) {
        print_room(current_room);

        char direction;
        printf("Which direction do you want to go? (n/s/e/w) ");
        scanf(" %c", &direction);

        switch (direction) {
            case 'n':
                if (current_room->north != NULL) {
                    current_room = current_room->north;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 's':
                if (current_room->south != NULL) {
                    current_room = current_room->south;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'e':
                if (current_room->east != NULL) {
                    current_room = current_room->east;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'w':
                if (current_room->west != NULL) {
                    current_room = current_room->west;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }
    }

    // Clean up
    for (int i = 0; i < ROOM_COUNT; i++) {
        destroy_room(rooms[i]);
    }

    return 0;
}