//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

//Defining the board size
#define BOARD_SIZE 8

//Defining the player's tokens
#define PLAYER1_TOKEN 'X'
#define PLAYER2_TOKEN 'O'

//Defining the empty and invalid squares
#define EMPTY ' '
#define INVALID '#'

//Structure for a single board square
typedef struct square {
    char token;
    int valid;
} Square;

//Function to print the board
void print_board(Square board[][BOARD_SIZE]) {
    printf("\n  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].token);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to initialize the board
void initialize_board(Square board[][BOARD_SIZE], int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == player) {
                if (i < 3) board[i][j].token = PLAYER1_TOKEN;
                else if (i > 4) board[i][j].token = PLAYER2_TOKEN;
                else board[i][j].token = EMPTY;
                board[i][j].valid = 1;
            } else {
                board[i][j].token = INVALID;
                board[i][j].valid = 0;
            }
        }
    }
}

//Function to check if the move is valid
int is_valid_move(Square board[][BOARD_SIZE], int player, int start_x, int start_y, int end_x, int end_y) {
    //Make sure the start and end positions are within the board
    if (start_x < 0 || start_x >= BOARD_SIZE || start_y < 0 || start_y >= BOARD_SIZE ||
        end_x < 0 || end_x >= BOARD_SIZE || end_y < 0 || end_y >= BOARD_SIZE) {
        return 0;
    }

    //Make sure the start position has the player's token and the end position is empty
    if (board[start_x][start_y].token != (player == 1 ? PLAYER1_TOKEN : PLAYER2_TOKEN) ||
        board[end_x][end_y].token != EMPTY) {
        return 0;
    }

    //Check if the move is diagonal and only one square away
    if (abs(end_x - start_x) != 1 || abs(end_y - start_y) != 1) {
        return 0;
    }

    //Check if the move is in the correct direction
    if (player == 1 && end_x < start_x) {
        return 0;
    } else if (player == 2 && end_x > start_x) {
        return 0;
    }

    return 1;
}

//Function to make a move
void make_move(Square board[][BOARD_SIZE], int start_x, int start_y, int end_x, int end_y) {
    board[end_x][end_y].token = board[start_x][start_y].token;
    board[start_x][start_y].token = EMPTY;
}

//Function to check if a player has won
int has_player_won(Square board[][BOARD_SIZE], int player) {
    char token = (player == 1 ? PLAYER1_TOKEN : PLAYER2_TOKEN);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].token == token) {
                //Check if the player can make a move
                if ((player == 1 && board[i-1][j-1].token == EMPTY && is_valid_move(board, player, i, j, i-1, j-1)) ||
                    (player == 1 && board[i-1][j+1].token == EMPTY && is_valid_move(board, player, i, j, i-1, j+1)) ||
                    (player == 2 && board[i+1][j-1].token == EMPTY && is_valid_move(board, player, i, j, i+1, j-1)) ||
                    (player == 2 && board[i+1][j+1].token == EMPTY && is_valid_move(board, player, i, j, i+1, j+1))) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    Square board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int start_x, start_y, end_x, end_y;

    printf("Welcome to the Ken Thompson-style Checkers game!\n\n");

    initialize_board(board, player);
    while (!has_player_won(board, player)) {
        printf("Player %d's turn:\n", player);
        print_board(board);
        printf("Enter start position (e.g. 4 3): ");
        scanf("%d %d", &start_x, &start_y);
        printf("Enter end position (e.g. 5 4): ");
        scanf("%d %d", &end_x, &end_y);
        if (is_valid_move(board, player, start_x-1, start_y-1, end_x-1, end_y-1)) {
            make_move(board, start_x-1, start_y-1, end_x-1, end_y-1);
            player = player == 1 ? 2 : 1;
        } else {
            printf("Invalid move, try again.\n\n");
        }
    }

    printf("Player %d wins!\n", player == 1 ? 2 : 1);
    print_board(board);

    return 0;
}