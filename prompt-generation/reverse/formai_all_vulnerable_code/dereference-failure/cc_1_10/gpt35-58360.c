//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATION_LIMIT 10

// Function to initialize the board with random cells
int** initBoard(){
    int** board = (int**)malloc(ROWS * sizeof(int*));

    for(int i = 0; i < ROWS; i++){
        board[i] = (int*)calloc(COLS, sizeof(int));
        for(int j = 0; j < COLS; j++){
            board[i][j] = rand() % 2;
        }
    }
    return board;
}

// Function to print the current state of the board
void printBoard(int** board, int generation){
    printf("Generation %d:\n", generation);
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(board[i][j] == 1){
                printf("*");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get the number of live neighbors for a given cell
int countLiveNeighbors(int** board, int row, int col){
    int count = 0;
    int i, j;

    // Check all 8 surrounding cells
    for(i = row - 1; i <= row + 1; i++){
        for(j = col - 1; j <= col + 1; j++){
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)){
                count += board[i][j];
            }
        }
    }
    return count;
}

// Function to update the board for the next generation
void updateBoard(int** board){
    int i, j;

    // Create a temporary board to update the cells
    int** tempBoard = (int**)malloc(ROWS * sizeof(int*));
    for(i = 0; i < ROWS; i++){
        tempBoard[i] = (int*)calloc(COLS, sizeof(int));
    }

    // Update each cell based on the number of live neighbors
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            int liveNeighbors = countLiveNeighbors(board, i, j);

            if(board[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)){
                tempBoard[i][j] = 1;
            }else if(board[i][j] == 0 && liveNeighbors == 3){
                tempBoard[i][j] = 1;
            }
        }
    }

    // Copy the updated board back to the original board
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = tempBoard[i][j];
        }
    }

    // Free the temporary board
    for(i = 0; i < ROWS; i++){
        free(tempBoard[i]);
    }
    free(tempBoard);
}

int main(){
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    int** board = initBoard();

    // Print the initial state of the board
    printBoard(board, 0);

    // Update the board for a certain number of generations
    for(int generation = 1; generation <= GENERATION_LIMIT; generation++){
        updateBoard(board);
        printBoard(board, generation);
    }

    // Free the board
    for(int i = 0; i < ROWS; i++){
        free(board[i]);
    }
    free(board);

    return 0;
}