//FormAI DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to read in a wav file */
int read_wav_file(char *filename, short *buffer, int max_samples) {
    FILE *file;
    short data;
    int byte_counter = 0;
    int sample_counter = 0;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: cannot open WAV file!\n");
        return -1;
    }

    /* Skip RIFF header */
    fseek(file, 24, SEEK_CUR);

    /* Read samples */
    while (sample_counter < max_samples) {
        fread(&data, sizeof(short), 1, file);
        buffer[sample_counter] = data;
        byte_counter += 2;
        sample_counter++;
    }

    fclose(file);
    return sample_counter;
}

/* Function to write out a wav file */
void write_wav_file(char *filename, short *buffer, int sample_rate, int max_samples) {
    FILE *file;
    int byte_rate = sample_rate * sizeof(short);
    int subchunk2_size = max_samples * sizeof(short);

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: cannot create WAV file!\n");
        return;
    }

    /* Write RIFF header */
    fwrite("RIFF", 1, 4, file);
    fwrite(&subchunk2_size, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    fwrite("\x10\0\0\0", 4, 1, file);
    fwrite("\x01\0", 2, 1, file);
    fwrite("\x01\0", 2, 1, file);
    fwrite(&sample_rate, 4, 1, file);
    fwrite(&byte_rate, 4, 1, file);
    fwrite("\x02\0\x10\0", 4, 1, file);
    fwrite("data", 1, 4, file);
    fwrite(&subchunk2_size, 4, 1, file);

    /* Write samples */
    fwrite(buffer, sizeof(short), max_samples, file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    short *buffer = NULL;
    int num_samples = 0;
    float freq = 440.0f;
    int sample_rate = 44100;
    int duration = 5;
    int max_samples = sample_rate * duration;

    /* Allocate buffer */
    buffer = (short*) malloc(max_samples * sizeof(short));

    /* Generate sine wave */
    for (int i = 0; i < max_samples; i++) {
        float t = (float) i / (float) sample_rate;
        buffer[i] = (short) (32767.0 * sin(2.0 * M_PI * freq * t));
    }

    /* Write out wav file */
    write_wav_file("sine.wav", buffer, sample_rate, max_samples);

    /* Read in wav file */
    num_samples = read_wav_file("sine.wav", buffer, max_samples);

    /* Mix with noise */
    for (int i = 0; i < num_samples; i++) {
        float noise = ((float) rand() / (RAND_MAX / 2.0)) - 1.0;
        buffer[i] += (short) (32767.0 * noise * 0.1);
    }

    /* Write out noisy wav file */
    write_wav_file("noisy_sine.wav", buffer, sample_rate, max_samples);

    free(buffer);
    return 0;
}