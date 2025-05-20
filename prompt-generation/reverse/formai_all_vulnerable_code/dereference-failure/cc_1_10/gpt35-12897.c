//FormAI DATASET v1.0 Category: Audio processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFSIZE 1024

void printWaveFileHeader(char* buffer, int fileSize);
int getIntValue(char* buffer, int index, int numBytes);
void setIntValue(int value, char* buffer, int index, int numBytes);

int main(int argc, char* argv[])
{
    FILE* inputFile;
    FILE* outputFile;
    
    int bufferSize;
    char* buffer;
    int fileSize;
    
    if(argc != 3)
    {
        printf("Usage: audioProcessor inputfile.wav outputfile.wav\n");
        return 1;
    }
    
    inputFile = fopen(argv[1], "rb");
    if(inputFile == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    rewind(inputFile);
    
    buffer = (char*) malloc(sizeof(char) * fileSize);
    if(buffer == NULL)
    {
        printf("Error allocating memory for buffer\n");
        return 1;
    }
    
    bufferSize = fread(buffer, 1, fileSize, inputFile);
    
    outputFile = fopen(argv[2], "wb");
    if(outputFile == NULL)
    {
        printf("Error creating file %s\n", argv[2]);
        return 1;
    }
    
    printWaveFileHeader(buffer, fileSize);
    
    int i, j;
    int sample;
    int maxValue = 0;
    double newValue;
    
    for(i = 44; i < bufferSize; i += 2)
    {
        sample = getIntValue(buffer, i, 2);
        
        if(sample > maxValue)
        {
            maxValue = sample;
        }
    }
    
    for(i = 44; i < bufferSize; i += 2)
    {
        sample = getIntValue(buffer, i, 2);
        
        newValue = sample / (double) maxValue;
        newValue *= 32767;
        sample = (int) round(newValue);
        
        setIntValue(sample, buffer, i, 2);
    }
    
    fwrite(buffer, 1, bufferSize, outputFile);
    
    fclose(inputFile);
    fclose(outputFile);
    free(buffer);
    
    printf("File %s has been processed and saved as %s\n", argv[1], argv[2]);
    
    return 0;
}

void printWaveFileHeader(char* buffer, int fileSize)
{
    printf("RIFF chunk ID: %.4s\n", &buffer[0]);
    printf("RIFF chunk size: %d\n", getIntValue(buffer, 4, 4));
    printf("Format ID: %.4s\n", &buffer[8]);
    printf("Data chunk ID: %.4s\n", &buffer[12]);
    printf("Data chunk size: %d\n", getIntValue(buffer, 16, 4));
    printf("Audio format: %d\n", getIntValue(buffer, 20, 2));
    printf("Number of channels: %d\n", getIntValue(buffer, 22, 2));
    printf("Sample rate: %d\n", getIntValue(buffer, 24, 4));
    printf("Byte rate: %d\n", getIntValue(buffer, 28, 4));
    printf("Block align: %d\n", getIntValue(buffer, 32, 2));
    printf("Bits per sample: %d\n", getIntValue(buffer, 34, 2));
}

int getIntValue(char* buffer, int index, int numBytes)
{
    int value = 0;
    
    while(numBytes > 0)
    {
        value <<= 8;
        value += (unsigned char) buffer[index];
        index++;
        numBytes--;
    }
    
    return value;
}

void setIntValue(int value, char* buffer, int index, int numBytes)
{
    while(numBytes > 0)
    {
        buffer[index] = (unsigned char) value;
        value >>= 8;
        index++;
        numBytes--;
    }
}