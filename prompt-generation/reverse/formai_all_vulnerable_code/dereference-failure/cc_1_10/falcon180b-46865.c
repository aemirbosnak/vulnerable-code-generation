//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

typedef struct {
    int size;
    double *signal;
    double *fft;
} Signal;

Signal *createSignal(int size) {
    Signal *signal = (Signal *)malloc(sizeof(Signal));
    signal->size = size;
    signal->signal = (double *)malloc(sizeof(double) * size);
    signal->fft = (double *)malloc(sizeof(double) * size);
    return signal;
}

void destroySignal(Signal *signal) {
    free(signal->signal);
    free(signal->fft);
    free(signal);
}

void fillSignal(Signal *signal, double value) {
    int i;
    for (i = 0; i < signal->size; i++) {
        signal->signal[i] = value;
    }
}

void fft(Signal *signal) {
    int i, j, k;
    double theta = 2 * PI / signal->size;
    double w = cos(theta);
    double wk = 1.0;

    for (i = 0; i < signal->size / 2; i++) {
        for (j = 0; j < signal->size; j += 2) {
            double temp = signal->signal[j] * wk - signal->signal[j + 1] * w;
            signal->signal[j] += signal->signal[j + 1] + temp;
            signal->signal[j + 1] = signal->signal[j] - signal->signal[j + 1] + temp;
        }
        wk = w * wk;
        w = w * w - 1.0;
    }
}

void printSignal(Signal *signal) {
    int i;
    for (i = 0; i < signal->size; i++) {
        printf("%lf ", signal->signal[i]);
    }
    printf("\n");
}

void printFFT(Signal *signal) {
    int i;
    for (i = 0; i < signal->size; i++) {
        printf("%lf ", signal->fft[i]);
    }
    printf("\n");
}

int main() {
    Signal *signal = createSignal(MAX_SIZE);
    fillSignal(signal, 1.0);
    fft(signal);
    printSignal(signal);
    printFFT(signal);
    destroySignal(signal);
    return 0;
}