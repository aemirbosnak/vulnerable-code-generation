//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define BUFFER_SIZE (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} point;

void print_grid(int **grid) {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            printf(grid[i][j] ? "##" : " .");
        }
        printf("\n");
    }
}

int count_neighbors(int **grid, int x, int y) {
    int count = 0;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {-1, 0, 1, -1, 0, 1, 1, 1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && grid[ny][nx] != grid[y][x]) {
            ++count;
        }
    }

    return count;
}

void next_generation(int **grid) {
    int **next_grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; ++i) {
        next_grid[i] = calloc(WIDTH, sizeof(int));
        for (int j = 0; j < WIDTH; ++j) {
            next_grid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int neighbors = count_neighbors(grid, j, i);
            next_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
        }
    }

    int **temp = grid;
    grid = next_grid;
    next_grid = temp;
    free(next_grid);
}

int main(void) {
    srand(time(NULL));

    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; ++i) {
        grid[i] = calloc(WIDTH, sizeof(int));
    }

    int living_cells = RAND_MAX / 2;

    for (int i = 0; i < living_cells; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        grid[y][x] = 1;
    }

    puts("Initial state:");
    print_grid(grid);

    for (int i = 0; i < 5; ++i) {
        next_generation(grid);
        puts("\nSurprised?");
        print_grid(grid);
    }

    for (int i = 0; i < HEIGHT; ++i) {
        free(grid[i]);
    }
    free(grid);

    return EXIT_SUCCESS;
}