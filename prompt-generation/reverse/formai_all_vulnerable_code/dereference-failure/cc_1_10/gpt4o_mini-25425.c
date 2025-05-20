//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4
#define MAX_TURNS 20

// Function prototyping
void initializeGrid(int grid[GRID_SIZE][GRID_SIZE]);
void shuffleGrid(int grid[GRID_SIZE][GRID_SIZE]);
void printGrid(const int grid[GRID_SIZE][GRID_SIZE], const bool revealed[GRID_SIZE][GRID_SIZE]);
bool revealCell(int grid[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE], int row, int col);
bool checkMatch(int firstRow, int firstCol, int secondRow, int secondCol, int grid[GRID_SIZE][GRID_SIZE]);
bool isGameWon(const bool revealed[GRID_SIZE][GRID_SIZE]);

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    bool revealed[GRID_SIZE][GRID_SIZE] = {false};
    int turnCount = 0;
    int firstRow, firstCol, secondRow, secondCol;

    srand(time(NULL));
    initializeGrid(grid);
    shuffleGrid(grid);

    while(turnCount < MAX_TURNS && !isGameWon(revealed)) {
        printGrid(grid, revealed);

        // First selection
        printf("Select first cell (row col): ");
        scanf("%d %d", &firstRow, &firstCol);

        if (!revealCell(grid, revealed, firstRow, firstCol)) {
            printf("Invalid selection! Try again.\n");
            continue;
        }
        printGrid(grid, revealed);

        // Second selection
        printf("Select second cell (row col): ");
        scanf("%d %d", &secondRow, &secondCol);

        if (!revealCell(grid, revealed, secondRow, secondCol)) {
            printf("Invalid selection! Try again.\n");
            revealed[firstRow][firstCol] = false; // Hide the first selection again
            continue;
        }
        printGrid(grid, revealed);

        // Check for a match
        if (checkMatch(firstRow, firstCol, secondRow, secondCol, grid)) {
            printf("Match found!\n");
        } else {
            printf("No match. Try again.\n");
            revealed[firstRow][firstCol] = false; // Hide the first selection again
            revealed[secondRow][secondCol] = false; // Hide the second selection again
        }

        turnCount++;
    }

    if (isGameWon(revealed)) {
        printf("Congratulations! You've matched all pairs!\n");
    } else {
        printf("Game over! You've reached the maximum number of turns.\n");
    }

    return 0;
}

void initializeGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    int numbers[GRID_SIZE * GRID_SIZE / 2];
    for (int i = 0; i < GRID_SIZE * GRID_SIZE / 2; i++) {
        numbers[i] = i + 1; // Fill with pairs
    }

    for (int i = 0; i < GRID_SIZE * GRID_SIZE / 2; i++) {
        grid[i / GRID_SIZE][i % GRID_SIZE] = numbers[i];
        grid[(GRID_SIZE * GRID_SIZE / 2) + i / GRID_SIZE][i % GRID_SIZE] = numbers[i];
    }
}

void shuffleGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int randIndex = rand() % (GRID_SIZE * GRID_SIZE);
        int temp = grid[i / GRID_SIZE][i % GRID_SIZE];
        grid[i / GRID_SIZE][i % GRID_SIZE] = grid[randIndex / GRID_SIZE][randIndex % GRID_SIZE];
        grid[randIndex / GRID_SIZE][randIndex % GRID_SIZE] = temp;
    }
}

void printGrid(const int grid[GRID_SIZE][GRID_SIZE], const bool revealed[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", grid[i][j]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool revealCell(int grid[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE || revealed[row][col]) {
        return false; // Invalid selection
    }
    revealed[row][col] = true; // Reveal the cell
    return true;
}

bool checkMatch(int firstRow, int firstCol, int secondRow, int secondCol, int grid[GRID_SIZE][GRID_SIZE]) {
    return grid[firstRow][firstCol] == grid[secondRow][secondCol];
}

bool isGameWon(const bool revealed[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!revealed[i][j]) {
                return false; // A cell is still hidden
            }
        }
    }
    return true; // All cells are revealed
}