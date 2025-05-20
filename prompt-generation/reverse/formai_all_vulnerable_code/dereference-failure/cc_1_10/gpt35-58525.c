//FormAI DATASET v1.0 Category: Audio processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int sample_rate = 44100; // CD quality sampling rate
    int duration_in_seconds = 10; // Generate a 10-second audio clip
    int num_samples = sample_rate * duration_in_seconds;
    float frequency = 440.0; // Generate a 440Hz sine wave
    float amplitude = 0.5; // Set the amplitude of the sine wave to half
    float phase = 0.0; // Start at phase zero
    float pi = 3.14159265358979323846; // Define pi constant
    float sample_time = 1.0 / sample_rate; // Calculate the time interval between each sample

    // Allocate memory for the audio buffer
    float *audio_buffer = (float*)malloc(num_samples * sizeof(float));

    // Generate the sine wave
    for (int i = 0; i < num_samples; i++) {
        float sample = amplitude * sin(2.0 * pi * frequency * (float)i * sample_time + phase);
        audio_buffer[i] = sample;
    }

    // Apply an echo effect to the audio buffer
    float echo_delay_in_seconds = 0.2; // Set the echo delay to 200 milliseconds
    int echo_delay_in_samples = (int)(echo_delay_in_seconds * sample_rate);
    float echo_decay = 0.5; // Set the echo decay rate to 50%
    for (int i = echo_delay_in_samples; i < num_samples; i++) {
        audio_buffer[i] += echo_decay * audio_buffer[i - echo_delay_in_samples];
    }

    // Normalize the audio buffer
    float max_amplitude = 0;
    for (int i = 0; i < num_samples; i++) {
        if (fabs(audio_buffer[i]) > max_amplitude) {
            max_amplitude = fabs(audio_buffer[i]);
        }
    }
    for (int i = 0; i < num_samples; i++) {
        audio_buffer[i] /= max_amplitude;
    }

    // Write the audio buffer to a WAV file
    FILE *wav_file = fopen("output.wav", "wb");
    if (wav_file == NULL) {
        printf("Could not create output WAV file.\n");
        return 1;
    }
    fwrite("RIFF", 4, 1, wav_file);
    int file_size = 36 + num_samples * 2;
    fwrite(&file_size, 4, 1, wav_file);
    fwrite("WAVE", 4, 1, wav_file);
    fwrite("fmt ", 4, 1, wav_file);
    int format_chunk_size = 16;
    fwrite(&format_chunk_size, 4, 1, wav_file);
    short audio_format = 1; // PCM audio format
    fwrite(&audio_format, 2, 1, wav_file);
    short num_channels = 1; // Mono audio
    fwrite(&num_channels, 2, 1, wav_file);
    fwrite(&sample_rate, 4, 1, wav_file);
    int byte_rate = sample_rate * num_channels * 2; // 2 bytes per sample
    fwrite(&byte_rate, 4, 1, wav_file);
    short block_align = num_channels * 2; // 2 bytes per sample
    fwrite(&block_align, 2, 1, wav_file);
    short bit_depth = 16; // 16-bit samples
    fwrite(&bit_depth, 2, 1, wav_file);
    fwrite("data", 4, 1, wav_file);
    fwrite(&num_samples, 4, 1, wav_file);
    for (int i = 0; i < num_samples; i++) {
        short sample = (short)(audio_buffer[i] * 32767.0);
        fwrite(&sample, 2, 1, wav_file);
    }
    fclose(wav_file);

    // Free memory
    free(audio_buffer);

    return 0;
}