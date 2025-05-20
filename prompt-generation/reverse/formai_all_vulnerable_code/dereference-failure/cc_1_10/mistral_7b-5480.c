//MISTRAL-7B DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81 // gravitational acceleration
#define WIDTH 50
#define HEIGHT 20
#define BALL_RADIUS 1

typedef struct {
    double x, y, vx, vy;
} ball_t;

typedef struct {
    int width, height;
    unsigned char *data;
} screen_t;

void update(ball_t *ball) {
    ball->vy += G;
    ball->y += ball->vy;

    if (ball->y < 0) {
        ball->y = 0;
        ball->vy = -BALL_RADIUS * 0.5 * G;
    }

    ball->x += ball->vx;
    if (ball->x < 0 || ball->x > WIDTH - 2 * BALL_RADIUS) {
        ball->vx = -ball->vx;
    }
}

void draw_ball(ball_t ball, screen_t *screen) {
    int x = ball.x;
    int y = ball.y;

    for (int i = 0; i < BALL_RADIUS; i++) {
        int xx = x + i - BALL_RADIUS / 2;
        int yy = y + i;

        if (xx < 0 || xx >= screen->width || yy < 0 || yy >= screen->height) {
            screen->data[yy * screen->width + xx] = 0;
            continue;
        }

        screen->data[yy * screen->width + xx] = 255;
    }
}

void clear_screen(screen_t *screen) {
    for (int y = 0; y < screen->height; y++) {
        for (int x = 0; x < screen->width; x++) {
            screen->data[y * screen->width + x] = 0;
        }
    }
}

int main() {
    ball_t ball = {0, 0, 0, 0};
    screen_t screen = {.width = WIDTH, .height = HEIGHT, .data = calloc(WIDTH * HEIGHT, sizeof(unsigned char))};

    int fps = 60;
    double dt = 1.0 / fps;

    while (1) {
        clear_screen(&screen);
        update(&ball);
        draw_ball(ball, &screen);

        for (int y = 0; y < screen.height; y++) {
            for (int x = 0; x < screen.width; x++) {
                putchar(screen.data[y * screen.width + x]);
            }
            putchar('\n');
        }
        fflush(stdout);
        usleep(dt * 1000000);
    }

    free(screen.data);
    return 0;
}