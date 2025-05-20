//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int fib0;
    int fib1;
} FibState;

FibState init_fib(int n) {
    FibState fib;
    fib.fib0 = 0;
    fib.fib1 = 1;
    return fib;
}

int next_fib(FibState *fib) {
    int temp = fib->fib1;
    fib->fib1 = fib->fib0 + fib->fib1;
    fib->fib0 = temp;
    return fib->fib1;
}

void print_fib(int n) {
    FibState fib = init_fib(n);
    for (int i = 0; i < n; i++) {
        printf("%d ", next_fib(&fib));
    }
    printf("\n");
}

void plot_fib(int n) {
    FibState fib = init_fib(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int fib_num = next_fib(&fib);
        if (fib_num > max) {
            max = fib_num;
        }
    }

    int scale = max / 100;
    if (scale == 0) {
        scale = 1;
    }

    for (int i = 0; i < n; i++) {
        int fib_num = next_fib(&fib);
        int height = ceil(fib_num / scale);
        for (int j = 0; j < height; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void graph_fib(int n) {
    FibState fib = init_fib(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int fib_num = next_fib(&fib);
        if (fib_num > max) {
            max = fib_num;
        }
    }

    int scale_x = n / 100;
    if (scale_x == 0) {
        scale_x = 1;
    }

    int scale_y = max / 100;
    if (scale_y == 0) {
        scale_y = 1;
    }

    for (int j = 0; j <= max; j += scale_y) {
        printf("%4d |", j);
        for (int i = 0; i < n; i += scale_x) {
            int fib_num = next_fib(&fib);
            if (fib_num >= j) {
                printf(" *");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("    ");
    for (int i = 0; i < n; i += scale_x) {
        printf("%4d ", i);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n = 100;
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    print_fib(n);
    plot_fib(n);
    graph_fib(n);

    return 0;
}