//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define PADDLE_SIZE 5

// Define the paddle structure
typedef struct Paddle {
    int x;
    int y;
    int direction;
} Paddle;

// Function to initialize the paddles
void initialize_paddles(Paddle *p1, Paddle *p2) {
    p1->x = BOARD_SIZE / 2 - PADDLE_SIZE / 2;
    p1->y = BOARD_SIZE - PADDLE_SIZE - 1;
    p1->direction = 0;

    p2->x = BOARD_SIZE / 2 + PADDLE_SIZE / 2;
    p2->y = 0;
    p2->direction = 1;
}

// Function to move the paddles
void move_paddles(Paddle *p1, Paddle *p2) {
    if (p1->direction == 0) {
        p1->y--;
    } else if (p1->direction == 1) {
        p1->y++;
    }

    if (p2->direction == 0) {
        p2->y--;
    } else if (p2->direction == 1) {
        p2->y++;
    }
}

// Function to update the ball
void update_ball(int *x, int *y) {
    *x++;
    *y--;

    if (*x >= BOARD_SIZE - 1) {
        *x = BOARD_SIZE - 2;
        *y = rand() % BOARD_SIZE;
    } else if (*x <= 0) {
        *x = 0;
        *y = rand() % BOARD_SIZE;
    }
}

// Main game loop
int main() {
    // Initialize the paddles
    Paddle p1;
    Paddle p2;
    initialize_paddles(&p1, &p2);

    // Initialize the ball
    int ball_x = BOARD_SIZE / 2;
    int ball_y = BOARD_SIZE - 1;

    // Game loop
    while (1) {
        // Move the paddles
        move_paddles(&p1, &p2);

        // Update the ball
        update_ball(&ball_x, &ball_y);

        // Check if the ball has hit a paddle
        if (ball_x >= p1.x && ball_x <= p1.x + PADDLE_SIZE && ball_y == p1.y) {
            ball_x--;
            ball_y = rand() % BOARD_SIZE;
        } else if (ball_x <= p2.x && ball_x >= p2.x - PADDLE_SIZE && ball_y == p2.y) {
            ball_x++;
            ball_y = rand() % BOARD_SIZE;
        }

        // Print the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (i == ball_x && j == ball_y) {
                    printf("O ");
                } else if (i == p1.x && j == p1.y) {
                    printf("P ");
                } else if (i == p2.x && j == p2.y) {
                    printf("P ");
                } else {
                    printf(". ");
                }
            }

            printf("\n");
        }

        // Check if the player has won or lost
        if (ball_x >= BOARD_SIZE - 1) {
            printf("Player 1 won!");
            break;
        } else if (ball_x <= 0) {
            printf("Player 2 won!");
            break;
        }
    }

    return 0;
}