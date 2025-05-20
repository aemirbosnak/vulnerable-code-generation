//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define WALL 1
#define EMPTY 0

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void createMaze(Cell **maze, int w, int h) {
    int i, j;
    *maze = malloc(w * h * sizeof(Cell));
    for (i = 0; i < w * h; i++) {
        (*maze)[i].x = i % w;
        (*maze)[i].y = i / w;
        (*maze)[i].state = EMPTY;
    }
}

void generateMaze(Cell **maze) {
    int i, j, r, x, y;
    srand(time(NULL));
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 2) {
                maze[i][j].state = WALL;
            }
        }
    }
}

void printMaze(Cell **maze) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            switch (maze[i][j].state) {
                case WALL:
                    printf("#");
                    break;
                case EMPTY:
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Cell **maze;
    createMaze(&maze, WIDTH, HEIGHT);
    generateMaze(maze);
    printMaze(maze);

    return 0;
}