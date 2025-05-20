//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define FREQ 440.0
#define PI 3.14159265

typedef struct {
    float *data;
    size_t length;
} Signal;

Signal* create_signal(size_t length) {
    Signal *signal = (Signal *)malloc(sizeof(Signal));
    signal->data = (float *)malloc(length * sizeof(float));
    signal->length = length;
    return signal;
}

void free_signal(Signal *signal) {
    free(signal->data);
    free(signal);
}

void generate_sine_wave(Signal *signal, float frequency, float sample_rate) {
    for (size_t i = 0; i < signal->length; ++i) {
        signal->data[i] = sinf(2 * PI * frequency * i / sample_rate);
    }
}

void low_pass_filter(Signal *input, Signal *output, float cutoff_freq, float sample_rate) {
    float rc = 1.0 / (2 * PI * cutoff_freq);
    float dt = 1.0 / sample_rate;
    float alpha = dt / (rc + dt);

    output->data[0] = input->data[0];  // Set the first output value

    for (size_t i = 1; i < input->length; ++i) {
        output->data[i] = output->data[i - 1] + alpha * (input->data[i] - output->data[i - 1]);
    }
}

void save_signal_to_file(Signal *signal, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    fwrite(signal->data, sizeof(float), signal->length, file);
    fclose(file);
}

void print_signal(Signal *signal) {
    for (size_t i = 0; i < signal->length; ++i) {
        printf("%f\n", signal->data[i]);
    }
}

int main() {
    size_t length = SAMPLE_RATE * DURATION;
    
    Signal *input_signal = create_signal(length);
    Signal *output_signal = create_signal(length);
    
    generate_sine_wave(input_signal, FREQ, SAMPLE_RATE);
    
    float cutoff_frequency = 1000.0; // Low-pass cutoff frequency
    low_pass_filter(input_signal, output_signal, cutoff_frequency, SAMPLE_RATE);
    
    save_signal_to_file(input_signal, "input_signal.dat");
    save_signal_to_file(output_signal, "output_signal.dat");

    printf("Input and filtered output signals have been generated and saved.\n");

    // Optionally print the first 10 samples of each signal to the console
    printf("Input Signal (first 10 samples):\n");
    print_signal(input_signal);
    
    printf("Output Signal (first 10 samples after low-pass filter):\n");
    print_signal(output_signal);
    
    free_signal(input_signal);
    free_signal(output_signal);
    
    return 0;
}