//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Constants for the DSP
#define SAMPLE_RATE 44100
#define PI 3.14159265
#define BUF_SIZE 1024

// Structure to hold sound signal information
typedef struct {
    double *data;         // Dynamic array for storing samples
    int length;          // Length of the signal
} Signal;

// Function to create a signal with a specified frequency
Signal* generate_signal(double frequency, double duration) {
    int num_samples = (int)(duration * SAMPLE_RATE);
    Signal *signal = (Signal*)malloc(sizeof(Signal));
    signal->data = (double*)malloc(num_samples * sizeof(double));
    signal->length = num_samples;

    for(int i = 0; i < num_samples; i++) {
        signal->data[i] = sin(2 * PI * frequency * (i / (double)SAMPLE_RATE));
    }

    return signal;
}

// Function to apply a simple low-pass filter to the signal
void low_pass_filter(Signal *signal, double cutoff_frequency) {
    double RC = 1.0 / (cutoff_frequency * 2 * PI);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    double previous = 0.0;

    for (int i = 0; i < signal->length; i++) {
        signal->data[i] = previous + (alpha * (signal->data[i] - previous));
        previous = signal->data[i];
    }
}

// Function to print the signal for inspection
void print_signal(Signal *signal) {
    for (int i = 0; i < signal->length; i++) {
        printf("%f\n", signal->data[i]);
    }
}

// Function to free the signal memory
void free_signal(Signal *signal) {
    free(signal->data);
    free(signal);
}

// The great detective's journey into sound
void sherlock_decodes_sound() {
    printf("** The Adventure of the Mysterious Sound **\n");
    
    // Generate a signal of frequency 440 Hz (A4 note)
    double frequency = 440.0;
    double duration = 1.0; // 1 second
    Signal *signalA = generate_signal(frequency, duration);
    
    // Apply a low-pass filter with a cutoff frequency of 300 Hz
    printf("Applying low-pass filter...\n");
    low_pass_filter(signalA, 300.0);

    // Print the filtered signal
    printf("Filtered Signal Samples:\n");
    print_signal(signalA);

    // Clean up the memory
    free_signal(signalA);
}

int main() {
    sherlock_decodes_sound();
    return 0;
}