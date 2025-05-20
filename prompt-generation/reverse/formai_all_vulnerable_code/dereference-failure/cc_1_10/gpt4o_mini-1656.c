//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void init_board(ChessBoard *cb) {
    const char *initial[SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    for (int i = 0; i < SIZE; i++) {
        strcpy(cb->board[i], initial[i]);
    }
}

void print_board(ChessBoard *cb) {
    printf("  A B C D E F G H\n");
    printf(" +----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", 8-i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", cb->board[i][j]);
        }
        printf("\n");
    }
    printf(" +----------------\n");
}

int is_valid_position(char *move) {
    return strlen(move) == 4 && 
           move[0] >= 'A' && move[0] <= 'H' && 
           move[1] >= '1' && move[1] <= '8' && 
           move[2] >= 'A' && move[2] <= 'H' && 
           move[3] >= '1' && move[3] <= '8';
}

void move_piece(ChessBoard *cb, char *move) {
    int from_col = move[0] - 'A';
    int from_row = 8 - (move[1] - '0');
    int to_col = move[2] - 'A';
    int to_row = 8 - (move[3] - '0');

    if (cb->board[from_row][from_col] != '.' && 
        from_row >= 0 && from_row < SIZE && 
        from_col >= 0 && from_col < SIZE && 
        to_row >= 0 && to_row < SIZE && 
        to_col >= 0 && to_col < SIZE) {
        cb->board[to_row][to_col] = cb->board[from_row][from_col];
        cb->board[from_row][from_col] = '.';
    } else {
        printf("Invalid move!\n");
    }
}

int main() {
    ChessBoard chess_board;
    init_board(&chess_board);
    
    char move[5];

    while (1) {
        print_board(&chess_board);
        printf("Enter your move (e.g., E2E4) or 'exit' to quit: ");
        fgets(move, sizeof(move), stdin);

        // Remove newline character if it exists
        move[strcspn(move, "\n")] = 0;

        if (strcmp(move, "exit") == 0) {
            break;
        }

        if (is_valid_position(move)) {
            move_piece(&chess_board, move);
        } else {
            printf("Invalid input. Try again!\n");
        }
    }

    return 0;
}