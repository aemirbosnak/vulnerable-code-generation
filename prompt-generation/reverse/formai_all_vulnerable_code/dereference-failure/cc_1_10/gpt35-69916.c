//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initialize_board(int board[ROWS][COLS]);
void output_board(int board[ROWS][COLS]);
int select_random_number(int used_numbers[]);
int check_bingo(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int used_numbers[75] = {0};
    int number;
    int bingo = 0;
    int turn = 1;

    srand(time(NULL));

    printf("Welcome to the Bingo Simulator\n");

    initialize_board(board);

    while (!bingo && turn <= 75) {
        printf("Turn %d\n", turn);
        output_board(board);

        number = select_random_number(used_numbers);
        printf("The next number called is %d\n", number);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == number) {
                    board[i][j] = -1;
                }
            }
        }

        bingo = check_bingo(board);

        turn++;
    }

    if (bingo) {
        printf("BINGO! You won on turn %d\n", turn - 1);
    } else {
        printf("Sorry, no more turns left.\n");
    }

    return 0;
}

void initialize_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (i * 15) + j + 1;
        }
    }
}

void output_board(int board[ROWS][COLS]) {
    printf("--------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("|   ");
            } else if (board[i][j] < 10) {
                printf("| %d ", board[i][j]);
            } else {
                printf("|%d ", board[i][j]);
            }
        }
        printf("|\n");
        printf("--------------------\n");
    }
}

int select_random_number(int used_numbers[]) {
    int number;

    do {
        number = rand() % 75 + 1;
    } while (used_numbers[number] == 1);

    used_numbers[number] = 1;

    return number;
}

int check_bingo(int board[ROWS][COLS]) {
    int count;

    // Check rows
    for (int i = 0; i < ROWS; i++) {
        count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (board[j][i] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check diagonals
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][COLS - i - 1] == -1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    return 0;
}