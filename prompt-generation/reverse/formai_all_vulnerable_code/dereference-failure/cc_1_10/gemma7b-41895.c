//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 10

typedef struct Room {
    int num;
    char name[20];
    struct Room* next;
} Room;

Room* createRoom(int num, char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->num = num;
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

void startGame() {
    Room* roomList = createRoom(1, "The Hall");
    roomList = createRoom(2, "The Kitchen");
    roomList = createRoom(3, "The Living Room");
    roomList = createRoom(4, "The Bedroom");

    connectRooms(roomList, roomList->next);
    connectRooms(roomList->next, roomList->next->next);
    connectRooms(roomList->next->next, roomList->next->next->next);

    Room* currentRoom = roomList;
    char input[20];

    printf("You are in %s. What do you want to do? ", currentRoom->name);
    scanf("%s", input);

    if (strcmp(input, "go north") == 0) {
        currentRoom = currentRoom->next;
        printf("You are now in %s. ", currentRoom->name);
    } else if (strcmp(input, "go south") == 0) {
        currentRoom = currentRoom->next->next;
        printf("You are now in %s. ", currentRoom->name);
    } else {
        printf("Invalid input. Please try again. ");
    }
}

int main() {
    startGame();

    return 0;
}