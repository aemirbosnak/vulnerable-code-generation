//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define GRID_SIZE 4
#define MAX_ATTEMPTS 2
#define MAX_PAIRS (GRID_SIZE * GRID_SIZE) / 2

// Function prototypes
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void shufflePairs(char grid[GRID_SIZE][GRID_SIZE]);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int reveal[GRID_SIZE][GRID_SIZE]);
void getUserInput(int *row, int *col);
int isMatch(char grid[GRID_SIZE][GRID_SIZE], int firstRow, int firstCol, int secondRow, int secondCol);
int checkWin(int pairsFound, int totalPairs);
void playMemoryGame();

int main() {
    srand(time(NULL)); // Seed for randomness
    playMemoryGame();
    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    char symbols = 'A';
    for (int i = 0; i < MAX_PAIRS; i++) {
        grid[i / 2][i % 2] = symbols++;
        grid[i / 2][(GRID_SIZE - 1) - (i % 2)] = grid[i / 2][i % 2]; // Create pairs
    }
}

void shufflePairs(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int randomRow = rand() % GRID_SIZE;
            int randomCol = rand() % GRID_SIZE;

            // Swap positions
            char temp = grid[i][j];
            grid[i][j] = grid[randomRow][randomCol];
            grid[randomRow][randomCol] = temp;
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int reveal[GRID_SIZE][GRID_SIZE]) {
    printf("\nMemory Game Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if(reveal[i][j]) {
                printf(" %c ", grid[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

void getUserInput(int *row, int *col) {
    printf("Enter row and column (0 to %d): ", GRID_SIZE - 1);
    scanf("%d %d", row, col);
}

int isMatch(char grid[GRID_SIZE][GRID_SIZE], int firstRow, int firstCol, int secondRow, int secondCol) {
    return grid[firstRow][firstCol] == grid[secondRow][secondCol];
}

int checkWin(int pairsFound, int totalPairs) {
    return pairsFound == totalPairs;
}

void playMemoryGame() {
    char grid[GRID_SIZE][GRID_SIZE];
    int reveal[GRID_SIZE][GRID_SIZE] = {0};
    initializeGrid(grid);
    shufflePairs(grid);

    int pairsFound = 0, attempts = 0;

    while (!checkWin(pairsFound, MAX_PAIRS)) {
        displayGrid(grid, reveal);
        
        int firstRow, firstCol;
        printf("\nSelect the first card: ");
        getUserInput(&firstRow, &firstCol);
        reveal[firstRow][firstCol] = 1; // Reveal first card

        displayGrid(grid, reveal);

        int secondRow, secondCol;
        printf("\nSelect the second card: ");
        getUserInput(&secondRow, &secondCol);
        reveal[secondRow][secondCol] = 1; // Reveal second card

        displayGrid(grid, reveal);

        if (isMatch(grid, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            attempts++;
            sleep(2); // Give player time to see cards
            reveal[firstRow][firstCol] = 0; // Hide first card
            reveal[secondRow][secondCol] = 0; // Hide second card
        }

        if (attempts >= MAX_ATTEMPTS) {
            printf("Too many attempts! Game over.\n");
            break;
        }
    }

    if (checkWin(pairsFound, MAX_PAIRS)) {
        printf("Congratulations! You found all pairs!\n");
    }
}