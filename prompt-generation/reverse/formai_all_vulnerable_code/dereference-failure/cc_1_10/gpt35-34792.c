//FormAI DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to print the board
void printBoard(int** board, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == 1){
                printf("X ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors of a cell
int countNeighbors(int** board, int rows, int cols, int i, int j){
    int count = 0;
    for(int a=-1; a<=1; a++){
        for(int b=-1; b<=1; b++){
            int x = i+a;
            int y = j+b;
            if(x>=0 && y>=0 && x<rows && y<cols && !(a==0 && b==0)){
                count += board[x][y];
            }
        }
    }
    return count;
}

// function to simulate one generation using the rules of the game
void simulateGeneration(int** board, int rows, int cols){
    int** newBoard = (int**)malloc(sizeof(int*) * rows);
    for(int i=0; i<rows; i++){
        newBoard[i] = (int*)malloc(sizeof(int) * cols);
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int neighbors = countNeighbors(board, rows, cols, i, j);
            if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                newBoard[i][j] = 0;
            }
            else if(board[i][j] == 0 && neighbors == 3){
                newBoard[i][j] = 1;
            }
            else{
                newBoard[i][j] = board[i][j];
            }
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            board[i][j] = newBoard[i][j];
        }
    }
}

int main(){
    srand(time(NULL));
    int rows = 20;
    int cols = 40;
    int** board = (int**)malloc(sizeof(int*) * rows);
    for(int i=0; i<rows; i++){
        board[i] = (int*)malloc(sizeof(int) * cols);
        for(int j=0; j<cols; j++){
            board[i][j] = rand() % 2;
        }
    }
    int generations = 100;
    for(int i=0; i<generations; i++){
        system("clear");
        printf("Generation %d:\n", i+1);
        printBoard(board, rows, cols);
        simulateGeneration(board, rows, cols);
        usleep(500000);
    }
    return 0;
}