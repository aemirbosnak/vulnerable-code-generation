//FormAI DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Curious C Audio Processing Example */

int main() {

    printf("Welcome to the curious C audio processing example!\n");
    printf("In this program, we will generate a sine wave and apply some basic processing to it.\n");

    /* Define some variables */
    double sample_rate = 44100.0;
    double frequency = 440.0;
    double duration = 1.0;
    int num_samples = (int)(duration * sample_rate);

    /* Allocate memory for our audio buffer */
    double* audio_buffer = (double*)malloc(num_samples * sizeof(double));

    /* Generate a sine wave */
    for (int i = 0; i < num_samples; i++) {
        double time = (double)i / sample_rate;
        double sample = sin(2.0 * M_PI * frequency * time);
        audio_buffer[i] = sample;
    }

    /* Apply some processing */
    printf("Do you want some processing? (Y/N):\n");
    char ans = getchar();
    if (ans == 'Y' || ans == 'y') {
        double gain = 0.5;
        double threshold = 0.75;
        for (int i = 0; i < num_samples; i++) {
            if (audio_buffer[i] > threshold) {
                audio_buffer[i] *= gain;
            }
        }
        printf("Processing complete!\n");
    } else {
        printf("No processing applied.\n");
    }

    /* Write audio data to a file */
    FILE* audio_file = fopen("output.wav", "wb");
    int bits_per_sample = 16;
    int byte_rate = sample_rate * bits_per_sample / 8;
    int block_align = bits_per_sample / 8;
    fwrite("RIFF", 4, 1, audio_file);
    int file_size = 36 + num_samples * block_align;
    fwrite(&file_size, 4, 1, audio_file);
    fwrite("WAVE", 4, 1, audio_file);
    fwrite("fmt ", 4, 1, audio_file);
    int subchunk1_size = 16;
    fwrite(&subchunk1_size, 4, 1, audio_file);
    short audio_format = 1;
    fwrite(&audio_format, 2, 1, audio_file);
    short num_channels = 1;
    fwrite(&num_channels, 2, 1, audio_file);
    fwrite(&sample_rate, 4, 1, audio_file);
    fwrite(&byte_rate, 4, 1, audio_file);
    fwrite(&block_align, 2, 1, audio_file);
    fwrite(&bits_per_sample, 2, 1, audio_file);
    fwrite("data", 4, 1, audio_file);
    int subchunk2_size = num_samples * block_align;
    fwrite(&subchunk2_size, 4, 1, audio_file);
    for (int i = 0; i < num_samples; i++) {
        short sample = (short)(audio_buffer[i] * 32767);
        fwrite(&sample, 2, 1, audio_file);
    }
    fclose(audio_file);

    /* Free memory */
    free(audio_buffer);

    printf("Output file written to output.wav. Thanks for processing with us!\n");

    return 0;
}