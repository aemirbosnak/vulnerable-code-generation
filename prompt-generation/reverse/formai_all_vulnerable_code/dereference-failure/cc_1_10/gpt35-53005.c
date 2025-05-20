//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void generateBoard(int board[][5]);
void printBoard(int board[][5]);
void playGame(int board[][5]);
void checkScore(int board[][5], int *score);

//main function
int main() {
    int board[5][5];
    int score = 0;

    generateBoard(board); //generate the board
    printBoard(board); //print the board
    playGame(board); //play the game
    checkScore(board, &score); //check the final score

    printf("Final Score: %d\n", score); //print the final score

    return 0;
}

//function to generate the board with random numbers between 1 and 9
void generateBoard(int board[][5]) {
    srand(time(NULL)); //seed the random number generator

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = rand() % 9 + 1; //generate random number between 1 and 9
        }
    }
}

//function to print the board
void printBoard(int board[][5]) {
    printf("\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", board[i][j]); //print each cell
        }
        printf("\n");
    }
    printf("\n");
}

//function to play the game
void playGame(int board[][5]) {
    int row, col, num;

    for (int i = 0; i < 10; i++) { //play 10 rounds
        printf("Round %d\n", i+1);
        printf("Enter row, column, and number separated by spaces: ");
        scanf("%d %d %d", &row, &col, &num); //ask user for input
        board[row-1][col-1] = num; //update the board with user's input
        printBoard(board); //print the updated board
    }
}

//function to check the final score
void checkScore(int board[][5], int *score) {
    *score = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == i+j+2) { //if the cell contains the correct number
                (*score)++; //increment the score
            }
        }
    }
}