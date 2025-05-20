//FormAI DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define FFT_SIZE 1024
#define SAMPLE_RATE 44100

int main(int argc, char** argv)
{
    srand(time(NULL));
    
    /** create input samples **/
    float* input_samples = (float*)calloc(FFT_SIZE, sizeof(float));
    
    for(int i = 0; i < FFT_SIZE; i++)
    {
        // generate random values between -1 and 1
        input_samples[i] = (float)(rand() % 20001 - 10000) / 10000.0;
    }
    
    /** create sin/cos tables **/
    float* cos_table = (float*)calloc(FFT_SIZE, sizeof(float));
    float* sin_table = (float*)calloc(FFT_SIZE, sizeof(float));
    
    for(int i = 0; i < FFT_SIZE; i++)
    {
        float angle = 2.0 * M_PI * ((float)i / (float)FFT_SIZE);
        cos_table[i] = cos(angle);
        sin_table[i] = sin(angle);
    }
    
    /** calculate FFT **/
    float* real_samples = (float*)calloc(FFT_SIZE, sizeof(float));
    float* imaginary_samples = (float*)calloc(FFT_SIZE, sizeof(float));
    
    for(int i = 0; i < FFT_SIZE; i++)
    {
        real_samples[i] = input_samples[i];
    }
    
    int half_size = FFT_SIZE / 2;
    
    for(int k = 0; k < half_size; k++)
    {
        float real_sum = 0.0;
        float imaginary_sum = 0.0;
        for(int n = 0; n < FFT_SIZE; n++)
        {
            real_sum += real_samples[n] * cos_table[(k * n) % FFT_SIZE];
            imaginary_sum -= real_samples[n] * sin_table[(k * n) % FFT_SIZE];
        }
        real_samples[k] = real_sum;
        imaginary_samples[k] = imaginary_sum;
    }
    
    for(int i = half_size; i < FFT_SIZE; i++)
    {
        real_samples[i] = imaginary_samples[FFT_SIZE - i];
        imaginary_samples[i] = 0.0;
    }
    
    /** calculate spectrum **/
    float* spectrum = (float*)calloc(half_size, sizeof(float));
    
    for(int k = 0; k < half_size; k++)
    {
        float amplitude = sqrt(real_samples[k] * real_samples[k] + imaginary_samples[k] * imaginary_samples[k]);
        float dB = 20 * log10(amplitude);
        spectrum[k] = dB;
    }
    
    /** print spectrum **/
    printf("Frequency\tMagnitude (dB)\n");
    
    for(int i = 0; i < half_size; i++)
    {
        float frequency = (float)i * ((float)SAMPLE_RATE / (float)FFT_SIZE);
        printf("%.2f Hz:\t%.2f dB\n", frequency, spectrum[i]);
    }
    
    /** clean up **/
    free(input_samples);
    free(cos_table);
    free(sin_table);
    free(real_samples);
    free(imaginary_samples);
    free(spectrum);
    
    return 0;
}