//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALIVE 'O'
#define DEAD ' '

typedef struct {
    int rows;
    int cols;
    char **grid;
} GameOfLife;

void initializeGrid(GameOfLife *game);
void freeGrid(GameOfLife *game);
void displayGrid(GameOfLife *game);
void randomizeGrid(GameOfLife *game);
void updateGrid(GameOfLife *game);
int countNeighbors(GameOfLife *game, int x, int y);

int main() {
    GameOfLife game;
    
    // Ask for grid dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &game.rows);
    printf("Enter the number of columns: ");
    scanf("%d", &game.cols);

    // Initialize the game grid
    initializeGrid(&game);
    
    // Randomly populate the grid
    randomizeGrid(&game);

    // Game loop
    while (1) {
        printf("\033[H\033[J"); // Clear console for new frame
        displayGrid(&game);
        updateGrid(&game);
        usleep(500000); // Sleep for 500ms
    }

    freeGrid(&game);
    return 0;
}

void initializeGrid(GameOfLife *game) {
    game->grid = malloc(game->rows * sizeof(char *));
    for (int i = 0; i < game->rows; i++) {
        game->grid[i] = malloc(game->cols * sizeof(char));
    }
}

void freeGrid(GameOfLife *game) {
    for (int i = 0; i < game->rows; i++) {
        free(game->grid[i]);
    }
    free(game->grid);
}

void displayGrid(GameOfLife *game) {
    for (int r = 0; r < game->rows; r++) {
        for (int c = 0; c < game->cols; c++) {
            printf("%c ", game->grid[r][c]);
        }
        printf("\n");
    }
}

void randomizeGrid(GameOfLife *game) {
    srand(time(NULL));
    for (int r = 0; r < game->rows; r++) {
        for (int c = 0; c < game->cols; c++) {
            game->grid[r][c] = (rand() % 2) ? ALIVE : DEAD;
        }
    }
}

void updateGrid(GameOfLife *game) {
    char **newGrid = malloc(game->rows * sizeof(char *));
    for (int i = 0; i < game->rows; i++) {
        newGrid[i] = malloc(game->cols * sizeof(char));
    }

    for (int r = 0; r < game->rows; r++) {
        for (int c = 0; c < game->cols; c++) {
            int neighbors = countNeighbors(game, r, c);
            if (game->grid[r][c] == ALIVE) {
                newGrid[r][c] = (neighbors < 2 || neighbors > 3) ? DEAD : ALIVE;
            } else {
                newGrid[r][c] = (neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }

    for (int i = 0; i < game->rows; i++) {
        free(game->grid[i]);
    }
    free(game->grid);

    game->grid = newGrid;
}

int countNeighbors(GameOfLife *game, int x, int y) {
    int count = 0;
    for (int r = x - 1; r <= x + 1; r++) {
        for (int c = y - 1; c <= y + 1; c++) {
            if (r < 0 || r >= game->rows || c < 0 || c >= game->cols || (r == x && c == y)) {
                continue;
            }
            if (game->grid[r][c] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}