//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 80
#define HEIGHT 24

const char *BORDER = "============================================================";
const char *PADDLE = "==";
const char BALL = 'O';
const char BLOCK = '#';
const char EMPTY = ' ';

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
} Ball;

typedef struct {
    int x;
    int width;
} Paddle;

typedef struct {
    int x;
    int y;
    int active;
} Block;

int kbhit() {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void updateBall(Ball *ball, Paddle *paddle, Block *blocks[]) {
    int i, j;
    int oldx = ball->x;
    int oldy = ball->y;
    ball->x += ball->dx;
    ball->y += ball->dy;
    if (ball->x < 0 || ball->x >= WIDTH) {
        ball->x = oldx;
        ball->dx = -ball->dx;
    }
    if (ball->y < 0) {
        ball->y = 0;
        ball->dy = -ball->dy;
    }
    if (ball->y >= HEIGHT) {
        ball->x = WIDTH / 2;
        ball->y = HEIGHT / 2;
        ball->dx = (rand() % 2 == 0 ? -1 : 1);
        ball->dy = -1;
        paddle->x = WIDTH / 2 - paddle->width / 2;
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                if (blocks[i][j].active) {
                    blocks[i][j].active = 0;
                    return;
                }
            }
        }
    }
    if (ball->y == HEIGHT - 1 && ball->x >= paddle->x && ball->x < paddle->x + paddle->width) {
        ball->y = oldy;
        ball->dy = -ball->dy;
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (blocks[i][j].active && ball->y == i && ball->x == j) {
                ball->y = oldy;
                ball->dy = -ball->dy;
                blocks[i][j].active = 0;
                return;
            }
        }
    }
}

void drawBorders() {
    printf("%s\n", BORDER);
}

void drawBall(int x, int y) {
    printf("\033[%d;%dH%c", y + 1, x + 1, BALL);
}

void eraseBall(int x, int y) {
    printf("\033[%d;%dH%c", y + 1, x + 1, EMPTY);
}

void drawPaddle(int x, int y, int width) {
    int i;
    for (i = 0; i < width; i++) {
        printf("\033[%d;%dH%s", y + 1, x + i + 1, PADDLE);
    }
}

void erasePaddle(int x, int y, int width) {
    int i;
    for (i = 0; i < width; i++) {
        printf("\033[%d;%dH%s", y + 1, x + i + 1, EMPTY);
    }
}

void drawBlock(int x, int y) {
    printf("\033[%d;%dH%c", y + 1, x + 1, BLOCK);
}

void eraseBlock(int x, int y) {
    printf("\033[%d;%dH%c", y + 1, x + 1, EMPTY);
}

void drawBlocks(Block *blocks[]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (blocks[i][j].active) {
                drawBlock(j, i);
            }
        }
    }
}

void clearScreen() {
    printf("\033[2J");
}

int main() {
    Ball ball = {WIDTH / 2, HEIGHT / 2, (rand() % 2 == 0 ? -1 : 1), -1};
    Paddle paddle = {WIDTH / 2 - 5, 10};
    Block *blocks[HEIGHT], **p;
    int i, j, k, fd, flags;
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    printf("\033[?25l");
    clearScreen();
    drawBorders();
    for (i = 0; i < HEIGHT; i++) {
        blocks[i] = malloc(WIDTH * sizeof(Block));
        for (j = 0; j < WIDTH; j++) {
            blocks[i][j].x = j;
            blocks[i][j].y = i;
            blocks[i][j].active = 1;
        }
    }
    drawBlocks(blocks);
    drawPaddle(paddle.x, HEIGHT - 2, paddle.width);
    drawBall(ball.x, ball.y);
    while (1) {
        usleep(10000);
        updateBall(&ball, &paddle, blocks);
        eraseBall(ball.x, ball.y);
        drawBall(ball.x, ball.y);
        if (kbhit()) {
            char c = getchar();
            if (c == 'a' && paddle.x > 0) {
                erasePaddle(paddle.x, HEIGHT - 2, paddle.width);
                paddle.x--;
                drawPaddle(paddle.x, HEIGHT - 2, paddle.width);
            } else if (c == 'd' && paddle.x + paddle.width < WIDTH) {
                erasePaddle(paddle.x, HEIGHT - 2, paddle.width);
                paddle.x++;
                drawPaddle(paddle.x, HEIGHT - 2, paddle.width);
            } else if (c == 'q') {
                break;
            }
        }
        clearScreen();
        drawBorders();
        drawBlocks(blocks);
        drawPaddle(paddle.x, HEIGHT - 2, paddle.width);
        drawBall(ball.x, ball.y);
        fflush(stdout);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    printf("\033[?25h");
    return 0;
}