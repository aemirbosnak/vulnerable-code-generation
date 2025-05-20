//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH (10)
#define HEIGHT (10)

typedef struct {
    int x;
    int y;
} position_t;

bool is_valid_position(int grid[WIDTH][HEIGHT], position_t pos, int value) {
    if (pos.x < 0 || pos.x >= WIDTH || pos.y < 0 || pos.y >= HEIGHT) {
        return false;
    }
    if (grid[pos.x][pos.y] != 0) {
        return false;
    }
    grid[pos.x][pos.y] = value;
    return true;
}

void print_grid(int grid[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

void generate_spiral(int grid[WIDTH][HEIGHT], int n) {
    position_t current_position = {.x = 0, .y = 0};
    int value = 1;
    bool moving_right = true;

    while (value <= n) {
        if (moving_right) {
            if (!is_valid_position(grid, current_position, value)) {
                printf("Invalid position at (%d, %d)\n", current_position.x, current_position.y);
                exit(EXIT_FAILURE);
            }
            current_position.x++;
            if (current_position.x == WIDTH) {
                moving_right = false;
            }
        } else {
            if (!is_valid_position(grid, current_position, value)) {
                printf("Invalid position at (%d, %d)\n", current_position.x, current_position.y);
                exit(EXIT_FAILURE);
            }
            current_position.y++;
            if (current_position.y == HEIGHT) {
                moving_right = true;
            }
        }
        value++;
    }

    print_grid(grid);
}

int main(int argc, char *argv[]) {
    int n = argc > 1 ? atoi(argv[1]) : 100;
    int grid[WIDTH][HEIGHT];
    memset(grid, 0, sizeof(grid));
    generate_spiral(grid, n);
    return EXIT_SUCCESS;
}