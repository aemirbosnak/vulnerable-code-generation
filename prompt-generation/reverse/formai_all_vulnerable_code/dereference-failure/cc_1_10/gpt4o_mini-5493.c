//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define FREQUENCY 440
#define PI 3.141592653589793

typedef struct {
    float *samples;
    int length;
} Signal;

Signal generate_sine_wave(float frequency, int sample_rate, int duration) {
    int num_samples = sample_rate * duration;
    Signal wave;
    wave.length = num_samples;
    wave.samples = (float *)malloc(sizeof(float) * num_samples);

    for (int i = 0; i < num_samples; i++) {
        wave.samples[i] = 0.5f * sinf(2.0f * PI * frequency * ((float)i / sample_rate));
    }
    return wave;
}

void apply_low_pass_filter(Signal *signal, float cutoff_frequency, int sample_rate) {
    float rc = 1.0 / (2 * PI * cutoff_frequency);
    float dt = 1.0 / sample_rate;
    float alpha = dt / (rc + dt);

    for (int i = 1; i < signal->length; i++) {
        signal->samples[i] = signal->samples[i - 1] + alpha * (signal->samples[i] - signal->samples[i - 1]);
    }
}

void save_wave_file(const char *filename, Signal *signal, int sample_rate) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    // Write WAV header
    fwrite("RIFF", sizeof(char), 4, file);
    int chunk_size = 36 + signal->length * sizeof(short);
    fwrite(&chunk_size, sizeof(int), 1, file);
    fwrite("WAVE", sizeof(char), 4, file);
    fwrite("fmt ", sizeof(char), 4, file);
    int subchunk1_size = 16;
    short audio_format = 1;
    short num_channels = 1;
    fwrite(&subchunk1_size, sizeof(int), 1, file);
    fwrite(&audio_format, sizeof(short), 1, file);
    fwrite(&num_channels, sizeof(short), 1, file);
    fwrite(&sample_rate, sizeof(int), 1, file);
    int byte_rate = sample_rate * num_channels * sizeof(short);
    fwrite(&byte_rate, sizeof(int), 1, file);
    short block_align = num_channels * sizeof(short);
    fwrite(&block_align, sizeof(short), 1, file);
    short bits_per_sample = 16;
    fwrite(&bits_per_sample, sizeof(short), 1, file);
    fwrite("data", sizeof(char), 4, file);
    int subchunk2_size = signal->length * sizeof(short);
    fwrite(&subchunk2_size, sizeof(int), 1, file);

    // Write audio samples
    for (int i = 0; i < signal->length; i++) {
        short sample = (short)(signal->samples[i] * 32767); // Convert to 16-bit signed integer
        fwrite(&sample, sizeof(short), 1, file);
    }

    fclose(file);
}

void free_signal(Signal *signal) {
    free(signal->samples);
    signal->samples = NULL;
    signal->length = 0;
}

int main() {
    printf("Starting the peaceful creation of a sine wave\n");

    Signal sine_wave = generate_sine_wave(FREQUENCY, SAMPLE_RATE, DURATION);
    printf("Generated sine wave with frequency %.2f Hz\n", FREQUENCY);

    printf("Applying low-pass filter...\n");
    apply_low_pass_filter(&sine_wave, 500.0, SAMPLE_RATE);
    
    const char *output_filename = "sine_wave.wav";
    save_wave_file(output_filename, &sine_wave, SAMPLE_RATE);
    printf("Wave file saved as %s\n", output_filename);

    free_signal(&sine_wave);
    printf("Freed memory and finished peacefully.\n");
    
    return 0;
}