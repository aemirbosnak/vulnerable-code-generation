//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5       // Duration of the signal in seconds
#define FREQUENCY 440.0  // Frequency of the sine wave in Hz
#define PI 3.14159265359
#define FILTER_ALPHA 0.1 // Low-pass filter smoothing factor

void generate_sine_wave(float* buffer, int length, float frequency) {
    for (int i = 0; i < length; i++) {
        buffer[i] = (float)(sin(2 * PI * frequency * i / SAMPLE_RATE));
    }
}

void apply_low_pass_filter(float* input, float* output, int length, float alpha) {
    output[0] = input[0]; // Initialize first sample
    for (int i = 1; i < length; i++) {
        output[i] = alpha * input[i] + (1 - alpha) * output[i - 1];
    }
}

void save_to_file(const char* filename, float* data, int length) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        return;
    }
    
    fwrite(data, sizeof(float), length, file);
    fclose(file);
}

void print_usage() {
    printf("Digital Signal Processing - Sine Wave Generation\n");
    printf("Usage: ./dsp_program <output filename>\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }
    
    int total_samples = SAMPLE_RATE * DURATION;
    
    // Allocate memory for the sine wave and the filtered output
    float* sine_wave = (float*)malloc(total_samples * sizeof(float));
    float* filtered_output = (float*)malloc(total_samples * sizeof(float));
    
    if (!sine_wave || !filtered_output) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    // Generate the sine wave
    generate_sine_wave(sine_wave, total_samples, FREQUENCY);
    
    // Apply the low-pass filter
    apply_low_pass_filter(sine_wave, filtered_output, total_samples, FILTER_ALPHA);
    
    // Save the filtered output to a file
    save_to_file(argv[1], filtered_output, total_samples);

    // Clean up
    free(sine_wave);
    free(filtered_output);
    
    printf("Signal processing complete. Output saved to %s\n", argv[1]);
    return 0;
}