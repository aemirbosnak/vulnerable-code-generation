//FormAI DATASET v1.0 Category: Audio processing ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void cyberize(float *samples, int length){
    for(int i=0;i<length;i++){
        samples[i] = pow(samples[i],2)/(1+fabs(samples[i]));
    }
    for(int i=0;i<length;i++){
        samples[i] = sin(samples[i]);
    }
    for(int i=0;i<length;i++){
        samples[i] = samples[i] > 0 ? 1-samples[i] : fabs(samples[i])-1;
    }
}

int main(){
    int sampleRate = 22050;
    int duration = 5;
    int numSamples = sampleRate * duration;
    float *samples = (float *)malloc(numSamples * sizeof(float));

    for(int i=0;i<numSamples;i++){
        samples[i] = (float)rand()/RAND_MAX;
    }

    cyberize(samples,numSamples);

    FILE *outFile = fopen("cyberpunk.wav","wb");
    //write file header
    int bitsPerSample = 16;
    int byteRate = sampleRate * bitsPerSample/8;
    int blockAlign = bitsPerSample/8;
    int dataSize = numSamples * bitsPerSample/8 + 36;
    fwrite("RIFF",4,1,outFile);
    fwrite(&dataSize,4,1,outFile);
    fwrite("WAVE",4,1,outFile);
    fwrite("fmt ",4,1,outFile);
    int fmtSize = 16;
    fwrite(&fmtSize,4,1,outFile);
    short audioFormat = 1;
    fwrite(&audioFormat,2,1,outFile);
    short numChannels = 1;
    fwrite(&numChannels,2,1,outFile);
    fwrite(&sampleRate,4,1,outFile);
    fwrite(&byteRate,4,1,outFile);
    fwrite(&blockAlign,2,1,outFile);
    fwrite(&bitsPerSample,2,1,outFile);
    fwrite("data",4,1,outFile);
    fwrite(&dataSize-36,4,1,outFile);

    for(int i=0;i<numSamples;i++){
        short sample = (short)(samples[i] * 32767);
        fwrite(&sample,2,1,outFile);
    }

    fclose(outFile);
    printf("Audio file written successfully!");

    free(samples);
    return 0;
}