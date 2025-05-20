//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_PATH_LENGTH 20

typedef struct Room {
    char name[20];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

Room** generateMaze(int numRooms) {
    Room** maze = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    return maze;
}

void traverseMaze(Room* currentRoom) {
    printf("%s\n", currentRoom->name);

    if (currentRoom->north) {
        traverseMaze(currentRoom->north);
    }
    if (currentRoom->south) {
        traverseMaze(currentRoom->south);
    }
    if (currentRoom->east) {
        traverseMaze(currentRoom->east);
    }
    if (currentRoom->west) {
        traverseMaze(currentRoom->west);
    }
}

int main() {
    srand(time(NULL));

    int numRooms = rand() % MAX_ROOM_NUM + 10;
    Room** maze = generateMaze(numRooms);

    traverseMaze(maze[0]);

    return 0;
}