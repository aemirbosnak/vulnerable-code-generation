//FormAI DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int size = 4;
    int **gameBoard = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        gameBoard[i] = (int *) malloc(size * sizeof(int));
    }
    
    int numValues = size * size / 2;
    int *values = (int *) malloc(numValues * sizeof(int));
    for (int i = 0; i < numValues; i++) {
        values[i] = i;
    }
    
    int numTiles = size * size;
    int *tiles = (int *) malloc(numTiles * sizeof(int));
    for (int i = 0; i < numTiles; i++) {
        tiles[i] = i;
    }
    
    int numMatches = 0;
    srand(time(NULL));
    while (numMatches < numValues) {
        // Randomly select a value
        int valueIndex = rand() % numValues;
        int value = values[valueIndex];
        
        // Place value on two random tiles
        int matchCount = 0;
        while (matchCount < 2) {
            int tileIndex = rand() % numTiles;
            if (tiles[tileIndex] != -1) {
                int row = tileIndex / size;
                int col = tileIndex % size;
                gameBoard[row][col] = value;
                tiles[tileIndex] = -1;
                matchCount++;
            }
        }
        
        numMatches++;
    }
    
    // Main game loop
    int moves = 0;
    int numRevealed = 0;
    int prevRow = -1;
    int prevCol = -1;
    int gameComplete = 0;
    while (!gameComplete) {
        // Display board
        printf("\nMoves: %d\n", moves);
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (row == prevRow && col == prevCol) {
                    printf("%d ", gameBoard[row][col]);
                } else if (gameBoard[row][col] == -1) {
                    printf(". ");
                } else {
                    printf("? ");
                }
            }
            printf("\n");
        }
        
        // Get input from user
        printf("\nEnter row and column to reveal: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 1 || row > size || col < 1 || col > size) {
            printf("Invalid input. Row and column must be in range 1-%d.\n", size);
            continue;
        }
        
        // Check if revealed tile matches previous tile
        row--;
        col--;
        if (gameBoard[row][col] != -1) {
            printf("Tile already revealed. Please choose a different tile.\n");
            continue;
        }
        
        gameBoard[row][col] = prevRow == -1 ? -2 : gameBoard[prevRow][prevCol];
        prevRow = prevRow == -1 ? row : -1;
        prevCol = prevCol == -1 ? col : -1;
        
        // Check if two tiles have been revealed
        numRevealed++;
        if (numRevealed == 2) {
            moves++;
            if (gameBoard[prevRow][prevCol] == gameBoard[row][col]) {
                printf("Match found!\n");
                gameBoard[prevRow][prevCol] = -1;
                gameBoard[row][col] = -1;
                numRevealed = 0;
                numMatches--;
            } else {
                printf("No match found!\n");
                gameBoard[prevRow][prevCol] = -1;
                gameBoard[row][col] = -1;
                numRevealed = 0;
            }
        }
        
        // Check if game is complete
        if (numMatches == 0) {
            printf("\nGame complete in %d moves!\n", moves);
            gameComplete = 1;
        }
    }
    
    // Free memory
    for (int i = 0; i < size; i++) {
        free(gameBoard[i]);
    }
    free(gameBoard);
    free(values);
    free(tiles);
    
    return 0;
}