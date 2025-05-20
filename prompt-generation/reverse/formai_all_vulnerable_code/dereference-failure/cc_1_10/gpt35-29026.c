//FormAI DATASET v1.0 Category: Chess AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char piece; // 'P', 'R', 'N', 'B', 'Q', 'K'
    int color; // 0 for white, 1 for black
} Piece;

typedef struct {
    Piece **grid;
} Board;

void initialize_board(Board *board);
void print_board(Board *board);
void make_move(Board *board, Position start, Position end, int turn);
int get_piece_value(char piece);
int evaluate_board(Board *board);
int minimax(Board *board, int depth, int alpha, int beta, int maximizingPlayer, int turn);

int main() {
    Board *board = malloc(sizeof(Board));
    initialize_board(board);
    print_board(board);

    int turn = 0; // 0 for white, 1 for black
    int game_over = 0;
    while (!game_over) {
        if (turn == 0) {
            // white's turn
            printf("White's turn.\n");
            // get move from user
            Position start;
            Position end;
            printf("Enter starting position (e.g. a2, b7, etc.): ");
            scanf("%d,%d", &start.x, &start.y);
            printf("Enter ending position: ");
            scanf("%d,%d", &end.x, &end.y);
            make_move(board, start, end, turn);
        } else {
            // black's turn (AI)
            printf("Black's turn.\n");
            int alpha = -9999;
            int beta = 9999;
            int best_value = minimax(board, 3, alpha, beta, 1, turn);
            printf("The best move for black has value %d.\n", best_value);
            // TODO: update board with best move
        }

        print_board(board);

        // check if game is over
        // TODO

        turn = (turn + 1) % 2;
    }

    // free memory and exit
    // TODO

    return 0;
}

void initialize_board(Board *board) {
    board->grid = malloc(sizeof(Piece *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->grid[i] = malloc(sizeof(Piece) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 1) {
                board->grid[i][j].piece = 'P';
                board->grid[i][j].color = 0;
            } else if (i == 6) {
                board->grid[i][j].piece = 'P';
                board->grid[i][j].color = 1;
            } else if ((i == 0 && j == 0) || (i == 0 && j == 7)) {
                board->grid[i][j].piece = 'R';
                board->grid[i][j].color = 0;
            } else if ((i == 7 && j == 0) || (i == 7 && j == 7)) {
                board->grid[i][j].piece = 'R';
                board->grid[i][j].color = 1;
            } else if ((i == 0 && j == 1) || (i == 0 && j == 6)) {
                board->grid[i][j].piece = 'N';
                board->grid[i][j].color = 0;
            } else if ((i == 7 && j == 1) || (i == 7 && j == 6)) {
                board->grid[i][j].piece = 'N';
                board->grid[i][j].color = 1;
            } else if ((i == 0 && j == 2) || (i == 0 && j == 5)) {
                board->grid[i][j].piece = 'B';
                board->grid[i][j].color = 0;
            } else if ((i == 7 && j == 2) || (i == 7 && j == 5)) {
                board->grid[i][j].piece = 'B';
                board->grid[i][j].color = 1;
            } else if (i == 0 && j == 3) {
                board->grid[i][j].piece = 'Q';
                board->grid[i][j].color = 0;
            } else if (i == 7 && j == 3) {
                board->grid[i][j].piece = 'Q';
                board->grid[i][j].color = 1;
            } else if (i == 0 && j == 4) {
                board->grid[i][j].piece = 'K';
                board->grid[i][j].color = 0;
            } else if (i == 7 && j == 4) {
                board->grid[i][j].piece = 'K';
                board->grid[i][j].color = 1;
            } else {
                board->grid[i][j].piece = '-';
                board->grid[i][j].color = -1;
            }
        }
    }
}

void print_board(Board *board) {
    printf("\n   a b c d e f g h\n");
    printf("  +-----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->grid[i][j].piece);
        }
        printf("| %d\n", i + 1);
    }
    printf("  +-----------------+\n");
    printf("   a b c d e f g h\n\n");
}

void make_move(Board *board, Position start, Position end, int turn) {
    // TODO
}

int get_piece_value(char piece) {
    switch(piece) {
        case 'P':
            return 1;
        case 'R':
            return 5;
        case 'N':
            return 3;
        case 'B':
            return 3;
        case 'Q':
            return 9;
        case 'K':
            return 100;
        default:
            return 0;
    }
}

int evaluate_board(Board *board) {
    int white_score = 0;
    int black_score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = board->grid[i][j].piece;
            int value = get_piece_value(piece);
            if (board->grid[i][j].color == 0) {
                white_score += value;
            } else if (board->grid[i][j].color == 1) {
                black_score += value;
            }
        }
    }
    return white_score - black_score;
}

int minimax(Board *board, int depth, int alpha, int beta, int maximizingPlayer, int turn) {
    if (depth == 0) {
        return evaluate_board(board);
    }

    // TODO: implement minimax algorithm

    return 0;
}