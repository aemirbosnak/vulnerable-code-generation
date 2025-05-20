//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10
#define PADDLE_WIDTH 4
#define PADDLE_HEIGHT 1
#define BALL_WIDTH 1

typedef struct {
    int x; // Ball X Position
    int y; // Ball Y Position
    int dx; // Ball X Direction
    int dy; // Ball Y Direction
} Ball;

typedef struct {
    int x; // Paddle X Position
} Paddle;

void draw_board(Ball ball, Paddle paddle, int bricks[BOARD_WIDTH][BOARD_HEIGHT]) {
    system("clear");
    for (int y = 0; y <= BOARD_HEIGHT; y++) {
        for (int x = 0; x <= BOARD_WIDTH; x++) {
            // Draw bricks
            if (y < 3 && bricks[x][y] == 1) {
                printf("#"); // Brick
            }
            // Draw the ball
            else if (x == ball.x && y == ball.y) {
                printf("O"); // Ball
            }
            // Draw the paddle
            else if (y == BOARD_HEIGHT && x >= paddle.x && x < paddle.x + PADDLE_WIDTH) {
                printf("-"); // Paddle
            } 
            // Draw space
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int key_pressed(void) {
    struct termios oldt, newt;
    int oldf;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        return ch;
    }
    return -1;
}

void init_bricks(int bricks[BOARD_WIDTH][BOARD_HEIGHT]) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < 3; y++) {
            bricks[x][y] = 1; // All bricks are initialized
        }
    }
}

int main() {
    Ball ball = { BOARD_WIDTH / 2, BOARD_HEIGHT - 2, 1, -1 };
    Paddle paddle = { BOARD_WIDTH / 2 - PADDLE_WIDTH / 2 };
    int bricks[BOARD_WIDTH][BOARD_HEIGHT];
    int game_over = 0;

    init_bricks(bricks);

    while (!game_over) {
        draw_board(ball, paddle, bricks);

        ball.x += ball.dx;
        ball.y += ball.dy;

        // Bounce off the walls
        if (ball.x <= 0 || ball.x >= BOARD_WIDTH) {
            ball.dx = -ball.dx;
        }
        if (ball.y <= 0) {
            ball.dy = -ball.dy;
        }

        // Bounce off the paddle
        if (ball.y == BOARD_HEIGHT && ball.x >= paddle.x && ball.x < paddle.x + PADDLE_WIDTH) {
            ball.dy = -ball.dy;
        }

        // Check for brick collision
        if (ball.y < 3 && bricks[ball.x][ball.y] == 1) {
            bricks[ball.x][ball.y] = 0; // Remove brick
            ball.dy = -ball.dy; // Bounce the ball
        }

        // Check if ball falls below paddle
        if (ball.y > BOARD_HEIGHT) {
            game_over = 1;
        }

        // Control paddle movement
        int key = key_pressed();
        if (key == 'a' && paddle.x > 0) {
            paddle.x--; // Move left
        } else if (key == 'd' && paddle.x < BOARD_WIDTH - PADDLE_WIDTH) {
            paddle.x++; // Move right
        }

        usleep(100000); // Control game speed
    }

    printf("Game Over! You lost.\n");
    return 0;
}