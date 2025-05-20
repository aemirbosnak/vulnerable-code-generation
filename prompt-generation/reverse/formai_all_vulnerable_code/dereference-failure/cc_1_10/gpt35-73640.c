//FormAI DATASET v1.0 Category: Audio processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE_HZ 44100
#define PI 3.14159265358979323846

int main() {
    // Generate a 1KHz sine wave
    float frequency = 1000;  // Hz
    float amplitude = 0.5;  // range [-1, 1]
    float time_step = 1.0 / SAMPLE_RATE_HZ;
    float duration = 2;  // seconds

    int num_samples = duration * SAMPLE_RATE_HZ;
    float *audio_buffer = (float*) malloc(num_samples * sizeof(float));
    int sample_index;
    for (sample_index = 0; sample_index < num_samples; sample_index++) {
        float t = sample_index * time_step;  // time in seconds
        float waveform_value = amplitude * sin(2 * PI * frequency * t);
        audio_buffer[sample_index] = waveform_value;
    }

    // Apply a filter
    float cutoff_frequency = 500;  // Hz
    float q = 1 / sqrt(2);
    float w0 = 2 * PI * cutoff_frequency / SAMPLE_RATE_HZ;
    float alpha = sin(w0) / (2 * q);

    float b0 = (1 - cos(w0)) / 2;
    float b1 = 1 - cos(w0);
    float b2 = (1 - cos(w0)) / 2;
    float a0 = 1 + alpha;
    float a1 = -2 * cos(w0);
    float a2 = 1 - alpha;

    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    for (sample_index = 0; sample_index < num_samples; sample_index++) {
        float x0 = audio_buffer[sample_index];

        float y0 = (b0 / a0) * x0 + (b1 / a0) * x1 + (b2 / a0) * x2
                 - (a1 / a0) * y1 - (a2 / a0) * y2;

        audio_buffer[sample_index] = y0;

        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
    }

    // Write the audio to disk
    FILE* audio_file = fopen("output.raw", "wb");
    fwrite(audio_buffer, sizeof(float), num_samples, audio_file);
    fclose(audio_file);

    free(audio_buffer);

    return 0;
}