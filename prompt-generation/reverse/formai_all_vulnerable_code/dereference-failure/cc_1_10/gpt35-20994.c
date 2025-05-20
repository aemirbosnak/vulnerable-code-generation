//FormAI DATASET v1.0 Category: Audio processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function for generating a random waveform
void randomWave(float *x, int length) {
    for (int i = 0; i < length; i++) {
        x[i] = ((float)rand() / RAND_MAX) * 2 - 1; // Scale between -1 and 1
    }
}

// Function for applying a low-pass filter to a waveform
void lowPassFilter(float *x, int length, float cutoff) {
    float RC = 1.0 / (2 * M_PI * cutoff);
    float dt = 1.0 / 44100; // Sampling rate of 44100 Hz
    
    float alpha = dt / (RC + dt);
    float y_prev = 0;

    for (int i = 0; i < length; i++) {
        float y = alpha * x[i] + (1 - alpha) * y_prev;
        y_prev = y;
        x[i] = y;
    }
}

int main() {
    // Initialize waveform
    int length = 44100; // 1 second of audio at 44100 Hz
    float *waveform = malloc(length * sizeof(float));
    randomWave(waveform, length);

    // Apply low-pass filter
    float cutoff = 5000; // Hz
    lowPassFilter(waveform, length, cutoff);

    // Write waveform to file
    FILE *file = fopen("output.wav", "w");
    fprintf(file, "RIFF");
    int chunkSize = 36 + length*sizeof(float);
    fprintf(file, "%c%c%c%c", chunkSize&0xff, (chunkSize>>8)&0xff, (chunkSize>>16)&0xff, (chunkSize>>24)&0xff);
    fprintf(file, "WAVEfmt ");
    fprintf(file, "%c%c%c%c", 16, 0, 0, 0); // Subchunk1Size
    fprintf(file, "%c%c%c%c", 1, 0); // AudioFormat
    fprintf(file, "%c%c", 1, 0); // NumChannels
    int sampleRate = 44100;
    fprintf(file, "%c%c%c%c", sampleRate&0xff, (sampleRate>>8)&0xff, (sampleRate>>16)&0xff, (sampleRate>>24)&0xff);
    int byteRate = sampleRate * sizeof(float);
    fprintf(file, "%c%c%c%c", byteRate&0xff, (byteRate>>8)&0xff, (byteRate>>16)&0xff, (byteRate>>24)&0xff);
    int blockAlign = sizeof(float);
    fprintf(file, "%c%c", blockAlign&0xff, (blockAlign>>8)&0xff);
    int bitsPerSample = 8 * sizeof(float);
    fprintf(file, "%c%c", bitsPerSample&0xff, (bitsPerSample>>8)&0xff);
    fprintf(file, "data");
    int dataSize = length * sizeof(float);
    fprintf(file, "%c%c%c%c", dataSize&0xff, (dataSize>>8)&0xff, (dataSize>>16)&0xff, (dataSize>>24)&0xff);
    for (int i = 0; i < length; i++) {
        fwrite(&waveform[i], 1, sizeof(float), file);
    }
    fclose(file);

    free(waveform);
    return 0;
}