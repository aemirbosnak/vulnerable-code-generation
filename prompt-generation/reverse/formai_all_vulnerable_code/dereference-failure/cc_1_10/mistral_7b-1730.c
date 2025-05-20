//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15

typedef struct {
    int x, y;
} point;

void maze_generate(int **maze, int x, int y, int visited[][WIDTH]);
void print_maze(int **maze);

int main() {
    srand(time(NULL));

    int **maze = malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    int visited[WIDTH][WIDTH] = {{0}};

    maze_generate(maze, 0, 0, visited);

    print_maze(maze);

    for (int i = 0; i < WIDTH; i++)
        free(maze[i]);
    free(maze);

    return 0;
}

void maze_generate(int **maze, int x, int y, int visited[][WIDTH]) {
    visited[x][y] = 1;

    point directions[] = {
        {x - 2, y},
        {x + 2, y},
        {x, y - 2},
        {x, y + 2}
    };

    int random_index = rand() % 4;
    point direction = directions[random_index];

    if (direction.x >= 0 && direction.x < WIDTH &&
        direction.y >= 0 && direction.y < HEIGHT &&
        maze[direction.x][direction.y] == 0) {

        maze[x][y] = 1;
        maze[direction.x][direction.y] = 1;

        maze_generate(maze, direction.x, direction.y, visited);
    } else {
        random_index = (random_index + 1) % 4;
        direction = directions[random_index];
        maze_generate(maze, x, y, visited);
    }
}

void print_maze(int **maze) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}