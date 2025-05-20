//Falcon2-11B DATASET v1.0 Category: Digital signal processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

int main() {

    // Define input signal
    double input_signal[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    int input_signal_size = 10;

    // Allocate memory for input signal
    double *input_data = (double*)malloc(sizeof(double) * input_signal_size);
    for (int i = 0; i < input_signal_size; i++) {
        input_data[i] = input_signal[i];
    }

    // Define output signal
    double output_signal[2 * input_signal_size];

    // Allocate memory for output signal
    double *output_data = (double*)malloc(sizeof(double) * 2 * input_signal_size);
    for (int i = 0; i < 2 * input_signal_size; i++) {
        output_data[i] = 0.0;
    }

    // Perform FFT
    fftw_plan plan = fftw_plan_dft_r2c_1d(input_signal_size, input_data, output_data, FFTW_ESTIMATE);
    fftw_execute(plan);

    // Print output signal
    printf("Input Signal: ");
    for (int i = 0; i < input_signal_size; i++) {
        printf("%f ", input_data[i]);
    }
    printf("\n");

    printf("Output Signal: ");
    for (int i = 0; i < 2 * input_signal_size; i++) {
        printf("%f ", output_data[i]);
    }
    printf("\n");

    // Free memory
    free(input_data);
    free(output_data);

    // Clean up FFTW
    fftw_destroy_plan(plan);

    return 0;
}