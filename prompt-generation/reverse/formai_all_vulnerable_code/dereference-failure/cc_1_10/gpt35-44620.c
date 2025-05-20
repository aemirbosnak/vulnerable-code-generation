//FormAI DATASET v1.0 Category: Chess engine ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOVES 1000

const char* PIECE_NAMES[] = {"king", "queen", "rook", "bishop", "knight", "pawn"};

typedef enum {
    NONE,
    WHITE,
    BLACK
} ChessPlayer;

typedef enum {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
} ChessPiece;

typedef struct {
    int row;
    int col;
} ChessPos;

typedef struct {
    ChessPiece piece;
    ChessPlayer player;
    ChessPos pos;
} ChessPieceInstance;

typedef struct {
    ChessPieceInstance* pieces;
    int num_pieces;
} ChessBoard;

typedef struct {
    ChessPos from_pos;
    ChessPos to_pos;
} ChessMove;

void setup_board(ChessBoard* board) {
    board->num_pieces = 32;
    board->pieces = (ChessPieceInstance*) malloc(board->num_pieces * sizeof(ChessPieceInstance));

    int i;
    for (i = 0; i < board->num_pieces; i++) {
        board->pieces[i].pos.row = (i < 16) ? 0 : 7; // first two rows of pieces
        board->pieces[i].pos.col = i % 8; // columns 0 to 7
        board->pieces[i].player = (i < 16) ? WHITE : BLACK; // first 16 are white, rest are black

        switch (i % 8) {
            case 0:
            case 7:
                // rook
                board->pieces[i].piece = ROOK;
                break;
            case 1:
            case 6:
                // knight
                board->pieces[i].piece = KNIGHT;
                break;
            case 2:
            case 5:
                // bishop
                board->pieces[i].piece = BISHOP;
                break;
            case 3:
                // queen
                board->pieces[i].piece = QUEEN;
                break;
            case 4:
                // king
                board->pieces[i].piece = KING;
                break;
        }
    }
}

void print_board(ChessBoard board) {
    int i;
    for (i = 0; i < 64; i++) {
        if (i % 8 == 0) {
            printf("\n +---+---+---+---+---+---+---+---+\n");
        }

        int piece_index;
        for (piece_index = 0; piece_index < board.num_pieces; piece_index++) {
            ChessPieceInstance piece = board.pieces[piece_index];

            if (piece.pos.row * 8 + piece.pos.col == i) {
                printf(" | %s ", PIECE_NAMES[piece.piece]);
                if (piece.player == WHITE) {
                    printf("(W)");
                } else {
                    printf("(B)");
                }
                break;
            }
        }

        if (piece_index == board.num_pieces) {
            printf(" |   ");
        }

        if (i % 8 == 7) {
            printf("|\n +---+---+---+---+---+---+---+---+");
        }
    }
    printf("\n");
}

ChessPieceInstance* get_piece_at_pos(ChessBoard board, ChessPos pos) {
    int i;
    for (i = 0; i < board.num_pieces; i++) {
        ChessPieceInstance* piece = &board.pieces[i];
        if (piece->pos.row == pos.row && piece->pos.col == pos.col) {
            return piece;
        }
    }

    return NULL;
}

int is_legal_move(ChessBoard board, ChessPieceInstance* piece, ChessPos to_pos) {
    int i;
    for (i = 0; i < board.num_pieces; i++) {
        ChessPieceInstance* other_piece = &board.pieces[i];

        if (other_piece == piece) {
            continue;
        }

        if (other_piece->pos.row == to_pos.row && other_piece->pos.col == to_pos.col) {
            if (piece->player == other_piece->player) {
                return 0; // can't move to a square occupied by a piece of the same color
            } else {
                return 1; // can capture other player's piece
            }
        }
    }

    return 1; // no piece at target position, legal move
}

int perform_move(ChessBoard* board, ChessMove move) {
    ChessPieceInstance* piece = get_piece_at_pos(*board, move.from_pos);

    if (!piece) {
        return 0; // no piece at starting position
    }

    if (!is_legal_move(*board, piece, move.to_pos)) {
        return 0; // illegal move
    }

    piece->pos = move.to_pos;
    return 1; // successful move
}

int main() {
    ChessBoard board;
    setup_board(&board);
    print_board(board);
    return 0;
}