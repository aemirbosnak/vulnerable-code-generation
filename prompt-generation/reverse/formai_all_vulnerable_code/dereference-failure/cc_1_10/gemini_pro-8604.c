//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct room {
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

void free_room(room *room) {
    free(room->name);
    free(room->description);
    free(room);
}

room *current_room;

void init_game() {
    room *room1 = create_room("Room 1", "This is the first room.");
    room *room2 = create_room("Room 2", "This is the second room.");
    room *room3 = create_room("Room 3", "This is the third room.");

    room1->north = room2;
    room1->east = room3;
    room2->south = room1;
    room2->east = room3;
    room3->west = room1;
    room3->west = room2;

    current_room = room1;
}

void process_command(char *command) {
    if (strcmp(command, "north") == 0) {
        if (current_room->north != NULL) {
            current_room = current_room->north;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "east") == 0) {
        if (current_room->east != NULL) {
            current_room = current_room->east;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "south") == 0) {
        if (current_room->south != NULL) {
            current_room = current_room->south;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "west") == 0) {
        if (current_room->west != NULL) {
            current_room = current_room->west;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(command, "look") == 0) {
        printf("%s\n", current_room->description);
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else {
        printf("I don't understand that command.\n");
    }
}

int main() {
    init_game();

    char command[MAX_CMD_LEN];

    while (1) {
        printf("> ");
        fgets(command, MAX_CMD_LEN, stdin);
        command[strcspn(command, "\n")] = 0;  // remove newline character
        process_command(command);
    }

    return 0;
}