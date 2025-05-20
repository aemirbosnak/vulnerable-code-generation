//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
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
        rooms[i] = createRoom(i + 1);
    }

    for (int i = 0; i < numRooms - 1; i++) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                connectRooms(rooms[i], rooms[i + 1]);
                break;
            case 1:
                connectRooms(rooms[i], rooms[i - 1]);
                break;
            case 2:
                connectRooms(rooms[i], rooms[i + 1]);
                break;
            case 3:
                connectRooms(rooms[i], rooms[i - 1]);
                break;
        }
    }

    // Print the maze
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: ", rooms[i]->num);
        if (rooms[i]->north) {
            printf("North to Room %d\n", rooms[i]->north->num);
        }
        if (rooms[i]->south) {
            printf("South to Room %d\n", rooms[i]->south->num);
        }
        if (rooms[i]->east) {
            printf("East to Room %d\n", rooms[i]->east->num);
        }
        if (rooms[i]->west) {
            printf("West to Room %d\n", rooms[i]->west->num);
        }
        printf("\n");
    }
}

int main() {
    generateMaze(MAX_ROOM_NUM);

    return 0;
}