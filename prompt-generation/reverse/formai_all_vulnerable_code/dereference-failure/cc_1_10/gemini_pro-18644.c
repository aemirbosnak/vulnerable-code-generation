//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

typedef struct {
    char **grid;
    int width;
    int height;
} Maze;

Maze *create_maze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->grid = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = '#';
        }
    }
    return maze;
}

void free_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void print_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(Maze *maze) {
    srand(time(NULL));

    // Create a stack of points to visit
    Point stack[WIDTH * HEIGHT];
    int stack_size = 0;

    // Start at the top left corner
    Point current = {0, 0};
    stack[stack_size++] = current;

    while (stack_size > 0) {
        // Pop the top point from the stack
        current = stack[--stack_size];

        // Mark the current point as visited
        maze->grid[current.y][current.x] = '.';

        // Get a list of all the unvisited neighbors of the current point
        Point neighbors[4];
        int num_neighbors = 0;
        if (current.x > 0 && maze->grid[current.y][current.x - 1] == '#') {
            neighbors[num_neighbors++] = (Point){current.x - 1, current.y};
        }
        if (current.y > 0 && maze->grid[current.y - 1][current.x] == '#') {
            neighbors[num_neighbors++] = (Point){current.x, current.y - 1};
        }
        if (current.x < maze->width - 1 && maze->grid[current.y][current.x + 1] == '#') {
            neighbors[num_neighbors++] = (Point){current.x + 1, current.y};
        }
        if (current.y < maze->height - 1 && maze->grid[current.y + 1][current.x] == '#') {
            neighbors[num_neighbors++] = (Point){current.x, current.y + 1};
        }

        // Randomly select a neighbor and push it onto the stack
        if (num_neighbors > 0) {
            int index = rand() % num_neighbors;
            stack[stack_size++] = neighbors[index];
        }
    }
}

int main() {
    Maze *maze = create_maze(WIDTH, HEIGHT);
    generate_maze(maze);
    print_maze(maze);
    free_maze(maze);
    return 0;
}