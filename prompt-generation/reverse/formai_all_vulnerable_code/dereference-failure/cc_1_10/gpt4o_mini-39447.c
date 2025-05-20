//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // 4x4 grid
#define NUM_PAIRS (SIZE * SIZE) / 2

typedef struct {
    int value;
    int isVisible;
} Cell;

void initializeGrid(Cell grid[SIZE][SIZE]);
void shuffleValues(int values[NUM_PAIRS]);
void printGrid(Cell grid[SIZE][SIZE]);
void revealCell(Cell grid[SIZE][SIZE], int row, int col);
int checkForMatch(Cell grid[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol);
int isGridFull(Cell grid[SIZE][SIZE]);
void playGame();

int main() {
    srand(time(0));
    playGame();
    return 0;
}

void initializeGrid(Cell grid[SIZE][SIZE]) {
    int values[NUM_PAIRS];
    
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i + 1; // Fill values from 1 to NUM_PAIRS
    }
    
    shuffleValues(values);
    
    for (int i = 0, vIndex = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j].value = values[vIndex / 2]; // Each value appears twice
            grid[i][j].isVisible = 0; // Initially, cells are not revealed
            vIndex++;
        }
    }
}

void shuffleValues(int values[NUM_PAIRS]) {
    for (int i = NUM_PAIRS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }
}

void printGrid(Cell grid[SIZE][SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isVisible) {
                printf("[%d] ", grid[i][j].value);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

void revealCell(Cell grid[SIZE][SIZE], int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        grid[row][col].isVisible = 1; // Mark cell as visible
    }
}

int checkForMatch(Cell grid[SIZE][SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    if (grid[firstRow][firstCol].value == grid[secondRow][secondCol].value) {
        return 1; // Match found
    }
    return 0; // No match
}

int isGridFull(Cell grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!grid[i][j].isVisible) {
                return 0; // There are still hidden cells
            }
        }
    }
    return 1; // All cells are revealed
}

void playGame() {
    Cell grid[SIZE][SIZE];
    initializeGrid(grid);
    int matchesFound = 0;
    int firstRow, firstCol, secondRow, secondCol;

    while (matchesFound < NUM_PAIRS) {
        printGrid(grid);
        printf("Select first cell (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        revealCell(grid, firstRow, firstCol);
        printGrid(grid);

        printf("Select second cell (row col): ");
        scanf("%d %d", &secondRow, &secondCol);
        revealCell(grid, secondRow, secondCol);
        printGrid(grid);

        if (checkForMatch(grid, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
            matchesFound++;
        } else {
            printf("Not a match, try again.\n");
            grid[firstRow][firstCol].isVisible = 0; // Hide first cell again
            grid[secondRow][secondCol].isVisible = 0; // Hide second cell again
        }

        if (isGridFull(grid)) {
            printf("Congratulations! You've found all the matches!\n");
        }
    }
}