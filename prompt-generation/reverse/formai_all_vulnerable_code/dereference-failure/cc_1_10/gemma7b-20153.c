//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 10

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Room* prev;
} Room;

Room* CreateRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->prev = NULL;
    return newRoom;
}

void ConnectRooms(Room* room1, Room* room2) {
    room1->next = room2;
    room2->prev = room1;
}

void PlayGame() {
    Room* currentRoom = CreateRoom("The Hall");
    Room* room1 = CreateRoom("The Kitchen");
    Room* room2 = CreateRoom("The Bedroom");

    ConnectRooms(currentRoom, room1);
    ConnectRooms(room1, room2);

    printf("You are in %s. What do you want to do?", currentRoom->name);
    char input[20];
    scanf("%s", input);

    // Check if the input is valid
    if (strcmp(input, "north") == 0) {
        currentRoom = currentRoom->next;
        printf("You are now in %s.", currentRoom->name);
    } else if (strcmp(input, "south") == 0) {
        currentRoom = currentRoom->prev;
        printf("You are now in %s.", currentRoom->name);
    } else {
        printf("Invalid input.");
    }
}

int main() {
    PlayGame();
    return 0;
}