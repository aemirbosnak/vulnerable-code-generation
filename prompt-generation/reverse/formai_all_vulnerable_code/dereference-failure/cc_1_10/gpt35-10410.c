//FormAI DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 4
#define COLS 4

char gameBoard[ROWS][COLS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char displayBoard[ROWS][COLS] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int flippedCards[2][2];
int score = 0;
int attempts = 0;

void displayBoardState() {
    printf("\n\n\n\n\t\t\t%c\t\t\t%c\t\t\t%c\t\t\t%c\n\n\n", displayBoard[0][0], displayBoard[0][1], displayBoard[0][2], displayBoard[0][3]);
    printf("\t\t\t%c\t\t\t%c\t\t\t%c\t\t\t%c\n\n\n", displayBoard[1][0], displayBoard[1][1], displayBoard[1][2], displayBoard[1][3]);
    printf("\t\t\t%c\t\t\t%c\t\t\t%c\t\t\t%c\n\n\n", displayBoard[2][0], displayBoard[2][1], displayBoard[2][2], displayBoard[2][3]);
    printf("\t\t\t%c\t\t\t%c\t\t\t%c\t\t\t%c\n\n\n", displayBoard[3][0], displayBoard[3][1], displayBoard[3][2], displayBoard[3][3]);
}

void shuffleCards(char arr[]) {
    int n = strlen(arr);
    for(int i = 0; i < n; i++) {
        int j = rand() % (i + 1);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void checkMatch() {
    int row1 = flippedCards[0][0];
    int col1 = flippedCards[0][1];
    int row2 = flippedCards[1][0];
    int col2 = flippedCards[1][1];
    if(gameBoard[row1][col1] == gameBoard[row2][col2]) {
        displayBoard[row1][col1] = gameBoard[row1][col1];
        displayBoard[row2][col2] = gameBoard[row2][col2];
        printf("\n\n\t\t\tMATCH FOUND! WELL DONE!\n\n");
        score++;
    } else {
        displayBoard[row1][col1] = ' ';
        displayBoard[row2][col2] = ' ';
        printf("\n\n\t\t\tNO MATCH FOUND. TRY AGAIN!\n\n");
    }
    attempts++;
    printf("\n\n\t\t\tATTEMPTS: %d", attempts);
    printf("\t\t\t\tSCORE: %d", score);
}

void playRound() {
    int row, col;
    printf("\n\n\t\t\tENTER ROW: ");
    scanf("%d", &row);
    printf("\n\n\t\t\tENTER COLUMN: ");
    scanf("%d", &col);
    row--;
    col--;
    if(row > 3 || col > 3 || row < 0 || col < 0) {
        printf("\n\n\t\t\tINVALID ENTRY. PLEASE TRY AGAIN.\n\n");
    } else if(displayBoard[row][col] == gameBoard[row][col]) {
        printf("\n\n\t\t\tCARD ALREADY FLIPPED. PLEASE TRY AGAIN.\n\n");
    } else {
        displayBoard[row][col] = gameBoard[row][col];
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tFLIPPED CARD: %c", gameBoard[row][col]);
        if(flippedCards[0][0] == -1 && flippedCards[0][1] == -1) {
            flippedCards[0][0] = row;
            flippedCards[0][1] = col;
        } else {
            flippedCards[1][0] = row;
            flippedCards[1][1] = col;
            checkMatch();
            flippedCards[0][0] = -1;
            flippedCards[0][1] = -1;
            flippedCards[1][0] = -1;
            flippedCards[1][1] = -1;
        }
    }
    displayBoardState();
}

int main() {
    srand(time(0));
    shuffleCards(gameBoard);
    displayBoardState();
    while(score < 8) {
        playRound();
    }
    printf("\n\n\t\t\tCONGRATULATIONS! YOU WON IN %d ATTEMPTS", attempts);
    return 0;
}