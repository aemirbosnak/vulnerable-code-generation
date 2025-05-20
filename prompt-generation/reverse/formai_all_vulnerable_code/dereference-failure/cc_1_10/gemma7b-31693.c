//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int size) {
    srand(time(NULL));
    Room** maze = (Room**)malloc(size * sizeof(Room*));
    for (int i = 0; i < size; i++) {
        maze[i] = (Room*)malloc(sizeof(Room));
        maze[i]->x = rand() % size;
        maze[i]->y = rand() % size;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    for (int i = 0; i < size; i++) {
        Room* current = maze[i];
        if (i > 0) {
            int direction = rand() % MAX_PATHS;
            switch (direction) {
                case 0:
                    current->north = maze[rand() % MAX_ROOMS];
                    break;
                case 1:
                    current->south = maze[rand() % MAX_ROOMS];
                    break;
                case 2:
                    current->east = maze[rand() % MAX_ROOMS];
                    break;
                case 3:
                    current->west = maze[rand() % MAX_ROOMS];
                    break;
            }
        }
    }

    return maze;
}

int main() {
    Room** maze = generateMaze(5);
    for (int i = 0; i < 5; i++) {
        printf("Room %d: (%d, %d)\n", i, maze[i]->x, maze[i]->y);
    }

    return 0;
}