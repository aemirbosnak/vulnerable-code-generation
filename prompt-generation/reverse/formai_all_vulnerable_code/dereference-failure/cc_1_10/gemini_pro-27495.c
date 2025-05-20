//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum Player {
    PLAYER_X,
    PLAYER_O,
} Player;

typedef struct Cell {
    Player player;
    bool marked;
} Cell;

typedef struct Board {
    Cell cells[3][3];
} Board;

Board board;

Player current_player = PLAYER_X;

void print_usage() {
    printf("Usage: tic-tac-toe [player]\n");
    printf("  player: x for player X or o for player O\n");
}

bool is_valid_input(char input) {
    return input == 'x' || input == 'o';
}

bool is_valid_move(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && !board.cells[row][col].marked;
}

bool is_board_full() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (!board.cells[row][col].marked) {
                return false;
            }
        }
    }
    return true;
}

bool has_player_won(Player player) {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board.cells[row][0].player == player && board.cells[row][1].player == player && board.cells[row][2].player == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board.cells[0][col].player == player && board.cells[1][col].player == player && board.cells[2][col].player == player) {
            return true;
        }
    }

    // Check diagonals
    if (board.cells[0][0].player == player && board.cells[1][1].player == player && board.cells[2][2].player == player) {
        return true;
    }
    if (board.cells[0][2].player == player && board.cells[1][1].player == player && board.cells[2][0].player == player) {
        return true;
    }

    return false;
}

void print_board() {
    printf("\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board.cells[row][col].marked) {
                printf("%c ", board.cells[row][col].player == PLAYER_X ? 'X' : 'O');
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void make_move(int row, int col) {
    board.cells[row][col].player = current_player;
    board.cells[row][col].marked = true;
}

void switch_player() {
    current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
}

int main(int argc, char** argv) {
    if (argc != 2 || !is_valid_input(argv[1][0])) {
        print_usage();
        return 1;
    }

    current_player = argv[1][0] == 'x' ? PLAYER_X : PLAYER_O;

    while (!is_board_full()) {
        print_board();

        int row, col;
        do {
            printf("Player %c, it's your turn (row, column): ", current_player == PLAYER_X ? 'X' : 'O');
            scanf(" %d %d", &row, &col);
            printf("\n");
        } while (!is_valid_move(row, col));

        make_move(row, col);

        if (has_player_won(current_player)) {
            print_board();
            printf("Player %c has won!\n", current_player == PLAYER_X ? 'X' : 'O');
            return 0;
        }

        switch_player();
    }

    print_board();
    printf("The game ended in a tie.\n");
    return 0;
}