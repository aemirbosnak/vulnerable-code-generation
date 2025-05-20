//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
// C Bingo simulator example program in a multiplayer style

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBERS 25
#define MAX_PLAYERS 4

// Function to generate random number between 1-25
int generateRandomNumber() {
    return rand() % MAX_NUMBERS + 1;
}

// Function to check if number is already called
bool isNumberCalled(int number, int *calledNumbers, int numCalled) {
    for(int i=0; i<numCalled; i++) {
        if(calledNumbers[i] == number) {
            return true;
        }
    }
    return false;
}

// Function to print bingo board
void printBoard(int **boards, int numPlayers) {
    printf("BINGO BOARD:\n");
    for(int i=0; i<numPlayers; i++) {
        printf("Player %d:\n", i+1);
        for(int j=0; j<ROWS; j++) {
            for(int k=0; k<COLS; k++) {
                printf("%d\t", boards[i][j*ROWS + k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to check if bingo is achieved for any player
bool checkBingo(int **boards, int numPlayers) {
    bool bingo = false;
    for(int i=0; i<numPlayers; i++) {
        // Check rows
        for(int j=0; j<ROWS; j++) {
            bool rowBingo = true;
            for(int k=0; k<COLS; k++) {
                if(boards[i][j*ROWS + k] != -1) {
                    rowBingo = false;
                    break;
                }
            }
            if(rowBingo) {
                printf("BINGO! Row %d for Player %d\n", j+1, i+1);
                bingo = true;
            }
        }
        // Check columns
        for(int j=0; j<COLS; j++) {
            bool colBingo = true;
            for(int k=0; k<ROWS; k++) {
                if(boards[i][k*ROWS + j] != -1) {
                    colBingo = false;
                    break;
                }
            }
            if(colBingo) {
                printf("BINGO! Column %d for Player %d\n", j+1, i+1);
                bingo = true;
            }
        }
        // Check diagonals
        bool diag1Bingo = true, diag2Bingo = true;
        for(int j=0; j<ROWS; j++) {
            if(boards[i][j*ROWS + j] != -1) {
                diag1Bingo = false;
            }
            if(boards[i][(j+1)*ROWS - (j+1)] != -1) {
                diag2Bingo = false;
            }
        }
        if(diag1Bingo) {
            printf("BINGO! Diagonal 1 for Player %d\n", i+1);
            bingo = true;
        }
        if(diag2Bingo) {
            printf("BINGO! Diagonal 2 for Player %d\n", i+1);
            bingo = true;
        }
    }
    return bingo;
}

int main() {
    srand(time(0));
    int numPlayers = 0;
    int *calledNumbers = malloc(sizeof(int) * MAX_NUMBERS);
    int **boards = malloc(MAX_PLAYERS * sizeof(int*));
    for(int i=0; i<MAX_PLAYERS; i++) {
        boards[i] = malloc(ROWS * COLS * sizeof(int));
    }
    printf("Enter number of players (1-4): ");
    scanf("%d", &numPlayers);
    while(numPlayers < 1 || numPlayers > 4) {
        printf("Invalid number. Enter number of players (1-4): ");
        scanf("%d", &numPlayers);
    }
    // Initialize boards
    for(int i=0; i<numPlayers; i++) {
        for(int j=0; j<ROWS*COLS; j++) {
            boards[i][j] = generateRandomNumber();
            while(isNumberCalled(boards[i][j], calledNumbers, j)) {
                boards[i][j] = generateRandomNumber();
            }
            calledNumbers[j] = boards[i][j];
        }
    }
    // Mark center as free
    for(int i=0; i<numPlayers; i++) {
        boards[i][12] = -1;
    }
    bool bingo = false;
    printBoard(boards, numPlayers);
    // Game loop
    while(!bingo) {
        int calledNumber = generateRandomNumber();
        while(isNumberCalled(calledNumber, calledNumbers, MAX_NUMBERS)) {
            calledNumber = generateRandomNumber();
        }
        printf("Number called: %d\n", calledNumber);
        calledNumbers[MAX_NUMBERS] = calledNumber;
        // Mark number on boards
        for(int i=0; i<numPlayers; i++) {
            for(int j=0; j<ROWS*COLS; j++) {
                if(boards[i][j] == calledNumber) {
                    boards[i][j] = -1;
                    break;
                }
            }
        }
        printBoard(boards, numPlayers);
        bingo = checkBingo(boards, numPlayers);
    }
    printf("BINGO!\n");
    free(calledNumbers);
    for(int i=0; i<MAX_PLAYERS; i++) {
        free(boards[i]);
    }
    free(boards);
    return 0;
}