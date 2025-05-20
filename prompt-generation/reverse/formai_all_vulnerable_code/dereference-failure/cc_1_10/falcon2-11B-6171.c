//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 20
#define MAX_Y 20

typedef struct {
    int x;
    int y;
} Coordinate;

Coordinate* getRandomCoordinate() {
    Coordinate* random = (Coordinate*)malloc(sizeof(Coordinate));
    random->x = rand() % MAX_X;
    random->y = rand() % MAX_Y;
    return random;
}

void printMaze(Coordinate* maze, int mazeSize) {
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            if (maze[i].x == j && maze[i].y == i) {
                printf("O");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    Coordinate* maze = (Coordinate*)malloc(sizeof(Coordinate) * MAX_X * MAX_Y);
    Coordinate* start = getRandomCoordinate();
    Coordinate* end = getRandomCoordinate();

    for (int i = 0; i < MAX_X * MAX_Y; i++) {
        maze[i].x = rand() % MAX_X;
        maze[i].y = rand() % MAX_Y;
    }

    for (int i = 0; i < MAX_X * MAX_Y; i++) {
        if (maze[i].x == start->x && maze[i].y == start->y) {
            maze[i].x = rand() % MAX_X;
            maze[i].y = rand() % MAX_Y;
        }
        if (maze[i].x == end->x && maze[i].y == end->y) {
            maze[i].x = rand() % MAX_X;
            maze[i].y = rand() % MAX_Y;
        }
    }

    printMaze(maze, MAX_X * MAX_Y);

    return 0;
}