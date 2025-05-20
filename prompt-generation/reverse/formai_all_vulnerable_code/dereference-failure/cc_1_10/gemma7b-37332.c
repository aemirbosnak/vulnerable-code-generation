//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUMBER 10

typedef struct Room {
    int number;
    char name[20];
    struct Room* nextRoom;
} Room;

Room* createRoom(int number, char* name) {
    Room* room = malloc(sizeof(Room));
    room->number = number;
    strcpy(room->name, name);
    room->nextRoom = NULL;
    return room;
}

void connectRooms(Room* room1, Room* room2) {
    room1->nextRoom = room2;
}

int main() {
    Room* room1 = createRoom(1, "The Hall");
    Room* room2 = createRoom(2, "The Kitchen");
    Room* room3 = createRoom(3, "The Living Room");
    Room* room4 = createRoom(4, "The Bedroom");

    connectRooms(room1, room2);
    connectRooms(room2, room3);
    connectRooms(room3, room4);

    printf("You are in %s.\n", room1->name);

    char command;
    scanf("%c", &command);

    switch (command) {
        case 'n':
            printf("You went north to %s.\n", room2->name);
            break;
        case 's':
            printf("You went south to %s.\n", room3->name);
            break;
        case 'e':
            printf("You went east to %s.\n", room4->name);
            break;
        case 'w':
            printf("You went west to %s.\n", room2->name);
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    return 0;
}