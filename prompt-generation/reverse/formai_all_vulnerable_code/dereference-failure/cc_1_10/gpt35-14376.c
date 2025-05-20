//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ephemeral
/* 
This program uses digital signal processing to generate a unique sound effect.
It generates a sine wave and modulates it with a square wave to create a pulsing sound.

To compile: gcc -o dsp_example dsp_example.c -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_FREQUENCY 44100  // Sampling frequency in Hz
#define AMPLITUDE 0.5  // Amplitude of the sine wave
#define SQUARE_WAVE_FREQUENCY 10  // Square wave frequency in Hz
#define DURATION 5  // Duration of the sound effect in seconds

int main()
{
    double dt = 1.0 / SAMPLING_FREQUENCY; // Time step
    int nsamples = round(DURATION * SAMPLING_FREQUENCY); // Number of samples
    
    // Allocate memory for the output wave
    double *output_wave = (double *)malloc(nsamples * sizeof(double));
    
    // Generate the sine wave
    for (int i = 0; i < nsamples; i++) {
        double t = i * dt;
        output_wave[i] = AMPLITUDE * sin(2 * M_PI * SQUARE_WAVE_FREQUENCY * t);
    }
    
    // Modulate the sine wave with a square wave
    for (int i = 0; i < nsamples; i++) {
        double t = i * dt;
        double modulator = sign(sin(2 * M_PI * SQUARE_WAVE_FREQUENCY * t)); // Square wave
        output_wave[i] *= modulator;
    }
    
    // Write the output wave to a binary file
    FILE *outfile = fopen("sound_effect.raw", "wb");
    fwrite(output_wave, sizeof(double), nsamples, outfile);
    fclose(outfile);
    
    free(output_wave);
    
    return 0;
}

// Helper function to get the sign of a number
int sign(double x)
{
    if (x >= 0) {
        return 1;
    } else {
        return -1;
    }
}