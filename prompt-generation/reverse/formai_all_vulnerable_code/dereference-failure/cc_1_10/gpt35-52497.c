//FormAI DATASET v1.0 Category: Audio processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main () {
    // Welcome message
    printf("Welcome to the immersive audio processing program!\n\n");

    // Initializing variables
    int sampleRate = 44100;  
    int bitDepth = 16;  
    float volume = 1.0;  
    char filename[50];  
    char input[50];  

    // File input prompt 
    printf("Please enter the filename of the audio file you would like to process: ");
    scanf("%s", input);

    // File extension check
    char *ext = strrchr(input, '.');
    if (strcmp(ext, ".wav") != 0) {
        printf("Invalid file type. Please choose a .wav file.\n");
        return 1;
    }

    // Copy file name to filename variable
    strcpy(filename, input);

    // File open
    FILE *audioFile;
    audioFile = fopen(filename, "rb");
    if (audioFile == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    // File read
    fseek(audioFile, 44, SEEK_SET);
    int dataSize = 0;
    fread(&dataSize, 4, 1, audioFile);
    int data[dataSize];
    fread(data, dataSize, 1, audioFile);
    fclose(audioFile);

    // Audio processing 
    for (int i = 0; i < dataSize; i++) {
        // Channel separation
        int channel1 = (data[i] >> bitDepth) & 0xFFFF;
        int channel2 = data[i] & 0xFFFF;
        // Volume adjustment
        channel1 *= volume;
        channel2 *= volume;
        // Re-combine channels
        data[i] = (channel1 << bitDepth) | channel2;
    }

    // Save processed audio to new file
    char newFilename[50];
    strcpy(newFilename, "processed-");
    strcat(newFilename, filename);
    FILE *outputFile;
    outputFile = fopen(newFilename, "wb");
    if (outputFile == NULL) {
        printf("Output file could not be created.\n");
        return 1;
    }
    fwrite(data, dataSize, 1, outputFile);
    fclose(outputFile);

    // Exit message 
    printf("Audio processing complete. The processed audio has been saved to %s.\n", newFilename);
    return 0;
}