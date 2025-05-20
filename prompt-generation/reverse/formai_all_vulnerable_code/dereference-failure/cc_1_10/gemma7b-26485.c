//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PLAYER 2

typedef struct Maze {
    int **data;
    int width;
    int height;
} Maze;

Maze *create_maze(int w, int h) {
    Maze *maze = malloc(sizeof(Maze));
    maze->data = malloc(h * sizeof(int *) + 1);
    for (int i = 0; i < h; i++) {
        maze->data[i] = malloc(w * sizeof(int) + 1);
    }
    maze->width = w;
    maze->height = h;
    return maze;
}

void generate_maze(Maze *maze) {
    srand(time(NULL));
    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            maze->data[y][x] = EMPTY;
        }
    }

    int num_walls = 50;
    for (int i = 0; i < num_walls; i++) {
        int x = rand() % maze->width;
        int y = rand() % maze->height;
        maze->data[y][x] = WALL;
    }

    maze->data[0][0] = PLAYER;
}

void draw_maze(Maze *maze) {
    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            switch (maze->data[y][x]) {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PLAYER:
                    printf("P");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Maze *maze = create_maze(MAZE_WIDTH, MAZE_HEIGHT);
    generate_maze(maze);
    draw_maze(maze);
    return 0;
}