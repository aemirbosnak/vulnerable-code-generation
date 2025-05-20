//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MEMORY_GAME_SIZE 10
#define MEMORY_GAME_ROWS 4
#define MEMORY_GAME_COLS 4

typedef struct memory_game_t {
    char** grid;
    int row_size;
    int col_size;
    int current_row;
    int current_col;
} memory_game_t;

void init_memory_game(memory_game_t* game) {
    game->grid = (char**) malloc(MEMORY_GAME_SIZE * sizeof(char*));
    for (int i = 0; i < MEMORY_GAME_SIZE; i++) {
        game->grid[i] = (char*) malloc(MEMORY_GAME_ROWS * sizeof(char));
        for (int j = 0; j < MEMORY_GAME_ROWS; j++) {
            game->grid[i][j] = '?';
        }
    }
    game->row_size = MEMORY_GAME_ROWS;
    game->col_size = MEMORY_GAME_COLS;
    game->current_row = 0;
    game->current_col = 0;
}

void print_memory_game(memory_game_t* game) {
    for (int i = 0; i < MEMORY_GAME_SIZE; i++) {
        for (int j = 0; j < MEMORY_GAME_ROWS; j++) {
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }
}

void move_up(memory_game_t* game) {
    if (game->current_row > 0) {
        game->current_row--;
        game->current_col = (game->current_col + game->row_size - 1) % game->row_size;
    }
}

void move_down(memory_game_t* game) {
    if (game->current_row < MEMORY_GAME_ROWS - 1) {
        game->current_row++;
        game->current_col = (game->current_col + game->row_size - 1) % game->row_size;
    }
}

void move_left(memory_game_t* game) {
    if (game->current_col > 0) {
        game->current_col--;
        game->current_row = (game->current_row + game->col_size - 1) % game->col_size;
    }
}

void move_right(memory_game_t* game) {
    if (game->current_col < MEMORY_GAME_COLS - 1) {
        game->current_col++;
        game->current_row = (game->current_row + game->col_size - 1) % game->col_size;
    }
}

void reveal_cell(memory_game_t* game, int row, int col) {
    if (row < MEMORY_GAME_ROWS && col < MEMORY_GAME_COLS) {
        game->grid[row][col] = '!';
    }
}

int main() {
    srand(time(NULL));
    memory_game_t* game = (memory_game_t*) malloc(sizeof(memory_game_t));
    init_memory_game(game);

    while (1) {
        print_memory_game(game);
        char command = getchar();
        if (command == 'q') {
            break;
        }
        if (command == 'u') {
            move_up(game);
        } else if (command == 'd') {
            move_down(game);
        } else if (command == 'l') {
            move_left(game);
        } else if (command == 'r') {
            move_right(game);
        } else if (command == '!') {
            reveal_cell(game, game->current_row, game->current_col);
        }
    }

    free(game->grid);
    return 0;
}