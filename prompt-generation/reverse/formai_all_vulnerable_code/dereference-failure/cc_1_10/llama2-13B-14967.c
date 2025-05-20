//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MEMORY_GAME_SIZE 10
#define MEMORY_GAME_ROWS 4
#define MEMORY_GAME_COLS 4

typedef struct memory_game_t {
    char **grid;
    int row_size;
    int col_size;
    int current_row;
    int current_col;
} memory_game_t;

void init_game(memory_game_t *game) {
    game->grid = (char **) malloc(MEMORY_GAME_SIZE * sizeof(char *));
    for (int i = 0; i < MEMORY_GAME_SIZE; i++) {
        game->grid[i] = (char *) malloc(MEMORY_GAME_ROWS * sizeof(char));
        for (int j = 0; j < MEMORY_GAME_ROWS; j++) {
            game->grid[i][j] = ' ';
        }
    }
    game->row_size = MEMORY_GAME_ROWS;
    game->col_size = MEMORY_GAME_COLS;
    game->current_row = 0;
    game->current_col = 0;
}

void print_grid(memory_game_t *game) {
    for (int i = 0; i < MEMORY_GAME_SIZE; i++) {
        for (int j = 0; j < MEMORY_GAME_ROWS; j++) {
            printf("%c", game->grid[i][j]);
        }
        printf("\n");
    }
}

void move_up(memory_game_t *game) {
    if (game->current_row > 0) {
        game->current_row -= 1;
        game->current_col = (game->current_col + game->row_size - 1) % game->row_size;
        print_grid(game);
    }
}

void move_down(memory_game_t *game) {
    if (game->current_row < MEMORY_GAME_ROWS - 1) {
        game->current_row += 1;
        game->current_col = (game->current_col + game->row_size - 1) % game->row_size;
        print_grid(game);
    }
}

void move_left(memory_game_t *game) {
    if (game->current_col > 0) {
        game->current_col -= 1;
        game->current_row = (game->current_row + game->col_size - 1) % game->col_size;
        print_grid(game);
    }
}

void move_right(memory_game_t *game) {
    if (game->current_col < MEMORY_GAME_COLS - 1) {
        game->current_col += 1;
        game->current_row = (game->current_row + game->col_size - 1) % game->col_size;
        print_grid(game);
    }
}

void show_memory(memory_game_t *game) {
    print_grid(game);
}

int main() {
    memory_game_t game;
    init_game(&game);
    srand(time(NULL));
    for (int i = 0; i < MEMORY_GAME_SIZE; i++) {
        for (int j = 0; j < MEMORY_GAME_ROWS; j++) {
            game.grid[i][j] = 'A' + (rand() % 26);
        }
    }
    show_memory(&game);
    move_down(&game);
    move_down(&game);
    move_down(&game);
    move_down(&game);
    move_up(&game);
    move_up(&game);
    move_up(&game);
    move_up(&game);
    return 0;
}