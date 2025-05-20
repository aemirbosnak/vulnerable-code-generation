//FormAI DATASET v1.0 Category: Chess AI ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef enum {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, EMPTY} PieceType;

typedef enum {BLACK, WHITE} PieceColor;

typedef struct {
    PieceType type;
    PieceColor color;
} Piece;

typedef struct {
    Piece *piece;
    int x;
    int y;
} Square;

void initialize_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    char row[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            Piece *piece = malloc(sizeof(Piece));
            if (i < 2) {
                piece->color = BLACK;
            } else if (i >= 6) {
                piece->color = WHITE;
            } else {
                piece = NULL;
            }
            if (i == 0) {
                switch (j) {
                    case 0:
                    case 7:
                        piece->type = ROOK;
                        break;
                    case 1:
                    case 6:
                        piece->type = KNIGHT;
                        break;
                    case 2:
                    case 5:
                        piece->type = BISHOP;
                        break;
                    case 3:
                        piece->type = QUEEN;
                        break;
                    case 4:
                        piece->type = KING;
                        break;
                    default:
                        piece = NULL;
                }
            } else if (i == 1 || i == 6) {
                piece->type = PAWN;
            }
            board[i][j].piece = piece;
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
}

void print_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            Piece *piece = board[i][j].piece;
            char icon;
            if (!piece) {
                icon = ' ';
            } else {
                switch (piece->type) {
                    case PAWN:
                        icon = 'P';
                        break;
                    case ROOK:
                        icon = 'R';
                        break;
                    case KNIGHT:
                        icon = 'N';
                        break;
                    case BISHOP:
                        icon = 'B';
                        break;
                    case QUEEN:
                        icon = 'Q';
                        break;
                    case KING:
                        icon = 'K';
                        break;
                    default:
                        icon = ' ';
                }
                if (piece->color == BLACK) {
                    icon += 32;
                }
            }
            printf("%c ", icon);
        }
        printf("\n");
    }
}

bool is_valid_move(Square board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    Piece *piece = board[x1][y1].piece;
    if (!piece) {
        return false;
    }
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    Piece *target = board[x2][y2].piece;
    if (target) {
        if (target->color == piece->color) {
            return false;
        }
    }
    switch (piece->type) {
        case PAWN:
            if (piece->color == WHITE) {
                if (y1 == y2 && x1 - x2 == 1 && !target) {
                    return true;
                }
                if (y1 == y2 - 1 && (x1 - x2 == 1 || x1 == 6) && target) {
                    return true;
                }
                if (y1 == y2 + 1 && (x1 - x2 == 1 || x1 == 6) && target) {
                    return true;
                }
            } else {
                if (y1 == y2 && x2 - x1 == 1 && !target) {
                    return true;
                }
                if (y1 == y2 - 1 && (x2 - x1 == 1 || x1 == 1) && target && target->color != piece->color) {
                    return true;
                }
                if (y1 == y2 + 1 && (x2 - x1 == 1 || x1 == 1) && target && target->color != piece->color) {
                    return true;
                }
            }
            break;
        case ROOK:
            if (x1 == x2 || y1 == y2) {
                if (x1 == x2 && y2 < y1) {
                    int i;
                    for (i = y1-1; i > y2; i--) {
                        if (board[x1][i].piece) {
                            return false;
                        }
                    }
                }
                if (x1 == x2 && y2 > y1) {
                    int i;
                    for (i = y1+1; i < y2; i++) {
                        if (board[x1][i].piece) {
                            return false;
                        }
                    }
                }
                if (y1 == y2 && x2 < x1) {
                    int i;
                    for (i = x1-1; i > x2; i--) {
                        if (board[i][y1].piece) {
                            return false;
                        }
                    }
                }
                if (y1 == y2 && x2 > x1) {
                    int i;
                    for (i = x1+1; i < x2; i++) {
                        if (board[i][y1].piece) {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case KNIGHT:
            if (x2 == x1+1 && y2 == y1+2) return true;
            if (x2 == x1+2 && y2 == y1+1) return true;
            if (x2 == x1+2 && y2 == y1-1) return true;
            if (x2 == x1+1 && y2 == y1-2) return true;
            if (x2 == x1-1 && y2 == y1-2) return true;
            if (x2 == x1-2 && y2 == y1-1) return true;
            if (x2 == x1-2 && y2 == y1+1) return true;
            if (x2 == x1-1 && y2 == y1+2) return true;
            break;
        case BISHOP:
            if (abs(x2 - x1) == abs(y2 - y1)) {
                int i, j;
                int x_diff = x2 - x1;
                int y_diff = y2 - y1;
                if (x_diff > 0 && y_diff > 0) {
                    for (i = x1+1, j = y1+1; i < x2; i++, j++) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                if (x_diff > 0 && y_diff < 0) {
                    for (i = x1+1, j = y1-1; i < x2; i++, j--) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                if (x_diff < 0 && y_diff < 0) {
                    for (i = x1-1, j = y1-1; i > x2; i--, j--) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                if (x_diff < 0 && y_diff > 0) {
                    for (i = x1-1, j = y1+1; i > x2; i--, j++) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case QUEEN:
            if (x1 == x2 || y1 == y2) {
                if (x1 == x2 && y2 < y1) {
                    int i;
                    for (i = y1-1; i > y2; i--) {
                        if (board[x1][i].piece) {
                            return false;
                        }
                    }
                }
                if (x1 == x2 && y2 > y1) {
                    int i;
                    for (i = y1+1; i < y2; i++) {
                        if (board[x1][i].piece) {
                            return false;
                        }
                    }
                }
                if (y1 == y2 && x2 < x1) {
                    int i;
                    for (i = x1-1; i > x2; i--) {
                        if (board[i][y1].piece) {
                            return false;
                        }
                    }
                }
                if (y1 == y2 && x2 > x1) {
                    int i;
                    for (i = x1+1; i < x2; i++) {
                        if (board[i][y1].piece) {
                            return false;
                        }
                    }
                }
                return true;
            }
            if (abs(x2 - x1) == abs(y2 - y1)) {
                int i, j;
                int x_diff = x2 - x1;
                int y_diff = y2 - y1;
                if (x_diff > 0 && y_diff > 0) {
                    for (i = x1+1, j = y1+1; i < x2; i++, j++) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                if (x_diff > 0 && y_diff < 0) {
                    for (i = x1+1, j = y1-1; i < x2; i++, j--) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                if (x_diff < 0 && y_diff < 0) {
                    for (i = x1-1, j = y1-1; i > x2; i--, j--) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                if (x_diff < 0 && y_diff > 0) {
                    for (i = x1-1, j = y1+1; i > x2; i--, j++) {
                        if (board[i][j].piece) {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case KING:
            if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) {
                return false;
            }
            return true;
            break;
        default:
            return false;
    }
    return false;
}

int score_position(Square board[BOARD_SIZE][BOARD_SIZE]) {
    int score = 0;
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            Piece *piece = board[i][j].piece;
            if (piece && piece->color == BLACK) {
                switch (piece->type) {
                    case PAWN:
                        score -= 1;
                        break;
                    case ROOK:
                        score -= 5;
                        break;
                    case KNIGHT:
                        score -= 3;
                        break;
                    case BISHOP:
                        score -= 3;
                        break;
                    case QUEEN:
                        score -= 9;
                        break;
                    case KING:
                        score -= 100;
                        break;
                }
            }
            if (piece && piece->color == WHITE) {
                switch (piece->type) {
                    case PAWN:
                        score += 1;
                        break;
                    case ROOK:
                        score += 5;
                        break;
                    case KNIGHT:
                        score += 3;
                        break;
                    case BISHOP:
                        score += 3;
                        break;
                    case QUEEN:
                        score += 9;
                        break;
                    case KING:
                        score += 100;
                        break;
                }
            }
        }
    }
    return score;
}

int minimax(Square board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, bool is_maximizing) {
    int i, j;
    if (depth == 0) {
        return score_position(board);
    }
    if (is_maximizing) {
        int max_score = -1000;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].piece && board[i][j].piece->color == WHITE) {
                    int k, l;
                    for (k = 0; k < BOARD_SIZE; k++) {
                        for (l = 0; l < BOARD_SIZE; l++) {
                            if (is_valid_move(board, i, j, k, l)) {
                                Piece *temp = board[k][l].piece;
                                board[k][l].piece = board[i][j].piece;
                                board[i][j].piece = NULL;
                                int score = minimax(board, depth-1, alpha, beta, false);
                                if (score > max_score) {
                                    max_score = score;
                                }
                                alpha = alpha > max_score ? alpha : max_score;
                                board[i][j].piece = board[k][l].piece;
                                board[k][l].piece = temp;
                                if (beta <= alpha) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return max_score;
    } else {
        int min_score = 1000;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].piece && board[i][j].piece->color == BLACK) {
                    int k, l;
                    for (k = 0; k < BOARD_SIZE; k++) {
                        for (l = 0; l < BOARD_SIZE; l++) {
                            if (is_valid_move(board, i, j, k, l)) {
                                Piece *temp = board[k][l].piece;
                                board[k][l].piece = board[i][j].piece;
                                board[i][j].piece = NULL;
                                int score = minimax(board, depth-1, alpha, beta, true);
                                if (score < min_score) {
                                    min_score = score;
                                }
                                beta = beta < min_score ? beta : min_score;
                                board[i][j].piece = board[k][l].piece;
                                board[k][l].piece = temp;
                                if (beta <= alpha) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return min_score;
    }
}

int main() {
    Square board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    printf("\n");
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].piece && board[i][j].piece->color == WHITE) {
                int k, l;
                for (k = 0; k < BOARD_SIZE; k++) {
                    for (l = 0; l < BOARD_SIZE; l++) {
                        if (is_valid_move(board, i, j, k, l)) {
                            Piece *temp = board[k][l].piece;
                            board[k][l].piece = board[i][j].piece;
                            board[i][j].piece = NULL;
                            int score = minimax(board, 3, -1000, 1000, false);
                            board[i][j].piece = board[k][l].piece;
                            board[k][l].piece = temp;
                            printf("(%d,%d) -> (%d,%d): %d\n", i, j, k, l, score);
                        }
                    }
                }
            }
        }
    }
    return 0;
}