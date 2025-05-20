//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#define ROWS 4
#define COLS 6

int score = 0;

void printBoard(char board[ROWS][COLS]) {
    printf("\n\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) { 
            printf("%c", board[i][j]);
        }
        printf("\n"); 
    }
    printf("\n\n"); 
}

bool checkWin(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 'O') {
                return false;
            }
        }
    }
    printf("\nCongratulations! You won with a score of %d.\n", score);
    return true;
}

void fire(char board[ROWS][COLS], int row, int col) {
    if(board[row][col] == 'O') {
        board[row][col] = 'X';
        score += 1;
        printf("\nHit! Score: %d\n", score);
    } else if(board[row][col] == '-') {
        printf("\nYou already fired there.\n");
    } else {
        board[row][col] = '-';
        printf("\nMissed!\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
  
    char board[ROWS][COLS];
    int invader_row = rand() % ROWS;
    int invader_col = rand() % COLS;
  
    // initialize board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = 'O';
        }
    }
    
    printBoard(board);
    
    while(true) {
        int fire_row;
        int fire_col;
        
        printf("\nEnter the row to fire at: ");
        scanf("%d", &fire_row);
        
        printf("\nEnter the column to fire at: ");
        scanf("%d", &fire_col);
        
        fire(board, fire_row, fire_col);
        
        invader_row += 1;
        invader_row %= ROWS;
        
        board[invader_row][invader_col] = 'O';
        board[(invader_row - 1 + ROWS) % ROWS][invader_col] = '-'; 
        
        printBoard(board);
        
        if(checkWin(board)) {
            break;
        }
        
        sleep(1); // simulate invader movement delay 
    }
    
    return 0;
}