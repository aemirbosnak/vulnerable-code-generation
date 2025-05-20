//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 256
#define FS 44100
#define PI 3.14159265358979323846
#define TWO_PI (2*PI)
#define MAX_AMPLITUDE 32767

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    int i, j, k, n;
    double sample_rate, t, freq, phase, amplitude;
    double x, y, cos_term, sin_term;
    double *signal, *spectrum;
    double *window;

    input_file = fopen("input.raw", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen("output.raw", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    sample_rate = FS;

    signal = (double *) malloc(N * sizeof(double));
    spectrum = (double *) malloc(N/2 * sizeof(double));
    window = (double *) malloc(N * sizeof(double));

    for (i = 0; i < N; i++) {
        fread(&signal[i], sizeof(double), 1, input_file);
    }

    for (i = 0; i < N; i++) {
        window[i] = 0.5 * (1 - cos(TWO_PI * i / (N - 1)));
    }

    for (i = 0; i < N; i++) {
        signal[i] *= window[i];
    }

    for (n = 0; n < N/2; n++) {
        spectrum[n] = 0;
        for (i = 0; i < N; i++) {
            x = signal[i] * cos(TWO_PI * n * i / N);
            y = signal[i] * sin(TWO_PI * n * i / N);
            spectrum[n] += x*x + y*y;
        }
    }

    for (n = 0; n < N/2; n++) {
        spectrum[n] = sqrt(spectrum[n] / N);
    }

    for (n = 0; n < N/2; n++) {
        fwrite(&spectrum[n], sizeof(double), 1, output_file);
    }

    free(signal);
    free(spectrum);
    free(window);

    fclose(input_file);
    fclose(output_file);

    return 0;
}