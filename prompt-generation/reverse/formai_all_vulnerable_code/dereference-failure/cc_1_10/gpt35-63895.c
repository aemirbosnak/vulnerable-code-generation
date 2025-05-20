//FormAI DATASET v1.0 Category: Audio processing ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define WAV_HEADER_SIZE 44

int main(){

    char header[WAV_HEADER_SIZE];

    FILE *f1, *f2;
    f1 = fopen("input.wav","rb"); //opening the input file in read mode
    f2 = fopen("output.wav","wb"); //opening the output file in write mode

    //Reading the wave header
    fread(header,sizeof(header),1,f1);

    int audioSize = 0;
    memcpy(&audioSize,&header[40],4); //Extracting the size of the audio data

    short *buffer = malloc(audioSize); //Allocating memory to store the audio data
    short *newBuffer = malloc(audioSize); //Allocating memory to store the filtered audio data

    //Reading the wave audio data
    fread(buffer,audioSize,1,f1);

    //Applying a low-pass filter to the audio data
    int samplingFrequency = 44100;
    int cutoffFrequency = 8000;
    int numSamples = audioSize/sizeof(short);
    double RC = 1.0/(2*M_PI*cutoffFrequency);
    double dt = 1.0/samplingFrequency;
    double alpha = RC/(RC+dt);

    newBuffer[0] = buffer[0];

    for(int i=1; i<numSamples; i++){
        newBuffer[i] = alpha*buffer[i] + (1.0-alpha)*newBuffer[i-1];
    }

    //Writing the filtered audio data to the output file
    fwrite(header,sizeof(header),1,f2);
    fwrite(newBuffer,audioSize,1,f2);

    //Closing the files and freeing the memory
    fclose(f1);
    fclose(f2);
    free(buffer);
    free(newBuffer);

    return 0;
}