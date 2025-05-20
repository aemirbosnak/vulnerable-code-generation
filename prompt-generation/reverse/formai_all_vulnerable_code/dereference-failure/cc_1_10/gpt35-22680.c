//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to draw the game board */
void draw_board(char board[]) {
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |     |     \n\n");
}

/* Function to check if a spot is empty or not */
int spot_available(char board[], int spot) {
    if (board[spot] == ' ')
        return 1;
    else
        return 0;
}

/* Function to check if board is full or not */
int is_board_full(char board[]) {
    for (int i = 1; i <= 9; i++) {
        if (board[i] == ' ')
            return 0;
    }
    return 1;
}

/* Function to check if game is over or not */
char game_over(char board[]) {
    if (board[1] == board[2] && board[2] == board[3] && board[1] != ' ')
        return board[1];
    else if (board[4] == board[5] && board[5] == board[6] && board[4] != ' ')
        return board[4];
    else if (board[7] == board[8] && board[8] == board[9] && board[7] != ' ')
        return board[7];
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    else if (board[3] == board[6] && board[6] == board[9] && board[3] != ' ')
        return board[3];
    else if (board[1] == board[5] && board[5] == board[9] && board[1] != ' ')
        return board[1];
    else if (board[3] == board[5] && board[5] == board[7] && board[3] != ' ')
        return board[3];
    else if (is_board_full(board))
        return 'T';
    else
        return ' ';
}

/* Function for AI move */
int get_computer_move(char board[]) {
    int move;

    /* Check if computer can win */
    for (int i = 1; i <= 9; i++) {
        if (spot_available(board, i)) {
            board[i] = 'O';
            if (game_over(board) == 'O') {
                return i;
            }
            else {
                board[i] = ' ';
            }
        }
    }

    /* Check if player can win and block them */
    for (int i = 1; i <= 9; i++) {
        if (spot_available(board, i)) {
            board[i] = 'X';
            if (game_over(board) == 'X') {
                return i;
            }
            else {
                board[i] = ' ';
            }
        }
    }

    /* If player is not in any winning position, choose a random spot */
    do {
        move = rand() % 9 + 1;
    } while (!spot_available(board, move));

    return move;
}

/* Main function */
int main() {
    char board[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int player, turn;
    char result;

    /* Initialize random number generator */
    srand(time(NULL));

    /* Randomly decide who goes first */
    player = rand() % 2 + 1;

    /* Game loop */
    for (turn = 1; turn <= 9; turn++) {
        draw_board(board);

        if (player == 1) {
            printf("Player 1 (X), enter a spot: ");
            int spot;
            scanf("%d", &spot);

            while (!spot_available(board, spot)) {
                printf("Spot not available, please choose another spot: ");
                scanf("%d", &spot);
            }

            board[spot] = 'X';
        }
        else {
            int move = get_computer_move(board);
            board[move] = 'O';
            printf("Computer chooses spot %d\n", move);
        }

        /* Check if game is over */
        result = game_over(board);
        if (result != ' ') {
            break;
        }

        /* Switch player */
        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    }

    /* Draw final board */
    draw_board(board);

    /* Print result */
    switch (result) {
        case 'X':
            printf ("Congratulations! Player 1 wins!\n");
            break;
        case 'O':
            printf ("Computer wins! Better luck next time.\n");
            break;
        case 'T':
            printf ("It's a tie!\n");
            break;
    }

    return 0;
}