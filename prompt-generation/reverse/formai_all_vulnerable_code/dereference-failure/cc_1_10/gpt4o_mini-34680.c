//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846
#define FREQUENCY 440.0
#define DURATION 5
#define MAX_SAMPLES (SAMPLE_RATE * DURATION)

void generate_sine_wave(float *buffer, int samples, float frequency, float amplitude) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = amplitude * sin((2 * PI * frequency * i) / SAMPLE_RATE);
    }
}

void apply_hamming_window(float *buffer, int samples) {
    for (int i = 0; i < samples; i++) {
        buffer[i] *= 0.54 - 0.46 * cos((2 * PI * i) / (samples - 1));
    }
}

void fft(float *real, float *imag, int n) {
    int i, j, k, m, mmax, istep;
    double wt, wtemp, wr, wpr, wpi, theta;

    // Bit-reversal permutation
    j = 0;
    for (i = 0; i < n; i++) {
        if (j > i) {
            float temp_real = real[j];
            float temp_imag = imag[j];
            real[j] = real[i];
            imag[j] = imag[i];
            real[i] = temp_real;
            imag[i] = temp_imag;
        }
        m = n >> 1;
        while (m >= 1 && j >= m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }

    // FFT
    mmax = 1;
    while (n > mmax) {
        istep = mmax << 1;
        theta = -2.0 * PI / (double) istep;
        wpr = cos(theta);
        wpi = sin(theta);
        wr = 1.0;
        wtemp = sin(0.5 * theta);
        wpr = -2.0 * wtemp * wtemp;

        for (m = 0; m < mmax; m++) {
            for (i = m; i < n; i += istep) {
                j = i + mmax;
                float temp_real = wr * real[j] - wpi * imag[j];
                float temp_imag = wr * imag[j] + wpi * real[j];
                real[j] = real[i] - temp_real;
                imag[j] = imag[i] - temp_imag;
                real[i] += temp_real;
                imag[i] += temp_imag;
            }
            wr = (wtemp = wr) * wpr - wpi * wtemp;
            wpi = wpi * wpr + wtemp * wtemp;
        }
        mmax = istep;
    }
}

void output_to_file(const char *filename, const float *buffer, int samples) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    // Write the PCM data to the file
    fwrite(buffer, sizeof(float), samples, fp);
    fclose(fp);
}

int main() {
    float *sine_wave = malloc(MAX_SAMPLES * sizeof(float));
    float *hamming_windowed = malloc(MAX_SAMPLES * sizeof(float));
    float *real = malloc(MAX_SAMPLES * sizeof(float));
    float *imag = calloc(MAX_SAMPLES, sizeof(float)); // imaginary part initialized to 0
    
    if (!sine_wave || !hamming_windowed || !real || !imag) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Generate the sine wave
    printf("Generating a sine wave...\n");
    generate_sine_wave(sine_wave, MAX_SAMPLES, FREQUENCY, 1.0f);
    memcpy(hamming_windowed, sine_wave, MAX_SAMPLES * sizeof(float));

    // Apply the Hamming window
    printf("Applying Hamming window...\n");
    apply_hamming_window(hamming_windowed, MAX_SAMPLES);

    // Prepare for FFT
    printf("Processing FFT...\n");
    memcpy(real, hamming_windowed, MAX_SAMPLES * sizeof(float));
    
    // Perform FFT
    fft(real, imag, MAX_SAMPLES);

    // Output results
    output_to_file("sine_wave.wav", hamming_windowed, MAX_SAMPLES);
    output_to_file("fft_real.dat", real, MAX_SAMPLES);
    output_to_file("fft_imag.dat", imag, MAX_SAMPLES);
    
    printf("Done! Sine wave and FFT results have been written to files.\n");

    // Clean up
    free(sine_wave);
    free(hamming_windowed);
    free(real);
    free(imag);

    return 0;
}