//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DESC_LEN 256

typedef struct room {
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

room *rooms[MAX_ROOMS];
int num_rooms = 0;

void add_room(char *description) {
    if (num_rooms >= MAX_ROOMS) {
        fprintf(stderr, "Error: Too many rooms!\n");
        exit(1);
    }

    rooms[num_rooms] = malloc(sizeof(room));
    rooms[num_rooms]->description = strdup(description);
    rooms[num_rooms]->north = NULL;
    rooms[num_rooms]->east = NULL;
    rooms[num_rooms]->south = NULL;
    rooms[num_rooms]->west = NULL;

    num_rooms++;
}

void connect_rooms(room *room1, room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
        default:
            fprintf(stderr, "Error: Invalid direction!\n");
            exit(1);
            break;
    }
}

void print_room(room *room) {
    printf("%s\n", room->description);

    if (room->north != NULL) {
        printf("To the north, you see %s.\n", room->north->description);
    }
    if (room->east != NULL) {
        printf("To the east, you see %s.\n", room->east->description);
    }
    if (room->south != NULL) {
        printf("To the south, you see %s.\n", room->south->description);
    }
    if (room->west != NULL) {
        printf("To the west, you see %s.\n", room->west->description);
    }
}

int main() {
    // Create some rooms.
    add_room("You are in a small, dark room.");
    add_room("You are in a large, open field.");
    add_room("You are in a forest.");
    add_room("You are in a cave.");
    add_room("You are in a castle.");

    // Connect the rooms.
    connect_rooms(rooms[0], rooms[1], 'n');
    connect_rooms(rooms[1], rooms[2], 'e');
    connect_rooms(rooms[2], rooms[3], 's');
    connect_rooms(rooms[3], rooms[4], 'w');

    // Play the game.
    room *current_room = rooms[0];

    while (1) {
        // Print the current room.
        print_room(current_room);

        // Get the player's input.
        char input[MAX_DESC_LEN];
        printf("> ");
        fgets(input, MAX_DESC_LEN, stdin);

        // Parse the player's input.
        char direction = input[0];

        // Move the player to the next room.
        switch (direction) {
            case 'n':
                current_room = current_room->north;
                break;
            case 'e':
                current_room = current_room->east;
                break;
            case 's':
                current_room = current_room->south;
                break;
            case 'w':
                current_room = current_room->west;
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }

    return 0;
}