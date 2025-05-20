//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

double lpf1_coeff(double cutoff_freq, double sample_rate)
{
    double r = exp(-2.0 * M_PI * cutoff_freq / sample_rate);
    return 1.0 - r;
}

int main()
{
    int i;
    double cutoff_freq = 1000.0;
    double coeff = lpf1_coeff(cutoff_freq, SAMPLE_RATE);
    double output = 0.0;
    double buffer[BUFFER_SIZE] = {0};

    FILE *input_file = fopen("input.raw", "rb");
    FILE *output_file = fopen("output.raw", "wb");

    if (!input_file || !output_file) {
        fprintf(stderr, "Error: Input/output file cannot be opened\n");
        return 1;
    }

    while (1) {
        // Read sample from input file
        int n = fread(buffer, sizeof(double), BUFFER_SIZE, input_file);
        if (n <= 0) {
            break;
        }

        // Process samples with LPF
        for (i = 0; i < n; i++) {
            output = coeff * buffer[i] + (1.0 - coeff) * output;
            buffer[i] = output;
        }

        // Write processed samples to output file
        fwrite(buffer, sizeof(double), n, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Audio processing completed successfully!\n");

    return 0;
}