//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Module 1: Reads in an audio file of specified length and outputs the sample array
int* read_audio_file(char* filename, int length) {
    FILE* file = fopen(filename, "rb"); // open audio file in binary read mode
    if (file == NULL) { // check if file is successfully opened
        printf("Error: cannot open specified file.\n");
        return NULL;
    }
    int* audio_sample = (int*) malloc(length * sizeof(int)); // allocate memory for sample array
    fread(audio_sample, sizeof(int), length, file); // read in specified number of samples
    fclose(file); // close file
    return audio_sample; // return sample array
}

// Module 2: Applies a low-pass filter with specified cutoff frequency to an audio sample array
void lowpass_filter(int* sample_array, int length, int cutoff_frequency) {
    double cutoff_normalised = 2 * M_PI * cutoff_frequency / 44100; // normalise cutoff frequency
    double alpha = sin(cutoff_normalised) / (2 * pow(cos(cutoff_normalised) + 1, 0.5)); // calculate alpha value
    double beta = (1 - cos(cutoff_normalised)) / 2; // calculate beta value
    double prev_y = sample_array[0]; // initialise previous output as first sample
    for (int i = 1; i < length; i++) { // loop through all samples
        double y = alpha * (sample_array[i] + sample_array[i-1]) + beta * prev_y; // calculate output sample using filter equation
        prev_y = y; // update previous output value
        sample_array[i] = (int) y; // update sample array with output sample
    }
}

// Module 3: Writes an audio sample array to a specified file for output
void write_audio_file(int* sample_array, int length, char* filename) {
    FILE* file = fopen(filename, "wb"); // open output file in binary write mode
    if (file == NULL) { // check if file is successfully opened
        printf("Error: cannot open specified file.\n");
        return;
    }
    fwrite(sample_array, sizeof(int), length, file); // write sample array to file
    fclose(file); // close file
}

// main function: applies a low-pass filter to an audio file, then outputs the filtered audio to a new file
int main() {
    // read in audio file
    int* sample_array = read_audio_file("input.wav", 441000);
    if (sample_array == NULL) { // check if file reading was successful
        return 1;
    }

    // apply low-pass filter with cutoff frequency of 500 Hz
    lowpass_filter(sample_array, 441000, 500);

    // write filtered audio to output file
    write_audio_file(sample_array, 441000, "output.wav");

    // free memory allocated for sample array
    free(sample_array);

    return 0;
}