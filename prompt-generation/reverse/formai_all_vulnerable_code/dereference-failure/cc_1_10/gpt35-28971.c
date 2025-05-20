//FormAI DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define PI 3.14159

int main() {
    int numSamples = SAMPLE_RATE * DURATION;
    double freq = 440;
    double increment = freq / SAMPLE_RATE;
    double phase = 0;

    short *audio = (short *) calloc(numSamples, sizeof(short));

    for (int i = 0; i < numSamples; i++) {
        double sample = sin(phase * 2 * PI);
        audio[i] = (short) (sample * 32767);

        phase += increment;
        if (phase > 1.0) {
            phase -= 2.0;
        }
    }

    FILE *outputFile = fopen("happy_song.wav", "wb");

    fwrite("RIFF", 1, 4, outputFile);
    int chunkSize = 36 + (numSamples * sizeof(short));
    fwrite(&chunkSize, 1, 4, outputFile);
    fwrite("WAVE", 1, 4, outputFile);

    fwrite("fmt ", 1, 4, outputFile);
    int subchunk1Size = 16;
    fwrite(&subchunk1Size, 1, 4, outputFile);
    short audioFormat = 1;
    fwrite(&audioFormat, 1, 2, outputFile);
    short numChannels = 1;
    fwrite(&numChannels, 1, 2, outputFile);
    int byteRate = SAMPLE_RATE * sizeof(short);
    fwrite(&byteRate, 1, 4, outputFile);
    short blockAlign = sizeof(short);
    fwrite(&blockAlign, 1, 2, outputFile);
    short bitDepth = 16;
    fwrite(&bitDepth, 1, 2, outputFile);

    fwrite("data", 1, 4, outputFile);
    fwrite(&numSamples, 1, 4, outputFile);
    fwrite(audio, sizeof(short), numSamples, outputFile);

    fclose(outputFile);
    free(audio);

    printf("Your happy song has been saved to happy_song.wav. Enjoy and stay happy!\n");

    return 0;
}