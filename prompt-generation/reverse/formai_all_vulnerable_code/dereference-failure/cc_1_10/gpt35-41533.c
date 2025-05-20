//FormAI DATASET v1.0 Category: Chess AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define DEPTH_LIMIT 4

typedef struct {
    char piece_type;
    char color;
} Piece;

typedef struct {
    Piece **board;
    char turn;
    int depth;
    int score;
} Game;

int evaluate_board(Game *game) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j].piece_type == 'P') {
                score += game->board[i][j].color == 'W' ? 1 : -1;
            } else if (game->board[i][j].piece_type == 'R') {
                score += game->board[i][j].color == 'W' ? 5 : -5;
            } else if (game->board[i][j].piece_type == 'N') {
                score += game->board[i][j].color == 'W' ? 3 : -3;
            } else if (game->board[i][j].piece_type == 'B') {
                score += game->board[i][j].color == 'W' ? 3 : -3;
            } else if (game->board[i][j].piece_type == 'Q') {
                score += game->board[i][j].color == 'W' ? 9 : -9;
            } else if (game->board[i][j].piece_type == 'K') {
                score += game->board[i][j].color == 'W' ? 100 : -100;
            }
        }
    }
    return score;
}

void generate_possible_moves(Game *game, int *num_moves, int *moves) {
    int idx = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j].color != game->turn) {
                continue;
            }
            if (game->board[i][j].piece_type == 'P') {
                if (game->board[i][j].color == 'W') {
                    if (i == 1) {
                        moves[idx++] = i * 10 + j;
                        moves[idx++] = i + 2 * 10 + j;
                    } else {
                        moves[idx++] = i * 10 + j;
                        moves[idx++] = (game->board[i+1][j].piece_type == 0) ? i + 1 * 10 + j : i + 2 * 10 + j;
                    }
                } else {
                    if (i == 6) {
                        moves[idx++] = i * 10 + j;
                        moves[idx++] = i - 2 * 10 + j;
                    } else {
                        moves[idx++] = i * 10 + j;
                        moves[idx++] = (game->board[i-1][j].piece_type == 0) ? i - 1 * 10 + j : i - 2 * 10 + j;
                    }
                }
            }
            else if (game->board[i][j].piece_type == 'R') {
                for (int k = i+1; k < BOARD_SIZE && game->board[k][j].piece_type == 0; k++) {
                    moves[idx++] = i * 10 + j;
                    moves[idx++] = k * 10 + j;
                }
                for (int k = i-1; k >= 0 && game->board[k][j].piece_type == 0; k--) {
                    moves[idx++] = i * 10 + j;
                    moves[idx++] = k * 10 + j;
                }
                for (int k = j+1; k < BOARD_SIZE && game->board[i][k].piece_type == 0; k++) {
                    moves[idx++] = i * 10 + j;
                    moves[idx++] = i * 10 + k;
                }
                for (int k = j-1; k >= 0 && game->board[i][k].piece_type == 0; k--) {
                    moves[idx++] = i * 10 + j;
                    moves[idx++] = i * 10 + k;
                }
            }
            // Other pieces
        }
    }
    *num_moves = idx;
}

void make_move(Game *game, int move) {
    int i1 = move / 10, j1 = move % 10;
    int i2 = (move / 10) + 1, j2 = move % 10;
    game->board[i2][j2] = game->board[i1][j1];
    game->board[i1][j1].piece_type = 0;
    game->board[i1][j1].color = 0;
}

void take_back(Game *game, int move) {
    int i1 = move / 10, j1 = move % 10;
    int i2 = (move / 10) + 1, j2 = move % 10;
    game->board[i1][j1] = game->board[i2][j2];
    game->board[i2][j2].piece_type = 0;
    game->board[i2][j2].color = 0;
}

int minimax(Game *game, int alpha, int beta) {
    if (game->depth == DEPTH_LIMIT) {
        return evaluate_board(game);
    }
    int possible_moves[100];
    int num_moves = 0;
    generate_possible_moves(game, &num_moves, possible_moves);
    if (game->turn == 'W') {
        for (int i = 0; i < num_moves; i++) {
            make_move(game, possible_moves[i]);
            game->turn = 'B';
            game->depth++;
            int score = minimax(game, alpha, beta);
            game->depth--;
            game->turn = 'W';
            take_back(game, possible_moves[i]);
            if (score >= beta) {
                return beta;
            }
            if (score > alpha) {
                alpha = score;
            }
        }
        return alpha;
    } else {
        for (int i = 0; i < num_moves; i++) {
            make_move(game, possible_moves[i]);
            game->turn = 'W';
            game->depth++;
            int score = minimax(game, alpha, beta);
            game->depth--;
            game->turn = 'B';
            take_back(game, possible_moves[i]);
            if (score <= alpha) {
                return alpha;
            }
            if (score < beta) {
                beta = score;
            }
        }
        return beta;
    }
}

int get_best_move(Game *game) {
    int possible_moves[100];
    int num_moves = 0;
    generate_possible_moves(game, &num_moves, possible_moves);
    int max_score = -1000;
    int best_move = 0;
    for (int i = 0; i < num_moves; i++) {
        make_move(game, possible_moves[i]);
        game->turn = 'B';
        game->depth++;
        int score = minimax(game, -1000, 1000);
        game->depth--;
        game->turn = 'W';
        take_back(game, possible_moves[i]);
        if (score > max_score) {
            max_score = score;
            best_move = possible_moves[i];
        }
    }
    return best_move;
}

int main() {
    Piece **board = (Piece **) malloc(sizeof(Piece *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Piece*) malloc(sizeof(Piece) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].piece_type = 0;
            board[i][j].color = 0;
        }
    }
    // Set up board
    board[0][0].piece_type = 'R';
    board[0][0].color = 'B';
    board[0][1].piece_type = 'N';
    board[0][1].color = 'B';
    board[0][2].piece_type = 'B';
    board[0][2].color = 'B';
    board[0][3].piece_type = 'Q';
    board[0][3].color = 'B';
    board[0][4].piece_type = 'K';
    board[0][4].color = 'B';
    board[0][5].piece_type = 'B';
    board[0][5].color = 'B';
    board[0][6].piece_type = 'N';
    board[0][6].color = 'B';
    board[0][7].piece_type = 'R';
    board[0][7].color = 'B';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i].piece_type = 'P';
        board[1][i].color = 'B';
    }
    board[7][0].piece_type = 'R';
    board[7][0].color = 'W';
    board[7][1].piece_type = 'N';
    board[7][1].color = 'W';
    board[7][2].piece_type = 'B';
    board[7][2].color = 'W';
    board[7][3].piece_type = 'Q';
    board[7][3].color = 'W';
    board[7][4].piece_type = 'K';
    board[7][4].color = 'W';
    board[7][5].piece_type = 'B';
    board[7][5].color = 'W';
    board[7][6].piece_type = 'N';
    board[7][6].color = 'W';
    board[7][7].piece_type = 'R';
    board[7][7].color = 'W';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i].piece_type = 'P';
        board[6][i].color = 'W';
    }

    Game *game = (Game *) malloc(sizeof(Game));
    game->board = board;
    game->turn = 'W';
    game->depth = 0;
    game->score = evaluate_board(game);

    int best_move = get_best_move(game);
    printf("Best move: %d -> %d\n", best_move / 10, best_move % 10);
    
    return 0;
}