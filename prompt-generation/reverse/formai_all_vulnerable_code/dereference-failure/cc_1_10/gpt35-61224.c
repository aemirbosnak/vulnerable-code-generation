//FormAI DATASET v1.0 Category: Digital signal processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846 // Define the value of Pi

// Function to generate a sine wave
void generateSineWave(float freq, float duration_ms, int sample_rate, short int *buffer)
{
    int num_samples = sample_rate * (duration_ms / 1000); // Calculate the number of samples
    float amplitude = 32767; // Set the amplitude
    float phase_increment = (freq * 2 * PI) / sample_rate; // Calculate the phase increment
    
    // Loop through each sample and calculate the corresponding value using the sine function
    for(int i = 0; i < num_samples; i++)
    {
        float phase = i * phase_increment; // Calculate the phase
        float value = sin(phase) * amplitude; // Calculate the value using the sine function
        
        buffer[i] = (short int) value; // Store the value in the buffer as a shorts integer
    }
}

// Function to add two signals
void addSignals(short int *signal1, short int *signal2, int num_samples, short int *result)
{
    // Loop through each sample and add the corresponding values of signal1 and signal2
    for(int i = 0; i < num_samples; i++)
    {
        result[i] = signal1[i] + signal2[i];
    }
}

int main()
{
    int sample_rate = 44100; // Set the sample rate to 44.1 kHz
    int duration_ms = 5000; // Set the duration of the sine wave to 5 seconds
    
    // Allocate memory for the buffers
    short int *sine_wave_buffer = (short int *) malloc(sample_rate * (duration_ms / 1000) * sizeof(short int));
    short int *result_buffer = (short int *) malloc(sample_rate * (duration_ms / 1000) * sizeof(short int));
    
    // Generate a sine wave at 440 Hz
    generateSineWave(440, duration_ms, sample_rate, sine_wave_buffer);
    
    // Generate a sine wave at 880 Hz
    short int *sine_wave_buffer2 = (short int *) malloc(sample_rate * (duration_ms / 1000) * sizeof(short int));
    generateSineWave(880, duration_ms, sample_rate, sine_wave_buffer2);
    
    // Add the two signals
    addSignals(sine_wave_buffer, sine_wave_buffer2, sample_rate * (duration_ms / 1000), result_buffer);
    
    // Print out the first 10 values of the result buffer
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", result_buffer[i]);
    }
    
    // Free the memory
    free(sine_wave_buffer);
    free(sine_wave_buffer2);
    free(result_buffer);
    
    return 0;
}