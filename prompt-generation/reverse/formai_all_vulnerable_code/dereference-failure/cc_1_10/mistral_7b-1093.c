//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define WIDTH 41
#define HEIGHT 21

typedef struct {
    int x, y;
} point;

bool is_valid(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

void print_maze(bool** maze) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x]) printf("  ##");
            else printf(" %c", is_valid(x - 1, y) ? '#' : ' ');
        }
        printf("\n");
    }
}

void carve_passage(bool** maze, int x, int y) {
    maze[y][x] = true;
    int dx[4] = {-1, 1, 1, -1};
    int dy[4] = {-1, -1, 1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_valid(nx, ny) && !maze[ny][nx]) {
            carve_passage(maze, nx, ny);
            maze[y][x] = false;
            maze[ny][nx] = false;
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    bool** maze = calloc(HEIGHT, sizeof(bool*));

    for (int y = 0; y < HEIGHT; y++) maze[y] = calloc(WIDTH, sizeof(bool));

    point start = {rand() % WIDTH, rand() % HEIGHT};
    maze[start.y][start.x] = true;

    carve_passage(maze, start.x, start.y);
    print_maze(maze);

    for (int y = 0; y < HEIGHT; y++) free(maze[y]);
    free(maze);

    return 0;
}

// Generate a procedurally random maze using depth-first search algorithm.
// The maze is represented as a 2D boolean array where true denotes a passable cell.
// The entrance is randomly placed within the maze.
// Print the maze to the console.
// Free the memory allocated for the maze.