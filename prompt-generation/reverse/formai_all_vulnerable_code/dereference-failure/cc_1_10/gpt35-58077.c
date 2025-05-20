//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to print the current board
void print_board(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check if a player has won
int check_win(char board[], char player) {
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the board is full
int check_board_full(char board[]) {
    int i;
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

// Function to get the move from the player
int get_move(char board[], char player) {
    int move;
    printf("Player %c's move: ", player);
    scanf("%d", &move);

    // Make sure the move is valid
    while (board[move-1] != ' ' || move < 1 || move > 9) {
        printf("Invalid move. Try again: ");
        scanf("%d", &move);
    }

    return move;
}

// Function to get the computer's move
int get_computer_move(char board[], char computer) {
    int i;
    char player = (computer == 'X') ? 'O' : 'X';

    // Check for winning move
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = computer;
            if (check_win(board, computer)) {
                return i+1;
            } else {
                board[i] = ' ';
            }
        }
    }

    // Check for blocking move
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = player;
            if (check_win(board, player)) {
                board[i] = computer;
                return i+1;
            } else {
                board[i] = ' ';
            }
        }
    }

    // Choose a random move
    do {
        i = rand() % 9;
    } while (board[i] != ' ');

    board[i] = computer;
    return i+1;
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int turn;
    char player = 'X';
    char computer = 'O';
    int move;

    // Randomly choose who goes first
    turn = rand() % 2;

    // Main game loop
    while (!check_board_full(board)) {
        print_board(board);

        if (turn % 2 == 0) {
            // Player's turn
            move = get_move(board, player);
            board[move-1] = player;
            if (check_win(board, player)) {
                print_board(board);
                printf("Congratulations! Player %c has won the game!\n", player);
                return 0;
            }
        } else {
            // Computer's turn
            printf("Computer's turn...\n");
            move = get_computer_move(board, computer);
            if (check_win(board, computer)) {
                print_board(board);
                printf("The computer has won the game!\n");
                return 0;
            }
        }

        turn++;
    }

    // If the board is full and neither player has won, it's a tie
    print_board(board);
    printf("The game is a tie!\n");

    return 0;
}