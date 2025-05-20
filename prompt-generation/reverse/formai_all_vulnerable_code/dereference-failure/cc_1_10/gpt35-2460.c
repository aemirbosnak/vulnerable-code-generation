//FormAI DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void generateTone(char *fileName, float frequency, float duration) {
    int sampleRate = 44100; // standard sample rate for CD quality audio
    int numChannels = 1; // mono channel
    int bitsPerSample = 16; // CD quality audio
    int numSamples = (int)(duration * sampleRate); // total number of samples needed
    short *samples = (short*)malloc(numChannels * numSamples * sizeof(short)); // allocate memory for audio data
    
    // generate waveform values for the given frequency
    for (int i = 0; i < numSamples; i++) {
        float time = (float)i / sampleRate; // current time in seconds
        float value = sin(2 * PI * frequency * time); // sine wave value at current time
        if (value > 1.0) value = 1.0; // clipping
        if (value < -1.0) value = -1.0; // clipping
        samples[i] = (short)(value * 32767); // convert float value to short integer for PCM format
    }
    
    // write audio data to file
    FILE *file;
    file = fopen(fileName, "wb");
    if (!file) {
        printf("Error: could not open file '%s' for writing.\n", fileName);
        return;
    }
    
    // write data chunk
    fwrite("data", 4, 1, file); // chunk identifier
    int dataSize = numChannels * numSamples * bitsPerSample / 8; // size of audio data chunk in bytes
    fwrite(&dataSize, 4, 1, file); // size of data chunk
    for (int i = 0; i < numSamples; i++) {
        for (int j = 0; j < numChannels; j++) {
            fwrite(&samples[i*numChannels+j], bitsPerSample/8, 1, file); // write sample to file
        }
    }
    
    // write format chunk
    int formatSize = 16; // size of format chunk in bytes
    short audioFormat = 1; // PCM audio format
    int byteRate = sampleRate * numChannels * bitsPerSample / 8; // bytes per second
    short blockAlign = numChannels * bitsPerSample / 8; // bytes per sample
    fwrite("fmt ", 4, 1, file); // chunk identifier
    fwrite(&formatSize, 4, 1, file); // size of format chunk
    fwrite(&audioFormat, 2, 1, file); // audio format
    fwrite(&numChannels, 2, 1, file); // number of channels
    fwrite(&sampleRate, 4, 1, file); // sample rate
    fwrite(&byteRate, 4, 1, file); // byte rate
    fwrite(&blockAlign, 2, 1, file); // block alignment
    fwrite(&bitsPerSample, 2, 1, file); // bits per sample
    
    // write RIFF chunk
    int fileSize = 4 + (8 + formatSize) + (8 + dataSize); // size of entire file in bytes
    fwrite("RIFF", 4, 1, file); // file identifier
    fwrite(&fileSize, 4, 1, file); // total file size
    fwrite("WAVE", 4, 1, file); // file type
    
    fclose(file);
    free(samples);
    printf("Successfully generated tone file '%s' with frequency %.2f Hz and duration %.2f seconds.\n", fileName, frequency, duration);
}

int main() {
    generateTone("440Hz.wav", 440.0, 1.0); // generate 1 second of 440 Hz sine wave audio
    generateTone("880Hz.wav", 880.0, 1.0); // generate 1 second of 880 Hz sine wave audio
    return 0;
}