//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: systematic
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 20
#define BALL_SIZE 15
#define BRICK_WIDTH 75
#define BRICK_HEIGHT 30
#define BRICK_ROWS 5
#define BRICK_COLS 10

typedef struct {
    int x, y;
    int width, height;
} Paddle;

typedef struct {
    int x, y;
    int dx, dy;
    int size;
} Ball;

typedef struct {
    bool active;
} Brick;

Display *display;
Window window;
GC gc;
Paddle paddle;
Ball ball;
Brick bricks[BRICK_ROWS][BRICK_COLS];

void initBricks() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].active = true;
        }
    }
}

void drawBricks() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].active) {
                XFillRectangle(display, window, gc, j * BRICK_WIDTH, i * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT);
            }
        }
    }
}

void initPaddle() {
    paddle.x = (WIDTH - PADDLE_WIDTH) / 2;
    paddle.y = HEIGHT - PADDLE_HEIGHT - 30;
    paddle.width = PADDLE_WIDTH;
    paddle.height = PADDLE_HEIGHT;
}

void drawPaddle() {
    XFillRectangle(display, window, gc, paddle.x, paddle.y, paddle.width, paddle.height);
}

void initBall() {
    ball.x = (WIDTH - BALL_SIZE) / 2;
    ball.y = paddle.y - BALL_SIZE;
    ball.dx = 5;
    ball.dy = -5;
    ball.size = BALL_SIZE;
}

void drawBall() {
    XFillArc(display, window, gc, ball.x, ball.y, ball.size, ball.size, 0, 360*64);
}

void checkCollision() {
    // Check for paddle collision
    if (ball.y + ball.size >= paddle.y &&
        ball.x + ball.size >= paddle.x &&
        ball.x <= paddle.x + paddle.width) {
        ball.dy = -ball.dy;  // Bounce off paddle
    }

    // Check for brick collisions
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j].active) {
                if (ball.x + ball.size >= j * BRICK_WIDTH && 
                    ball.x <= j * BRICK_WIDTH + BRICK_WIDTH &&
                    ball.y + ball.size >= i * BRICK_HEIGHT && 
                    ball.y <= i * BRICK_HEIGHT + BRICK_HEIGHT) {
                    bricks[i][j].active = false;
                    ball.dy = -ball.dy;  // Bounce off brick
                }
            }
        }
    }
}

void updateBall() {
    ball.x += ball.dx;
    ball.y += ball.dy;

    if (ball.x <= 0 || ball.x + ball.size >= WIDTH) {
        ball.dx = -ball.dx;  // Bounce off walls
    }
    if (ball.y <= 0) {
        ball.dy = -ball.dy;  // Bounce off top
    }
    if (ball.y >= HEIGHT) {
        // Ball fell below the paddle, game over
        printf("Game Over! You lost!\n");
        exit(0);
    }
}

int main() {
    // Create display
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 10, 10, WIDTH, HEIGHT, 1, BlackPixel(display, 0), WhitePixel(display, 0));
    XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);
    gc = XCreateGC(display, window, 0, 0);
    
    XMapWindow(display, window);
    XFlush(display);

    // Initialize game objects
    initBricks();
    initPaddle();
    initBall();
    
    while (1) {
        XEvent event;
        while (XPending(display)) {
            XNextEvent(display, &event);
            if (event.type == KeyPress) {
                // Exit on key press
                XDestroyWindow(display, window);
                XCloseDisplay(display);
                exit(0);
            }
        }

        // Clear window
        XClearWindow(display, window);
        
        // Update game state
        checkCollision();
        updateBall();
        
        // Draw everything
        drawBricks();
        drawPaddle();
        drawBall();
        
        XFlush(display);
        usleep(16000);  // Sleep to control frame rate
    }

    // Cleanup
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}