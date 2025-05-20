//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_WALL_NUM 5

typedef struct room {
    int num;
    struct room* north;
    struct room* south;
    struct room* east;
    struct room* west;
} room;

room** generateMaze(int size) {
    srand(time(NULL));
    room** maze = malloc(size * sizeof(room*));
    for (int i = 0; i < size; i++) {
        maze[i] = malloc(sizeof(room));
        maze[i]->num = i + 1;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    for (int i = 0; i < size; i++) {
        int numWalls = rand() % MAX_WALL_NUM + 1;
        for (int j = 0; j < numWalls; j++) {
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
    room** maze = generateMaze(size);

    for (int i = 0; i < size; i++) {
        printf("Room %d: ", maze[i]->num);
        if (maze[i]->north) {
            printf("North to Room %d ", maze[i]->north->num);
        }
        if (maze[i]->south) {
            printf("South to Room %d ", maze[i]->south->num);
        }
        if (maze[i]->east) {
            printf("East to Room %d ", maze[i]->east->num);
        }
        if (maze[i]->west) {
            printf("West to Room %d ", maze[i]->west->num);
        }
        printf("\n");
    }

    return 0;
}