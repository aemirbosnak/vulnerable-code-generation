//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a table game
typedef struct {
    int width;
    int height;
    int** board;
} Game;

// Function to initialize the game board
void init_game(Game* game, int width, int height) {
    game->width = width;
    game->height = height;
    game->board = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        game->board[i] = (int*)malloc(width * sizeof(int));
    }
}

// Function to print the game board
void print_game(Game* game) {
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            printf("%d ", game->board[i][j]);
        }
        printf("\n");
    }
}

// Function to play a turn in the game
void play_turn(Game* game, int row, int col) {
    game->board[row][col] = 1;
}

// Function to check if a player has won the game
int is_game_won(Game* game) {
    // Check for horizontal wins
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width - 3; j++) {
            if (game->board[i][j] == game->board[i][j + 1] && game->board[i][j + 1] == game->board[i][j + 2] && game->board[i][j + 2] == game->board[i][j + 3]) {
                return 1;
            }
        }
    }

    // Check for vertical wins
    for (int i = 0; i < game->width; i++) {
        for (int j = 0; j < game->height - 3; j++) {
            if (game->board[j][i] == game->board[j + 1][i] && game->board[j + 1][i] == game->board[j + 2][i] && game->board[j + 2][i] == game->board[j + 3][i]) {
                return 1;
            }
        }
    }

    // Check for diagonal wins
    for (int i = 0; i < game->height - 3; i++) {
        for (int j = 0; j < game->width - 3; j++) {
            if (game->board[i][j] == game->board[i + 1][j + 1] && game->board[i + 1][j + 1] == game->board[i + 2][j + 2] && game->board[i + 2][j + 2] == game->board[i + 3][j + 3]) {
                return 1;
            }
        }
    }

    // Check for diagonal wins
    for (int i = 0; i < game->height - 3; i++) {
        for (int j = 0; j < game->width - 3; j++) {
            if (game->board[i][j] == game->board[i + 1][j + 1] && game->board[i + 1][j + 1] == game->board[i + 2][j + 2] && game->board[i + 2][j + 2] == game->board[i + 3][j + 3]) {
                return 1;
            }
        }
    }

    return 0;
}

// Main function
int main() {
    Game game;
    init_game(&game, 3, 3);
    printf("Game board:\n");
    print_game(&game);

    play_turn(&game, 0, 0);
    play_turn(&game, 0, 1);
    play_turn(&game, 1, 1);
    play_turn(&game, 1, 0);
    play_turn(&game, 0, 2);

    printf("\nIs the game won? %d\n", is_game_won(&game));

    return 0;
}