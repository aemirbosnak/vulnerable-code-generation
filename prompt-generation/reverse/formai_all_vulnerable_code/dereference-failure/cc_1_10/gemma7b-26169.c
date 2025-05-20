//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
    char name[20];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

Room** generateMaze(int numRooms) {
    Room** rooms = malloc(numRooms * sizeof(Room*));
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->name[0] = 'a' + i;
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
    }

    return rooms;
}

void printMaze(Room** rooms) {
    for (int i = 0; rooms[i] != NULL; i++) {
        printf("%s: ", rooms[i]->name);
        if (rooms[i]->north) {
            printf("N ");
        }
        if (rooms[i]->south) {
            printf("S ");
        }
        if (rooms[i]->east) {
            printf("E ");
        }
        if (rooms[i]->west) {
            printf("W ");
        }
        printf("\n");
    }
}

int main() {
    Room** maze = generateMaze(MAX_ROOMS);
    printMaze(maze);
    return 0;
}