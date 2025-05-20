//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

typedef unsigned char byte;

void clear_screen() {
    printf("\033[2J\033[1;1H");
}

void set_cursor_position(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

void set_cursor_visibility(int visible) {
    printf("\033[?25%sh", visible ? "" : "l");
}

void draw_fibonacci_sequence(int n) {
    byte *fibonacci = malloc(n * sizeof(byte));
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    double max_value = fibonacci[n - 1];
    double scale = (double)HEIGHT / max_value;

    for (int i = 0; i < n; i++) {
        double value = fibonacci[i] * scale;
        int height = (int)round(value);
        for (int j = 0; j < height; j++) {
            set_cursor_position(i, HEIGHT - j - 1);
            printf("#");
        }
    }

    free(fibonacci);
}

int main(int argc, char **argv) {
    int n = 100;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    set_cursor_visibility(0);
    clear_screen();
    draw_fibonacci_sequence(n);

    sleep(10);

    clear_screen();
    set_cursor_visibility(1);
    return 0;
}