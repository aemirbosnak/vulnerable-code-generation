//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

typedef struct GameData {
    int **board;
    int player_turn;
    int score_a;
    int score_b;
    int game_state;
} GameData;

void InitializeGame(GameData *game_data) {
    game_data->board = (int **)malloc(MAX_HEIGHT * sizeof(int *));
    for (int h = 0; h < MAX_HEIGHT; h++) {
        game_data->board[h] = (int *)malloc(MAX_WIDTH * sizeof(int));
        for (int w = 0; w < MAX_WIDTH; w++) {
            game_data->board[h][w] = 0;
        }
    }

    game_data->player_turn = 1;
    game_data->score_a = 0;
    game_data->score_b = 0;
    game_data->game_state = 0;
}

void PlayGame(GameData *game_data) {
    // Game loop
    while (game_data->game_state == 0) {
        // Get player move
        int row, column;
        printf("Enter row and column (1-50): ");
        scanf("%d %d", &row, &column);

        // Validate move
        if (row < 1 || row > MAX_HEIGHT || column < 1 || column > MAX_WIDTH) {
            printf("Invalid move.\n");
            continue;
        }

        // Place piece
        game_data->board[row - 1][column - 1] = game_data->player_turn;

        // Check if player won
        if (CheckWin(game_data) == game_data->player_turn) {
            game_data->game_state = 1;
            printf("Congratulations! You won!\n");
        } else {
            // Next turn
            game_data->player_turn *= -1;
        }
    }

    // Game over
    printf("Game over. Final score:\n");
    printf("Player A: %d\n", game_data->score_a);
    printf("Player B: %d\n", game_data->score_b);
}

int CheckWin(GameData *game_data) {
    // Check rows
    for (int h = 0; h < MAX_HEIGHT; h++) {
        for (int w = 0; w < MAX_WIDTH; w++) {
            if (game_data->board[h][w] * 3 == game_data->player_turn) {
                return game_data->player_turn;
            }
        }
    }

    // Check columns
    for (int w = 0; w < MAX_WIDTH; w++) {
        for (int h = 0; h < MAX_HEIGHT; h++) {
            if (game_data->board[h][w] * 3 == game_data->player_turn) {
                return game_data->player_turn;
            }
        }
    }

    // Check diagonals
    for (int d = 0; d < MAX_HEIGHT; d++) {
        for (int r = 0; r < MAX_WIDTH; r++) {
            if (game_data->board[r][d] * 3 == game_data->player_turn) {
                return game_data->player_turn;
            }
        }
    }

    // No win
    return 0;
}

int main() {
    // Allocate game data
    GameData game_data;
    InitializeGame(&game_data);

    // Play the game
    PlayGame(&game_data);

    return 0;
}