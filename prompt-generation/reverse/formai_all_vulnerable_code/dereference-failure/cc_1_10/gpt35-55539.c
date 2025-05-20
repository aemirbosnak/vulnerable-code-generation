//FormAI DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265

typedef struct {
    double a0, a1, a2, b0, b1, b2;
    double in1, in2, out1, out2;
} BiQuad;

void initBiQuad(BiQuad *bq) {
    bq->in1 = bq->in2 = bq->out1 = bq->out2 = 0;
}

void setLPF(BiQuad *bq, float frequency, float Q) {
    double w0 = 2 * PI * frequency / SAMPLE_RATE;
    double alpha = sin(w0) / (2 * Q);

    bq->b0 = (1 - cos(w0)) / 2;
    bq->b1 = 1 - cos(w0);
    bq->b2 = (1 - cos(w0)) / 2;
    bq->a0 = 1 + alpha;
    bq->a1 = -2 * cos(w0);
    bq->a2 = 1 - alpha;
}

double process(BiQuad *bq, double input) {
    double output = input * bq->b0 + bq->in1 * bq->b1 + bq->in2 * bq->b2
            - bq->out1 * bq->a1 - bq->out2 * bq->a2;

    bq->in2 = bq->in1;
    bq->in1 = input;
    bq->out2 = bq->out1;
    bq->out1 = output;

    return output / bq->a0;
}

int main() {
    BiQuad filter;
    float frequency = 3000; // Hz
    float Q = 0.7;
    initBiQuad(&filter);
    setLPF(&filter, frequency, Q);

    float duration = 3; // seconds
    int numSamples = SAMPLE_RATE * duration;
    double *waveform = (double*)malloc(numSamples * sizeof(double));

    // Generate a 440 Hz sine wave for 3 seconds
    for(int i = 0; i < numSamples; i++) {
        waveform[i] = sin(2 * PI * 440 * i / SAMPLE_RATE);
    }

    // Apply the filter to the waveform
    for(int i = 0; i < numSamples; i++) {
        waveform[i] = process(&filter, waveform[i]);
    }

    // Write the waveform to a file
    FILE *file = fopen("output.raw", "wb");
    fwrite(waveform, sizeof(double), numSamples, file);
    fclose(file);

    free(waveform);
    return 0;
}