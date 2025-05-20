//FormAI DATASET v1.0 Category: Chess engine ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOARD_LENGTH 8

enum PieceType {
    K, Q, R, B, N, P, k, q, r, b, n, p, EMPTY
};

enum Player {
    WHITE, BLACK
};

struct Piece {
    enum PieceType type;
    enum Player player;
};

struct ChessBoard {
    struct Piece board[BOARD_LENGTH][BOARD_LENGTH];
    enum Player currentPlayer;
};

struct ChessBoard* create_board() {
    struct ChessBoard* board = (struct ChessBoard*) malloc(sizeof(struct ChessBoard));
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (i == 0) {
                switch(j) {
                    case 0:
                    case 7:
                        board->board[i][j] = (struct Piece) {R, WHITE};
                        break;
                    case 1:
                    case 6:
                        board->board[i][j] = (struct Piece) {N, WHITE};
                        break;
                    case 2:
                    case 5:
                        board->board[i][j] = (struct Piece) {B, WHITE};
                        break;
                    case 3:
                        board->board[i][j] = (struct Piece) {Q, WHITE};
                        break;
                    case 4:
                        board->board[i][j] = (struct Piece) {K, WHITE};
                        break;
                }
            } else if (i == 1) {
                board->board[i][j] = (struct Piece) {P, WHITE};
            } else if (i == 6) {
                board->board[i][j] = (struct Piece) {p, BLACK};
            } else if (i == 7) {
                switch(j) {
                    case 0:
                    case 7:
                        board->board[i][j] = (struct Piece) {r, BLACK};
                        break;
                    case 1:
                    case 6:
                        board->board[i][j] = (struct Piece) {n, BLACK};
                        break;
                    case 2:
                    case 5:
                        board->board[i][j] = (struct Piece) {b, BLACK};
                        break;
                    case 3:
                        board->board[i][j] = (struct Piece) {q, BLACK};
                        break;
                    case 4:
                        board->board[i][j] = (struct Piece) {k, BLACK};
                        break;
                }
            } else {
                board->board[i][j] = (struct Piece) {EMPTY, WHITE};
            }
        }
    }
    board->currentPlayer = WHITE;
    return board;
}

void print_board(struct ChessBoard* board) {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            switch(board->board[i][j].type) {
                case K:
                    printf("K");
                    break;
                case Q:
                    printf("Q");
                    break;
                case R:
                    printf("R");
                    break;
                case B:
                    printf("B");
                    break;
                case N:
                    printf("N");
                    break;
                case P:
                    printf("P");
                    break;
                case k:
                    printf("k");
                    break;
                case q:
                    printf("q");
                    break;
                case r:
                    printf("r");
                    break;
                case b:
                    printf("b");
                    break;
                case n:
                    printf("n");
                    break;
                case p:
                    printf("p");
                    break;
                case EMPTY:
                    printf(".");
                    break;
            }
            printf(" ");
        }
        printf("\n");
    }
}

void move_piece(struct ChessBoard* board, int start_x, int start_y, int end_x, int end_y) {
    board->board[end_x][end_y] = board->board[start_x][start_y];
    board->board[start_x][start_y].type = EMPTY;
    board->board[start_x][start_y].player = WHITE;
}

void play_game(struct ChessBoard* board) {
    while (1) {
        print_board(board);
        printf("%s to move: ", board->currentPlayer == WHITE ? "White" : "Black");
        char move[5];
        scanf("%s", move);
        int start_x = move[0] - 'a';
        int start_y = move[1] - '1';
        int end_x = move[2] - 'a';
        int end_y = move[3] - '1';
        move_piece(board, start_x, start_y, end_x, end_y);
        board->currentPlayer = board->currentPlayer == WHITE ? BLACK : WHITE;
    }
}

int main() {
    struct ChessBoard* board = create_board();
    play_game(board);
    return 0;
}