//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Room {
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
    int visited;
} Room;

void printDescription(Room*);
Room* createRoom(char*);

char *commands[] = {
    "north",
    "south",
    "east",
    "west",
    "exit"
};

Room *currentRoom;

int main() {
    // create rooms
    Room *start = createRoom("You are in a dark room. A dim light illuminates the exit to the north.");
    Room *northRoom = createRoom("You have entered a brightly lit room. The exit is to the south.");
    Room *exitRoom = createRoom("You have reached the exit. Congratulations!");

    // connect rooms
    start->north = northRoom;
    northRoom->south = start;
    northRoom->north = exitRoom;
    exitRoom->south = northRoom;

    // set starting room
    currentRoom = start;
    currentRoom->visited = 1;

    // game loop
    while(1) {
        printDescription(currentRoom);

        // get user input
        char userInput[50];
        printf("\n> ");
        fgets(userInput, 50, stdin);

        // remove newline character
        userInput[strcspn(userInput, "\n")] = '\0';

        // check if input is a valid command
        int validCommand = 0;
        for(int i = 0; i < 5; i++) {
            if(strcmp(userInput, commands[i]) == 0) {
                validCommand = 1;
                break;
            }
        }

        // execute command or display error message
        if(validCommand) {
            if(strcmp(userInput, "north") == 0) {
                if(currentRoom->north == NULL) {
                    printf("You cannot go that way.\n");
                } else {
                    currentRoom = currentRoom->north;
                    currentRoom->visited = 1;
                }
            } else if(strcmp(userInput, "south") == 0) {
                if(currentRoom->south == NULL) {
                    printf("You cannot go that way.\n");
                } else {
                    currentRoom = currentRoom->south;
                    currentRoom->visited = 1;
                }
            } else if(strcmp(userInput, "east") == 0) {
                if(currentRoom->east == NULL) {
                    printf("You cannot go that way.\n");
                } else {
                    currentRoom = currentRoom->east;
                    currentRoom->visited = 1;
                }
            } else if(strcmp(userInput, "west") == 0) {
                if(currentRoom->west == NULL) {
                    printf("You cannot go that way.\n");
                } else {
                    currentRoom = currentRoom->west;
                    currentRoom->visited = 1;
                }
            } else {
                // exit command
                printf("Thanks for playing!\n");
                exit(0);
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

void printDescription(Room *room) {
    printf("%s\n", room->description);

    if(room->north != NULL && room->north->visited == 0) {
        printf("There is an unexplored room to the north.\n");
    }

    if(room->south != NULL && room->south->visited == 0) {
        printf("There is an unexplored room to the south.\n");
    }

    if(room->east != NULL && room->east->visited == 0) {
        printf("There is an unexplored room to the east.\n");
    }

    if(room->west != NULL && room->west->visited == 0) {
        printf("There is an unexplored room to the west.\n");
    }
}

Room* createRoom(char *description) {
    Room *room = malloc(sizeof(Room));
    room->description = description;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    room->visited = 0;
    return room;
}