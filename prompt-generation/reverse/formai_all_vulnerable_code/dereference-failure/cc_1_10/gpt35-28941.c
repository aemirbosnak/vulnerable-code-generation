//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct RoomStruct {
    char name[50];
    char description[200];
    struct RoomStruct* north;
    struct RoomStruct* east;
    struct RoomStruct* south;
    struct RoomStruct* west;
} Room;

Room* currentRoom;

void createRooms() {
    Room* room1 = (Room*)malloc(sizeof(Room));
    Room* room2 = (Room*)malloc(sizeof(Room));
    Room* room3 = (Room*)malloc(sizeof(Room));

    strcpy(room1->name, "Entrance");
    strcpy(room1->description, "You are standing in front of a large old building. The door is locked and the windows are boarded up.");

    strcpy(room2->name, "Dark Room");
    strcpy(room2->description, "As you enter the room, you can barely see anything. It is pitch black and the air is damp.");

    strcpy(room3->name, "Treasure Room");
    strcpy(room3->description, "As you enter the room, you see a large pile of treasure in the middle. There are also many dangerous traps.");

    // Set connections between rooms
    room1->north = NULL;
    room1->east = room2;
    room1->south = NULL;
    room1->west = NULL;

    room2->north = NULL;
    room2->east = NULL;
    room2->south = room3;
    room2->west = room1;

    room3->north = room2;
    room3->east = NULL;
    room3->south = NULL;
    room3->west = NULL;

    currentRoom = room1;
}

void printRoomDescription() {
    printf("\n%s\n\n", currentRoom->description);
}

void goNorth() {
    if(currentRoom->north == NULL) {
        printf("There is no exit to the north.\n");
    } else {
        currentRoom = currentRoom->north;
        printRoomDescription();
    }
}

void goEast() {
    if(currentRoom->east == NULL) {
        printf("There is no exit to the east.\n");
    } else {
        currentRoom = currentRoom->east;
        printRoomDescription();
    }
}

void goSouth() {
    if(currentRoom->south == NULL) {
        printf("There is no exit to the south.\n");
    } else {
        currentRoom = currentRoom->south;
        printRoomDescription();
    }
}

void goWest() {
    if(currentRoom->west == NULL) {
        printf("There is no exit to the west.\n");
    } else {
        currentRoom = currentRoom->west;
        printRoomDescription();
    }
}

void getInput() {
    char input[20];
    printf("Enter a command: ");
    scanf("%s", input);
    printf("\n");

    if(strcmp(input, "north") == 0) {
        goNorth();
    } else if(strcmp(input, "east") == 0) {
        goEast();
    } else if(strcmp(input, "south") == 0) {
        goSouth();
    } else if(strcmp(input, "west") == 0) {
        goWest();
    } else if(strcmp(input, "quit") == 0) {
        printf("Goodbye.\n");
        exit(0);
    } else {
        printf("Invalid command. Try again.\n\n");
    }
}

int main() {
    createRooms();
    printRoomDescription();

    while(1) {
        getInput();
    }

    return 0;
}