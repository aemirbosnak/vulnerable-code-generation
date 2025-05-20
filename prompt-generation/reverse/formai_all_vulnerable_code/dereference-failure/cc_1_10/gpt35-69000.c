//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_SHIPS 4

// Function to randomly place ships on the board
void placeShips(int board[][BOARD_SIZE], int ships) {
    int i, x, y;
    for (i = 0; i < ships; i++) {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
        if (board[x][y] == 0)
            board[x][y] = 1;
        else
            i--;
    }
}

// Function to display the board
void displayBoard(int board[][BOARD_SIZE]) {
    int i, j;
    printf(" ");
    for (i = 0; i < BOARD_SIZE; i++)
        printf(" %d", i);
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 0: printf(" ."); break;
                case 1: printf(" S"); break;
                case 2: printf(" X"); break;
                case 3: printf(" O"); break;
            }   
        }
        printf("\n");
    }
}

// Function to play the game
void playGame(int board[][BOARD_SIZE], int ships) {
    int i, x, y, guesses;
    guesses = 0;
    while (ships > 0) {
        printf("Guess a location (x, y): ");
        scanf("%d %d", &x, &y);
        if (board[x][y] == 1) {
            printf("Hit!\n");
            board[x][y] = 2;
            ships--;
        } else {
            printf("Miss!\n");
            board[x][y] = 3;
        }
        guesses++;
        displayBoard(board);
        printf("Ships remaining: %d\n", ships);
        printf("Guesses: %d\n", guesses);
    }
    printf("Game over! You won in %d guesses!\n", guesses);
}

// Main function
int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    placeShips(board, MAX_SHIPS);
    displayBoard(board);
    playGame(board, MAX_SHIPS);
    return 0;
}