//FormAI DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int sample_rate = 44100; // Sampling rate in Hz
    int duration = 3; // Duration of audio clip in seconds
    int num_samples = sample_rate * duration; // Total number of samples

    // Allocate memory for audio data
    double* audio_data = (double*)malloc(num_samples * sizeof(double));

    // Generate a sine wave signal of 440 Hz with amplitude 0.5
    double amplitude = 0.5;
    double frequency = 440.0; // Hz
    double phase = 0.0;
    double phase_increment = 2.0 * M_PI * frequency / sample_rate;

    for (int i = 0; i < num_samples; i++) {
        audio_data[i] = amplitude * sin(phase);
        phase += phase_increment;
        if (phase >= 2.0 * M_PI) {
            phase -= 2.0 * M_PI;
        }
    }

    // Apply a low-pass filter to the audio data
    double cutoff_frequency = 500.0; // Hz
    double decay_rate = 0.99;
    double filter_coefficient = pow(decay_rate, 1.0 / (2.0 * M_PI * cutoff_frequency / sample_rate));

    double previous_sample = 0.0;
    for (int i = 0; i < num_samples; i++) {
        double current_sample = audio_data[i];
        audio_data[i] = filter_coefficient * previous_sample + (1.0 - filter_coefficient) * current_sample;
        previous_sample = audio_data[i];
    }

    // Apply a gain to the audio data
    double gain = 2.0;
    for (int i = 0; i < num_samples; i++) {
        audio_data[i] *= gain;
    }

    // Write the audio data to a WAV file
    FILE* file = fopen("output.wav", "wb");
    int bits_per_sample = 16;
    int byte_rate = sample_rate * (bits_per_sample / 8);
    int block_align = bits_per_sample / 8;

    char* header = (char*)malloc(44 * sizeof(char));
    sprintf(header, "RIFF----WAVEfmt \20\0\0\0\1\0\2\0----\0\0\1\0\16\0data----");

    // Write the header
    fseek(file, 0, SEEK_SET);
    fwrite(header, 1, 44, file);

    // Write the audio data
    fseek(file, 44, SEEK_SET);
    for (int i = 0; i < num_samples; i++) {
        short sample = round(audio_data[i] * 32767);
        fwrite(&sample, sizeof(sample), 1, file);
    }

    // Update the header with file length
    int file_length = ftell(file) - 8;
    header[4] = (char)(file_length & 0xff);
    header[5] = (char)((file_length >> 8) & 0xff);
    header[6] = (char)((file_length >> 16) & 0xff);
    header[7] = (char)((file_length >> 24) & 0xff);

    // Update the header with audio format
    header[20] = (char)(bits_per_sample / 8); // Block align
    header[22] = (char)(bits_per_sample); // Bits per sample

    // Update the header with sample rate
    header[24] = (char)(sample_rate & 0xff);
    header[25] = (char)((sample_rate >> 8) & 0xff);
    header[26] = (char)((sample_rate >> 16) & 0xff);
    header[27] = (char)((sample_rate >> 24) & 0xff);

    // Update the header with byte rate
    header[28] = (char)(byte_rate & 0xff);
    header[29] = (char)((byte_rate >> 8) & 0xff);
    header[30] = (char)((byte_rate >> 16) & 0xff);
    header[31] = (char)((byte_rate >> 24) & 0xff);

    // Update the header with data length
    int data_length = num_samples * (bits_per_sample / 8);
    header[40] = (char)(data_length & 0xff);
    header[41] = (char)((data_length >> 8) & 0xff);
    header[42] = (char)((data_length >> 16) & 0xff);
    header[43] = (char)((data_length >> 24) & 0xff);

    // Write the updated header
    fseek(file, 0, SEEK_SET);
    fwrite(header, 1, 44, file);

    // Close the file and free memory
    fclose(file);
    free(header);
    free(audio_data);

    return 0;
}