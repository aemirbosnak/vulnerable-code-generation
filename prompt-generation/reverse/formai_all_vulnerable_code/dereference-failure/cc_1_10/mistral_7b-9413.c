//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 12
#define FPS 10000000
#define DELAY_NS (1000000000 / FPS)
#define ARROW "\033[A"
#define CLEAR "\033[2J"
#define RESET "\033[0m"

typedef struct {
    int x, y, value;
} cell;

void draw_cell(int x, int y, int value) {
    char str[10];
    sprintf(str, "\033[%d;%dH%s%d", y, x, value > 9 ? " [" : "", value);
    write(STDOUT_FILENO, str, strlen(str));
}

void fibonacci_sequence(int n) {
    cell arr[n];
    int i, a = 0, b = 1;

    arr[0].x = WIDTH / 2;
    arr[0].y = HEIGHT / 2;
    arr[0].value = a;

    for (i = 1; i < n; i++) {
        arr[i].x = arr[i - 1].x;
        arr[i].y = arr[i - 1].y + 1;

        usleep(DELAY_NS);
        draw_cell(arr[i].x, arr[i].y, a);

        usleep(DELAY_NS);
        arr[i].value = a + b;
        draw_cell(arr[i].x, arr[i].y, arr[i].value);

        a = b;
        b = arr[i].value;
    }

    usleep(DELAY_NS);
    printf("\033[%d;%dH%sPress any key to clear the screen...\n", HEIGHT, 0, RESET);
    fgetc(stdin);
    system(CLEAR);
}

int main() {
    srand(time(NULL));
    fibonacci_sequence(rand() % 20 + 10);
    return 0;
}