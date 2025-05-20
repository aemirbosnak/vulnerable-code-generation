//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    char *name;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

Room *createRoom(char *name, char *description) {
    Room *room = (Room *)malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void destroyRoom(Room *room) {
    free(room->name);
    free(room->description);
    free(room);
}

void connectRooms(Room *room1, Room *room2, char direction) {
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

void printRoom(Room *room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
}

void playGame(Room *room) {
    printRoom(room);

    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    char *command = strtok(input, " ");
    char *argument = strtok(NULL, " ");

    if (strcmp(command, "go") == 0) {
        if (strcmp(argument, "north") == 0) {
            if (room->north != NULL) {
                playGame(room->north);
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(argument, "south") == 0) {
            if (room->south != NULL) {
                playGame(room->south);
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(argument, "east") == 0) {
            if (room->east != NULL) {
                playGame(room->east);
            } else {
                printf("There is no door to the east.\n");
            }
        } else if (strcmp(argument, "west") == 0) {
            if (room->west != NULL) {
                playGame(room->west);
            } else {
                printf("There is no door to the west.\n");
            }
        } else {
            printf("Invalid direction.\n");
        }
    } else if (strcmp(command, "look") == 0) {
        printRoom(room);
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    Room *room1 = createRoom("The foyer", "You are standing in the foyer of a large house.");
    Room *room2 = createRoom("The living room", "You are standing in the living room of a large house.");
    Room *room3 = createRoom("The dining room", "You are standing in the dining room of a large house.");
    Room *room4 = createRoom("The kitchen", "You are standing in the kitchen of a large house.");
    Room *room5 = createRoom("The master bedroom", "You are standing in the master bedroom of a large house.");

    connectRooms(room1, room2, 'n');
    connectRooms(room1, room3, 's');
    connectRooms(room2, room4, 'e');
    connectRooms(room3, room5, 'w');

    playGame(room1);

    destroyRoom(room1);
    destroyRoom(room2);
    destroyRoom(room3);
    destroyRoom(room4);
    destroyRoom(room5);

    return 0;
}