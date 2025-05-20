//Gemma-7B DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
    char name[20];
    struct Room* nextRoom;
} Room;

Room* createRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->nextRoom = NULL;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    room1->nextRoom = room2;
}

int main() {
    Room* rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = NULL;
    }

    // Create the rooms
    rooms[0] = createRoom("The Grand Hall");
    rooms[1] = createRoom("The Dining Hall");
    rooms[2] = createRoom("The Library");
    rooms[3] = createRoom("The Ballroom");

    // Connect the rooms
    connectRooms(rooms[0], rooms[1]);
    connectRooms(rooms[1], rooms[2]);
    connectRooms(rooms[2], rooms[3]);

    // Start in the Grand Hall
    Room* currentRoom = rooms[0];

    // Wander through the rooms
    while (currentRoom) {
        printf("You are in %s.\n", currentRoom->name);

        // Go to the next room
        currentRoom = currentRoom->nextRoom;
    }

    return 0;
}