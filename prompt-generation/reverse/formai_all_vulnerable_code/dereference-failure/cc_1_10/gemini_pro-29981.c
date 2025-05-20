//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20

typedef struct room {
    char name[MAX_NAME_LENGTH];
    char description[256];
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
} room;

room *rooms[MAX_ROOMS];
int num_rooms = 0;

room *current_room;

void create_room(char *name, char *description) {
    if (num_rooms >= MAX_ROOMS) {
        printf("Error: Too many rooms.\n");
        return;
    }

    room *new_room = malloc(sizeof(room));
    strcpy(new_room->name, name);
    strcpy(new_room->description, description);
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;

    rooms[num_rooms++] = new_room;
}

void connect_rooms(room *room1, room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            break;
        case 's':
            room1->south = room2;
            break;
        case 'e':
            room1->east = room2;
            break;
        case 'w':
            room1->west = room2;
            break;
    }
}

void print_room() {
    printf("%s\n", current_room->name);
    printf("%s\n", current_room->description);
    printf("Exits:");
    if (current_room->north != NULL) printf(" north");
    if (current_room->south != NULL) printf(" south");
    if (current_room->east != NULL) printf(" east");
    if (current_room->west != NULL) printf(" west");
    printf("\n");
}

void move(char direction) {
    switch (direction) {
        case 'n':
            if (current_room->north != NULL) current_room = current_room->north;
            break;
        case 's':
            if (current_room->south != NULL) current_room = current_room->south;
            break;
        case 'e':
            if (current_room->east != NULL) current_room = current_room->east;
            break;
        case 'w':
            if (current_room->west != NULL) current_room = current_room->west;
            break;
    }
}

int main() {
    create_room("Forest", "You are in a forest.");
    create_room("Cave", "You are in a cave.");
    connect_rooms(rooms[0], rooms[1], 'n');

    current_room = rooms[0];

    char input[256];

    while (1) {
        print_room();

        printf("> ");
        gets(input);

        if (strcmp(input, "n") == 0) {
            move('n');
        } else if (strcmp(input, "s") == 0) {
            move('s');
        } else if (strcmp(input, "e") == 0) {
            move('e');
        } else if (strcmp(input, "w") == 0) {
            move('w');
        } else if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    return 0;
}