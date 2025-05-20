//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 8000
#define FREQUENCY 440.0   // Frequency of the sine wave in Hz
#define DURATION 1.0      // Duration of the waveform in seconds
#define ALPHA 0.1         // Smoothing factor for the low-pass filter

typedef struct {
    float* samples;
    int length;
} Signal;

Signal* generate_sine_wave(float frequency, float duration) {
    int num_samples = (int)(SAMPLE_RATE * duration);
    Signal* sine_wave = (Signal*)malloc(sizeof(Signal));
    sine_wave->samples = (float*)malloc(num_samples * sizeof(float));
    sine_wave->length = num_samples;

    for (int i = 0; i < num_samples; i++) {
        sine_wave->samples[i] = 0.5f * sinf(2 * M_PI * frequency * i / SAMPLE_RATE);
    }
    
    return sine_wave;
}

Signal* apply_low_pass_filter(Signal* input_signal) {
    Signal* filtered_signal = (Signal*)malloc(sizeof(Signal));
    filtered_signal->samples = (float*)malloc(input_signal->length * sizeof(float));
    filtered_signal->length = input_signal->length;

    filtered_signal->samples[0] = input_signal->samples[0]; // Initialize first sample

    for (int i = 1; i < input_signal->length; i++) {
        filtered_signal->samples[i] = ALPHA * input_signal->samples[i] +
                                       (1 - ALPHA) * filtered_signal->samples[i - 1];
    }

    return filtered_signal;
}

void write_signal_to_file(Signal* signal, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }
    
    for (int i = 0; i < signal->length; i++) {
        fprintf(file, "%d %f\n", i, signal->samples[i]);
    }
    
    fclose(file);
}

void cleanup(Signal* signal) {
    if (signal) {
        free(signal->samples);
        free(signal);
    }
}

int main() {
    Signal* sine_wave = generate_sine_wave(FREQUENCY, DURATION);
    Signal* filtered_wave = apply_low_pass_filter(sine_wave);
    
    write_signal_to_file(sine_wave, "sine_wave.txt");
    write_signal_to_file(filtered_wave, "filtered_wave.txt");
    
    printf("Sine wave and filtered wave written to 'sine_wave.txt' and 'filtered_wave.txt'.\n");
    
    // Instructions to plot the data
    printf("To plot the results, run the following command:\n");
    printf("gnuplot -e \"plot 'sine_wave.txt' with lines title 'Sine Wave', 'filtered_wave.txt' with lines title 'Filtered Wave'\"\n");

    cleanup(sine_wave);
    cleanup(filtered_wave);
    
    return 0;
}