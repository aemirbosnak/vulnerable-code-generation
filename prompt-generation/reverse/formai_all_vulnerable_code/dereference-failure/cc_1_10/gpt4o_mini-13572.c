//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Game Configuration
int gridSize = 5; // Default size of the grid
int numTreasures = 3; // Default number of treasures
int numTraps = 2; // Default number of traps

// Function to initialize the grid with treasures and traps
void initializeGrid(char grid[MAX_SIZE][MAX_SIZE]) {
    // Initialize the grid with empty spaces
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = '.';
        }
    }
    
    // Place treasures in random locations
    for (int t = 0; t < numTreasures; t++) {
        int x, y;
        do {
            x = rand() % gridSize;
            y = rand() % gridSize;
        } while (grid[x][y] != '.'); // Ensure no overlap
        grid[x][y] = 'T'; // 'T' for Treasure
    }

    // Place traps in random locations
    for (int t = 0; t < numTraps; t++) {
        int x, y;
        do {
            x = rand() % gridSize;
            y = rand() % gridSize;
        } while (grid[x][y] != '.'); // Ensure no overlap
        grid[x][y] = 'X'; // 'X' for Trap
    }
}

// Function to print the grid
void printGrid(char grid[MAX_SIZE][MAX_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check the player's move
int checkMove(char grid[MAX_SIZE][MAX_SIZE], int x, int y) {
    if (grid[x][y] == 'T') {
        printf("Congratulations! You found a treasure!\n");
        grid[x][y] = '.'; // Remove the treasure
        return 1; // Treasure found
    } else if (grid[x][y] == 'X') {
        printf("Oh no! You fell into a trap!\n");
        return -1; // Trap hit
    } else {
        printf("Nothing here. Keep searching!\n");
        return 0; // No treasure found
    }
}

// Main game loop
void playGame() {
    char grid[MAX_SIZE][MAX_SIZE];
    int treasuresFound = 0;
    int trapsHit = 0;
    int gameStatus = 1; // 1 for ongoing, 0 for quit

    // Initialize random seed
    srand(time(NULL));

    // Initialize the game grid
    initializeGrid(grid);

    while (gameStatus) {
        printGrid(grid);
        int x, y;

        printf("Enter your move coordinates (row and column [0-%d] separated by a space), or -1 to quit: ", gridSize - 1);
        scanf("%d %d", &x, &y);

        if (x == -1 || y == -1) {
            gameStatus = 0; // Quit the game
            printf("Thanks for playing! You found %d treasures and hit %d traps.\n", treasuresFound, trapsHit);
            break;
        }

        if (x < 0 || x >= gridSize || y < 0 || y >= gridSize) {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }

        int result = checkMove(grid, x, y);
        
        if (result == 1) {
            treasuresFound++;
        } else if (result == -1) {
            trapsHit++;
        }
        
        if (treasuresFound == numTreasures) {
            printf("You found all the treasures! You win!\n");
            gameStatus = 0; // End game
        }

        if (trapsHit >= numTraps) {
            printf("Too many traps hit! Game over.\n");
            gameStatus = 0; // End game
        }
    }
}

int main() {
    printf("Welcome to Treasure Hunt!\n");
    printf("You can configure the game settings:\n");

    printf("Enter grid size (max %d): ", MAX_SIZE);
    scanf("%d", &gridSize);
    gridSize = gridSize > MAX_SIZE ? MAX_SIZE : gridSize;
    
    printf("Enter number of treasures: ");
    scanf("%d", &numTreasures);

    printf("Enter number of traps: ");
    scanf("%d", &numTraps);

    playGame();

    return 0;
}