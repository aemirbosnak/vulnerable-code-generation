//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define SAMPLE_DURATION 5
#define NUM_SAMPLES (SAMPLE_RATE * SAMPLE_DURATION)
#define PI 3.14159265358979323846

typedef struct {
    double freq;
    double amp;
    double phase;
} tone_t;

void generate_tone(double *buffer, int num_samples, tone_t tone) {
    double phase_increment = tone.freq / SAMPLE_RATE;
    for (int i = 0; i < num_samples; i++) {
        double phase = tone.phase + i * phase_increment;
        double sample = tone.amp * sin(phase * 2 * PI);
        buffer[i] += sample;
        tone.phase = phase;
    }
}

int main() {
    FILE *output_file;
    output_file = fopen("romantic_song.wav", "wb");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    tone_t melody = {440, 0.5, 0};
    tone_t harmony = {660, 0.3, 0};

    double *buffer = malloc(NUM_SAMPLES * sizeof(double));

    for (int i = 0; i < NUM_SAMPLES; i++) {
        generate_tone(buffer, SAMPLE_RATE, melody);
        generate_tone(buffer, SAMPLE_RATE, harmony);
        fwrite(buffer, sizeof(double), SAMPLE_RATE, output_file);
    }

    fclose(output_file);
    free(buffer);

    printf("Romantic song generated successfully!\n");
    return 0;
}