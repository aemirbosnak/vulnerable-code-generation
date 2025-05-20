//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define EMPTY 0
#define WALL 1
#define START 2
#define END 3

typedef struct Cell {
    int x;
    int y;
    int type;
} Cell;

Cell **createMaze(int w, int h) {
    Cell **maze = malloc(h * sizeof(Cell *) + w * sizeof(Cell));
    for (int y = 0; y < h; y++) {
        maze[y] = malloc(w * sizeof(Cell));
        for (int x = 0; x < w; x++) {
            maze[y][x].x = x;
            maze[y][x].y = y;
            maze[y][x].type = EMPTY;
        }
    }

    return maze;
}

void generateMaze(Cell **maze) {
    srand(time(NULL));
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (maze[y][x].type == EMPTY) {
                maze[y][x].type = WALL;
            }
        }
    }

    maze[0][0].type = START;
    maze[MAZE_HEIGHT - 1][MAZE_WIDTH - 1].type = END;
}

void drawMaze(Cell **maze) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            switch (maze[y][x].type) {
                case WALL:
                    printf("%c", '#');
                    break;
                case START:
                    printf("%c", 'S');
                    break;
                case END:
                    printf("%c", 'E');
                    break;
                default:
                    printf("%c", '.');
                    break;
            }
        }

        printf("\n");
    }
}

int main() {
    Cell **maze = createMaze(MAZE_WIDTH, MAZE_HEIGHT);
    generateMaze(maze);
    drawMaze(maze);

    return 0;
}