//FormAI DATASET v1.0 Category: Digital signal processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265

typedef struct {
    double real;
    double imag;
} complex;

void fourier_transform(double* input, complex* output, int num_samples) {
    int i, j;

    for (i = 0; i < num_samples; i++) {
        output[i].real = 0;
        output[i].imag = 0;

        for (j = 0; j < num_samples; j++) {
            output[i].real += input[j] * cos(2 * PI * i * j / num_samples);
            output[i].imag -= input[j] * sin(2 * PI * i * j / num_samples);
        }
    }
}

void frequency_to_index(double freq, int* index, int num_samples) {
    *index = (int)(freq / (SAMPLE_RATE / num_samples));
}

void index_to_frequency(int index, double* freq, int num_samples) {
    *freq = (double)index * SAMPLE_RATE / num_samples;
}

void notch_filter(double* input, double* output, double freq, int num_samples) {
    int notch_index;
    frequency_to_index(freq, &notch_index, num_samples);

    complex* fft_output = (complex*)malloc(sizeof(complex) * num_samples);
    fourier_transform(input, fft_output, num_samples);

    int i;
    for (i = 0; i < num_samples; i++) {
        double amplitude = sqrt(pow(fft_output[i].real, 2) + pow(fft_output[i].imag, 2));

        if (i == notch_index || i == (num_samples - notch_index)) {
            amplitude = 0;
        }

        output[i] = amplitude;
    }

    free(fft_output);
}

int main() {
    int num_samples = 1024;

    double* input_signal = (double*)malloc(sizeof(double) * num_samples);
    int i;
    for (i = 0; i < num_samples; i++) {
        input_signal[i] = sin(i * 2 * PI * 440 / SAMPLE_RATE) + sin(i * 2 * PI * 880 / SAMPLE_RATE);
    }

    double* filtered_signal = (double*)malloc(sizeof(double) * num_samples);
    notch_filter(input_signal, filtered_signal, 440, num_samples);

    FILE* fp = fopen("output.raw", "wb");
    for (i = 0; i < num_samples; i++) {
        fwrite(&filtered_signal[i], sizeof(double), 1, fp);
    }
    fclose(fp);

    free(input_signal);
    free(filtered_signal);

    return 0;
}