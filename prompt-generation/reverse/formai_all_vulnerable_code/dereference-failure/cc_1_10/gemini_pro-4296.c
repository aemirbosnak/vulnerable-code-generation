//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DIRECTIONS 4

typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

room* create_room(char* name, char* description) {
    room* new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

void destroy_room(room* room) {
    free(room->name);
    free(room->description);
    free(room);
}

void connect_rooms(room* room1, room* room2, char* direction) {
    if (strcmp(direction, "north") == 0) {
        room1->north = room2;
    } else if (strcmp(direction, "east") == 0) {
        room1->east = room2;
    } else if (strcmp(direction, "south") == 0) {
        room1->south = room2;
    } else if (strcmp(direction, "west") == 0) {
        room1->west = room2;
    }
}

void print_room(room* room) {
    printf("You are in the %s.\n", room->name);
    printf("%s\n", room->description);
    printf("You can go: ");
    if (room->north != NULL) {
        printf("north ");
    }
    if (room->east != NULL) {
        printf("east ");
    }
    if (room->south != NULL) {
        printf("south ");
    }
    if (room->west != NULL) {
        printf("west ");
    }
    printf("\n");
}

int main() {
    room* rooms[MAX_ROOMS] = {
        create_room("Foyer", "You are in a small foyer with a door to the north."),
        create_room("Living Room", "You are in a large living room with a fireplace to the north and a door to the east."),
        create_room("Kitchen", "You are in a small kitchen with a stove to the west and a door to the south."),
        create_room("Dining Room", "You are in a large dining room with a table and chairs to the east."),
        create_room("Master Bedroom", "You are in a large master bedroom with a bed to the east and a door to the south."),
        create_room("Guest Bedroom", "You are in a small guest bedroom with a bed to the west and a door to the north."),
        create_room("Bathroom", "You are in a small bathroom with a toilet to the west and a door to the south."),
        create_room("Study", "You are in a small study with a desk to the west and a door to the east."),
        create_room("Conservatory", "You are in a large conservatory with a large window to the south and a door to the east."),
        create_room("Library", "You are in a large library with bookshelves to the north, east, and south."),
    };

    connect_rooms(rooms[0], rooms[1], "north");
    connect_rooms(rooms[1], rooms[2], "east");
    connect_rooms(rooms[1], rooms[3], "south");
    connect_rooms(rooms[3], rooms[4], "east");
    connect_rooms(rooms[3], rooms[6], "south");
    connect_rooms(rooms[4], rooms[5], "north");
    connect_rooms(rooms[6], rooms[7], "north");
    connect_rooms(rooms[7], rooms[8], "east");
    connect_rooms(rooms[8], rooms[9], "east");

    room* current_room = rooms[0];

    while (1) {
        print_room(current_room);

        char direction[10];
        printf("> ");
        scanf("%s", direction);

        if (strcmp(direction, "north") == 0) {
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(direction, "east") == 0) {
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(direction, "south") == 0) {
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(direction, "west") == 0) {
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("You cannot go that way.\n");
            }
        } else if (strcmp(direction, "quit") == 0) {
            break;
        } else {
            printf("I do not understand that command.\n");
        }
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        destroy_room(rooms[i]);
    }

    return 0;
}