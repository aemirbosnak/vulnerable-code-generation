//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100

typedef struct node {
    int x;
    int y;
    int g;
    int h;
} node_t;

bool is_valid_cell(int x, int y, int height, int width) {
    // Check if the cell is within the grid and not blocked
    return x >= 0 && y >= 0 && x < width && y < height;
}

void print_grid(int height, int width) {
    // Print the grid to the console
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (is_valid_cell(x, y, height, width)) {
                printf("*");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int height = MAX_HEIGHT;
    int width = MAX_WIDTH;

    // Create a grid of nodes
    node_t *grid = (node_t *)malloc(height * width * sizeof(node_t));
    for (int i = 0; i < height * width; i++) {
        grid[i].x = -1;
        grid[i].y = -1;
        grid[i].g = 0;
        grid[i].h = 0;
    }

    // Set up the start and end nodes
    grid[0].x = 0;
    grid[0].y = 0;
    grid[0].g = 0;
    grid[0].h = 10;

    grid[height - 1].x = width - 1;
    grid[height - 1].y = width - 1;
    grid[height - 1].g = 0;
    grid[height - 1].h = 10;

    // Perform the A* search
    node_t current = grid[0];
    node_t previous = grid[0];
    while (true) {
        if (current.x == height - 1 && current.y == width - 1) {
            break;
        }
        int min_g = 100000;
        int min_index = -1;
        for (int i = 0; i < height * width; i++) {
            if (grid[i].x == current.x && grid[i].y == current.y) {
                continue;
            }
            int g_diff = grid[i].g - current.g;
            if (g_diff < 0) {
                continue;
            }
            int h_diff = grid[i].h - current.h;
            int f_diff = g_diff + h_diff;
            if (f_diff < min_g) {
                min_g = f_diff;
                min_index = i;
            }
        }
        if (min_index == -1) {
            break;
        }
        current = grid[min_index];
        previous = grid[current.x * width + current.y];
        grid[current.x * width + current.y].g = grid[previous.x * width + previous.y].g + 1;
        grid[current.x * width + current.y].h = grid[previous.x * width + previous.y].h + 1;
    }

    // Print the path
    print_grid(height, width);
    printf("Path length: %d\n", grid[height - 1].g);

    free(grid);

    return 0;
}