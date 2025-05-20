//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 10
#define MAX_Doors 3

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int size) {
    srand(time(NULL));
    Room** maze = (Room**)malloc(size * sizeof(Room*));
    for (int i = 0; i < size; i++) {
        maze[i] = (Room*)malloc(sizeof(Room));
        maze[i]->x = i;
        maze[i]->y = -1;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    for (int i = 0; i < size; i++) {
        int numDoors = rand() % MAX_Doors;
        for (int j = 0; j < numDoors; j++) {
            switch (rand() % 4) {
                case 0:
                    maze[i]->north = maze[rand() % size];
                    break;
                case 1:
                    maze[i]->south = maze[rand() % size];
                    break;
                case 2:
                    maze[i]->east = maze[rand() % size];
                    break;
                case 3:
                    maze[i]->west = maze[rand() % size];
                    break;
            }
        }
    }

    return maze;
}

int main() {
    int size = 10;
    Room** maze = generateMaze(size);

    for (int i = 0; i < size; i++) {
        printf("Room %d: (%d, %d)\n", maze[i]->x, maze[i]->y);
        printf("Doors:\n");
        if (maze[i]->north) printf("North: Room %d\n", maze[i]->north->x);
        if (maze[i]->south) printf("South: Room %d\n", maze[i]->south->x);
        if (maze[i]->east) printf("East: Room %d\n", maze[i]->east->x);
        if (maze[i]->west) printf("West: Room %d\n", maze[i]->west->x);
        printf("\n");
    }

    return 0;
}