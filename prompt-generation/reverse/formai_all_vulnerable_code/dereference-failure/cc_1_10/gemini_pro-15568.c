//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

room *create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

void destroy_room(room *room) {
    free(room->name);
    free(room->description);
    free(room);
}

void print_room(room *room) {
    printf("You are in %s.\n", room->name);
    printf("%s\n", room->description);
}

void move_player(room **player_room, char *direction) {
    if (!strcmp(direction, "north") && (*player_room)->north != NULL) {
        *player_room = (*player_room)->north;
    } else if (!strcmp(direction, "east") && (*player_room)->east != NULL) {
        *player_room = (*player_room)->east;
    } else if (!strcmp(direction, "south") && (*player_room)->south != NULL) {
        *player_room = (*player_room)->south;
    } else if (!strcmp(direction, "west") && (*player_room)->west != NULL) {
        *player_room = (*player_room)->west;
    } else {
        printf("You cannot go that way.\n");
    }
}

int main() {
    room *room1 = create_room("Room 1", "This is the first room.");
    room *room2 = create_room("Room 2", "This is the second room.");
    room *room3 = create_room("Room 3", "This is the third room.");
    room *room4 = create_room("Room 4", "This is the fourth room.");
    room *room5 = create_room("Room 5", "This is the fifth room.");

    room1->north = room2;
    room1->east = room3;
    room2->south = room1;
    room2->east = room4;
    room3->west = room1;
    room3->east = room5;
    room4->west = room2;
    room5->west = room3;

    room *player_room = room1;

    char input[256];
    while (1) {
        print_room(player_room);
        printf("What do you want to do?\n");
        fgets(input, sizeof(input), stdin);
        if (!strcmp(input, "quit\n")) {
            break;
        } else if (!strcmp(input, "north\n")) {
            move_player(&player_room, "north");
        } else if (!strcmp(input, "east\n")) {
            move_player(&player_room, "east");
        } else if (!strcmp(input, "south\n")) {
            move_player(&player_room, "south");
        } else if (!strcmp(input, "west\n")) {
            move_player(&player_room, "west");
        } else {
            printf("I don't understand that command.\n");
        }
    }

    destroy_room(room1);
    destroy_room(room2);
    destroy_room(room3);
    destroy_room(room4);
    destroy_room(room5);

    return 0;
}