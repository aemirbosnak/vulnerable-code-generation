//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int row, col;
} Point;

void setupBoard(char board[][BOARD_SIZE], char values[]);
void shuffleValues(char values[]);
void clearScreen();
void displayBoard(char board[][BOARD_SIZE]);
void swap(char *a, char *b);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {0};
    char values[BOARD_SIZE * BOARD_SIZE / 2];

    // initialize game
    setupBoard(board, values);

    // display the empty board
    displayBoard(board);

    // main game loop
    Point selected[2] = {{0, 0}, {0, 0}};
    int correctGuesses = 0;
    while (correctGuesses < BOARD_SIZE * BOARD_SIZE / 2) {
        // prompt user for first selection
        printf("Select the first card (row column): ");
        scanf("%d %d", &selected[0].row, &selected[0].col);

        // reveal first selection on the board
        board[selected[0].row - 1][selected[0].col - 1] = values[(selected[0].row - 1) * BOARD_SIZE + selected[0].col - 1];
        displayBoard(board);

        // prompt user for second selection
        printf("Select the second card (row column): ");
        scanf("%d %d", &selected[1].row, &selected[1].col);

        // reveal second selection on the board
        board[selected[1].row - 1][selected[1].col - 1] = values[(selected[1].row - 1) * BOARD_SIZE + selected[1].col - 1];
        displayBoard(board);

        // check if the selections match
        if (board[selected[0].row - 1][selected[0].col - 1] == board[selected[1].row - 1][selected[1].col - 1]) {
            printf("Match!\n");
            correctGuesses++;
        } else {
            printf("No match.\n");

            // hide the selections on the board
            board[selected[0].row - 1][selected[0].col - 1] = 0;
            board[selected[1].row - 1][selected[1].col - 1] = 0;
        }

        // clear the screen for the next turn
        clearScreen();
    }

    printf("Congratulations, you won!\n");

    return 0;
}

void setupBoard(char board[][BOARD_SIZE], char values[]) {
    // set up values for the game
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        values[i] = 'A' + i;
        values[i + BOARD_SIZE * BOARD_SIZE / 2] = 'A' + i;
    }
    shuffleValues(values);

    // fill the board with zeros
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void shuffleValues(char values[]) {
    srand(time(NULL)); // seed the random number generator

    // shuffle the values
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int j = rand() % (BOARD_SIZE * BOARD_SIZE);
        swap(&values[i], &values[j]);
    }
}

void clearScreen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 1, 1);
}

void displayBoard(char board[][BOARD_SIZE]) {
    printf("     ");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        printf("%d   ", i);
    }
    printf("\n");

    for (int i = 1; i <= BOARD_SIZE; i++) {
        printf("   +");
        for (int j = 1; j < BOARD_SIZE; j++) {
            printf("---+");
        }
        printf("---+\n");

        printf(" %d ", i);
        for (int j = 1; j <= BOARD_SIZE; j++) {
            printf("| %c ", board[i - 1][j - 1] ? board[i - 1][j - 1] : ' ');
        }
        printf("|\n");
    }

    printf("   +");
    for (int j = 1; j < BOARD_SIZE; j++) {
        printf("---+");
    }
    printf("---+\n");
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}