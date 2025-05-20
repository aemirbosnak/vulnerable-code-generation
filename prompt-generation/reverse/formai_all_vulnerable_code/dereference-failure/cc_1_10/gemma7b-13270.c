//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10

typedef struct Room {
    int num;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

Room* createRoom(int num) {
    Room* room = malloc(sizeof(Room));
    room->num = num;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;

    return room;
}

void connectRooms(Room* room1, Room* room2) {
    room1->north = room2;
    room2->south = room1;
}

void generateMaze(int numRooms) {
    srand(time(NULL));

    Room* rooms[numRooms];

    for (int i = 0; i < numRooms; i++) {
        rooms[i] = createRoom(i);
    }

    for (int i = 0; i < numRooms - 1; i++) {
        int randomRoom = rand() % numRooms;
        connectRooms(rooms[i], rooms[randomRoom]);
    }

    rooms[0]->north = rooms[numRooms - 1];
    rooms[numRooms - 1]->south = rooms[0];
}

int main() {
    generateMaze(MAX_ROOM_NUM);

    return 0;
}