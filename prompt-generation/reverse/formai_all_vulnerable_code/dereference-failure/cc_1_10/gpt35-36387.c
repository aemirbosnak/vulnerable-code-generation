//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define constants */
#define ROWS 5
#define COLS 5
#define NUM_VALUES 75

/* Function prototypes */
void generate_board(int board[ROWS][COLS]);
int generate_call(int called_values[NUM_VALUES]);
void print_board(int board[ROWS][COLS]);
bool check_bingo(int board[ROWS][COLS]);

/* Main function */
int main() {
    /* Initialize variables */
    int board[ROWS][COLS];
    int called_values[NUM_VALUES] = {0};
    int num_calls = 0;
    char input;

    /* Generate initial board */
    generate_board(board);
    printf("Welcome to Bingo!\n\n");
    print_board(board);

    /* Play the game */
    while (!check_bingo(board)) {
        printf("\nPress enter to call a number...");
        input = getchar();

        /* Generate call */
        int call = generate_call(called_values);
        called_values[num_calls++] = call;

        /* Update board */
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == call) {
                    board[i][j] = -1;
                }
            }
        }

        /* Print updated board */
        printf("\n\nCalled values:");
        for (int i = 0; i < num_calls; i++) {
            printf(" %d,", called_values[i]);
        }
        printf("\n\n");
        print_board(board);
    }

    /* Declare winner */
    printf("\n\nBingo! You win!\n");

    return 0;
}

/* Function to generate the initial board */
void generate_board(int board[ROWS][COLS]) {
    /* Initialize board to zeros */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    /* Generate random values for board */
    for (int i = 0; i < NUM_VALUES; i++) {
        int value = rand() % 75 + 1;
        int row = (value - 1) / 15;
        int col = (value - 1) % 15;
        if (col >= 2) {
            col++;
        }
        board[row][col] = value;
    }

    /* Set center square to free */
    board[2][2] = -1;
}

/* Function to generate the call */
int generate_call(int called_values[NUM_VALUES]) {
    int call;
    do {
        call = rand() % 75 + 1;
    } while (called_values[call - 1] != 0);
    return call;
}

/* Function to print the board */
void print_board(int board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to check for a bingo */
bool check_bingo(int board[ROWS][COLS]) {
    /* Check rows */
    for (int i = 0; i < ROWS; i++) {
        bool bingo = true;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != -1) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            return true;
        }
    }

    /* Check columns */
    for (int j = 0; j < COLS; j++) {
        bool bingo = true;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][j] != -1) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            return true;
        }
    }

    /* Check diagonals */
    if (board[0][0] == -1 && board[1][1] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        return true;
    }
    if (board[0][4] == -1 && board[1][3] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        return true;
    }

    /* No bingo */
    return false;
}