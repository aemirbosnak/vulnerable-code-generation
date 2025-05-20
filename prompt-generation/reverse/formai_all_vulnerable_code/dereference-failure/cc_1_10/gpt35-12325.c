//FormAI DATASET v1.0 Category: Chess AI ; Style: post-apocalyptic
/* 

Post-Apocalyptic Chess AI

This program simulates a chess match in a post-apocalyptic world, where the board is damaged and the pieces have unique abilities based on their mutations.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char symbol;
    Position pos;
    int alive;
    int power;
} Piece;

Piece** create_board() {
    Piece** board = (Piece**) malloc(BOARD_SIZE * sizeof(Piece*));
    if (board == NULL) {
        fprintf(stderr, "Unable to allocate memory for board.\n");
        exit(1);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Piece*) malloc(BOARD_SIZE * sizeof(Piece));
        if (board[i] == NULL) {
            fprintf(stderr, "Unable to allocate memory for board.\n");
            exit(1);
        }
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1) {
                if (j == 0 || j == BOARD_SIZE - 1) {
                    board[i][j].symbol = 'X'; // Wall
                    board[i][j].power = 0;
                } else if (j == 1 || j == BOARD_SIZE - 2) {
                    board[i][j].symbol = 'B'; // Brawler
                    board[i][j].power = 2;
                } else if (j == 2 || j == BOARD_SIZE - 3) {
                    board[i][j].symbol = 'S'; // Sniper
                    board[i][j].power = 3;
                } else {
                    board[i][j].symbol = 'M'; // Medic
                    board[i][j].power = 5;
                }
            } else if (i == 1 || i == BOARD_SIZE - 2) {
                board[i][j].symbol = 'W'; // Warrior
                board[i][j].power = 1;
            } else {
                board[i][j].symbol = ' '; // Empty space
                board[i][j].power = 0;
            }
            board[i][j].pos = (Position) {i, j};
            board[i][j].alive = 1;
        }
    }
    return board;
}

void print_board(Piece** board) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("[%c]", board[i][j].symbol);
        }
        printf("\n");
    }
}

Piece* get_piece(Piece** board, int row, int col) {
    if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE) {
        return NULL;
    }
    return &board[row][col];
}

int move_piece(Piece** board, int src_row, int src_col, int dest_row, int dest_col) {
    Piece* src_piece = get_piece(board, src_row, src_col);
    Piece* dest_piece = get_piece(board, dest_row, dest_col);
    if (src_piece == NULL || dest_piece == NULL) {
        return 0;
    }
    if (!src_piece->alive || src_piece->symbol == ' ' || dest_piece->symbol == 'X') {
        return 0;
    }
    int power_diff = src_piece->power - dest_piece->power;
    int rng = rand() % 6 + 1;
    if ((power_diff > 0 && rng < 6) || (power_diff == 0 && rng < 4)) {
        dest_piece->alive = 0;
        dest_piece->symbol = ' ';
        dest_piece->power = 0;
    } else {
        return 0;
    }
    dest_piece->symbol = src_piece->symbol;
    src_piece->symbol = ' ';
    return 1;
}

int main() {
    srand(time(NULL));
    Piece** board = create_board();
    print_board(board);
    int src_row, src_col, dest_row, dest_col;
    while (1) {
        printf("Enter source position (row col): ");
        scanf("%d %d", &src_row, &src_col);
        printf("Enter destination position (row col): ");
        scanf("%d %d", &dest_row, &dest_col);
        if (move_piece(board, src_row, src_col, dest_row, dest_col)) {
            printf("Move successful.\n");
            print_board(board);
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}