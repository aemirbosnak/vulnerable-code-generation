//FormAI DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
This program demonstrates Audio Processing
by taking an input audio file and performing
echo and fade-in effect on it.
*/

#define BUFFER_SIZE 4096 // buffer size for input audio data

// function to read input audio file
short* readAudioFile(const char* filename, unsigned int* sampleRate, unsigned int* numSamples) {
    FILE* file;
    short* audioData;
    char buff[4];

    file = fopen(filename, "rb"); // open file as binary
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    // read file header information
    fseek(file, 24, SEEK_SET);
    fread(sampleRate, 4, 1, file);
    fseek(file, 40, SEEK_SET);
    fread(numSamples, 4, 1, file);

    // allocate memory to store audio data
    audioData = (short*)malloc((*numSamples) * sizeof(short));

    // read audio data from file
    fseek(file, 44, SEEK_SET);
    fread(audioData, sizeof(short), (*numSamples), file);

    fclose(file);

    return audioData;
}

// function to write output audio file
void writeAudioFile(const char* filename, unsigned int sampleRate, unsigned int numSamples, short* audioData) {
    FILE* file;
    char buff[4];

    file = fopen(filename, "wb"); // open file as binary
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }

    // write file header information
    fwrite("RIFF", 4, 1, file);
    fwrite(buff, 4, 1, file);
    fwrite("WAVE", 4, 1, file);
    fwrite("fmt ", 4, 1, file);
    fwrite(buff, 4, 1, file); // chunk size
    fwrite("\x01\x00", 2, 1, file); // format (PCM)
    fwrite("\x02\x00", 2, 1, file); // number of channels
    fwrite(&sampleRate, 4, 1, file);
    fwrite(buff, 4, 1, file);
    fwrite("\x04\x00", 2, 1, file); // bits per sample
    fwrite("data", 4, 1, file);
    fwrite(buff, 4, 1, file); // chunk size
    fwrite(audioData, sizeof(short), numSamples, file);

    fclose(file);
}

// function to perform echo effect on audio data
void echoEffect(short* audioData, unsigned int numSamples, unsigned int delay, float decay) {
    for (int i = delay; i < numSamples; i++) {
        audioData[i] += (short)(audioData[i - delay] * decay);
    }
}

// function to perform fade-in effect on audio data
void fadeInEffect(short* audioData, unsigned int numSamples, unsigned int fadeLength) {
    for (int i = 0; i < fadeLength; i++) {
        audioData[i] *= (short)(sin(M_PI / 2.0 * i / fadeLength));
    }
}

int main() {
    unsigned int sampleRate = 0;
    unsigned int numSamples = 0;
    short* audioData = readAudioFile("input_audio.wav", &sampleRate, &numSamples);
    if (audioData == NULL) {
        return 1;
    }

    // perform echo effect
    echoEffect(audioData, numSamples, 22050, 0.5);

    // perform fade-in effect
    fadeInEffect(audioData, numSamples, 22050);

    // write output audio file
    writeAudioFile("output_audio.wav", sampleRate, numSamples, audioData);

    free(audioData);
    return 0;
}