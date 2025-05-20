//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 50
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct Room Room;
struct Room {
    char name[20];
    char description[200];
    Room* exits[4];
};

Room* createRoom(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    for(int i = 0; i < 4; i++) {
        room->exits[i] = NULL;
    }
    return room;
}

void link(Room* room1, Room* room2, int direction1, int direction2) {
    room1->exits[direction1] = room2;
    room2->exits[direction2] = room1;
}

void printDescription(Room* room) {
    printf("\n%s\n\n%s\n\n", room->name, room->description);
}

int getInput(char* input) {
    printf(">> ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    int length = strlen(input);
    if(input[length-1] == '\n') {
        input[length-1] = '\0';
    }
    return length;
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    // create rooms
    Room* start = createRoom("Start", "You are standing in a small room with a locked door in front of you.");
    Room* livingRoom = createRoom("Living Room", "The living room is dimly lit with a couch and TV in front of you.");
    Room* kitchen = createRoom("Kitchen", "The kitchen is a mess with dirty dishes piled high.");
    Room* backyard = createRoom("Backyard", "The backyard is a peaceful oasis with a small pond.");
    Room* attic = createRoom("Attic", "The attic is dusty and filled with old boxes.");

    // link rooms
    link(start, livingRoom, 0, 2);
    link(start, kitchen, 1, 3);
    link(livingRoom, backyard, 3, 1);
    link(kitchen, attic, 0, 1);

    // set starting room
    Room* currentRoom = start;

    // display starting room description
    printDescription(currentRoom);

    // game loop
    bool finished = false;
    while(!finished) {
        char input[MAX_INPUT_SIZE];
        getInput(input);
        int length = strlen(input);

        if(length == 0) {
            printf("Please enter a command.\n");
        }
        else if(strcmp(input, "quit") == 0) {
            printf("Thank you for playing!\n");
            finished = true;
        }
        else if(strcmp(input, "look") == 0) {
            printDescription(currentRoom);
        }
        else if(strcmp(input, "north") == 0 || strcmp(input, "n") == 0) {
            if(currentRoom->exits[0]) {
                currentRoom = currentRoom->exits[0];
                printDescription(currentRoom);
            }
            else {
                printf("There is no exit in that direction.\n");
            }
        }
        else if(strcmp(input, "east") == 0 || strcmp(input, "e") == 0) {
            if(currentRoom->exits[1]) {
                currentRoom = currentRoom->exits[1];
                printDescription(currentRoom);
            }
            else {
                printf("There is no exit in that direction.\n");
            }
        }
        else if(strcmp(input, "south") == 0 || strcmp(input, "s") == 0) {
            if(currentRoom->exits[2]) {
                currentRoom = currentRoom->exits[2];
                printDescription(currentRoom);
            }
            else {
                printf("There is no exit in that direction.\n");
            }
        }
        else if(strcmp(input, "west") == 0 || strcmp(input, "w") == 0) {
            if(currentRoom->exits[3]) {
                currentRoom = currentRoom->exits[3];
                printDescription(currentRoom);
            }
            else {
                printf("There is no exit in that direction.\n");
            }
        }
        else {
            printf("I do not understand that command.\n");
        }
    }

    return 0;
}