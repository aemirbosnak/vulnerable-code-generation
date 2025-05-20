//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the module interface
typedef struct {
    double *input;
    int input_length;
    double *output;
    int output_length;
} filter_module_t;

// Define the filter function
void filter(filter_module_t *module) {
    // Apply a moving average filter to the input data
    for (int i = 0; i < module->output_length; i++) {
        double sum = 0;
        for (int j = 0; j < module->input_length; j++) {
            sum += module->input[j + i];
        }
        module->output[i] = sum / module->input_length;
    }
}

// Define the main function
int main() {
    // Create a filter module
    filter_module_t module;

    // Allocate memory for the input and output data
    module.input = malloc(sizeof(double) * 100);
    module.output = malloc(sizeof(double) * 100);

    // Initialize the input data
    for (int i = 0; i < 100; i++) {
        module.input[i] = sin(2 * M_PI * i / 100);
    }

    // Set the input and output lengths
    module.input_length = 100;
    module.output_length = 100;

    // Call the filter function
    filter(&module);

    // Print the output data
    for (int i = 0; i < 100; i++) {
        printf("%f\n", module.output[i]);
    }

    // Free the allocated memory
    free(module.input);
    free(module.output);

    return 0;
}