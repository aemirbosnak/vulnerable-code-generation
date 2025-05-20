//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20

void draw(int **board, int x, int y) {
    printf("  ");
    for (int i = 0; i < x; i++) {
        printf("%c ", board[y][i] == 0 ? '.' : '_');
    }
    printf("\n");
}

int main() {
    int **board = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        board[i] = malloc(WIDTH * sizeof(int));
    }

    int player_x = 3;
    int player_y = 0;

    int ai_x = WIDTH - 1;
    int ai_y = HEIGHT - 1;

    int score_player = 0;
    int score_ai = 0;

    srand(time(NULL));

    // Game loop
    while (score_player < 5 && score_ai < 5) {
        // Player's turn
        draw(board, WIDTH, HEIGHT);
        printf("Enter your move (x, y): ");
        int move_x, move_y;
        scanf("%d %d", &move_x, &move_y);

        // Validate move
        if (move_x < 0 || move_x >= WIDTH || move_y < 0 || move_y >= HEIGHT) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the paddle
        board[move_y][move_x] = 1;

        // AI's turn
        int ai_move_x = rand() % WIDTH;
        int ai_move_y = ai_y - 1;

        // Move the AI paddle
        board[ai_move_y][ai_move_x] = 2;

        // Check if the AI has won
        if (board[ai_move_y][ai_move_x] == 2) {
            score_ai++;
            printf("AI wins!\n");
        }

        // Check if the player has won
        if (board[move_y][move_x] == 1) {
            score_player++;
            printf("You win!\n");
        }
    }

    // End game
    draw(board, WIDTH, HEIGHT);
    printf("Game over! Final score: %d - %d\n", score_player, score_ai);

    for (int i = 0; i < HEIGHT; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}