//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: ephemeral
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define DURATION 5 // Duration in seconds
#define FREQUENCY 440 // Frequency of sine wave in Hz
#define PI 3.14159265358979323846

// Low-pass filter function
void apply_low_pass_filter(float* input, float* output, int sample_count, float alpha) {
    output[0] = input[0]; // First sample remains unchanged
    for (int i = 1; i < sample_count; i++) {
        output[i] = (alpha * input[i]) + ((1 - alpha) * output[i - 1]);
    }
}

// Write wave data to a text file
void write_to_file(const char* filename, float* data, int sample_count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < sample_count; i++) {
        fprintf(file, "%f\n", data[i]);
    }
    fclose(file);
}

int main() {
    int sample_count = SAMPLE_RATE * DURATION;
    float* sine_wave = (float*)malloc(sample_count * sizeof(float));
    float* filtered_wave = (float*)malloc(sample_count * sizeof(float));
    
    // Generate sine wave
    for (int i = 0; i < sample_count; i++) {
        sine_wave[i] = 0.5 * sin(2 * PI * FREQUENCY * ((float)i / SAMPLE_RATE));
    }

    // Apply low-pass filter with alpha = 0.1
    float alpha = 0.1;
    apply_low_pass_filter(sine_wave, filtered_wave, sample_count, alpha);

    // Write both sine wave and filtered wave to separate files
    write_to_file("sine_wave.txt", sine_wave, sample_count);
    write_to_file("filtered_wave.txt", filtered_wave, sample_count);
    
    // Free the allocated memory
    free(sine_wave);
    free(filtered_wave);

    printf("Sine wave and filtered wave have been generated and written to files.\n");
    
    return 0;
}