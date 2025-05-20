//LLAMA2-13B DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1024

float *x[N]; // input signals
float *y[N]; // output signals
float *z[N]; // filtered signals

void init_signals(void) {
    int i;
    for (i = 0; i < N; i++) {
        x[i] = malloc(N * sizeof(float));
        y[i] = malloc(N * sizeof(float));
        z[i] = malloc(N * sizeof(float));
        for (int j = 0; j < N; j++) {
            x[i][j] = (j % 2 == 0) ? 1.0f : -1.0f;
            y[i][j] = 0.0f;
            z[i][j] = 0.0f;
        }
    }
}

void filter(void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            z[i][j] = x[i][j] * cos(2 * M_PI * j / N) + y[i][j];
        }
    }
}

void print_signals(void) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Signal %d: \n", i);
        for (int j = 0; j < N; j++) {
            printf("%f ", z[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    init_signals();
    filter();
    print_signals();
    return 0;
}