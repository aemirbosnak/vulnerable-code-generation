//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeGameBoard(char gameBoard[ROWS][COLS], char letters[ROWS*COLS/2]);
void shuffleLetters(char letters[ROWS*COLS/2]);
void displayGameBoard(char gameBoard[ROWS][COLS], int foundLetters[ROWS*COLS/2]);

int main() {
    srand(time(NULL)); // seed random number generator
    char gameBoard[ROWS][COLS];
    char letters[ROWS*COLS/2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // 8 unique letters
    int foundLetters[ROWS*COLS/2] = {0}; // tracks if a letter has been found

    initializeGameBoard(gameBoard, letters);
    shuffleLetters(letters);

    int guess1_row, guess1_col, guess2_row, guess2_col, matchesFound = 0;

    while (matchesFound < ROWS*COLS/2) {
        displayGameBoard(gameBoard, foundLetters);
        printf("Enter your first guess (row column): ");
        scanf("%d %d", &guess1_row, &guess1_col);
        while (gameBoard[guess1_row][guess1_col] == ' ' || foundLetters[gameBoard[guess1_row][guess1_col]-'A'] == 1) {
            printf("That letter has already been found! Please enter a valid guess.\n");
            printf("Enter your first guess (row column): ");
            scanf("%d %d", &guess1_row, &guess1_col);
        }
        printf("Enter your second guess (row column): ");
        scanf("%d %d", &guess2_row, &guess2_col);
        while ((guess1_row == guess2_row && guess1_col == guess2_col) || gameBoard[guess2_row][guess2_col] == ' ' || foundLetters[gameBoard[guess2_row][guess2_col]-'A'] == 1) {
            printf("Please enter a valid guess.\n");
            printf("Enter your second guess (row column): ");
            scanf("%d %d", &guess2_row, &guess2_col);
        }
        if (gameBoard[guess1_row][guess1_col] == gameBoard[guess2_row][guess2_col]) {
            foundLetters[gameBoard[guess1_row][guess1_col]-'A'] = 1;
            foundLetters[gameBoard[guess2_row][guess2_col]-'A'] = 1;
            matchesFound++;
            printf("You found a match!\n");
        } else {
            printf("Sorry, those letters don't match.\n");
        }
    }

    printf("Congratulations! You found all the matches!\n");

    return 0;
}

void initializeGameBoard(char gameBoard[ROWS][COLS], char letters[ROWS*COLS/2]) {
    int i, j, index = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            gameBoard[i][j] = letters[index];
            index++;
        }
    }
}

void shuffleLetters(char letters[ROWS*COLS/2]) {
    int i, j;
    char temp;
    for (i = 0; i < ROWS*COLS/2; i++) {
        j = rand() % (ROWS*COLS/2); // generate random index
        temp = letters[i]; // swap letters
        letters[i] = letters[j];
        letters[j] = temp;
    }
}

void displayGameBoard(char gameBoard[ROWS][COLS], int foundLetters[ROWS*COLS/2]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("  ");
        for (j = 0; j < COLS; j++) {
            if (foundLetters[gameBoard[i][j]-'A'] == 1) {
                printf("%c ", gameBoard[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}