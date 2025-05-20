//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

int main() {
    double sample_rate = SAMPLE_RATE;
    double buffer_size = BUFFER_SIZE;
    double pi = PI;

    double *buffer = (double *) malloc(buffer_size * sizeof(double));
    double *output = (double *) malloc(buffer_size * sizeof(double));

    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0.0;
    }

    FILE *input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    int num_samples = 0;
    while (fread(buffer, sizeof(double), buffer_size, input_file) == buffer_size) {
        num_samples += buffer_size;
        for (int i = 0; i < buffer_size; i++) {
            double sample = buffer[i];
            double frequency = 440.0;
            double amplitude = 0.5;
            double phase = 0.0;

            sample += amplitude * sin(2 * pi * frequency * (i / sample_rate) + phase);

            output[i] = sample;
        }

        fwrite(output, sizeof(double), buffer_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processed %d samples.\n", num_samples);

    free(buffer);
    free(output);

    return 0;
}