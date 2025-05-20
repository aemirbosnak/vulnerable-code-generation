//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_MAZE_SIZE 10

typedef struct Maze {
    int **map;
    int width;
    int height;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Maze;

Maze *create_maze(int w, int h) {
    Maze *maze = malloc(sizeof(Maze));
    maze->map = malloc(w * h * sizeof(int));
    maze->width = w;
    maze->height = h;
    maze->start_x = 0;
    maze->start_y = 0;
    maze->end_x = w - 1;
    maze->end_y = h - 1;

    return maze;
}

void draw_maze(Maze *maze) {
    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            printf("%d ", maze->map[x][y]);
        }
        printf("\n");
    }
}

void find_route(Maze *maze) {
    int x = maze->start_x;
    int y = maze->start_y;
    maze->map[x][y] = 2;

    while (x != maze->end_x || y != maze->end_y) {
        int dx = rand() % 4;
        int dy = rand() % 4;

        switch (dx) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }

        if (maze->map[x][y] == 0) {
            maze->map[x][y] = 2;
        }
    }

    maze->map[maze->end_x][maze->end_y] = 3;
}

int main() {
    Maze *maze = create_maze(MAX_MAZE_SIZE, MAX_MAZE_SIZE);
    find_route(maze);
    draw_maze(maze);

    return 0;
}