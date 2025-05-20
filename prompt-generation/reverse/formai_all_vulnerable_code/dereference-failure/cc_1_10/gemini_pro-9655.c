//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024  // Number of samples

double* generate_signal(double frequency, double sampling_rate) {
    double* signal = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2 * M_PI * frequency * i / sampling_rate);
    }
    return signal;
}

void apply_filter(double* signal, double* filter, int filter_length) {
    for (int i = 0; i < N; i++) {
        double filtered_sample = 0;
        for (int j = 0; j < filter_length; j++) {
            filtered_sample += signal[i - j] * filter[j];
        }
        signal[i] = filtered_sample;
    }
}

double* generate_filter(double cutoff_frequency, double sampling_rate) {
    double* filter = (double*)malloc(101 * sizeof(double));
    for (int i = 0; i < 101; i++) {
        double frequency = (i - 50) / 50.0 * sampling_rate / 2;
        filter[i] = 1 / (1 + pow(frequency / cutoff_frequency, 4));
    }
    return filter;
}

int main() {
    double frequency = 100;  // in Hz
    double sampling_rate = 1000;  // in Hz

    double* signal = generate_signal(frequency, sampling_rate);
    double* filter = generate_filter(150, sampling_rate);

    apply_filter(signal, filter, 101);

    for (int i = 0; i < N; i++) {
        printf("%f\n", signal[i]);
    }

    free(signal);
    free(filter);

    return 0;
}