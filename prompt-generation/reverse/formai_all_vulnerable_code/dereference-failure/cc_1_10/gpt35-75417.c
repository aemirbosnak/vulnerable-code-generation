//FormAI DATASET v1.0 Category: Digital signal processing ; Style: cheerful
/*
Welcome to the Digital Signal Processing Fun Zone!
In this program, we will demonstrate how to create a custom music player using DSP.
Are you ready to rock? Let's get started!
*/

//include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define some constants
#define SAMPLE_RATE 44100 //standard CD quality
#define BUFFER_SIZE 1024 //number of samples per buffer

int main() {
    //declare variables
    float frequency = 440; //A4 note frequency
    float amplitude = 0.5; //volume, ranges from 0 to 1
    int duration = 5; //length of note in seconds
    int sampleCount = duration * SAMPLE_RATE; //total number of samples
    float *buffer = (float *) malloc(sizeof(float) * BUFFER_SIZE); //audio buffer

    //calculate the phase increment to create the desired frequency
    float phaseIncrement = (2 * M_PI * frequency) / SAMPLE_RATE;

    //initialize the buffer to all zeroes
    for(int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0;
    }

    //generate the digital audio signal
    int sampleIndex = 0;
    while(sampleIndex < sampleCount) {
        float sampleValue = amplitude * sin(sampleIndex * phaseIncrement);

        //add the sample to the buffer
        buffer[sampleIndex % BUFFER_SIZE] += sampleValue;

        sampleIndex++;
    }

    //output the audio buffer to a file
    FILE *file = fopen("output.wav", "w");
    fprintf(file, "RIFF"); //header
    fprintf(file, "                 "); //file size, to be calculated later
    fprintf(file, "WAVE"); //file type
    fprintf(file, "fmt " //format subchunk
        "\x10\x00\x00\x00" //subchunk size
        "\x01\x00" //audio format (PCM)
        "\x01\x00" //number of channels (mono)
        "%c%c%c%c" //sample rate
        "%c%c" //byte rate
        "\x01\x00" //block align
        "\x08\x00" //bits per sample
        , SAMPLE_RATE & 0xff, (SAMPLE_RATE >> 8) & 0xff, (SAMPLE_RATE >> 16) & 0xff, (SAMPLE_RATE >> 24) & 0xff
        , (SAMPLE_RATE * 1) & 0xff, ((SAMPLE_RATE * 1) >> 8) & 0xff
    );
    fprintf(file, "data"); //data subchunk
    int dataSizePosition = ftell(file);
    fprintf(file, "                "); //data size, to be calculated later
    int sampleIndex2 = 0;
    while(sampleIndex2 < sampleCount) {
        int sampleValue2 = floor(buffer[sampleIndex2 % BUFFER_SIZE] * 127) + 127;
        fputc(sampleValue2, file);

        sampleIndex2++;
    }

    //calculate and fill in the file size and data size fields
    int fileSize = ftell(file) - 8;
    fseek(file, 4, SEEK_SET);
    fprintf(file, "%c%c%c%c", fileSize & 0xff, (fileSize >> 8) & 0xff, (fileSize >> 16) & 0xff, (fileSize >> 24) & 0xff);
    fseek(file, dataSizePosition, SEEK_SET);
    int dataSize = sampleCount * sizeof(int);
    fprintf(file, "%c%c%c%c", dataSize & 0xff, (dataSize >> 8) & 0xff, (dataSize >> 16) & 0xff, (dataSize >> 24) & 0xff);

    //close the file and free the buffer memory
    fclose(file);
    free(buffer);

    printf("Woo hoo! Your custom music player is ready to go!\n");

    return 0;
}