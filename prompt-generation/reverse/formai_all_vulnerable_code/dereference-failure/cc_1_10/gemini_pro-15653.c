//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

char *screen;
int cursor_x, cursor_y;

void init_screen() {
    screen = malloc(WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        screen[i] = ' ';
    }
    cursor_x = 0;
    cursor_y = 0;
}

void clear_screen() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        screen[i] = ' ';
    }
}

void move_cursor_to(int x, int y) {
    cursor_x = x;
    cursor_y = y;
}

void draw_char(char c) {
    screen[cursor_y * WIDTH + cursor_x] = c;
    cursor_x++;
}

void draw_string(char *str) {
    while (*str) {
        draw_char(*str);
        str++;
    }
}

void draw_int(int n) {
    char buf[16];
    sprintf(buf, "%d", n);
    draw_string(buf);
}

void draw_fibonacci_sequence(int n) {
    int a, b, c;
    a = 0;
    b = 1;
    for (int i = 0; i < n; i++) {
        c = a + b;
        draw_int(c);
    }
}

void draw_spiral(int n) {
    int x, y;
    x = n / 2;
    y = n / 2;
    for (int i = 0; i < n * n; i++) {
        draw_char('#');
        x += 1;
    }
}

int main() {
    int n;
    init_screen();
    draw_string("Enter the number of Fibonacci numbers to generate: ");
    draw_int(n);
    draw_fibonacci_sequence(n);
    draw_string("\nPress any key to continue...");
    getchar();
    clear_screen();
    draw_string("Drawing a spiral...");
    draw_spiral(10);
    draw_string("\nPress any key to exit...");
    getchar();
    return 0;
}