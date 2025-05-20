//FormAI DATASET v1.0 Category: Audio processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 2048

void compute_rms(float *buf, int len, float *result) {
    float sum_sq = 0.0f;
    int i;
    for (i = 0; i < len; i++) {
        sum_sq += buf[i] * buf[i];
    }
    *result = sqrtf(sum_sq / len);
}

void compute_spectral_centroid(float *buf, int len, float sample_rate, float *result) {
    float sum = 0.0f;
    float sum_weights = 0.0f;
    int i;
    for (i = 0; i < len; i++) {
        float freq = (float) i * sample_rate / (float) len;
        float weight = buf[i];
        sum += freq * weight;
        sum_weights += weight;
    }
    if (sum_weights != 0.0f) {
        *result = sum / sum_weights;
    } else {
        *result = 0.0f;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    float buf[SIZE];
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Failed to open file %s\n", argv[1]);
        return 1;
    }
    
    int read;
    do {
        read = fread(buf, sizeof(float), SIZE, file);
        float rms, centroid;
        compute_rms(buf, read, &rms);
        compute_spectral_centroid(buf, read, 44100.0f, &centroid);
        printf("RMS: %f, Centroid: %f\n", rms, centroid);
    } while (read == SIZE);

    return 0;
}