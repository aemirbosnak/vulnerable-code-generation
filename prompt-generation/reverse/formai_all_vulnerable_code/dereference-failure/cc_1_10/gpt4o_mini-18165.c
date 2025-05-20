//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define BUFFER_SIZE 1024

void applyGain(float* buffer, int count, float gain) {
    for (int i = 0; i < count; i++) {
        buffer[i] *= gain; 
    }
}

void applyReverb(float* buffer, int count, float decay) {
    float* temp = (float*)malloc(sizeof(float) * count);
    for (int i = 0; i < count; i++) {
        temp[i] = buffer[i];
        if (i > 0) {
            temp[i] += decay * buffer[i - 1];
        }
    }
    for (int i = 0; i < count; i++) {
        buffer[i] = temp[i];
    }
    free(temp);
}

void processAudio(const char* inputFile, const char* outputFile, float gain, float reverbDecay) {
    SNDFILE *inFile, *outFile;
    SF_INFO sfinfo;
    sfinfo.format = 0;

    inFile = sf_open(inputFile, SFM_READ, &sfinfo);
    if (!inFile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return;
    }
    outFile = sf_open(outputFile, SFM_WRITE, &sfinfo);
    if (!outFile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        sf_close(inFile);
        return;
    }

    float *buffer = (float*)malloc(BUFFER_SIZE * sizeof(float));
    int readCount;

    while ((readCount = sf_read_float(inFile, buffer, BUFFER_SIZE)) > 0) {
        applyGain(buffer, readCount, gain);
        applyReverb(buffer, readCount, reverbDecay);
        sf_write_float(outFile, buffer, readCount);
    }

    free(buffer);
    sf_close(inFile);
    sf_close(outFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <gain> <reverb_decay>\n", argv[0]);
        return 1;
    }

    const char* inputFile = argv[1];
    const char* outputFile = argv[2];
    float gain = atof(argv[3]);
    float reverbDecay = atof(argv[4]);

    processAudio(inputFile, outputFile, gain, reverbDecay);
    
    printf("Audio processing complete: %s processed to %s\n", inputFile, outputFile);
    return 0;
}