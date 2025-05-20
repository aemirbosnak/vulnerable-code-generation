//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TAPS 4
#define PI M_PI

typedef struct {
    float b[NUM_TAPS];
    float a[NUM_TAPS];
} IIR_Filter;

void iir_filter_init(IIR_Filter *filter, float *b_coeffs, float *a_coeffs) {
    int i;

    for (i = 0; i < NUM_TAPS; i++) {
        filter->b[i] = b_coeffs[i];
        filter->a[i] = a_coeffs[i];
    }
}

void iir_filter(IIR_Filter *filter, float input) {
    float output, temp;

    temp = input;
    output = filter->b[0] * input;

    for (int i = 1; i < NUM_TAPS; i++) {
        temp = input - filter->a[i] * temp;
        output += filter->b[i] * temp;
    }

    filter->a[0] = input;
    input = output;
}

void generate_sine_wave(float *buffer, int buffer_size, float amplitude, float frequency) {
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = amplitude * sin(2 * PI * frequency * i / (float) buffer_size);
    }
}

int main() {
    int buffer_size = 1024;
    int filter_coeffs_size = NUM_TAPS * 2;
    float *input_buffer, *output_buffer, *filter_coeffs;
    IIR_Filter lp_filter;

    input_buffer = (float *) malloc(buffer_size * sizeof(float));
    output_buffer = (float *) malloc(buffer_size * sizeof(float));

    if (!input_buffer || !output_buffer) {
        printf("Error: Failed to allocate memory!\n");
        free(input_buffer);
        free(output_buffer);
        return 1;
    }

    filter_coeffs = (float *) malloc(filter_coeffs_size * sizeof(float));

    if (!filter_coeffs) {
        printf("Error: Failed to allocate memory!\n");
        free(input_buffer);
        free(output_buffer);
        return 1;
    }

    // Low-pass filter coefficients
    filter_coeffs[0] = 0.9853;
    filter_coeffs[1] = 1.9310;
    filter_coeffs[2] = 0.9853;
    filter_coeffs[3] = -0.9615;

    iir_filter_init(&lp_filter, filter_coeffs, NULL);

    generate_sine_wave(input_buffer, buffer_size, 1.0, 0.25);

    for (int i = 0; i < buffer_size; i++) {
        iir_filter(&lp_filter, input_buffer[i]);
        output_buffer[i] = lp_filter.b[0] * input_buffer[i];

        for (int j = 1; j < NUM_TAPS; j++) {
            lp_filter.a[j] = input_buffer[i] - lp_filter.a[j] * output_buffer[i - 1];
            output_buffer[i] += lp_filter.b[j] * lp_filter.a[j];
        }

        lp_filter.a[0] = input_buffer[i];
    }

    // Output the filtered signal
    for (int i = 0; i < buffer_size; i++) {
        printf("%.4f\n", output_buffer[i]);
    }

    free(input_buffer);
    free(output_buffer);
    free(filter_coeffs);

    return 0;
}