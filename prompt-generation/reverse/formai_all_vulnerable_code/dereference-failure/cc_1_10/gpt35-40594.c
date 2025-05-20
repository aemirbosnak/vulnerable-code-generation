//FormAI DATASET v1.0 Category: Audio processing ; Style: synchronous
// Example program for Audio processing in C using a synchronous style

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100   // Sample rate in Hz
#define PI 3.14159265359    // Value of pi

// Function to generate a sine wave of a given frequency and amplitude
void generate_sine_wave(float* buffer, int buffer_size, float frequency, float amplitude)
{
    float delta = frequency / SAMPLE_RATE * 2 * PI;  // Calculate the phase increment per sample
    float phase = 0.0f;
    
    for (int i = 0; i < buffer_size; i++)
    {
        buffer[i] = amplitude * sin(phase);  // Calculate the sample value
        phase += delta;
        if (phase >= 2 * PI)                 // Wrap the phase if it goes outside the range [0, 2*pi)
            phase -= 2 * PI;
    }
}

// Function to normalize the samples in a buffer to the range [-1, 1]
void normalize_buffer(float* buffer, int buffer_size)
{
    float max_value = 0.0f;
    
    for (int i = 0; i < buffer_size; i++)
        if (fabs(buffer[i]) > max_value)
            max_value = fabs(buffer[i]);
    
    if (max_value > 1.0f)
        for (int i = 0; i < buffer_size; i++)
            buffer[i] /= max_value;
}

int main(void)
{
    int buffer_size = SAMPLE_RATE / 2;   // Generate a half-second buffer
    float* buffer = malloc(buffer_size * sizeof(float));
    
    generate_sine_wave(buffer, buffer_size, 440.0f, 0.5f);   // Generate a 440 Hz sine wave with 0.5 amplitude
    normalize_buffer(buffer, buffer_size);                   // Normalize the samples in the buffer
    
    // Write the raw audio data to a file
    FILE* fp = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(float), buffer_size, fp);
    fclose(fp);
    
    // Free the buffer memory
    free(buffer);
    
    return 0;
}