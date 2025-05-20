//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 21
#define PADDLE_SIZE 5

// Define the board structure
typedef struct Board {
    int **grid;
    int score1;
    int score2;
    int ball_x;
    int ball_y;
    int paddle1_x;
    int paddle1_y;
    int paddle2_x;
    int paddle2_y;
} Board;

// Function to initialize the board
void init_board(Board *board) {
    board->grid = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->grid[i] = malloc(BOARD_SIZE * sizeof(int));
    }

    board->score1 = 0;
    board->score2 = 0;
    board->ball_x = BOARD_SIZE / 2;
    board->ball_y = BOARD_SIZE - 1;
    board->paddle1_x = 0;
    board->paddle1_y = BOARD_SIZE - 1;
    board->paddle2_x = BOARD_SIZE - 1;
    board->paddle2_y = BOARD_SIZE - 1;
}

// Function to move the paddle
void move_paddle(Board *board, int direction) {
    switch (direction) {
        case 0:
            board->paddle1_y--;
            break;
        case 1:
            board->paddle1_y++;
            break;
    }

    // Keep the paddle within the bounds of the board
    if (board->paddle1_y < 0) {
        board->paddle1_y = 0;
    } else if (board->paddle1_y >= BOARD_SIZE - PADDLE_SIZE) {
        board->paddle1_y = BOARD_SIZE - PADDLE_SIZE;
    }
}

// Function to move the ball
void move_ball(Board *board) {
    int dx = rand() % 2 - 1;
    int dy = rand() % 2 - 1;

    board->ball_x += dx;
    board->ball_y += dy;

    // Keep the ball within the bounds of the board
    if (board->ball_x < 0) {
        board->ball_x = 0;
    } else if (board->ball_x >= BOARD_SIZE) {
        board->ball_x = BOARD_SIZE - 1;
    }

    if (board->ball_y < 0) {
        board->ball_y = 0;
    } else if (board->ball_y >= BOARD_SIZE) {
        board->ball_y = BOARD_SIZE - 1;
    }
}

// Function to check if the ball has hit the paddle
int has_ball_hit_paddle(Board *board) {
    // Check if the ball has hit the paddle1
    if (board->ball_x >= board->paddle1_x && board->ball_x <= board->paddle1_x + PADDLE_SIZE && board->ball_y == board->paddle1_y) {
        return 1;
    }

    // Check if the ball has hit the paddle2
    if (board->ball_x <= board->paddle2_x && board->ball_x >= board->paddle2_x - PADDLE_SIZE && board->ball_y == board->paddle2_y) {
        return 1;
    }

    return 0;
}

// Function to update the board
void update_board(Board *board) {
    // Move the ball
    move_ball(board);

    // Check if the ball has hit the paddle
    if (has_ball_hit_paddle(board)) {
        // Bounce the ball off the paddle
        board->ball_y *= -1;
    }

    // Increment the score if the ball reaches the end of the board
    if (board->ball_x == 0) {
        board->score1++;
    } else if (board->ball_x == BOARD_SIZE - 1) {
        board->score2++;
    }
}

int main() {
    Board board;
    init_board(&board);

    // Play the game
    while (!board.score1 || !board.score2) {
        update_board(&board);

        // Display the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%d ", board.grid[i][j]);
            }
            printf("\n");
        }

        // Display the score
        printf("Score: %d - %d\n", board.score1, board.score2);
    }

    // End the game
    printf("Game over! The winner is: ");
    if (board.score1 > board.score2) {
        printf("Player 1\n");
    } else if (board.score2 > board.score1) {
        printf("Player 2\n");
    } else {
        printf("It's a draw\n");
    }

    return 0;
}