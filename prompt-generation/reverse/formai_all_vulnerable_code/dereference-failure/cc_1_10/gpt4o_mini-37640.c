//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20
#define ALIVE 'O'
#define DEAD '.'

typedef struct {
    char **grid;
} GameOfLife;

void initialize_grid(GameOfLife *game) {
    game->grid = malloc(HEIGHT * sizeof(char *));
    for (int i = 0; i < HEIGHT; i++) {
        game->grid[i] = malloc(WIDTH * sizeof(char));
        for (int j = 0; j < WIDTH; j++) {
            game->grid[i][j] = DEAD; // Initialize to dead cells
        }
    }
}

void free_grid(GameOfLife *game) {
    for (int i = 0; i < HEIGHT; i++) {
        free(game->grid[i]);
    }
    free(game->grid);
}

void print_grid(GameOfLife *game) {
    system("clear"); // Clear the console for better visualization
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }
}

int count_alive_neighbors(GameOfLife *game, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int neighbor_x = (x + i + HEIGHT) % HEIGHT;
            int neighbor_y = (y + j + WIDTH) % WIDTH;
            if (game->grid[neighbor_x][neighbor_y] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void update_grid(GameOfLife *game) {
    char **new_grid = malloc(HEIGHT * sizeof(char *));
    for (int i = 0; i < HEIGHT; i++) {
        new_grid[i] = malloc(WIDTH * sizeof(char));
        for (int j = 0; j < WIDTH; j++) {
            int alive_neighbors = count_alive_neighbors(game, i, j);
            if (game->grid[i][j] == ALIVE) {
                new_grid[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                new_grid[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
    
    for (int i = 0; i < HEIGHT; i++) {
        free(game->grid[i]);
        game->grid[i] = new_grid[i];
    }
    free(new_grid);
}

void seed_initial_pattern(GameOfLife *game) {
    // Sample pattern: Glider
    game->grid[1][2] = ALIVE;
    game->grid[2][3] = ALIVE;
    game->grid[3][1] = ALIVE;
    game->grid[3][2] = ALIVE;
    game->grid[3][3] = ALIVE;
}

int main() {
    GameOfLife game;
    initialize_grid(&game);
    seed_initial_pattern(&game);
    
    while (1) {
        print_grid(&game);
        update_grid(&game);
        usleep(200000); // Sleep for 200 milliseconds
    }
    
    free_grid(&game);
    return 0;
}