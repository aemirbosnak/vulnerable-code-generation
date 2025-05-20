//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 2

typedef struct Room {
    int number;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

Room* CreateRoom(int number) {
    Room* room = malloc(sizeof(Room));
    room->number = number;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

void ConnectRooms(Room* room1, Room* room2) {
    room1->north = room2;
    room2->south = room1;
}

void GenerateMaze(int numRooms) {
    srand(time(NULL));
    Room** rooms = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = CreateRoom(i + 1);
    }

    for (int i = 0; i < numRooms - 1; i++) {
        ConnectRooms(rooms[rand() % numRooms], rooms[rand() % numRooms]);
    }

    // Print the maze
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: ", rooms[i]->number);
        if (rooms[i]->north) {
            printf("North to Room %d ", rooms[i]->north->number);
        }
        if (rooms[i]->south) {
            printf("South to Room %d ", rooms[i]->south->number);
        }
        if (rooms[i]->east) {
            printf("East to Room %d ", rooms[i]->east->number);
        }
        if (rooms[i]->west) {
            printf("West to Room %d ", rooms[i]->west->number);
        }
        printf("\n");
    }
}

int main() {
    GenerateMaze(MAX_ROOMS);
    return 0;
}