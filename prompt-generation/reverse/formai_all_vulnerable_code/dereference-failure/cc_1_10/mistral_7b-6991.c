//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21
#define WALL 0
#define PATH 1
#define START 2
#define END 3

typedef struct cell {
    int x, y;
    int value;
} cell;

void print_maze(cell **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cell *current = &maze[i][j];
            printf(current->value == WALL ? "%c" : current->value == START ? "S" : current->value == END ? "E" : " ");
        }
        printf("\n");
    }
}

void randomize_maze(cell **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cell *current = &maze[i][j];
            current->value = WALL;
        }
    }

    cell stack[WIDTH * HEIGHT];
    int top = 0;

    maze[1][1].value = START;
    stack[top].x = 1;
    stack[top].y = 1;
    top++;

    while (top > 0) {
        int x = stack[top - 1].x;
        int y = stack[top - 1].y;

        cell *current = &maze[y][x];
        int neighbors = 0;
        int dx[4] = {-1, 1, 1, -1};
        int dy[4] = {-1, -1, 1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[ny][nx].value == WALL) {
                neighbors++;
                maze[y][x].value = PATH;

                cell *new_cell = &maze[ny][nx];
                new_cell->value = PATH;
                stack[top].x = nx;
                stack[top].y = ny;
                top++;
            }
        }

        if (neighbors == 0) {
            top--;
            continue;
        }

        int direction = rand() % neighbors * 4;
        int dx2 = dx[direction / 4];
        int dy2 = dy[direction % 4];

        maze[y + dy2][x + dx2].value = PATH;
        stack[top].x = x + dx2;
        stack[top].y = y + dy2;
        top++;
    }

    maze[HEIGHT - 2][WIDTH - 2].value = END;
}

int main() {
    srand(time(NULL));

    cell **maze = malloc(sizeof(cell *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = malloc(sizeof(cell) * WIDTH);
    }

    randomize_maze(maze);
    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}