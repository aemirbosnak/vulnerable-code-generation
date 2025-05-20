//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define TREASURE 'T'
#define EMPTY '.'

void initializeGame(char grid[MAX_SIZE][MAX_SIZE], int size, int numTreasures);
void printGrid(char grid[MAX_SIZE][MAX_SIZE], int size);
void placeTreasures(char grid[MAX_SIZE][MAX_SIZE], int size, int numTreasures);
int isTreasure(char grid[MAX_SIZE][MAX_SIZE], int x, int y);
int checkWin(int foundTreasures, int numTreasures);

int main() {
    int size = 5; // Default grid size
    int numTreasures = 3; // Default number of treasures

    // User input for grid size and number of treasures
    printf("Enter grid size (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if(size > MAX_SIZE) {
        printf("Size exceeds maximum limit. Setting to %d.\n", MAX_SIZE);
        size = MAX_SIZE;
    }
    
    printf("Enter number of treasures (max %d): ", size * size);
    scanf("%d", &numTreasures);
    if(numTreasures > size * size) {
        printf("Number of treasures exceeds grid capacity. Setting to %d.\n", size * size);
        numTreasures = size * size;
    }

    char grid[MAX_SIZE][MAX_SIZE];
    initializeGame(grid, size, numTreasures);

    int foundTreasures = 0;
    int x, y;

    while (foundTreasures < numTreasures) {
        printGrid(grid, size);
        printf("Enter coordinates to search for treasure (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= size || y < 0 || y >= size) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        if (isTreasure(grid, x, y)) {
            printf("Congratulations! You found a treasure at (%d, %d)!\n", x, y);
            foundTreasures++;
            grid[x][y] = EMPTY; // Mark the treasure as found
        } else {
            printf("No treasure at (%d, %d). Try again!\n", x, y);
        }

        if (checkWin(foundTreasures, numTreasures)) {
            printf("You've found all the treasures! You win!\n");
            break;
        }
    }

    return 0;
}

void initializeGame(char grid[MAX_SIZE][MAX_SIZE], int size, int numTreasures) {
    // Fill grid with empty spaces
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = EMPTY;

    // Place treasures in the grid
    placeTreasures(grid, size, numTreasures);
}

void printGrid(char grid[MAX_SIZE][MAX_SIZE], int size) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void placeTreasures(char grid[MAX_SIZE][MAX_SIZE], int size, int numTreasures) {
    srand(time(0)); // Seed random number generator

    for (int i = 0; i < numTreasures; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while (grid[x][y] == TREASURE); // Ensure we don't place a treasure in the same spot

        grid[x][y] = TREASURE; // Place treasure
    }
}

int isTreasure(char grid[MAX_SIZE][MAX_SIZE], int x, int y) {
    return grid[x][y] == TREASURE;
}

int checkWin(int foundTreasures, int numTreasures) {
    return foundTreasures == numTreasures;
}