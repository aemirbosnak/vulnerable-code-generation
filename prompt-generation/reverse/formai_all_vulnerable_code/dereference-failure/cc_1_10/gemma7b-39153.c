//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int row;
    int col;
    struct Node* next;
} Node;

typedef struct Game {
    Node** board;
    int current_player;
    int game_over;
    struct Game* next;
} Game;

Game* create_game() {
    Game* game = malloc(sizeof(Game));
    game->board = malloc(sizeof(Node*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[i] = malloc(sizeof(Node));
        game->board[i]->row = i;
        game->board[i]->col = -1;
        game->board[i]->next = NULL;
    }
    game->current_player = 1;
    game->game_over = 0;
    game->next = NULL;
    return game;
}

void make_move(Game* game, int row, int col) {
    if (game->board[row]->col != -1) {
        return;
    }
    game->board[row]->col = game->current_player;
    game->current_player = (game->current_player == 1) ? 2 : 1;
}

int check_game_over(Game* game) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (game->board[r]->col == game->board[r + 1]->col &&
            game->board[r]->col == game->board[r + 2]->col &&
            game->board[r]->col != -1) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (game->board[0]->col == game->board[1]->col &&
            game->board[0]->col == game->board[2]->col &&
            game->board[0]->col != -1) {
            return 1;
        }
    }

    // Check diagonals
    if (game->board[0]->col == game->board[1]->col &&
        game->board[0]->col == game->board[2]->col &&
        game->board[0]->col != -1) {
        return 1;
    }

    // If all cells are occupied and no winner, game is over
    return 0;
}

void play_game() {
    Game* game = create_game();

    // Game loop
    while (!game->game_over) {
        int row, col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &row, &col);
        make_move(game, row, col);

        // Check if game is over
        if (check_game_over(game)) {
            game->game_over = 1;
            printf("Game over! The winner is player %d.\n", game->current_player);
        }
    }

    free(game->board);
    free(game);
}

int main() {
    play_game();

    return 0;
}