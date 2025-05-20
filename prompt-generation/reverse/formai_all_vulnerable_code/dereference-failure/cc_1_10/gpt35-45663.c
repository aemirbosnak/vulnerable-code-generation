//FormAI DATASET v1.0 Category: Audio processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 4096
#define AMPLITUDE 32767

float note_freq[] = {130.8, 164.8, 196.0, 277.2};
float duration[] = {0.5, 0.5, 0.5, 0.5};

float create_note(float freq, float dur, int sample_rate, int sample_size, int num_channels) {
    int num_samples = (int) (dur * sample_rate);
    float phase_inc = freq * 2 * M_PI / sample_rate;
    short *samples = calloc(num_samples * num_channels, sample_size / 8);

    for (int i = 0; i < num_samples; i++) {
        short sample = (int) (AMPLITUDE * sin(i * phase_inc));
        for (int j = 0; j < num_channels; j++) {
            samples[i * num_channels + j] = sample;
        }
    }

    FILE *fp = fopen("note.wav", "wb");
    if (!fp) return -1;

    int bits_per_sample = sample_size / num_channels;
    int byte_rate = sample_rate * num_channels * bits_per_sample / 8;
    int block_align = num_channels * bits_per_sample / 8;

    fwrite("RIFF", 1, 4, fp);
    fwrite("\0\0\0\0", 1, 4, fp);                    // File size (to be filled in later)
    fwrite("WAVEfmt ", 1, 8, fp);
    fwrite("\20\0\0\0", 1, 4, fp);                   // Chunk size
    fwrite("\1\0", 1, 2, fp);                        // Audio format (1 = PCM)
    fwrite(&num_channels, 1, 2, fp);                 // Number of channels
    fwrite(&sample_rate, 1, 4, fp);                  // Sample rate
    fwrite(&byte_rate, 1, 4, fp);                    // Byte rate
    fwrite(&block_align, 1, 2, fp);                  // Block align
    fwrite(&sample_size, 1, 2, fp);                  // Sample size (bits per sample)
    fwrite("data", 1, 4, fp);
    fwrite("\0\0\0\0", 1, 4, fp);                    // Data size (to be filled in later)

    int data_size = num_samples * num_channels * bits_per_sample / 8;
    fwrite(samples, 1, data_size, fp);

    fseek(fp, 4, SEEK_SET);
    int file_size = data_size + 36;
    fwrite(&file_size, 1, 4, fp);
    fseek(fp, 40, SEEK_SET);
    fwrite(&data_size, 1, 4, fp);

    fclose(fp);
    free(samples);

    return 0;
}

int main() {
    int sample_rate = 44100;
    int sample_size = 16;
    int num_channels = 2;

    for (int i = 0; i < 4; i++) {
        create_note(note_freq[i], duration[i], sample_rate, sample_size, num_channels);
    }

    return 0;
}