//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100

void fft(float* data, int n) {
    int i, j, k;
    float c[n];
    float w[n];

    // compute the FFT
    for (i = 0; i < n / 2; i++) {
        w[i] = 1.0 / (float)sqrt(2.0 * n);
        c[i] = 0.0;
        for (j = 0; j < n; j++) {
            c[i] += w[j] * data[j + i * n];
        }
        c[i] *= 0.5;
    }
    for (i = 0; i < n / 2; i++) {
        w[i] = 1.0 / (float)sqrt(2.0 * n);
        c[i] = 0.0;
        for (j = 0; j < n; j++) {
            c[i] += w[j] * data[j + i * n];
        }
        c[i] *= 0.5;
    }

    // write the result to a file
    FILE* fptr = fopen("output.wav", "w");
    fwrite(c, sizeof(float), n, fptr);
    fclose(fptr);
}

int main(int argc, char* argv[]) {
    FILE* fptr = fopen(argv[1], "r");
    fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    float* buffer = (float*)malloc(BUFFER_SIZE * sizeof(float));
    while (fread(buffer, sizeof(float), BUFFER_SIZE, fptr) == BUFFER_SIZE) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] *= 0.5;
        }
        fft(buffer, BUFFER_SIZE);
        for (int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] *= 0.5;
        }
        fwrite(buffer, sizeof(float), BUFFER_SIZE, stdout);
    }

    fclose(fptr);
    free(buffer);

    return 0;
}