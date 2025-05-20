//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate end;
} Maze;

Maze* createMaze(int size) {
    Maze* maze = (Maze*) malloc(sizeof(Maze));
    maze->start.x = rand() % size;
    maze->start.y = rand() % size;
    maze->end.x = rand() % size;
    maze->end.y = rand() % size;
    return maze;
}

void printMaze(Maze* maze) {
    printf("Maze:\n");
    for (int i = 0; i < maze->start.x; i++) {
        for (int j = 0; j < maze->start.y; j++) {
            printf("-");
        }
        printf("\n");
    }
    for (int i = 0; i < maze->end.x; i++) {
        for (int j = 0; j < maze->end.y; j++) {
            printf("O");
        }
        printf("\n");
    }
    for (int i = 0; i < maze->start.x; i++) {
        for (int j = 0; j < maze->start.y; j++) {
            printf("-");
        }
        printf("\n");
    }
}

int main() {
    int size = 10;
    srand(time(0));
    Maze* maze = createMaze(size);
    printMaze(maze);
    return 0;
}