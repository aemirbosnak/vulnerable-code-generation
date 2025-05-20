//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for table size and number of players
#define ROWS 5
#define COLS 5
#define PLAYERS 2

// function prototypes
void initTable(char table[ROWS][COLS]);
void updateTable(char table[ROWS][COLS], int player, int row, int col);
void printTable(char table[ROWS][COLS]);
int getRand();

// main function
int main() {
    // variable declaration
    char table[ROWS][COLS];
    int currentPlayer = 1;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    
    // initialize random seed
    srand(time(NULL));
    
    // initialize table
    initTable(table);
    
    // game loop
    while (1) {
        // print current table
        printf("Current Table:\n");
        printTable(table);
        
        // get player input
        int row, col;
        printf("Player %d's turn\n", currentPlayer);
        printf("Enter row and column number (0-4): ");
        scanf("%d %d", &row, &col);
        
        // update table
        updateTable(table, currentPlayer, row, col);
        
        // check for game over
        int gameOver = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (table[i][j] == '.') {
                    gameOver = 1;
                }
            }
        }
        
        // if game over, break game loop
        if (gameOver == 0) {
            break;
        }
        
        // switch to next player
        if (currentPlayer == PLAYERS) {
            currentPlayer = 1;
        } else {
            currentPlayer++;
        }
    }
    
    // calculate scores
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (table[i][j] == 'X') {
                playerOneScore++;
            } else if (table[i][j] == 'O') {
                playerTwoScore++;
            }
        }
    }
    
    // print final scores
    printf("Player 1 Score: %d\n", playerOneScore);
    printf("Player 2 Score: %d\n", playerTwoScore);
    
    return 0;
}

// function definition for initializing table
void initTable(char table[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = '.';
        }
    }
}

// function definition for updating table
void updateTable(char table[ROWS][COLS], int player, int row, int col) {
    if (player == 1) {
        table[row][col] = 'X';
    } else {
        table[row][col] = 'O';
    }
}

// function definition for printing table
void printTable(char table[ROWS][COLS]) {
    printf("\n  0 1 2 3 4\n");
    printf("  ---------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d|", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", table[i][j]);
        }
        printf("|\n");
    }
    printf("  ---------\n");
}

// function definition for generating random number
int getRand() {
    int num = rand() % 2;
    if (num == 0) {
        return 1;
    } else {
        return 2;
    }
}