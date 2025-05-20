//FormAI DATASET v1.0 Category: Audio processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to apply equalization filter to an audio signal
void equalize(double* audio_signal, int length, double gain, double frequency, double Q) {
    // calculate filter coefficients
    double w0 = 2 * M_PI * frequency;
    double alpha = sin(w0) / (2 * Q);
    double a0 = 1 + alpha / gain;
    double a1 = -2 * cos(w0);
    double a2 = 1 - alpha / gain;
    double b0 = (1 + gain) * (1 - cos(w0)) / 2;
    double b1 = (1 + gain) * (1 - cos(w0));
    double b2 = (1 + gain) * (1 - cos(w0)) / 2;
    
    // apply filter to audio signal
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int n = 0; n < length; ++n) {
        double xn = audio_signal[n];
        double yn = (b0/a0)*xn + (b1/a0)*x1 + (b2/a0)*x2 - (a1/a0)*y1 - (a2/a0)*y2;
        x2 = x1;
        x1 = xn;
        y2 = y1;
        y1 = yn;
        audio_signal[n] = yn;
    }
}

int main() {
    // generate example audio signal
    int sample_rate = 44100;
    int num_samples = 2*sample_rate;
    double* audio_signal = malloc(num_samples * sizeof(double));
    for (int n = 0; n < num_samples; ++n) {
        audio_signal[n] = sin(2 * M_PI * 440 * n / sample_rate);
    }
    
    // apply equalization filter to audio signal
    double gain = 3;
    double frequency = 1000;
    double Q = 1.5;
    equalize(audio_signal, num_samples, gain, frequency, Q);
    
    // write audio signal to file
    FILE* output_file = fopen("output.wav", "wb");
    int bits_per_sample = 16;
    int byte_rate = sample_rate * bits_per_sample / 8;
    int block_align = bits_per_sample / 8;
    fwrite("RIFF", 1, 4, output_file);
    int chunk_size = 36 + num_samples * block_align;
    fwrite(&chunk_size, sizeof(chunk_size), 1, output_file);
    fwrite("WAVE", 1, 4, output_file);
    fwrite("fmt ", 1, 4, output_file);
    int subchunk1_size = 16;
    fwrite(&subchunk1_size, sizeof(subchunk1_size), 1, output_file);
    short audio_format = 1;
    fwrite(&audio_format, sizeof(audio_format), 1, output_file);
    short num_channels = 1;
    fwrite(&num_channels, sizeof(num_channels), 1, output_file);
    fwrite(&sample_rate, sizeof(sample_rate), 1, output_file);
    fwrite(&byte_rate, sizeof(byte_rate), 1, output_file);
    fwrite(&block_align, sizeof(block_align), 1, output_file);
    fwrite(&bits_per_sample, sizeof(bits_per_sample), 1, output_file);
    fwrite("data", 1, 4, output_file);
    int subchunk2_size = num_samples * block_align;
    fwrite(&subchunk2_size, sizeof(subchunk2_size), 1, output_file);
    for (int n = 0; n < num_samples; ++n) {
        short sample = (short)round(audio_signal[n] * 32767);
        fwrite(&sample, sizeof(sample), 1, output_file);
    }
    fclose(output_file);
    
    // free memory
    free(audio_signal);
    
    return 0;
}