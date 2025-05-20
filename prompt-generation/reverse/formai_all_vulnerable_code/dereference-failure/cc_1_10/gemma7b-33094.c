//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
    int num;
    char **walls;
    struct Room **nextRooms;
} Room;

Room **createRoom(int num) {
    Room *newRoom = malloc(sizeof(Room));
    newRoom->num = num;
    newRoom->walls = malloc(MAX_PATHS * sizeof(char *));
    newRoom->nextRooms = NULL;

    for (int i = 0; i < MAX_PATHS; i++) {
        newRoom->walls[i] = NULL;
    }

    return newRoom;
}

void generateMaze(int numRooms) {
    srand(time(NULL));

    Room **rooms = malloc(numRooms * sizeof(Room));

    for (int i = 0; i < numRooms; i++) {
        rooms[i] = createRoom(i + 1);
    }

    for (int i = 0; i < numRooms; i++) {
        int numPaths = rand() % MAX_PATHS;

        for (int j = 0; j < numPaths; j++) {
            rooms[i]->walls[j] = rooms[rand() % numRooms];
        }
    }

    free(rooms);
}

int main() {
    generateMaze(MAX_ROOMS);

    return 0;
}