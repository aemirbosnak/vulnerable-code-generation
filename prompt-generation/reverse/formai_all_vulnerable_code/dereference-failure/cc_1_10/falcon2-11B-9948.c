//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Maze;

Maze* createMaze(int rows, int cols) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->start.x = 0;
    maze->start.y = 0;
    maze->end.x = rows - 1;
    maze->end.y = cols - 1;
    return maze;
}

void freeMaze(Maze* maze) {
    free(maze);
}

void printMaze(Maze* maze) {
    int rows = maze->end.x - maze->start.x + 1;
    int cols = maze->end.y - maze->start.y + 1;
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == maze->start.x && j == maze->start.y)
                printf("S ");
            else if (i == maze->end.x && j == maze->end.y)
                printf("E ");
            else
                printf("# ");
        }
        printf("\n");
    }
}

int main() {
    int rows = 10;
    int cols = 10;
    Maze* maze = createMaze(rows, cols);
    printMaze(maze);
    freeMaze(maze);
    return 0;
}