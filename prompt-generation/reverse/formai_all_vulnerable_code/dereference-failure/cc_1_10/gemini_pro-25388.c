//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define SCALE 2
#define DELAY 100000

typedef struct {
    int x, y;
} point;

typedef struct {
    point p1, p2;
} line;

typedef struct {
    line *lines;
    int num_lines;
    int max_lines;
} framebuffer;

void init_framebuffer(framebuffer *fb) {
    fb->lines = malloc(sizeof(line) * fb->max_lines);
    fb->num_lines = 0;
}

void add_line(framebuffer *fb, point p1, point p2) {
    if (fb->num_lines == fb->max_lines) {
        fb->lines = realloc(fb->lines, sizeof(line) * fb->max_lines * 2);
        fb->max_lines *= 2;
    }
    fb->lines[fb->num_lines++] = (line) {p1, p2};
}

void render_framebuffer(framebuffer *fb) {
    for (int i = 0; i < fb->num_lines; i++) {
        line l = fb->lines[i];
        for (int x = l.p1.x; x <= l.p2.x; x++) {
            for (int y = l.p1.y; y <= l.p2.y; y++) {
                putchar('@');
            }
            putchar('\n');
        }
    }
    fflush(stdout);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <num>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1) {
        printf("Error: number must be greater than 0\n");
        return 1;
    }

    framebuffer fb = {
        .lines = NULL,
        .num_lines = 0,
        .max_lines = 1000,
    };
    init_framebuffer(&fb);

    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        // draw the fibonacci number
        point p1 = {i * SCALE, HEIGHT - a * SCALE};
        point p2 = {i * SCALE, HEIGHT - (a + b) * SCALE};
        add_line(&fb, p1, p2);

        // advance the fibonacci numbers
        int c = a + b;
        a = b;
        b = c;

        // delay to show the animation
        for (int i = 0; i < DELAY; i++) { }
        system("clear");
        render_framebuffer(&fb);
    }

    return 0;
}