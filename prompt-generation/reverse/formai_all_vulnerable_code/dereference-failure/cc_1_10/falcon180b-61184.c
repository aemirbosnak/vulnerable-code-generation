//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 1000
#define PI 3.14159265358979323846

typedef struct {
    float freq;
    float amp;
    float phase;
} SineWave;

void initSineWave(SineWave* wave, float freq, float amp) {
    wave->freq = freq;
    wave->amp = amp;
    wave->phase = 0.0;
}

float generateSineWave(SineWave* wave) {
    float sample = sin(2.0 * PI * wave->freq * (wave->phase / SAMPLE_RATE));
    wave->phase += wave->freq / SAMPLE_RATE;
    if (wave->phase >= 1.0) {
        wave->phase -= 1.0;
    }
    return sample * wave->amp;
}

int main() {
    SineWave* wave1 = malloc(sizeof(SineWave));
    SineWave* wave2 = malloc(sizeof(SineWave));

    initSineWave(wave1, 440, 0.5);
    initSineWave(wave2, 880, 0.25);

    float* buffer = malloc(NUM_SAMPLES * sizeof(float));

    for (int i = 0; i < NUM_SAMPLES; i++) {
        float sample1 = generateSineWave(wave1);
        float sample2 = generateSineWave(wave2);
        float mix = sample1 + sample2;
        buffer[i] = mix;
    }

    FILE* output = fopen("output.raw", "wb");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fwrite(buffer, sizeof(float), NUM_SAMPLES, output);

    fclose(output);
    free(buffer);
    free(wave1);
    free(wave2);

    return 0;
}