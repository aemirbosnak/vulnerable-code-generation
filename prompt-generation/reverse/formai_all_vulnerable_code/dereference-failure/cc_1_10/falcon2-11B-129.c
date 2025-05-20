//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <alsa/asoundlib.h>

// Function to compute FFT and display spectrum
void fft(short int *data, int num_samples) {
    int i, j;
    short int temp;
    short int *buffer;
    short int *spectrum;

    // Create a buffer to hold the FFT spectrum
    buffer = malloc(num_samples / 2 + 1);
    if (buffer == NULL) {
        fprintf(stderr, "malloc failed!\n");
        return;
    }

    // Compute FFT and store results in buffer
    for (i = 0; i < num_samples / 2; i++) {
        temp = data[i];
        for (j = 0; j < num_samples / 2; j++) {
            buffer[i + j] += temp * cos(2 * M_PI * i * j / num_samples);
        }
    }

    // Display spectrum
    printf("Frequency Spectrum:\n");
    for (i = 0; i < num_samples / 2; i++) {
        printf("%5d ", i);
        for (j = 0; j < num_samples / 2; j++) {
            printf("%3d ", buffer[i + j]);
        }
        printf("\n");
    }

    // Free buffer
    free(buffer);
}

int main(int argc, char **argv) {
    int error;
    short int *data;
    int num_samples;

    // Open audio file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        exit(1);
    }

    // Read data from file
    fseek(fp, 0L, SEEK_END);
    num_samples = ftell(fp);
    rewind(fp);
    data = malloc(num_samples * sizeof(short int));
    if (data == NULL) {
        fprintf(stderr, "malloc failed!\n");
        exit(1);
    }
    error = fread(data, sizeof(short int), num_samples, fp);
    if (error!= num_samples) {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }

    // Compute FFT and display spectrum
    fft(data, num_samples);

    // Free memory
    free(data);

    return 0;
}