//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SAMPLE_RATE 44100

int main()
{
    // Allocate memory for input and output arrays
    float *input = malloc(SAMPLE_RATE * sizeof(float));
    float *output = malloc(SAMPLE_RATE * sizeof(float));
    
    // Create a sinewave as input
    for(int i = 0; i < SAMPLE_RATE; i++)
    {
        input[i] = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
    }
    
    // Apply low-pass filter to input and store in output array
    for(int i = 0; i < SAMPLE_RATE; i++)
    {
        if(i == 0)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = 0.5 * input[i] + 0.5 * input[i-1];
        }
    }
    
    // Apply high-pass filter to output and store in input array
    for(int i = 0; i < SAMPLE_RATE; i++)
    {
        if(i == 0)
        {
            input[i] = output[i];
        }
        else
        {
            input[i] = 0.5 * output[i] - 0.5 * output[i-1];
        }
    }
    
    // Normalize output array
    float max_amp = 0;
    for(int i = 0; i < SAMPLE_RATE; i++)
    {
        if(fabs(input[i]) > max_amp)
        {
            max_amp = fabs(input[i]);
        }
    }
    for(int i = 0; i < SAMPLE_RATE; i++)
    {
        input[i] = input[i] / max_amp;
    }
    
    // Write output to file
    FILE *fp = fopen("output.raw", "w");
    for(int i = 0; i < SAMPLE_RATE; i++)
    {
        fwrite(&input[i], sizeof(float), 1, fp);
    }
    fclose(fp);
    
    // Free memory
    free(input);
    free(output);
    
    return 0;
}