//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>

#define BOARD_WIDTH 70
#define BOARD_HEIGHT 20
#define BALL_INITIAL_X BOARD_WIDTH / 2
#define BALL_INITIAL_Y BOARD_HEIGHT / 2
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1
#define PADDLE_TOP_MARGIN 1
#define PADDLE_BOTTOM_MARGIN 1
#define BALL_INITIAL_SPEED 1
#define PADDLE_SPEED 1
#define BALL_LEFT -1
#define BALL_RIGHT 1
#define BALL_UP -1
#define BALL_DOWN 1
#define KB_UP_KEY 65
#define KB_DOWN_KEY 66
#define KB_ESC_KEY 27

typedef struct {
    int x;
    int y;
    int speedX;
    int speedY;
} Ball;

typedef struct {
    int x;
    int y;
    int score;
} Paddle;

int kbhit(void);
void resetTermios(void);

bool gameRunning = true;
Ball ball;
Paddle player1;
Paddle player2;
pthread_t threadPlayer2;
pthread_mutex_t mutex;
int scoreLimit;

void signalCallback(int signum) {
    gameRunning = false;
}

void* aiOpponent() {
    int paddleCenter, ballCenter;

    while (gameRunning) {
        pthread_mutex_lock(&mutex);
        paddleCenter = player2.x + PADDLE_WIDTH / 2;
        ballCenter = ball.x + ball.speedX;

        if (ballCenter < paddleCenter) {
            player2.x -= PADDLE_SPEED;
        } else if (ballCenter > paddleCenter) {
            player2.x += PADDLE_SPEED;
        }

        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Score limit not provided!\n");
        exit(EXIT_FAILURE);
    }

    scoreLimit = atoi(argv[1]);

    // Init game elements
    ball.x = BALL_INITIAL_X;
    ball.y = BALL_INITIAL_Y;
    ball.speedX = BALL_INITIAL_SPEED;
    ball.speedY = BALL_INITIAL_SPEED;

    player1.x = PADDLE_TOP_MARGIN;
    player1.y = BOARD_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    player1.score = 0;

    player2.x = BOARD_WIDTH - PADDLE_TOP_MARGIN - PADDLE_WIDTH;
    player2.y = BOARD_HEIGHT / 2 - PADDLE_HEIGHT / 2;
    player2.score = 0;

    // Register signal callback
    signal(SIGINT, signalCallback);

    // Start AI thread
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&threadPlayer2, NULL, aiOpponent, NULL);

    // Start game loop
    while (gameRunning) {
        // Move ball
        ball.x += ball.speedX;
        ball.y += ball.speedY;

        // Handle wall collisions
        if (ball.y == 0 || ball.y == BOARD_HEIGHT - 1) {
            ball.speedY *= -1;
        }

        // Handle paddle collisions
        if (ball.x == player1.x + PADDLE_WIDTH && ball.y >= player1.y && ball.y < player1.y + PADDLE_HEIGHT) {
            ball.speedX *= -1;
        } else if (ball.x == player2.x - 1 && ball.y >= player2.y && ball.y < player2.y + PADDLE_HEIGHT) {
            ball.speedX *= -1;
        }

        // Handle scoring and reset ball
        if (ball.x == 0 || ball.x == BOARD_WIDTH - 1) {
            if (ball.x == 0) {
                player2.score++;
            } else {
                player1.score++;
            }

            if (player1.score == scoreLimit || player2.score == scoreLimit) {
                gameRunning = false;
                break;
            }

            ball.x = BALL_INITIAL_X;
            ball.y = BALL_INITIAL_Y;
            ball.speedX = BALL_INITIAL_SPEED;
            ball.speedY = BALL_INITIAL_SPEED;
        }

        // Clear screen
        printf("\033[2J");
        
        // Draw board
        for (int row = 0; row < BOARD_HEIGHT; row++) {
            for (int col = 0; col < BOARD_WIDTH; col++) {
                if (row == ball.y && col == ball.x) {
                    printf("O");
                } else if (row >= player1.y && row < player1.y + PADDLE_HEIGHT && col >= player1.x && col < player1.x + PADDLE_WIDTH) {
                    printf("|");
                } else if (row >= player2.y && row < player2.y + PADDLE_HEIGHT && col >= player2.x && col < player2.x + PADDLE_WIDTH) {
                    printf("|");
                } else if (col == 0 || col == BOARD_WIDTH - 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Draw scores
        printf("\nScore: %d - %d\n", player1.score, player2.score);

        // Delay
        usleep(10000);

        // Handle user input
        if (kbhit()) {
            char input = getchar();
            switch (input) {
                case KB_UP_KEY:
                    if (player1.y > 0) {
                        player1.y--;
                    }
                    break;
                case KB_DOWN_KEY:
                    if (player1.y + PADDLE_HEIGHT < BOARD_HEIGHT) {
                        player1.y++;
                    }
                    break;
                case KB_ESC_KEY:
                    gameRunning = false;
                    break;
            }
        }
    }

    // Cleanup and exit
    pthread_join(threadPlayer2, NULL);
    pthread_mutex_destroy(&mutex);
    resetTermios();
    printf("\n\nThanks for playing!\n");
    exit(EXIT_SUCCESS);
}

int kbhit(void) {
    static struct termios oldTerm, newTerm;
    tcgetattr(STDIN_FILENO, &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm);
    return ch;
}

void resetTermios(void) {
    static struct termios oldTerm, newTerm;
    tcgetattr(STDIN_FILENO, &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);
}