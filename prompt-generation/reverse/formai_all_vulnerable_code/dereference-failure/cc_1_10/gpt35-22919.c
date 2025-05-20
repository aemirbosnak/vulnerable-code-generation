//FormAI DATASET v1.0 Category: Audio processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *buffer;
float *delayBuffer;

int main()
{
    printf("Welcome to the Immersive Audio Processor!\n");
    printf("This program will allow you to add echo to any audio file.\n");
    printf("Please enter the name of the audio file you want to process:\n");
    
    char fileName[50];
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "rb");
    if (!file)
    {
        printf("Error: could not open input file!\n");
        return 1;
    }
    
    fseek(file, 0L, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    buffer = (float*) malloc(fileSize);
    delayBuffer = (float*) malloc(fileSize + 100000);

    fread(buffer, sizeof(float), fileSize, file);
    fclose(file);
    
    float echoTime;
    printf("Enter the delay time (in milliseconds) for the echo effect: ");
    scanf("%f", &echoTime);
    printf("\n");
    
    float gain;
    printf("Enter the gain (between 0 and 1) for the echo effect: ");
    scanf("%f", &gain);
    printf("\n");
    
    float delayTime = echoTime * 0.001;
    int delaySamples = (int)(44100 * delayTime);
    
    int i, j;
    long index;
    
    for (i = 0; i < fileSize; i +=2 )
    {
        index = i/2;
        
        if (index < delaySamples)
        {
            delayBuffer[i] = buffer[i];
            delayBuffer[i + 1] = buffer[i + 1];
            
            buffer[i] *= (1-gain);
            buffer[i + 1] *= (1-gain);
        }
        else
        {
            delayBuffer[i] = delayBuffer[i - (delaySamples * 2)];
            delayBuffer[i + 1] = delayBuffer[i + 1 - (delaySamples * 2)];
            
            buffer[i] += (gain * delayBuffer[i - (delaySamples * 2)]);
            buffer[i + 1] += (gain * delayBuffer[i + 1 - (delaySamples * 2)]);
            
            buffer[i] *= 0.5;
            buffer[i + 1] *= 0.5;
        }
    }
    
    char outputFile[50];
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);
    printf("\n");

    FILE *output = fopen(outputFile, "wb");
    if (!output)
    {
        printf("Error: could not open output file!\n");
        return 1;
    }
    
    fwrite(buffer, sizeof(float), fileSize, output);
    fclose(output);
    
    free(buffer);
    free(delayBuffer);
    
    printf("Audio processing complete, output saved to: %s\n", outputFile);
    
    return 0;
}