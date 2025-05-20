//FormAI DATASET v1.0 Category: Audio processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// This program generates a sine wave and applies a low-pass filter to the audio waveform.
// The output is then written to a file for playback.

int main()
{
    FILE *output_file;
    output_file = fopen("output.wav", "wb");

    // Header Information for WAVE PCM Format
    const unsigned long header_size = 44;
    unsigned short audio_format = 1;
    unsigned short num_channels = 1;
    unsigned long sample_rate = 44100;
    unsigned long byte_rate = sample_rate * num_channels * (16 / 8);
    unsigned short block_align = num_channels * (16 / 8);
    unsigned short bits_per_sample = 16;

    // Calculate the frequency and duration of the sine wave
    float frequency = 440.0;
    float duration = 2.0;
    unsigned long num_samples = sample_rate * duration;

    // Generate the sine wave
    float *audio_data = (float*) calloc(num_samples, sizeof(float));
    for(unsigned long i = 0; i < num_samples; i++)
    {
        audio_data[i] = sin(2 * PI * frequency * ((float)i / sample_rate));
    }

    // Apply low-pass filter
    float cutoff_frequency = 5000.0;
    float RC = 1.0 / (2 * PI * cutoff_frequency);
    float dt = 1.0 / sample_rate;
    float alpha = dt / (RC + dt);
    float prev_output = 0;
    for(unsigned long i = 0; i < num_samples; i++)
    {
        float output = alpha * audio_data[i] + (1 - alpha) * prev_output;
        prev_output = output;
        audio_data[i] = output;
    }

    // Normalize audio data to range (-1, 1)
    float max_amplitude = 0;
    for(unsigned long i = 0; i < num_samples; i++)
    {
        if(fabs(audio_data[i]) > max_amplitude)
            max_amplitude = fabs(audio_data[i]);
    }
    for(unsigned long i = 0; i < num_samples; i++)
    {
        audio_data[i] /= max_amplitude;
    }

    // Write wave header information to file
    fwrite("RIFF", 1, 4, output_file);
    fwrite(&header_size, 4, 1, output_file);
    fwrite("WAVE", 1, 4, output_file);
    fwrite("fmt ", 1, 4, output_file);
    fwrite("\x10\x00\x00\x00", 1, 4, output_file);
    fwrite(&audio_format, 2, 1, output_file);
    fwrite(&num_channels, 2, 1, output_file);
    fwrite(&sample_rate, 4, 1, output_file);
    fwrite(&byte_rate, 4, 1, output_file);
    fwrite(&block_align, 2, 1, output_file);
    fwrite(&bits_per_sample, 2, 1, output_file);
    fwrite("data", 1, 4, output_file);
    fwrite(&num_samples, 4, 1, output_file);

    // Write audio data to file
    for(unsigned long i = 0; i < num_samples; i++)
    {
        short sample = (short) (audio_data[i] * 32767);
        fwrite(&sample, 2, 1, output_file);
    }

    // Close the output file
    fclose(output_file);

    return 0;
}