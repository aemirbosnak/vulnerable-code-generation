//FormAI DATASET v1.0 Category: Audio processing ; Style: Sherlock Holmes
// The Adventure of the Muffled Sound
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declare function to normalize audio signal
void normalize_signal(float* signal, int signal_length, float max_amplitude);

// Declare function to apply low-pass filter to audio signal
void low_pass_filter(float* signal, int signal_length, float cutoff_freq);

// Declare function to read audio data from file
int read_audio_file(float** signal, int* signal_length, char* filename);

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s [input filename] [output filename]\n", argv[0]);
        return 1;
    }
    char* input_filename = argv[1];
    char* output_filename = argv[2];

    // Read audio data from file
    float* signal;
    int signal_length;
    if (read_audio_file(&signal, &signal_length, input_filename) != 0) {
        printf("Error reading input file '%s'\n", input_filename);
        return 1;
    }

    // Normalize audio signal
    normalize_signal(signal, signal_length, 1.0);

    // Apply low-pass filter to audio signal (cutoff frequency = 400 Hz)
    low_pass_filter(signal, signal_length, 400.0);

    // Write filtered audio data to file
    FILE* fp = fopen(output_filename, "wb");
    fwrite(signal, sizeof(float), signal_length, fp);
    fclose(fp);

    // Free memory
    free(signal);

    printf("The muffled sound has been cleared up and saved to '%s'!\n", output_filename);
    return 0;
}

void normalize_signal(float* signal, int signal_length, float max_amplitude) {
    // Find maximum absolute amplitude of signal
    float max_abs_amplitude = 0.0;
    for (int i = 0; i < signal_length; i++) {
        float abs_amplitude = fabs(signal[i]);
        if (abs_amplitude > max_abs_amplitude) {
            max_abs_amplitude = abs_amplitude;
        }
    }

    // Normalize signal based on maximum absolute amplitude
    if (max_abs_amplitude > 0.0) {
        float scaling_factor = max_amplitude / max_abs_amplitude;
        for (int i = 0; i < signal_length; i++) {
            signal[i] *= scaling_factor;
        }
    }
}

void low_pass_filter(float* signal, int signal_length, float cutoff_freq) {
    // Compute time step and frequency step
    float dt = 1.0 / 44100.0;
    float df = 1.0 / (dt * signal_length);

    // Compute cutoff frequency in terms of frequency bins
    int cutoff_bin = (int)round(cutoff_freq / df);

    // Apply low-pass filter
    for (int i = 0; i < cutoff_bin; i++) {
        signal[i] = 0.0;
        signal[signal_length - 1 - i] = 0.0;
    }
}

int read_audio_file(float** signal, int* signal_length, char* filename) {
    // Open file for reading binary data
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return 1;
    }

    // Determine length of file in bytes
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Check if file length is a multiple of sizeof(float)
    if (file_size % sizeof(float) != 0) {
        fclose(fp);
        return 1;
    }

    // Allocate memory for signal array
    *signal_length = file_size / sizeof(float);
    *signal = (float*)malloc(*signal_length * sizeof(float));

    // Read binary data into signal array
    fread(*signal, sizeof(float), *signal_length, fp);

    // Close file
    fclose(fp);

    return 0;
}