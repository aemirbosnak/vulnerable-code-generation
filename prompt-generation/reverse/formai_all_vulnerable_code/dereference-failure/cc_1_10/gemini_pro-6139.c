//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef enum { X, O, EMPTY } CellState;

typedef struct {
    CellState cells[9];
    CellState turn;
    int depth;
    int score;
} GameState;

GameState* create_game_state() {
    GameState* game_state = malloc(sizeof(GameState));
    for (int i = 0; i < 9; i++) {
        game_state->cells[i] = EMPTY;
    }
    game_state->turn = X;
    game_state->depth = 0;
    game_state->score = 0;
    return game_state;
}

void destroy_game_state(GameState* game_state) {
    free(game_state);
}

void print_game_state(GameState* game_state) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CellState cell_state = game_state->cells[i * 3 + j];
            printf("%c ", cell_state == X ? 'X' : (cell_state == O ? 'O' : '.'));
        }
        printf("\n");
    }
    printf("\n");
}

int evaluate_game_state(GameState* game_state) {
    int winning_lines[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        int line[3] = {winning_lines[i][0], winning_lines[i][1], winning_lines[i][2]};
        if (game_state->cells[line[0]] != EMPTY && game_state->cells[line[0]] == game_state->cells[line[1]] && game_state->cells[line[1]] == game_state->cells[line[2]]) {
            return game_state->cells[line[0]] == X ? 10 : -10;
        }
    }

    int empty_cells = 0;
    for (int i = 0; i < 9; i++) {
        if (game_state->cells[i] == EMPTY) {
            empty_cells++;
        }
    }

    return empty_cells > 0 ? 0 : 1;
}

int min_max(GameState* game_state, int depth, int alpha, int beta) {
    int best_score = game_state->turn == X ? -1000 : 1000;
    int best_move = -1;

    for (int i = 0; i < 9; i++) {
        if (game_state->cells[i] == EMPTY) {
            game_state->cells[i] = game_state->turn;
            game_state->depth = depth + 1;
            int score = -min_max(game_state, depth + 1, -beta, -alpha);
            game_state->cells[i] = EMPTY;

            if (game_state->turn == X) {
                if (score > best_score) {
                    best_score = score;
                    best_move = i;
                }
                alpha = fmax(alpha, score);
            } else {
                if (score < best_score) {
                    best_score = score;
                    best_move = i;
                }
                beta = fmin(beta, score);
            }

            if (alpha >= beta) {
                break;
            }
        }
    }

    return best_move;
}

int main() {
    GameState* game_state = create_game_state();
    int game_over = 0;

    while (!game_over) {
        print_game_state(game_state);

        if (game_state->turn == X) {
            int move = min_max(game_state, 0, -1000, 1000);
            game_state->cells[move] = X;
            game_state->turn = O;
        } else {
            int row, col;
            printf("Enter your move (row, col): ");
            scanf("%d %d", &row, &col);
            int move = row * 3 + col;
            game_state->cells[move] = O;
            game_state->turn = X;
        }

        game_over = evaluate_game_state(game_state) != 0;
    }

    print_game_state(game_state);

    if (game_state->score == 10) {
        printf("X wins!\n");
    } else if (game_state->score == -10) {
        printf("O wins!\n");
    } else {
        printf("Tie!\n");
    }

    destroy_game_state(game_state);
    return 0;
}