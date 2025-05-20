//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define ALIVE 'O'
#define DEAD  '.'
#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    char **grid;
} GameOfLife;

void initializeGame(GameOfLife *game);
void freeGame(GameOfLife *game);
void printGrid(GameOfLife *game);
void updateGame(GameOfLife *game);
int countNeighbors(GameOfLife *game, int row, int col);
void clearBuffer();

int main() {
    GameOfLife game;
    initializeGame(&game);
    
    char choice;
    while (true) {
        printGrid(&game);
        updateGame(&game);
        printf("Continue to next generation? (y/n): ");
        choice = getchar();
        clearBuffer();
        
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    
    freeGame(&game);
    return 0;
}

void initializeGame(GameOfLife *game) {
    game->rows = 10;     // Set rows
    game->cols = 10;     // Set cols
    game->grid = malloc(game->rows * sizeof(char *));
    for (int i = 0; i < game->rows; i++) {
        game->grid[i] = malloc(game->cols * sizeof(char));
        for (int j = 0; j < game->cols; j++) {
            game->grid[i][j] = (rand() % 2) ? ALIVE : DEAD;  // Random initialization
        }
    }
}

void freeGame(GameOfLife *game) {
    for (int i = 0; i < game->rows; i++) {
        free(game->grid[i]);
    }
    free(game->grid);
}

void printGrid(GameOfLife *game) {
    system("clear");  // Clear the console
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }
}

void updateGame(GameOfLife *game) {
    char **newGrid = malloc(game->rows * sizeof(char *));
    for (int i = 0; i < game->rows; i++) {
        newGrid[i] = malloc(game->cols * sizeof(char));
        for (int j = 0; j < game->cols; j++) {
            int neighbors = countNeighbors(game, i, j);
            if (game->grid[i][j] == ALIVE) {
                newGrid[i][j] = (neighbors < 2 || neighbors > 3) ? DEAD : ALIVE;
            } else {
                newGrid[i][j] = (neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
    
    for (int i = 0; i < game->rows; i++) {
        free(game->grid[i]);
        game->grid[i] = newGrid[i];
    }
    free(newGrid);
}

int countNeighbors(GameOfLife *game, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < game->rows && newCol >= 0 && newCol < game->cols) {
                if (game->grid[newRow][newCol] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}