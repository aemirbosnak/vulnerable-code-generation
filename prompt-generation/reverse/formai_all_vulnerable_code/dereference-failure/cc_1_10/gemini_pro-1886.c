//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Generate a random signal
double *generate_signal(int N) {
    double *signal = malloc(N * sizeof(double));
    for (int n = 0; n < N; n++) {
        signal[n] = sin(2 * PI * n / 100) + 0.5 * sin(2 * PI * n / 50) + 0.25 * sin(2 * PI * n / 25);
    }
    return signal;
}

// Apply a moving average filter to the signal
double *moving_average(double *signal, int N, int M) {
    double *filtered_signal = malloc(N * sizeof(double));
    for (int n = 0; n < N; n++) {
        double sum = 0;
        for (int m = -M / 2; m <= M / 2; m++) {
            if (n + m >= 0 && n + m < N) {
                sum += signal[n + m];
            }
        }
        filtered_signal[n] = sum / M;
    }
    return filtered_signal;
}

// Plot the signal and the filtered signal
void plot_signal(double *signal, int N, char *title) {
    printf("%s\n", title);
    for (int n = 0; n < N; n++) {
        printf("%f ", signal[n]);
    }
    printf("\n");
}

int main() {
    // Generate a random signal
    int N = 1000;
    double *signal = generate_signal(N);

    // Apply a moving average filter to the signal
    int M = 10;
    double *filtered_signal = moving_average(signal, N, M);

    // Plot the signal and the filtered signal
    plot_signal(signal, N, "Original signal");
    plot_signal(filtered_signal, N, "Filtered signal");

    // Free the memory allocated for the signals
    free(signal);
    free(filtered_signal);

    return 0;
}