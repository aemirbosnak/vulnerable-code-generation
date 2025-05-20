//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_FRAMES 44100
#define MAX_AMP 32767

typedef struct {
    double freq;
    double amp;
    double phase;
} tone_t;

void generate_tone(tone_t *tone, double freq, double amp, double phase) {
    tone->freq = freq;
    tone->amp = amp;
    tone->phase = phase;
}

void process_frame(tone_t *tone, double *frame) {
    int i;
    double amp = tone->amp;
    double freq = tone->freq;
    double phase = tone->phase;
    for (i = 0; i < FRAME_SIZE; i++) {
        double t = i / SAMPLE_RATE;
        frame[i] += amp * sin(2 * M_PI * freq * t + phase);
    }
}

void add_tones(double *frame, int num_tones, tone_t *tones) {
    int i, j;
    for (i = 0; i < num_tones; i++) {
        process_frame(&tones[i], frame);
    }
}

int main() {
    srand(time(NULL));
    double *frame = malloc(FRAME_SIZE * sizeof(double));
    tone_t tones[3];
    generate_tone(&tones[0], 440, rand() % MAX_AMP + 1, rand() % 360);
    generate_tone(&tones[1], 660, rand() % MAX_AMP + 1, rand() % 360);
    generate_tone(&tones[2], 880, rand() % MAX_AMP + 1, rand() % 360);
    int num_tones = 3;
    int num_frames = NUM_FRAMES;
    FILE *fp = fopen("output.raw", "wb");
    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    for (int i = 0; i < num_frames; i++) {
        add_tones(frame, num_tones, tones);
        fwrite(frame, sizeof(double), FRAME_SIZE, fp);
    }
    fclose(fp);
    printf("Done.\n");
    return 0;
}