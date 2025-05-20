//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Initialize variables
    int frequency = 1000;
    int sampleRate = 44100;
    int duration = 5;
    int numSamples = sampleRate * duration;
    double *sineWave = (double*) malloc(numSamples * sizeof(double));
    
    // Generate sine wave
    for (int i = 0; i < numSamples; i++) {
        sineWave[i] = sin(2 * M_PI * frequency * i / sampleRate);
    }
    
    // Normalize waveform
    double max = 0;
    for (int i = 0; i < numSamples; i++) {
        if (fabs(sineWave[i]) > max) {
            max = fabs(sineWave[i]);
        }
    }
    for (int i = 0; i < numSamples; i++) {
        sineWave[i] /= max;
    }
    
    // Apply low-pass filter
    double cutoffFrequency = 500;
    double RC = 1 / (2 * M_PI * cutoffFrequency);
    double dt = 1 / (double) sampleRate;
    double alpha = dt / (RC + dt);
    
    double *filteredWave = (double*) malloc(numSamples * sizeof(double));
    filteredWave[0] = sineWave[0];
    
    for (int i = 1; i < numSamples; i++) {
        filteredWave[i] = alpha * sineWave[i] + (1 - alpha) * filteredWave[i - 1];
    }
    
    // Output results
    for (int i = 0; i < numSamples; i++) {
        printf("%f\n", filteredWave[i]);
    }
    
    // Free memory
    free(sineWave);
    free(filteredWave);
    
    return 0;
}