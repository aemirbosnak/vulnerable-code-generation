//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024 // number of samples

// function to generate a sine wave
void generate_sine_wave(double* wave, int n) {
    double frequency = 440; // Hz
    double amplitude = 1.0;
    double phase = 0.0;
    double delta_t = 1.0 / (double)n;
    for (int i = 0; i < n; i++) {
        wave[i] = amplitude * sin(2 * M_PI * frequency * (double)i * delta_t + phase);
    }
}

int main() {
    // allocate memory for the waveform
    double* wave = (double*)malloc(N * sizeof(double));

    // generate a sine wave
    generate_sine_wave(wave, N);

    // apply a low-pass filter
    double cutoff_frequency = 100; // Hz
    double nyquist_frequency = (double)N / 2;
    double normal_cutoff = cutoff_frequency / nyquist_frequency;
    double b0 = 1.0;
    double b1 = -2.0 * cos(M_PI * normal_cutoff);
    double a1 = 1.0;
    double xn_1 = 0.0;
    double xn_2 = 0.0;
    for (int i = 0; i < N; i++) {
        double xn = wave[i];
        double yn = b0 * xn + b1 * xn_1 + a1 * xn_2;
        wave[i] = yn;
        xn_2 = xn_1;
        xn_1 = xn;
    }

    // write the filtered waveform to a file
    FILE* fp = fopen("filtered_wave.txt", "w");
    for (int i = 0; i < N; i++) {
        fprintf(fp, "%f\n", wave[i]);
    }
    fclose(fp);

    // free memory
    free(wave);

    return 0;
}