//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_GAME_SIZE 10
#define MEMORY_GAME_ROWS 4
#define MEMORY_GAME_COLS 4

typedef struct memory_game_t {
    char **board;
    int row_size;
    int col_size;
    int current_row;
    int current_col;
} memory_game_t;

void init_memory_game(memory_game_t *game) {
    game->board = (char **)calloc(MEMORY_GAME_ROWS, sizeof(char *));
    for (int i = 0; i < MEMORY_GAME_ROWS; i++) {
        game->board[i] = (char *)calloc(MEMORY_GAME_COLS, sizeof(char));
    }
    game->row_size = MEMORY_GAME_COLS;
    game->col_size = MEMORY_GAME_COLS;
    game->current_row = 0;
    game->current_col = 0;
}

void print_memory_game(memory_game_t *game) {
    for (int i = 0; i < MEMORY_GAME_ROWS; i++) {
        for (int j = 0; j < MEMORY_GAME_COLS; j++) {
            printf("%c", game->board[i][j]);
        }
        printf("\n");
    }
}

void update_memory_game(memory_game_t *game) {
    char guess = getchar();
    if (guess == '\n') {
        guess = 0;
    }
    if (game->board[game->current_row][game->current_col] == guess) {
        game->current_col++;
        if (game->current_col == game->row_size) {
            game->current_row++;
            game->current_col = 0;
        }
    } else {
        game->current_col = 0;
        game->current_row++;
    }
}

int main() {
    memory_game_t game;
    init_memory_game(&game);

    for (int i = 0; i < MEMORY_GAME_SIZE; i++) {
        update_memory_game(&game);
        print_memory_game(&game);
    }

    return 0;
}