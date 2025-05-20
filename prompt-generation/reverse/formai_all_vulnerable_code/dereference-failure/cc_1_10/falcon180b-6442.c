//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 3
#define COLS 3
#define NUM_CELLS (ROWS * COLS)

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the game board
void print_board(int board[NUM_CELLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i*COLS + j]);
        }
        printf("\n");
    }
}

// Function to check if the game is won
int check_win(int board[NUM_CELLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i*COLS] == board[(i+1)*COLS-1] &&
            board[i*COLS] == board[i*COLS+1]) {
            return 1;
        }
    }

    for (int i = 0; i < COLS; i++) {
        if (board[i] == board[i*ROWS-1] &&
            board[i] == board[(i+1)*ROWS-1]) {
            return 1;
        }
    }

    if (board[0] == board[4] && board[0] == board[8]) {
        return 1;
    }

    if (board[2] == board[4] && board[2] == board[6]) {
        return 1;
    }

    return 0;
}

// Function to initialize the game board
void init_board(int board[NUM_CELLS]) {
    for (int i = 0; i < NUM_CELLS; i++) {
        board[i] = rand_int(1, 9);
    }
}

// Function to play the game
void play_game(int board[NUM_CELLS]) {
    int player_choice;
    int empty_cell = -1;

    init_board(board);
    print_board(board);

    while (1) {
        printf("Enter your move (row col): ");
        scanf("%d %d", &player_choice, &empty_cell);

        if (player_choice < 1 || player_choice > 9 || empty_cell < 0 || empty_cell >= NUM_CELLS) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[empty_cell]!= 0) {
            printf("Cell already occupied.\n");
            continue;
        }

        board[empty_cell] = player_choice;
        print_board(board);

        if (check_win(board)) {
            printf("Congratulations! You won!\n");
            break;
        }

        int computer_choice = rand_int(1, 9);
        while (board[computer_choice]!= 0) {
            computer_choice = rand_int(1, 9);
        }
        board[computer_choice] = -player_choice;
        print_board(board);

        if (check_win(board)) {
            printf("Sorry, you lost.\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    play_game(NULL);
    return 0;
}