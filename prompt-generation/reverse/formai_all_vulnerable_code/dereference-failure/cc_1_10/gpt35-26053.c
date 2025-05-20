//FormAI DATASET v1.0 Category: Audio processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FILTER_CUTOFF 4000

double lpf_coeff(double Fc, int n, int k);

int main() {
    int num_samples = SAMPLE_RATE * 5; // 5 seconds of audio
    double *audio_buffer = calloc(num_samples, sizeof(double));

    // Generate random white noise
    for (int i = 0; i < num_samples; i++) {
        audio_buffer[i] = (double)rand() / RAND_MAX * 2 - 1;
    }

    // Apply LPF (low-pass filter) to audio
    double *lpf_buffer = calloc(num_samples, sizeof(double));
    double prev_output = 0;
    double prev_input = 0;
    double RC = 1.0 / (2 * M_PI * FILTER_CUTOFF);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (dt + RC);
    for (int i = 0; i < num_samples; i++) {
        double input = audio_buffer[i];
        double output = alpha * input + (1 - alpha) * prev_output;
        prev_output = output;
        prev_input = input;
        lpf_buffer[i] = output;
    }

    // Apply gain to audio
    double gain = 3;
    for (int i = 0; i < num_samples; i++) {
        audio_buffer[i] *= gain;
        lpf_buffer[i] *= gain;
    }

    // Write audio files
    FILE *audio_file = fopen("audio.raw", "wb");
    fwrite(audio_buffer, sizeof(double), num_samples, audio_file);
    fclose(audio_file);

    FILE *lpf_file = fopen("lpf.raw", "wb");
    fwrite(lpf_buffer, sizeof(double), num_samples, lpf_file);
    fclose(lpf_file);

    free(audio_buffer);
    free(lpf_buffer);
    return 0;
}

double lpf_coeff(double Fc, int n, int k) {
    double theta = M_PI * Fc / SAMPLE_RATE;
    double a = sin(theta) / (2 * M_PI * Fc);
    double b = (1 - cos(theta)) / 2.0;
    double alpha = a * pow(2, (double)n/2);
    double beta = -b * cos(2 * M_PI * k / pow(2, n));
    return alpha + beta;
}