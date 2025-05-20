//FormAI DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024 // Size of buffer

int main()
{
    FILE *inpfile, *outfile; // File pointers
    short int samples[BUFFER_SIZE]; // Array to store audio samples
    int sample_rate, num_channels, bits_per_sample; // Audio properties
    int i, k; 
    
    inpfile = fopen("input.wav", "rb");
    
    if(inpfile == NULL) // Check if input file does not exists
    {
        printf("Could not open input file!");
        exit(1);
    }
    
    fseek(inpfile, 22, SEEK_SET); // Get the sample rate from input file
    fread(&sample_rate, sizeof(int), 1, inpfile);
    
    fseek(inpfile, 34, SEEK_SET); // Get the number of channels from input file
    fread(&num_channels, sizeof(short), 1, inpfile);
    
    fseek(inpfile, 32, SEEK_SET); // Get the bits per sample from input file
    fread(&bits_per_sample, sizeof(short), 1, inpfile);
    
    outfile = fopen("output.wav", "wb");
    
    if(outfile == NULL) // Check if output file does not exists
    {
        printf("Could not create output file!");
        exit(1);
    }
    
    fwrite(&sample_rate, sizeof(int), 1, outfile); // Write properties to output file
    fwrite(&num_channels, sizeof(short), 1, outfile);
    fwrite(&bits_per_sample, sizeof(short), 1, outfile);
    
    while(!feof(inpfile)) // Process audio samples
    {
        fread(samples, sizeof(short), BUFFER_SIZE, inpfile); // Read audio samples from input file
        
        for(i = 0; i < BUFFER_SIZE; i++) // Audio processing function
        {
            k = (int)(0.5 * sample_rate / M_PI); // Define the cutoff frequency
            samples[i] = (samples[i] < k && samples[i] > -k) ? 0 : samples[i]; // Apply the filter
        }
        
        fwrite(samples, sizeof(short), BUFFER_SIZE, outfile); // Write processed audio samples to output file
    }
    
    fclose(inpfile);
    fclose(outfile);
    
    return 0;
}