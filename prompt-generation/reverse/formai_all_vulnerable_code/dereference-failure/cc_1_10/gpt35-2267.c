//FormAI DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to read in a .wav file */
void readWAV(char *filename, short **data, int *size, int *sRate, int *numChannels)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    // Read in header information
    char chunkID[4];
    int chunkSize;
    char format[4];
    char subchunk1ID[4];
    int subchunk1Size;
    short audioFormat;
    short numChannels_t;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char subchunk2ID[4];
    int subchunk2Size;
    int i;

    fread(chunkID, 1, 4, file);
    fread(&chunkSize, 4, 1, file);
    fread(format, 1, 4, file);
    fread(subchunk1ID, 1, 4, file);
    fread(&subchunk1Size, 4, 1, file);
    fread(&audioFormat, 2, 1, file);
    fread(&numChannels_t, 2, 1, file);
    fread(&sampleRate, 4, 1, file);
    fread(&byteRate, 4, 1, file);
    fread(&blockAlign, 2, 1, file);
    fread(&bitsPerSample, 2, 1, file);
    fread(subchunk2ID, 1, 4, file);
    fread(&subchunk2Size, 4, 1, file);

    // Allocate memory for data array
    *data = (short*)malloc(subchunk2Size);

    // Read in audio samples
    *size = subchunk2Size / 2;
    *sRate = sampleRate;
    *numChannels = numChannels_t;
    for (i = 0; i < *size; i++) {
        fread((*data)+i, 2, 1, file);
    }

    fclose(file);
}

/* Function to write out a .wav file */
void writeWAV(char *filename, short *data, int size, int sRate, int numChannels)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for write!\n");
        exit(1);
    }
    // Create header information
    char chunkID[] = {'R', 'I', 'F', 'F'};
    int chunkSize = size*numChannels*2 + 36;
    char format[] = {'W', 'A', 'V', 'E'};
    char subchunk1ID[] = {'f', 'm', 't', ' '};
    int subchunk1Size = 16;
    short audioFormat = 1;
    short numChannels_t = numChannels;
    int sampleRate = sRate;
    int byteRate = sRate*numChannels*2;
    short blockAlign = numChannels*2;
    short bitsPerSample = 16;
    char subchunk2ID[] = {'d', 'a', 't', 'a'};
    int subchunk2Size = size*numChannels*2;
    int i;

    // Write out header information
    fwrite(chunkID, 1, 4, file);
    fwrite(&chunkSize, 4, 1, file);
    fwrite(format, 1, 4, file);
    fwrite(subchunk1ID, 1, 4, file);
    fwrite(&subchunk1Size, 4, 1, file);
    fwrite(&audioFormat, 2, 1, file);
    fwrite(&numChannels_t, 2, 1, file);
    fwrite(&sampleRate, 4, 1, file);
    fwrite(&byteRate, 4, 1, file);
    fwrite(&blockAlign, 2, 1, file);
    fwrite(&bitsPerSample, 2, 1, file);
    fwrite(subchunk2ID, 1, 4, file);
    fwrite(&subchunk2Size, 4, 1, file);

    // Write out audio samples
    for (i = 0; i < size*numChannels; i++) {
        fwrite((data)+i, 2, 1, file);
    }

    fclose(file);
}

/* Main audio processing function */
void audioProcess(char *inputPath, char *outputPath, float gain, float freqShift)
{
    short *data;
    int size;
    int sRate;
    int numChannels;

  	// Read in input .wav file
    readWAV(inputPath, &data, &size, &sRate, &numChannels);

    // Apply frequency shift
    int i;
    float phase = 0;
    float phaseInc = 2*M_PI*freqShift/sRate;
    for (i = 0; i < size*numChannels; i += numChannels) {
        float sample = (float)data[i];
        float output = sample * cos(phase) * gain;

        /* Use some creative techniques to fill in the remaining samples
           for the number of channels in the .wav file */
        int j;
        for (j = 1; j < numChannels; j++) {
            output += (float)data[i+j] * cos(phase) * gain;
        }

        // Write output samples back to data array
        int k;
        for (k = 0; k < numChannels; k++) {
            data[i+k] = (short)round(output);
        }

        phase += phaseInc;
        if (phase > 2*M_PI) {
            phase -= 2*M_PI;
        }
    }

    // Write out output .wav file
    writeWAV(outputPath, data, size, sRate, numChannels);

    // Free memory used by data array
    free(data);
}

/* Sample usage */
int main()
{
    audioProcess("input.wav", "output.wav", 1.5, 1000);
    return 0;
}