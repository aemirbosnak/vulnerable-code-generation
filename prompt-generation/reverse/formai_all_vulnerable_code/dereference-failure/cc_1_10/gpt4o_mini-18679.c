//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define PADDLE_WIDTH 80
#define PADDLE_HEIGHT 20
#define BALL_SIZE 20
#define BRICK_WIDTH 70
#define BRICK_HEIGHT 30

typedef struct {
    int x, y;
    int dx, dy;
} Ball;

typedef struct {
    int x, y;
} Paddle;

typedef struct {
    int x, y;
    bool active;
} Brick;

void initBall(Ball *ball) {
    ball->x = WIDTH / 2;
    ball->y = HEIGHT - 100;
    ball->dx = 4;
    ball->dy = -4;
}

void initPaddle(Paddle *paddle) {
    paddle->x = (WIDTH - PADDLE_WIDTH) / 2;
    paddle->y = HEIGHT - PADDLE_HEIGHT - 10;
}

void initBricks(Brick *bricks, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bricks[i * cols + j].x = j * (BRICK_WIDTH + 10) + 30;
            bricks[i * cols + j].y = i * (BRICK_HEIGHT + 10) + 50;
            bricks[i * cols + j].active = true;
        }
    }
}

void drawBrick(Display *display, Window window, Brick brick) {
    if (brick.active) {
        XFillRectangle(display, window, DefaultGC(display, 0), brick.x, brick.y, BRICK_WIDTH, BRICK_HEIGHT);
    }
}

void drawBall(Display *display, Window window, Ball ball) {
    XFillArc(display, window, DefaultGC(display, 0), ball.x, ball.y, BALL_SIZE, BALL_SIZE, 0, 360*64);
}

void drawPaddle(Display *display, Window window, Paddle paddle) {
    XFillRectangle(display, window, DefaultGC(display, 0), paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void checkCollision(Ball *ball, Paddle paddle, Brick *bricks, int rows, int cols) {
    if (ball->x <= 0 || ball->x >= WIDTH - BALL_SIZE) {
        ball->dx = -ball->dx;
    }
    if (ball->y <= 0) {
        ball->dy = -ball->dy;
    }
    if (ball->y >= HEIGHT) {
        printf("Game Over!\n");
        exit(0);
    }
    
    // Paddle collision
    if (ball->x + BALL_SIZE >= paddle.x && ball->x <= paddle.x + PADDLE_WIDTH &&
        ball->y + BALL_SIZE >= paddle.y && ball->y <= paddle.y + PADDLE_HEIGHT) {
        ball->dy = -ball->dy;
    }

    // Brick collisions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Brick *brick = &bricks[i * cols + j];
            if (brick->active &&
                ball->x + BALL_SIZE >= brick->x && ball->x <= brick->x + BRICK_WIDTH &&
                ball->y + BALL_SIZE >= brick->y && ball->y <= brick->y + BRICK_HEIGHT) {
                brick->active = false;
                ball->dy = -ball->dy;
            }
        }
    }
}

void moveBall(Ball *ball) {
    ball->x += ball->dx;
    ball->y += ball->dy;
}

int main() {
    Display *display;
    Window window;
    XEvent event;
    Ball ball;
    Paddle paddle;
    int rows = 5, cols = 10;
    Brick bricks[rows * cols];

    // Initialize X11
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, DefaultRootWindow(display),
                                  10, 10, WIDTH, HEIGHT, 1,
                                  BlackPixel(display, 0), WhitePixel(display, 0));
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    // Initialize game objects
    initBall(&ball);
    initPaddle(&paddle);
    initBricks(bricks, rows, cols);

    while (true) {
        XNextEvent(display, &event);
        XClearWindow(display, window);

        // Draw the game objects
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                drawBrick(display, window, bricks[i * cols + j]);
            }
        }
        drawBall(display, window, ball);
        drawPaddle(display, window, paddle);

        // Game logic
        moveBall(&ball);
        checkCollision(&ball, paddle, bricks, rows, cols);

        // Handle keyboard input
        if (event.type == KeyPress) {
            if (event.xkey.keycode == 38) { // Key A
                if (paddle.x > 0) {
                    paddle.x -= 20;
                }
            }
            if (event.xkey.keycode == 40) { // Key D
                if (paddle.x < WIDTH - PADDLE_WIDTH) {
                    paddle.x += 20;
                }
            }
        }

        usleep(16000); // Control frame speed
    }

    XCloseDisplay(display);
    return 0;
}